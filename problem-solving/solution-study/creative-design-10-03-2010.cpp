// 창의설계1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdafx.h>

long int cost(long int y, long int z)
{
	long int t;

	if(y > z) {
		t=z;
		z=y;
		y=t;
	}

	if(y==1)
		switch(z-1) {
		case 0 :
		case 1 : return 22020;
			break;
		case 2 : return 34650;
			break;
		case 3 : return 20640;
			break;
		case 4 : return 18350;
			break;
		case 5 : return 17550;
			break;
		case 6 : return 10500;
			break;
		case 7 : return 18000;
			break;
		case 8 : return 8700;
			break;
	}
	else if(y==2)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 : return 32770;
			break;
		case 3 : return 13050;
			break;
		case 4 : return 18500;
			break;
		case 5 : return 10300;
			break;
		case 6 : return 18500;
			break;
		case 7 : return 43350;
			break;
		case 8 : return 23950;
			break;
	}
	else if(y==3)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 : return 34750;
			break;
		case 4 : return 39650;
			break;
		case 5 : return 34250;
			break;
		case 6 : return 26300;
			break;
		case 7 : return 54850;
			break;
		case 8 : return 44750;
			break;
	}
	else if(y==4)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 :
		case 4 : return 14800;
			break;
		case 5 : return 27400;
			break;
		case 6 : return 15200;
			break;
		case 7 : return 46600;
			break;
		case 8 : return 30400;
			break;
	}
	else if(y==5)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 : return 15100;
			break;
		case 6 : return 17200;
			break;
		case 7 : return 40600;
			break;
		case 8 : return 22500;
			break;
	}
	else if(y==6)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
		case 6 : return 13900;
			break;
		case 7 : return 37900;
			break;
		case 8 : return 19200;
			break;
	}
	else if(y==7)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
		case 6 : 
		case 7 : return 31400;
			break;
		case 8 : return 11900;
			break;
	}
	else if(y==8)
		switch(z-1) {
		case 0 :
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
		case 6 :
		case 7 :
		case 8 : return 36700;
			break;
	}
};

void main()
{
long int temp,result,final,a,b,c,d,e,f,g,h,i,j,x;

	temp = 0;
	result = 0;

	for(x=23456789;x<=99999999;x++) {


A:

	a = 1;
	b = x/10000000;
	c = x/1000000 - 10*b;
	d = x/100000 - (100*b + 10*c);
	e = x/10000 - (1000*b + 100*c + 10*d);
	f = x/1000 - (10000*b + 1000*c + 100*d + 10*e);
	g = x/100 - (100000*b + 10000*c + 1000*d + 100*e + 10*f);
	h = x/10 - (1000000*b + 100000*c + 10000*d + 1000*e + 100*f + 10*g);
	i = x - (10000000*b + 1000000*c + 100000*d + 10000*e + 1000*f + 100*g + 10*h);
	j = 1;

	while(b==0 || c==0 || d==0 || e==0 || f==0 || g==0 || h==0 ||
		i==0 || b==1 || c==1 || d==1 || e==1 || f==1 || g==1 || h==1 || i==1) {
		x++;
		goto A;
	}

	if( b != c && b != d && b != e && b != f && b != g && b != h && b != i &&
		c != d && c != e && c != f && c != g && c != h && c != i &&
		d != e && d != f && d != g && d != h && d != i &&
		e != f && e != g &&	e != h && e != i &&
		f != g && f != h && f != i &&
		g != h && g != i &&
		h != i) {
			temp = cost(a,b) + cost(b,c) + cost(c,d) + cost(d,e) + cost(e,f) + cost(f,g) + cost(g,h) + cost(h,i) + cost(i,j);

			if(result == 0) {
			result = temp;
			final = x;
			} else if(temp < result) {
			result = temp;
			final = x;
			}
		}
	}

	printf("%ld \n",final);
	printf("%ld",result);
}