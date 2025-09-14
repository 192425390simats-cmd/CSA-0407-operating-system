#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char message[100], buffer[100];

    // Simulating Parent process writing
    fp = fopen("ipc.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter a message to send: ");
    gets(message);   // take input
    fputs(message, fp);
    fclose(fp);

    // Simulating Child process reading
    fp = fopen("ipc.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    printf("Child received: %s\n", buffer);

    return 0;
}

