#include "test.h"

void pr_exit(int status,int pid)
{
	int sig;
	if(WIFEXITED(status))
		printf("process %d nomal termination,exit status =%d\n",pid,WEXITSTATUS(status));
	else if(WIFEXITED(status))
	{
		sig=WTERMSIG(status);
		printf("process %d abnomal termination,exit status =%d%s\n",pid,sig,

		#ifdef WCOREDUMP
			WCOREDUMP(status)?"(core file generated)":"");
		#else
			"");
		#endif
		psignal(sig,"");
	}
	else if(WIFSTOPPED(status))
	{
		sig=WSTOPSIG(status);
		printf("process %d stopped,signal number =%d\n",pid,sig);
	}
}

int zero=0;

int main()
{
	int pid,status,r;
	if((pid=fork())==0)
		exit(0);
	if((pid=fork())==0)
		abort();
	if((pid=fork())==0)
	{
		status=status/zero;
		exit(0);
	}
	while((pid=wait(&status))>=0)
		pr_exit(status,pid);
	perror("parent wait over!\n");
	exit(0);
}
