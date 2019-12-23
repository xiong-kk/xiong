#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int ret;
	printf("cller1:pid=%d,ppid=%d\n",getpid(),getppid());
	execlp("test02","./test02","123","456",NULL);
	printf("after calling\n");
	sleep(1);
	return 0;
}
