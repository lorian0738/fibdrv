#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define FIB_DEV "/dev/fibonacci"

int main()
{
    long long sz;

    char buf[1];
    char write_buf[] = "testing writing";
    int offset = 100; /* TODO: try test something bigger than the limit */

    int fd = open(FIB_DEV, O_RDWR);
    if (fd < 0) {
        perror("Failed to open character device");
        exit(1);
    }

    // prepare csv for gnuplot
    FILE *fp = fopen("time.txt", "w+");
    // FILE *fp = fopen("time_woclz.txt", "w+"); // @@@ without clz
    // FILE *fp = fopen("time_loop.txt", "w+"); // ### with loop
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "nth Fibonacci Fast Doubling\n");
    // fprintf(fp, "Fast Doubling no clz\n"); // @@@ without clz
    // fprintf(fp, "loop\n"); // ### with loop

    for (int i = 0; i <= offset; i++) {
        // sz = read(fd, buf, 1);
        // long long time = write(fd, write_buf, strlen(write_buf));
        // printf("Writing to " FIB_DEV ", returned the sequence %lld\n", time);
        printf("Writing to " FIB_DEV ", returned the sequence %d\n", 1);
    }

    for (int i = 0; i <= offset; i++) {
        lseek(fd, i, SEEK_SET);
        sz = read(fd, buf, 1);
        long long time = write(fd, write_buf, strlen(write_buf));
        printf("Reading from " FIB_DEV
               " at offset %d, returned the sequence "
               "%lld.\n",
               i, sz);
        printf(fp, "%d %lld\n", i, time);
        // fprintf(fp, "%lld\n", time); // @@@ without clz
        // fprintf(fp, "%lld\n", time); // ### with loop
    }

    fclose(fp);

    for (int i = offset; i >= 0; i--) {
        lseek(fd, i, SEEK_SET);
        sz = read(fd, buf, 1);
        printf("Reading from " FIB_DEV
               " at offset %d, returned the sequence "
               "%lld.\n",
               i, sz);
    }

    close(fd);
    return 0;
}
