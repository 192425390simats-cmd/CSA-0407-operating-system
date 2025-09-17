#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buf[50];
    struct stat st;

    fd = open("sample.txt", O_CREAT | O_RDWR, 0777);
    write(fd, "UNIX IO demo\n", 13);

    lseek(fd, 0, SEEK_SET);
    read(fd, buf, sizeof(buf));
    printf("File content:\n%s", buf);

    fstat(fd, &st);
    printf("File size: %ld bytes\n", st.st_size);
    close(fd);

    DIR *d = opendir(".");
    struct dirent *dir;
    printf("Files in current directory:\n");
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }
    closedir(d);

    return 0;
}

