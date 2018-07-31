#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILE_LENGTH       (256)
#define MAX_CMD_LENGTH        (256)
#define FILE_PREFIX           ("/home/luopeng/Desktop/0801/")
#define FILE_PREFIX_SIZE      (sizeof(FILE_PREFIX))

#define is_file_name_legal(len)                       \
	if(FILE_PREFIX_SIZE + len >= MAX_FILE_LENGTH) \
		return -1;

#define DIR_MODE              (0770)
#define FILE_MODE             (0660)
#define FILE_CREATE_FLAG      (O_RDONLY | O_CREAT | O_CLOEXEC)

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

static int cp_s(const char *src, const char *des)
{
	int len;
	int res;
	strncpy(cmd, "cp ", 3);
	len = strlen(src);
	strncpy(cmd + 3, src, len);
	cmd[3+len-1] = ' ';
	strncpy(cmd + 3 + len, des, strlen(des));
	
	res = system(cmd);
	/* get the file names of the des */
}

static int mv_s(const char *src, const char *des)
{
	int len;
	strncpy(cmd, "mv ", 3);
	len = strlen(src);
	strncpy(cmd + 3, src, len);
	cmd[3+len-1] = ' ';
	strncpy(cmd + 3 + len, des, strlen(des));
	return system(cmd);
}

static void init(void)
{
	strncpy(buf, FILE_PREFIX, FILE_PREFIX_SIZE);
}

int main(int argc, char *argv[])
{
	char *name = "dirGrandFather";
	char *file = "dirGrandFather/test.log";
	int res;
	init();
	printf("%s\n", buf);
	res = mkdir_s(name, strlen(name));
	if (res && res != EEXIST) {
		printf("mkdir error\n");
		return -1;
	} else if (res) {
		printf("dir exist\n");
	}

	res = touch_s(file, strlen(file));
	if (res)
		printf("create file error\n");
	else
		printf("create file success\n");

	return 0;
}
