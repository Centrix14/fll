#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char buf[BUFSIZ] = "\0";

FILE *fll_fopen_s(char *fname, char *mode) {
	FILE *ptr = fopen(fname, mode);

	if (!ptr) {
		perror(__func__);
		exit(1);
	}
	return ptr;
}

char *fll_read_from_file(char *fname) {
	int c = 0, i = 0;
	FILE *src = NULL;

	src = fll_fopen_s(fname, "r");
	c = fgetc(src);
	while (!feof(src) && i < BUFSIZ-1) {
		buf[i++] = c;
		c = fgetc(src);
	}
	buf[i] = '\0';

	fclose(src);
	return buf;
}
