// square_check.c
#include <stdio.h>
int main(){
    int r,c; 
    printf("Rows and Cols: "); scanf("%d%d",&r,&c);
    if(r==c) printf("Square matrix\n");
    else printf("Not a square matrix\n");
    return 0;
}
