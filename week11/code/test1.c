#include "test.h"

int main()
{
	pid_t pid;
	int k,status;
	pid=fork();
	if(pid<0)
	{
		perror("fork error!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child %d : running!!\n",getpid());
		exit(120);
	}else
	{
		if((k=wait(&status))!=0)
		{
			if(WIFEXITED(status))
			printf("child exit with exit!\nexit code=%d\nsignal number=%d\n",WEXITSTATUS(status),k);
		}else if(WIFSIGNALED(status))
			printf("child terminatated with signal\nsignal number=%d\n",WTERMSIG(status));
		exit(0);
	}

	return 0;
}
