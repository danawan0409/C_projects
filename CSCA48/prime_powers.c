#include<stdlib.h>
#include<stdio.h>

double power(double x, int p){
	int i;
	double powered = x;
	for (i=1; i<p; i=i+1){
		powered = powered * x;
	}
	return powered;
}

int main(){
	int i,j;
	double powered;
	
	for (i=2; i<=100; i=i+1){
		int k = 1;
		for (j=2; j<=i-1; j=j+1){
			if(k>(i%j)){
				k = i%j;
			}
		}
		if(k!= 0){
			powered = power(1.4142, i);
			printf("%d, 1.4142^%d = %.6f\n", i, i, powered);
		}
	}
	return 0;
}