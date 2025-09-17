#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[100];
    char word[] = "UNIX";

    fp = fopen("text.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word)) {
            printf("%s", line);
        }
    }
    fclose(fp);
    return 0;
}

