#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void *fll_malloc_s(int size) {
	void *ptr = malloc(size);

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

void fll_free_s(void *ptr) {
	if (ptr)
		free(ptr);
}

int fll_get_file_size(char *fname) {
	struct stat buf;

	stat(fname, &buf);
	return buf.st_size;
}

char *fll_read_from_file(char *fname) {
	int size = fll_get_file_size(fname), c = 0, i = 0;
	char *buffer = NULL;
	FILE *src = NULL;

	buffer = fll_malloc_s(size);

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
