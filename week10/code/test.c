#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static void fun1()
{

	printf("invoked callbackfun!\n");
}
int main()
{
	atexit(fun1);
	FILE *fp;
	char buf[]={"buffer data!"};
	if((fp=fopen("test.txt","w+"))==NULL)
	{
		perror("create file failed!\n");
		exit(1);
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("create file failed!\n");
		exit(1);
	}
	printf("hello ");
	//exit(0);
	_exit(0);
}
