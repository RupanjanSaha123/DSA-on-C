// triplet_sparse.c
#include <stdio.h>

int main(){
    int r,c; 
    printf("Rows and Cols: "); scanf("%d%d",&r,&c);
    int A[r][c];
    printf("Enter elements:\n");
    int nz=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0) nz++;
        }

    int T[nz+1][3]; // triplet form
    T[0][0]=r; T[0][1]=c; T[0][2]=nz;
    int k=1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(A[i][j]!=0){
                T[k][0]=i;
                T[k][1]=j;
                T[k][2]=A[i][j];
                k++;
            }

    printf("Triplet representation (row col val):\n");
    for(int i=0;i<nz+1;i++)
        printf("%d %d %d\n", T[i][0], T[i][1], T[i][2]);

    return 0;
}
