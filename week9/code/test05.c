#include"my.h"
int g=1;

int main(void){
	int local=1;
	int *m=malloc(sizeof(int));
	*m=1;
	pid_t pid=fork();
	if(pid<0){
		printf("fork failed (%s)",strerror(errno));
		return 1;
	}
	else if(pid==0){
		local==999;
		*m=999;
		g=999;
		fprintf(stderr,"[child] child change local global malloc value to 999\n");
		free(m);
		sleep(10);
		fprintf(stderr,"[child] exit!\n");
	}
	else{
		fprintf(stderr,"[parent] parent waiting child exit!\n");
		waitpid(pid,NULL,0);	
fprintf(stderr,"[parent] child have exit!\n");
fprintf(stderr,"[parent] g=%d\n",g);
fprintf(stderr,"[parent] local=%d\n",local);
fprintf(stderr,"[parent] m=%d\n",*m);
	}
}
