#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <wait.h>
#include <string.h>
int main()
{
	pid_t p;
	int a;
	int fd[2];
	char w_buf[50];
	char r_buf[50];
	//memset(w_buf,0,sizeof(w_buf));
	memset(r_buf,0,sizeof(r_buf));
	
	if(pipe(fd)<0)
	{
		perror("pipe error!\n");
		exit(1);
	}
	p=fork();
	if(p<0)
	{
		perror("fork error!\n");
		exit(1);
	}else if(p==0){
		close(fd[0]);
		printf("child pid=%d\n",getpid());
		sprintf(w_buf,"child is running,pid=%d",getpid());
		if((a=write(fd[1],w_buf,sizeof(w_buf)))<0)
		{
			perror("write failed\n");
			exit(2);

		}
		printf("child write to pipe %d byte\n",a);
		close(fd[1]);
		exit(0);
	}else
	{
		close(fd[1]);
		wait(NULL);
		if((a=read(fd[0],r_buf,sizeof(r_buf)))<0)
		{
			perror("write failed\n");
			exit(2);

		}
		printf("parent read from pipe total=%d byte,content %s\n",a,r_buf);
		close(fd[0]);
		return 0;
	}
	
}
