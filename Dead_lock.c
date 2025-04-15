#include <stdio.h>
#define A 10
int main(){
    int p,r,alloc[A][A],need[A][A],max[A][A],avail[A],work[A],finish[A]={0},safeseq[A],count=0;
    printf("Enter no.of processes and resources:");
    scanf("%d%d",&p,&r);
    printf("Enter Allocated resources:\n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter Max Resources :\n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    printf("Available Resources:");
    for(int i=0;i<r;i++)
        scanf("%d",&avail[i]);
    for(int i=0;i<r;i++)
        work[i]=avail[i];
    while(count<p){
        int found=0;
        for(int i=0;i<p;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<r;j++)
                    if(need[i][j]>work[j])
                        break;
                    if(j==r){
                    for(int k=0;k<r;k++)
                        work[k]+=alloc[i][k];
                    safeseq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found){
            printf("Unsafe sequence occured\n");
            return 0;
        }
    }
    printf("safe sequence :");
    for(int i=0;i<p;i++)
        printf("P%d ",safeseq[i]);
    return 0;    
}