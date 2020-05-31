# introduction
file loading library (fll) is a library designed for uploading files to programs in the C programming language. It is very simple to use:
```c
char *buffer = NULL;
...
buffer = fll_read_from_file("my_file");
...
fll_free_s(buffer);
```

## functions
  + `char *fll_read_from_file(char *file_name)` -- returns the contents of the `file_name` file
  + `void fll_free_s(void *buffer)` -- frees the `buffer` buffer

## requirements  
  + C standard library
  + `sys/stat.h` header

### by ASZ  
