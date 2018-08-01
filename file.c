#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_FILE_LENGTH       (512)
#define MAX_CMD_LENGTH        (512)
#define FILE_PREFIX           ("/home/luopeng/Desktop/test/")
#define FILE_PREFIX_SIZE      (strlen(FILE_PREFIX))

#define is_file_name_legal(len)                       \
	if(FILE_PREFIX_SIZE + len >= MAX_FILE_LENGTH) \
		return -1;

#define DIR_MODE              (0770)
#define FILE_MODE             (0660)
#define FILE_CREATE_FLAG      (O_RDONLY | O_CREAT | O_CLOEXEC)

#define MOVE_FILE             ("mv ")
#define COPY_FILE             ("cp ")

static char buf[MAX_FILE_LENGTH];
static char cmd[MAX_CMD_LENGTH];

static int mkdir_s(const char *filename, int len)
{
	is_file_name_legal(len);
	strncpy(buf + FILE_PREFIX_SIZE - 1, filename, len);
	return mkdir(buf, DIR_MODE) ? errno : 0;
}

static int touch_s(const char *filename, int len)
{
	int fd;
	int res;
	is_file_name_legal(len);
	strncpy(buf + FILE_PREFIX_SIZE - 1, filename, len);
	fd = open(buf, FILE_CREATE_FLAG, FILE_MODE);
	res = errno;
	if (fd > 0)
		close(fd);
	return (fd > 0) ? 0 : res;
}

/* Copy file src to des
 * Both src and des should use absolute path
 *
 * Return 0 for success, otherwise a negative number.
 */
static int cp_mv_s(const char *opt, const char *src, const char *des)
{
	int len;
	int res;
	int index;
	char *last_name = NULL;
	DIR *dir = NULL;
	struct dirent *entry = NULL;

	if (!src || !des)
		return -EINVAL;

	strncpy(cmd, opt, 3);
	strncpy(cmd + 3, FILE_PREFIX, FILE_PREFIX_SIZE);

	index = 3 + FILE_PREFIX_SIZE;
	len   = strlen(src);
	strncpy(cmd + index, src, len);

	index += len;
	cmd[index++] = ' ';

	strncpy(cmd + index, FILE_PREFIX, FILE_PREFIX_SIZE);
	index += FILE_PREFIX_SIZE;
	len    = strlen(des);
	strncpy(cmd + index, des, len);
	cmd[index+1] = '\0';
	
	res = system(cmd);
	if (res) ;

	/* get the des file name */
	last_name = strrchr(src, '/');
	if (!last_name)
		return -EINVAL;

	res = -EACCES;
	len = strlen(last_name);
	dir = opendir(des);
	if (dir) {
		while ((entry = readdir(dir)) != NULL) {
			if (strlen(entry->d_name) == len
			    && !strncmp(entry->d_name, last_name, len))
				res = 0;
				break;
		}
		closedir(dir);
	}

	return res;
}

static void init(void)
{
	strncpy(buf, FILE_PREFIX, FILE_PREFIX_SIZE);
}

int main(int argc, char *argv[])
{
	char *name = "dirGrandFather";
	char *file = "dirGrandFather/test.log";
	char *file_mv = "dirGrandFather/mv.log";
	char *child = "dirGrandFather/dirChild";
	int res;

	init();

	res = mkdir_s(name, strlen(name));
	if (res && res != EEXIST) {
		printf("mkdir error\n");
		return -EINVAL;
	} else if (res) {
		printf("dir exist\n");
	}

	res = touch_s(file, strlen(file));
	if (res) {
		printf("create file error\n");
		return -EINVAL;
	} else
		printf("create file success\n");

	res = mkdir_s(child, strlen(child));
	if (res && res != EEXIST) {
		printf("mkdir error\n");
		return -EINVAL;
	} else if (res) {
		printf("dir exist\n");
	}

	if (!cp_mv_s(COPY_FILE, file, child)) {
		printf("copy success.\n");
	}

	if (!cp_mv_s(MOVE_FILE, file_mv, child)) {
		printf("move success.\n");
	}

	return 0;
}
