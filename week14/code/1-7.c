#include "my.h"
#define NUM 8
char *messages[NUM];
struct thread_data{
	int thread_id;
	int sum;
	char *message;
};
struct thread_data thread_data_array[NUM];
void *PrintHello(void *arg){
	int taskid,sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data=(struct thread_data*)arg;
	taskid=my_data->thread_id;
	sum=my_data->sum;
	hello_msg=my_data->message;
	printf("Thread %d : %s sum=%d\n",taskid,hello_msg,sum);
	pthread_exit(NULL);
	
}
int main(int argc,char**argv)
{
	pthread_t threads[NUM];
	int *taskids[NUM];
	int rc,t,sum;
	sum=0;
	messages[0]="English:helloworld";
	messages[1]="1213";
	messages[2]="haha";
	messages[3]="haa";
	messages[4]="haha25";
	messages[5]="haha2";
	messages[6]="hah2a";
	messages[7]="ha2ha";
	for(t=0;t<NUM;t++){
	sum=sum+t;
	thread_data_array[t].thread_id=t;
	thread_data_array[t].sum=sum;
	thread_data_array[t].message=messages[t];
	printf("create thread %d\n",t);
	rc=pthread_create(&threads[t],NULL,PrintHello,(void*)&thread_data_array[t]);
	if(rc){
		printf("error:return code f is %d\n",rc);
		exit(-1);
	}
	}
	pthread_exit(NULL);
}
