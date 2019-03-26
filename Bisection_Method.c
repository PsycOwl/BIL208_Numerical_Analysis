#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double func(double x){
		return (x * x - 5);		
}

int main(int argc, char *argv[]) {
	double min = 2, max = 3, mid, f_mid, f_min, f_max;
	int i = 0;
	mid = (min + max) / 2;
	f_mid = func(mid);
	
	
	
	printf("i = %d | min = %f | max = %f | mid = %f | f_min = %f | f_max = %f | f_mid = %f | € = -\n", i, min,max,mid,func(min),func(max), f_mid);
	for (i = 1; i < 100; i++) {
		
		
		if (func(min) * func(mid) < 0) max = mid;
		else if (func(min) * func(mid) > 0) min = mid;
		
		float acc = fabs(((min + max)/2 - mid)/(min + max)/2*100);
		mid = (min + max) / 2;
		f_mid = func(mid);
		
		printf("i = %d | min = %f | max = %f | mid = %f | f_min = %f | f_max = %f | f_mid = %f | € = %f\n", i, min,max,mid,func(min),func(max), f_mid, acc);
		if(acc < 0.01) break;
		
	}
}

