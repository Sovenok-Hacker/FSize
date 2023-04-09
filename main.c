#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    struct stat st;
    if (stat(argv[1], &st) != 0) {
        perror("Error in stat");
        return 1;
    }
    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file or does not exist.\n", argv[1]);
        return 1;
    }
    long int size = st.st_size;
    char* suffix = "B";
    if (size >= 1000000000000) {
        size /= 1000000000000;
        suffix = "TB";
    } else if (size >= 1000000000) {
        size /= 1000000000;
        suffix = "GB";
    } else if (size >= 1000000) {
        size /= 1000000;
        suffix = "MB";
    } else if (size >= 1000) {
        size /= 1000;
        suffix = "KB";
    }
    printf("%ld %s\n", size, suffix);
    return 0;
}
