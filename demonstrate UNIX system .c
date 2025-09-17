#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char write_buf[] = "Hello, UNIX file management demo!\n";
    char read_buf[100];

    fd = creat("demo.txt", 0777);
    write(fd, write_buf, strlen(write_buf));
    close(fd);

    fd = open("demo.txt", O_RDONLY);
    read(fd, read_buf, sizeof(read_buf));
    printf("Data in file:\n%s", read_buf);
    close(fd);

    return 0;
}

