#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char buf[BUFSIZ] = "\0";

void *fll_malloc_s(int size) {
	char *ptr = malloc(size);

	if (!ptr) {
		perror(__func__);
		exit(1);
	}
	return ptr;
}

FILE *fll_fopen_s(char *fname, char *mode) {
	FILE *ptr = fopen(fname, mode);

	if (!ptr) {
		perror(__func__);
		exit(1);
	}
	return ptr;
}

void fll_free_s(char *ptr) {
	if (ptr) {
		free(ptr);
		//printf(" ");	
	}
}

int fll_get_file_size(char *fname) {
	struct stat buf;

	stat(fname, &buf);
	return buf.st_size;
}

char *fll_read_from_file(char *fname) {
	int size = fll_get_file_size(fname), c = 0, i = 0;
	static char *buffer = NULL;
	FILE *src = NULL;

	buffer = fll_malloc_s(sizeof(char) * size);

	src = fll_fopen_s(fname, "r");
	c = fgetc(src);
	while (!feof(src)) {
		buffer[i++] = c;	
		c = fgetc(src);
	}
	buffer[i] = '\0';

	fclose(src);

	return buffer;
}

char *fll_read_from_file_static(char *fname) {
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
