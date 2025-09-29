// triangular_check.c
#include <stdio.h>
int main()
{
    int n, m;
    printf("Rows and Cols: ");
    scanf("%d%d", &n, &m);
    int a[n][m];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    if (n != m)
    {
        printf("Not triangular (not square)\n");
        return 0;
    }

    int isUpper = 1, isLower = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && a[i][j] != 0)
                isLower = 0; // below diagonal should be 0 for upper
            if (i < j && a[i][j] != 0)
                isUpper = 0; // above diagonal should be 0 for lower
        }
    }
    if (isUpper && !isLower)
        printf("Upper triangular\n");
    else if (isLower && !isUpper)
        printf("Lower triangular\n");
    else if (isUpper && isLower)
        printf("Diagonal (both upper and lower)\n");
    else
        printf("Neither upper nor lower triangular\n");
    return 0;
}
