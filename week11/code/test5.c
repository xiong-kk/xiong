#include "test.h"
int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("创建管道失败！\n");
		return -1;
	}
	result=fork();
	if(result<0)
	{
		perror("fork error!\n");
		exit(1);	
	}else if(result==0)
	{
		close(pipe_fd[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
			printf("child process read %d character,read string is %s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}else{

	close(pipe_fd[0]);
	if(write(pipe_fd[1],"第一串文字",10)!=-1)
		printf("parent process write \"第一串文字\"！\n");
	if(write(pipe_fd[1],"第二串文字",10)!=-1)
		printf("parent process write \"第二串文字\"！\n");
	close(pipe_fd[1]);
	waitpid(result,NULL,0);
	exit(0);
}
}
