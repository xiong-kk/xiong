#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g=88;
int main()
{

	int v=99;
	static int a=20;
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
		a=300;
		printf("child:pid=%d,g=%d,v=%d,%d\n",getpid(),g,v,a);
		printf("&g=%p,&v=%p,&a=%p",&g,&v,&a);
		while(g!=500)
			printf("wait for parent\n");
		//return 0;
		//exit(0);
		_exit(0);
	}
	else
	{
		g=500;
		printf("return value=%d\n",pid);
		printf("parent:pid=%d,g=%d,v=%d\n",getpid(),g,v);
		printf("&g=%p,&v=%p,&a=%p",&g,&v,&a);
		return 0;
		//exit(0);
		//_exit(0);
		
	}
	return 0;
}
