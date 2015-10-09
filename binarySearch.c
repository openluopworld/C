
/*
 * x: the search value
 * v: the array
 * n: the length of array
 * return the index of x if x is in v, otherwise return -1.
 */
int binarySearch(int x, int v[], int n) {
	int low = 0;
	int high = n-1;
	int middle = 0;
	while ( low <= high ) {
		middle = (low+high)/2;
		if (x < v[middle]) {
			high = middle-1;
		} else if (x > v[middle]) {
			low = middle+1;
		} else {
			return middle;
		}
	}
	return -1;
}
