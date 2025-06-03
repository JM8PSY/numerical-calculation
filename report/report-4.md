<div style="text-align: center">
  <h2>数値計算 ガウスジョルダン法レポート</h2>
</div><br>
<div style="text-align: right;">
  辻本純平<br>システム制御情報工学科3年
</div><br><br>

<!--
 課題の指示文：「ガウスジョルダン法を用いてプログラムにて計算を行う．」
-->

### 1. 使用したプログラム
```
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
```
\

ガウスジョルダン法を用いたC言語プログラムになる．
### 2. 計算結果
- Q1
```
vscode ➜ /workspaces/numerical-calculation/src (main) $ ./gaussjor
n = 2
2 3 19
5 -3 -26
係数行列 (右辺も含む)
  2.000  3.000 19.000
  5.000 -3.000-26.000
答え
-1.000000
7.000000
```

- Q2
```
vscode ➜ /workspaces/numerical-calculation/src (main) $ ./gaussjor
n = 2
4 7 -2
4 -2 16
係数行列 (右辺も含む)
  4.000  7.000 -2.000
  4.000 -2.000 16.000
答え
3.000000
-2.000000
```

- Q3
```
vscode ➜ /workspaces/numerical-calculation/src (main) $ ./gaussjor
n = 2
15 -2 0
7 -1 -1
係数行列 (右辺も含む)
 15.000 -2.000  0.000
  7.000 -1.000 -1.000
答え
2.000000
15.000000
```

- Q4
```
vscode ➜ /workspaces/numerical-calculation/src (main) $ ./gaussjor
n = 3
1 1 1 9
2 3 -2 5
3 -1 1 7
係数行列 (右辺も含む)
  1.000  1.000  1.000  9.000
  2.000  3.000 -2.000  5.000
  3.000 -1.000  1.000  7.000
答え
2.000000
3.000000
4.000000
```
- Q5
```
n) $ ./gaussjor
n = 3
1 1 -1 -6
2 4 3 9
5 3 1 4
係数行列 (右辺も含む)
  1.000  1.000 -1.000 -6.000
  2.000  4.000  3.000  9.000
  5.000  3.000  1.000  4.000
答え
1.000000
-2.000000
5.000000
```
- Q6
```
vscode ➜ /workspaces/numerical-calculation/src (main) $ ./gaussjor
n = 4       
1 1 1 1 5
3 2 1 0 0
27 9 3 1 1
27 6 1 0 0
係数行列 (右辺も含む)
  1.000  1.000  1.000  1.000  5.000
  3.000  2.000  1.000  0.000  0.000
 27.000  9.000  3.000  1.000  1.000
 27.000  6.000  1.000  0.000  0.000
答え
1.000000
-6.000000
9.000000
1.000000
```

##### 参考文献
Refs

<style>
  .page-break {
    page-break-before: always;
  }
</style>
