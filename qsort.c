
/*
 * <<The C Programming Language>> Page 119
 * Time: 2015.10.14
 *
 * order by v[left]...v[right] increaselly
 */
void qsort(void *v[], int left, int right, int(*comp)(void*, void*)) {
	int i, last;
	if ( left >= right) {
		return;
	}
	// let the middle element be the standard
	swap(v, left, (left+right)/2);
	last = left;
	for ( i = left+1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0 ) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	// the left part is smaller than v[last], the right part is bigger than v[last]
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}
