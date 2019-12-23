#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g=88;
int main()
{

	int v=99;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(0);
	}
	else if(pid==0)
	{

		g++;
		v++;
		printf("child:pid=%d,g=%d,v=%d\n",getpid(),g,v);
		printf("child:pid=%d,&g=%p,&v=%p\n",getpid(),&g,&v);
		execl("./1-4","1-4",NULL);
		static long h=100;
		printf("parent:pid=%d,g=%d,v=%d\n,&h=%16p",getpid(),g,v,&h);
		//return 0;
		//return 0;
		//exit(0);
		_exit(0);
	}
	else
	{
		printf("return value=%d\n",pid);
		printf("parent:pid=%d,g=%d,v=%d\n",getpid(),g,v);
		printf("parent:pid=%d,&g=%p,&v=%p\n",getpid(),&g,&v);
		//printf("&h=%16p\n",&h);
		//exit(0);
		_exit(0);
		
	}
	return 0;
}
