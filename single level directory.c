#include <stdio.h>
#include <string.h>

int main() {
    char files[10][20];
    int n=0, ch, i;
    char name[20];

    while(1) {
        printf("\n1.Create 2.Delete 3.List 4.Exit: ");
        scanf("%d",&ch);

        if(ch==1) {   // create
            scanf("%s",files[n]);
            n++;
        }
        else if(ch==2) {  // delete
            scanf("%s",name);
            for(i=0;i<n;i++)
                if(strcmp(files[i],name)==0) {
                    n--;
                    strcpy(files[i],files[n]);
                }
        }
        else if(ch==3) {  // list
            for(i=0;i<n;i++) printf("%s\n",files[i]);
        }
        else break;
    }
    return 0;
}

