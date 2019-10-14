#include"f.h"
int max(int *a,int n)
{
   int max=a[0];
   for(int i=0;i<n;i++)
   {
        if(max<a[i])
        {
            max=a[i];
        }

   }
   return max;
}
int sum(int *a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=a[i];
    }
    return sum;
   
}
void urand(int *a,int n)
{

    int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));




}
