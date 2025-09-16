#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, dir, i, j, seek=0, req[20], temp;

    scanf("%d",&n);              // number of requests
    for(i=0;i<n;i++) scanf("%d",&req[i]);
    scanf("%d",&head);           // head
    scanf("%d",&size);           // disk size
    scanf("%d",&dir);            // 0=left, 1=right

    req[n++]=head;
    if(dir==0) req[n++]=0; else req[n++]=size-1;

    for(i=0;i<n-1;i++)           // sort
      for(j=i+1;j<n;j++)
        if(req[i]>req[j]) {temp=req[i];req[i]=req[j];req[j]=temp;}

    for(i=0;i<n;i++) if(req[i]==head) break;

    if(dir==1){                  // right
        for(j=i;j<n-1;j++){seek+=abs(req[j+1]-head);head=req[j+1];}
        for(j=i-1;j>=0;j--){seek+=abs(req[j]-head);head=req[j];}
    } else {                     // left
        for(j=i;j>0;j--){seek+=abs(req[j-1]-head);head=req[j-1];}
        for(j=i+1;j<n;j++){seek+=abs(req[j]-head);head=req[j];}
    }

    printf("%d",seek);
    return 0;
}

