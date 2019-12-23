#include "lib.h"
#include <dlfcn.h>
int main()
{
	int a[5]={0,1,2,3,4};
	void (*f1)(),(*f4)();
	int (*f2)(),(*f3)();
	void *handle;
	handle=dlopen("//home/zl/文档/linuxprogram/week6/code/dyamiclib/libdytest.so",RTLD_LAZY);
	if(!handle){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	
	}
	f1=dlsym(handle,"urand");
	if(dlerror()!=NULL){
	
	fprintf(stderr,"%s\n",dlerror());
	exit(1);

	}
	f2=dlsym(handle,"max");
	if(dlerror()!=NULL){
	
	fprintf(stderr,"%s\n",dlerror());
	exit(1);

	}
	f3=dlsym(handle,"sum");
	if(dlerror()!=NULL){
	
	fprintf(stderr,"%s\n",dlerror());
	exit(1);

	}
	f4=dlsym(handle,"show");
	if(dlerror()!=NULL){
	
	fprintf(stderr,"%s\n",dlerror());
	exit(1);

	}
	f1(a,5);
	f4(a,5);
	printf("max=%d\n",f2(a,5));
	printf("sum=%d\n",f3(a,5));
	if(dlclose(handle)<0){

	fprintf(stderr,"%s\n",dlerror());
	exit(1);

	}
	return 0;
}
