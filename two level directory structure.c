#include <stdio.h>
#include <string.h>

char dir[10][20], file[10][10][20];
int fcount[10], dcount=0;

int main() {
    int ch,i,j; char d[20], f[20];
    while(1){
        printf("\n1.Create Dir 2.Create File 3.Delete File 4.List 5.Exit: ");
        scanf("%d",&ch);
        if(ch==1){ scanf("%s",dir[dcount]); fcount[dcount++]=0; }
        else if(ch==2){ scanf("%s %s",d,f); for(i=0;i<dcount;i++) if(strcmp(dir[i],d)==0) strcpy(file[i][fcount[i]++],f);}
        else if(ch==3){ scanf("%s %s",d,f); for(i=0;i<dcount;i++) if(strcmp(dir[i],d)==0) for(j=0;j<fcount[i];j++) if(strcmp(file[i][j],f)==0){ fcount[i]--; strcpy(file[i][j],file[i][fcount[i]]); } }
        else if(ch==4){ for(i=0;i<dcount;i++){ printf("%s:\n",dir[i]); for(j=0;j<fcount[i];j++) printf("  %s\n",file[i][j]); } }
        else break;
    }
    return 0;
}

