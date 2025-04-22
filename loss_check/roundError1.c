//
// �ۂߌ덷
// 0.6��3���|�������̂ƁA1.8���r����B���̂��������Ȃ��B
// �r�b�g���`�F�b�N���Ă݂悤�I�I
//

#include <stdio.h>

void bitdump(char *x, int T){
  int count = 0;

  // �S�Ẵo�C�g�ɂ������ăr�b�g���`�F�b�N
  for(int i=0;i<T;i++){
    // 1�o�C�g���ƂɃr�b�g���`�F�b�N
    for(int j=0;j<8;j++){

      // ��ʃr�b�g���珇�ɂP���O���`�F�b�N���\��
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

/*���s����
b= 1.800000e+00          a=6.000000e-01
different
0011111111111100110011001100110011001100110011001100110011001100(64 bit)
0011111111111100110011001100110011001100110011001100110011001101(64 bit)
*/
