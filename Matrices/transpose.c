#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns of Matrix: ");
    scanf("%d %d", &r, &c);

    int A[r][c], transpose[c][r];

    printf("Enter elements of Matrix:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            transpose[j][i] = A[i][j];

    printf("Transpose of the Matrix:\n");
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    return 0;
}
 