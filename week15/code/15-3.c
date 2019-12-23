#include "my.h"

int a[100],b[100];
int max;

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;

void *max_fun(void *arg){
	int *ap=(int *)arg;
	int rv,i,l_max=ap[0];
	for(i=1;i<100;i++)
		if(ap[i]>l_max)
			l_max=ap[i];
	rv=pthread_mutex_lock(&mtx);
	check_error(rv,"mutex_lock");
	if(l_max>max)
		max=l_max;
	rv=pthread_mutex_unlock(&mtx);
	check_error(rv,"mutex_unlock");
	pthread_exit(NULL);
}
int main()
{
	pthread_t tid1,tid2;
	int i,rv;
	//srand(time(NULL));
	for(i=1;i<100;i++)
	{
		a[i]=rand()%100;
		b[i]=rand()%100;
		printf("a[%d]=%d,b[%d]=%d\n",i,a[i],i,b[i]);

	}
	rv=pthread_create(&tid1,NULL,max_fun,a);
	check_error(rv,"pthread_create tid1");
	rv=pthread_create(&tid2,NULL,max_fun,b);
	check_error(rv,"pthread_create tid2");
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("max value=%d\n",max);
	return 0;
}
