
/*
	float,double,long double�́A�R���s���[�^�łǂ̂悤�ɕ\������Ă��邩�H
	�r�b�g�\����\�����Ċm���߂Ă݂�B

*/


#include <stdio.h>
#include <math.h>

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


/*
  int count = 0;
  int s = 8;
  int s2 = 12;

  if(T==16){
    s = 10;
    s2 = 16;
  }else if(T == 4){
    s = 4;
    s2 = 9;
  }
  for(int i=0;i<s;i++){
    for(int j=0;j<8;j++){
      if(x[s-i-1] & (1<<(7-j)))printf("1");
      else printf("0");
      count++;
      if(count==1 || count==s2)printf(" ");
    }
  }
  printf("\n");
*/
}

int main(void){

  float		a=1.125F;
  double 	b= 1.125;
  long double 	c=1.125L;
  _Float128 	d=1.125; 

  bitdump((char*)&a,sizeof(a));
  bitdump((char*)&b,sizeof(b));
  bitdump((char*)&c,/*sizeof(c)*/10);
  bitdump((char*)&d,sizeof(d));

}
