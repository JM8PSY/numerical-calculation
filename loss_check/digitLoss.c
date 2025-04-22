//
//　2次方程式の解の公式
//　x1=(-b+sqrt(b*b-4*a*c))/(2*a),　x2=(-b-sqrt(b*b-4*a*c))/(2*a)
//
//  bとsqrt(b*b-4*a*c)が近い値になったとき、値が小さくなり浮動小数点の
//元々持っている精度から、誤差が起こる。－＞桁落ち　
//有効数字という観点からも説明可能。
//
// 問題は引き算なので、それを無くすように式を変形する。
//
// x1の式の分子分母に(-b-sqrt(b*b-4*a*c))をかけて、式を整理すると、
// x1n= (-2*c)/(b+sqrt(b*b-4*a*c))になる。
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
