//
// 条件文の確認
// 1.0に正の値を加えると必ずその値より大きくなるはずだが。。。
//
//  引数は、繰り返し回数。回数分２で割っていくが、
// そのたびに、if( 1.0+b <= 1.0 )を評価する。
//  何回目で1.0+bは1.0以下になるか？
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

//	double a,b ;
	float a,b ;
	int i,mm, LOOP=atoi(argv[1]);
	a=b=1.0;

	for( i=0 ; i < LOOP ; ++i, b /= 2.0){
		if( 1.0+b <= 1.0 ){ //1.0+bは、1.0より大きいはずでも・・・
			printf("Emach = %d b=%e 1+b=%e\n",i,b,1.0+b);
		}
	}

}

/*
$gcc emach.c -o emach
$ ./emach 60
Emach = 53 b=1.110223e-16
Emach = 54 b=5.551115e-17
Emach = 55 b=2.775558e-17
Emach = 56 b=1.387779e-17
Emach = 57 b=6.938894e-18
Emach = 58 b=3.469447e-18
Emach = 59 b=1.734723e-18
*/
