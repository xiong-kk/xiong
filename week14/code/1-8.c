#include "my.h"
#define SIZE 10
int a[SIZE],b[SIZE];
void* max_fun(int *arg)
{
	int *ap=arg;
	int rv,i,k;
	k=0;
	for(i=1;i<SIZE;i++){
	if(ap[i]>ap[k])
		k=i;
	}
	pthread_exit((void *)&ap[k]);
}
int main()
{
	pthread_t tid1,tid2;
	int i,rv,**ptr1,**ptr2;
	for(i=1;i<SIZE;i++){
	a[i]=rand();
	b[i]=rand();
	}
	rv=pthread_create(&tid1,NULL,max_fun,a);
	check_error(rv,"pthread_create:tid1");
	rv=pthread_create(&tid2,NULL,max_fun,b);
	check_error(rv,"pthread_create:tid2");
	pthread_join(tid1,(void**)&ptr1);
	pthread_join(tid2,(void**)&ptr2);
	printf("thread1:max vlaue is %d\n",*ptr1);
	printf("thread2:max vlaue is %d\n",*ptr2);

}
