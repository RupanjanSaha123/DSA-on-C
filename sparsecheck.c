// sparse_check.c
#include <stdio.h>
int main(){
    int r,c, zeros=0, nz=0;
    printf("Rows and Cols: "); scanf("%d%d",&r,&c);
    int x;
    printf("Enter elements:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf("%d",&x);
            if(x==0) zeros++; else nz++;
        }
    int total = r*c;
    if(zeros > total/2) printf("Sparse matrix (zeros=%d, nonzeros=%d)\n", zeros, nz);
    else printf("Not sparse (zeros=%d, nonzeros=%d)\n", zeros, nz);
    return 0;
}
