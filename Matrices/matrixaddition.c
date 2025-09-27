
#include <stdio.h>

int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c], B[r][c], sum[r][c];

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            sum[i][j] = A[i][j] + B[i][j];

    printf("Matrix Addition Result:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}
