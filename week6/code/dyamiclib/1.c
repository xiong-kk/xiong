#include "lib.h"

int max(int *a,int n)
{
	int max=0,i=0;
	for(;i<n;i++){
		if(max<a[i])
			max=a[i];	
	}
	return max;
}

void show(int *a,int n)
{
	int i;
	printf("\n*******************\n");
	for (i=0;i<n;i++)
		printf("a[%d]=%d\t",i,a[i]);
	printf("\n*******************\n");
}
