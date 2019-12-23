#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	pid_t pid;
	int s;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}else if(pid==0){
	printf("child is running!\n");
	_exit(12);

	}else{

	//wait(NULL);
	wait(&s);
	printf("parent is running exit code=%d\n",WEXITSTATUS(s));
	return 0;
	}

}
