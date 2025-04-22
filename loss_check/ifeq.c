//
// �������̊m�F
// �������l�ł���Ƃ����������m�F���Ă݂�B
//
//�����Ŏw�肳���J��Ԃ��񐔂����A�P���R�Ŋ������̂��A
//�����񐔂R�������āA1�Ƃ̌덷��\������B
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	double a,b ;
	int i,LOOP=atoi(argv[1]);

	a=b=1.0;

	for( i=0 ; i < LOOP ; ++i ) b /= 3.0 ;
printf(" b=%e \n", b);
	for( i=0 ; i < LOOP ; ++i ) b *= 3.0;

	if( a == b) printf("OK\t a= %e b=%e a-b=%e\n", a,b,a-b );
	else printf("NO\t a= %e b=%e a-b=%e\n", a,b,a-b );

}

/*
$gcc ifeq.c -o ifeq
$ ./ifeq 9
 b=5.080526e-05
OK       a= 1.000000e+00 b=1.000000e+00 a-b=0.000000e+00
$ ./ifeq 10
 b=1.693509e-05
NO       a= 1.000000e+00 b=1.000000e+00 a-b=-2.220446e-16
*/

