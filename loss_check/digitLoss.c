//
//�@2���������̉��̌���
//�@x1=(-b+sqrt(b*b-4*a*c))/(2*a),�@x2=(-b-sqrt(b*b-4*a*c))/(2*a)
//
//  b��sqrt(b*b-4*a*c)���߂��l�ɂȂ����Ƃ��A�l���������Ȃ蕂�������_��
//���X�����Ă��鐸�x����A�덷���N����B�|���������@
//�L�������Ƃ����ϓ_����������\�B
//
// ���͈����Z�Ȃ̂ŁA����𖳂����悤�Ɏ���ό`����B
//
// x1�̎��̕��q�����(-b-sqrt(b*b-4*a*c))�������āA���𐮗�����ƁA
// x1n= (-2*c)/(b+sqrt(b*b-4*a*c))�ɂȂ�B
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	float a, b, c, x1, x2,x1n;
/*	a = 1e-8;
	b = 1e+8;
	c = 1e-8;*/
	a =  1.00000;
	b = -333.333;
	c =  1.23456;

	printf(" %ex^2+%ex+%e\n",a,b,c);
	x1  = ( -b + sqrt( b * b - 4 * a * c ) ) /( 2 * a );
	x1n = -2 * c / ( b + sqrt( b * b - 4 * a * c ) );
	x2  =  ( -b - sqrt( b * b - 4 * a * c ) ) /( 2 * a );

	printf("\tx1\t=\t%15e\n",x1);
	printf("\tx1n\t=\t%15e\n",x1n);
	printf("\tx2\t=\t%15e\n",x2);




}

/*
 1.000000e+00x^2+-3.333330e+02x+1.234560e+00
        x1      =          3.333293e+02
        x1n     =          3.331450e+02
        x2      =          3.705774e-03
*/
