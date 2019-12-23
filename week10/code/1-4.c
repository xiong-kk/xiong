#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g=10;
int a[10]={0};
int main()
{

	static int k=20;
	printf("test:pid=%d,&k=%16p,&g=%16p,&a=%16p\n",getpid(),&k,&g,&a);
	for(int i=0;i<10;i++)
		printf("test:g=%d,k=%d\n",g++,k++);
	return 0;
}
