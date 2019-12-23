#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int ret;
	printf("cller2:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("/home/zl/文档/linuxprogram/week9/code/test02");
	printf("after calling\n");
	sleep(100);
	return 0;
}
