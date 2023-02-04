#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int main(int argc, char **argv) {
	FILE* file;
	if (argc == 1) {
		printf("Usage: %s [filename]\n", argv[0]);
		return 1;
	}
	if (!is_file(argv[1])) {
		printf("It is a directory or not found.\n");
		return 1;
	}
	file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Can`t read file.\n");
		return 1;
	}
	fseek(file, 0L, SEEK_END);
	long int size = ftell(file);
	fclose(file);
	if (size>1000000000000) {
		printf("%ld TB\n", size / 1000000000000);
	}
	else if (size>1000000000) {
		printf("%ld GB\n", size / 1000000000);
	}
	else if (size>1000000) {
		printf("%ld MB\n", size / 1000000);
	}
	else if (size>1000) {
		printf("%ld KB\n", size / 1000);
	}
	else {
		printf("%ld B\n", size);
	}
	return 0;
}
