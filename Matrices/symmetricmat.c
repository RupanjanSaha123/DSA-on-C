// symmetric_matrix.c
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
        printf("Not symmetric (not square)\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                printf("Not symmetric\n");
                return 0;
            }
        }
    }
    printf("Symmetric\n");
    return 0;
}
