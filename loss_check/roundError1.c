//
// 丸め誤差
// 0.6に3を掛けたものと、1.8を比較する。何故か等しくない。
// ビットをチェックしてみよう！！
//

#include <stdio.h>

void bitdump(char *x, int T){
  int count = 0;

  // 全てのバイトにたいしてビットをチェック
  for(int i=0;i<T;i++){
    // 1バイトごとにビットをチェック
    for(int j=0;j<8;j++){

      // 上位ビットから順に１か０をチェックし表示
      if(x[T-i-1] & (1<<(7-j)))printf("1");
      else printf("0");

      count++;
    }
  }
  printf("(%d bit)\n",count);
}

int main ( )
{
   double a = 0.6,c=1.8;
   double b = 3 * a;
  printf( "b= %e \t a=%e\n",b,a) ;
   if ( b == c ) {
      printf("same\n") ;
   } else {
      printf("different\n") ;
   }

  bitdump((char*)&b,sizeof(b));
  bitdump((char*)&c,sizeof(c));

}

/*実行結果
b= 1.800000e+00          a=6.000000e-01
different
0011111111111100110011001100110011001100110011001100110011001100(64 bit)
0011111111111100110011001100110011001100110011001100110011001101(64 bit)
*/
