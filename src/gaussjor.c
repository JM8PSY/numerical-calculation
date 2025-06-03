/***********************************************************
    gaussjor.c -- Gauss (ガウス)--Jordan (ジョルダン) 法
***********************************************************/
#include "matutil.c"

void gaussjordan(int n, matrix a)
{
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (j = k + 1; j <= n; j++) a[k][j] /= a[k][k];
        for (i = 0; i < n; i++)
            if (i != k)
                for (j = k + 1; j <= n; j++)
                    a[i][j] -= a[i][k] * a[k][j];
    }
}

#include <limits.h>

double rnd(void)  /* 乱数  0 < rnd() < 1 */
{
    static unsigned long seed = 123456789UL;  /* 奇数 */

    return (seed *= 69069UL) / (ULONG_MAX + 1.0);
}

int main(void)
{
   int i, j, n;
   matrix a;
    printf("n = "); scanf("%d", &n);
    a = new_matrix(n, n + 1);
    for (i = 0; i < n; i++){
    for (j = 0; j <= n; j++){
        scanf("%lf",&a[i][j]); }
    }
    printf("係数行列 (右辺も含む)\n"); matprint(a, n + 1, 10, "%7.3f"); gaussjordan(n, a);
    printf("答え\n");
    for(i=0;i<n;++i) printf("%lf\n",a[i][n]);
    return 0; 
}

