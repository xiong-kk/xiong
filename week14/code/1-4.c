#include "my.h"

#define NUM_THREADS 4

struct info{
	int no;
	int n;

};

struct rval{
	int sum;
	pthread_t tid;
	double time;
};
	
void hello(void *t)
{
	pthread_t my_tid;
	time_t start,end;
	struct info *y;
	struct rval *r;
	start=clock();
	r=(struct rval*)malloc(sizeof(struct rval));
	//int s=0;
	r->sum=0;
	y=(struct info*)(t);
	for(int i=0;i<=y->n;i++)
	{
		//s+=i;
		r->sum+=i;

	}
	
		
	my_tid=pthread_self();
	r->tid=my_tid;
	printf("\tthread %d:my tid is %lx,hello world\n",(int)y->no+1,my_tid);
	printf("sum=%d\n",r->sum);
	//printf("\tThread %d:sum 1 to %d is %d\n",(int)y->no,y->n,s);
	end=clock();
	r->time=end-start;
	pthread_exit(r);
}

int main()
{
	pthread_t tid;
	struct info a[4];
	struct rval *tem;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		struct rval *tem;
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0){
			perror("thread create error!\n");
			return -1;		
		}
		pthread_join(tid,(void **)&tem);
		printf("Create thread %lx\n",tid);
		
		printf("tem[%d].sum=%d,time=%lfms,tid=%lx\n",t,tem->sum,tem->time,tem->tid);
			
		free(tem);
	}
	
	printf("Good bye!\n");
	pthread_exit(NULL);
}
