#include"f.h"
int main()
{
    int a[10];
    void *handle;
    void (*f3)();
    int (*f1)(),(*f2)();
    char* error;
    handle =dlopen("/home/rlk/my/week6/code/dyamiclib/libtest.so",RTLD_LAZY);
    if(!handle)
     {
         fprintf(stderr,"%s\n",dlerror());
         exit(1);
     }
    
    f1=dlsym(handle,"max");
    if((error=dlerror())!=NULL)
    {
         fprintf(stderr,"%s\n",dlerror());
         exit(1);
    }
    f2=dlsym(handle,"sum");
    if((error=dlerror())!=NULL)
    {
         fprintf(stderr,"%s\n",dlerror());
         exit(1);
    }
    f3=dlsym(handle,"urand");
    if((error=dlerror())!=NULL)
    {
         fprintf(stderr,"%s\n",dlerror());
         exit(1);
    }
    f3(a,10);
    printf("max is %d\n",f1(a,10));
    printf("sum is %d\n",f2(a,10));
    if(dlclose(handle)<0)
    {
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }

    return 0;
}
