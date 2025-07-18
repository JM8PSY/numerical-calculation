/***********************************************************
    matinv.c -- 逆行列
***********************************************************/
#include "matutil.c"  /* 行列操作用小道具集 */
#include <math.h>

double lu(int n, matrix a, int *ip)  /* LU分解 */
{
    int i, j, k, ii, ik;
    double t, u, det;
    vector weight;

    weight = new_vector(n);    /* weight[0..n-1] の記憶領域確保 */
    det = 0;                   /* 行列式 */
    for (k = 0; k < n; k++) {  /* 各行について */
        ip[k] = k;             /* 行交換情報の初期値 */
        u = 0;                 /* その行の絶対値最大の要素を求める */
        for (j = 0; j < n; j++) {
            t = fabs(a[k][j]);  if (t > u) u = t;
        }
        if (u == 0) goto EXIT; /* 0 なら行列はLU分解できない */
        weight[k] = 1 / u;     /* 最大絶対値の逆数 */
    }
    det = 1;                   /* 行列式の初期値 */
    for (k = 0; k < n; k++) {  /* 各行について */
        u = -1;
        for (i = k; i < n; i++) {  /* より下の各行について */
            ii = ip[i];            /* 重み×絶対値 が最大の行を見つける */
            t = fabs(a[ii][k]) * weight[ii];
            if (t > u) {  u = t;  j = i;  }
        }
        ik = ip[j];
        if (j != k) {
            ip[j] = ip[k];  ip[k] = ik;  /* 行番号を交換 */
            det = -det;  /* 行を交換すれば行列式の符号が変わる */
        }
        u = a[ik][k];  det *= u;  /* 対角成分 */
        if (u == 0) goto EXIT;    /* 0 なら行列はLU分解できない */
        for (i = k + 1; i < n; i++) {  /* Gauss消去法 */
            ii = ip[i];
            t = (a[ii][k] /= u);
            for (j = k + 1; j < n; j++)
                a[ii][j] -= t * a[ik][j];
        }
    }
EXIT:
    free_vector(weight);  /* 記憶領域を解放 */
    return det;           /* 戻り値は行列式 */
}

double matinv(int n, matrix a, matrix a_inv)
{
    int i, j, k, ii;
    double t, det;
    int *ip;   /* 行交換の情報 */

    ip = malloc(sizeof(int) * n);
    if (ip == NULL) error("記憶領域不足");
    det = lu(n, a, ip);
    if (det != 0)
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                ii = ip[i];  t = (ii == k);
                for (j = 0; j < i; j++)
                    t -= a[ii][j] * a_inv[j][k];
                a_inv[i][k] = t;
            }
            for (i = n - 1; i >= 0; i--) {
                t = a_inv[i][k];  ii = ip[i];
                for (j = i + 1; j < n; j++)
                    t -= a[ii][j] * a_inv[j][k];
                a_inv[i][k] = t / a[ii][i];
            }
        }
    free(ip);
    return det;
}

/************* 以下はテスト用 ****************/

#include <limits.h>

double rnd(void)  /* 乱数  0 < rnd() < 1 */
{
    static unsigned long seed = 123456789UL;  /* 奇数 */

    return (seed *= 69069UL) / (ULONG_MAX + 1.0);
}

int main(void)
{
int i, j, n;
    matrix a, gyaku, teisu, x, b_check; // 変数を宣言

    printf("行列の次元 n = ");
    scanf("%d", &n);

    printf("係数行列 A (n x n) を入力してください:\n");
    a = new_matrix(n, n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    // 定数行列は「n行1列」の列ベクトルとして扱うのが一般的です
    printf("定数行列 b (n x 1) を入力してください:\n");
    teisu = new_matrix(n, 1);
    for (i = 0; i < n; i++) {
        printf("b[%d][0] = ", i);
        scanf("%lf", &teisu[i][0]);
    }

    // --- 逆行列の計算 ---
    gyaku = new_matrix(n, n);
    double det = matinv(n, a, gyaku);
    if (det == 0) {
        printf("行列は逆行列を持ちません。\n");
        return 1;
    }
    printf("\n--- 計算結果 ---\n");
    printf("係数行列 A:\n");
    matprint(a, n, n, "%8.3f");
    printf("逆行列 A^{-1}:\n");
    matprint(gyaku, n, n, "%8.3f");
    printf("定数行列 b:\n");
    matprint(teisu, n, 1, "%8.3f");


    // --- 解 x = A^{-1} * b の計算 ---
    x = new_matrix(n, 1);
    multiply(n, n, 1, gyaku, teisu, x);
    printf("解 x = A^{-1} * b:\n");
    matprint(x, n, 1, "%8.3f");
    
    // 検算結果を格納する行列を確保
    b_check = new_matrix(n, 1);

    // 係数行列 a と 解 x の積を計算
    multiply(n, n, 1, a, x, b_check);

    /* --- メモリ解放 --- */
    free_matrix(a);
    free_matrix(gyaku);
    free_matrix(teisu);
    free_matrix(x);
    free_matrix(b_check);

    return 0;
}

