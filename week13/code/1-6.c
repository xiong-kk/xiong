#include "test.h"

void usage()
{
	fprintf(stderr,"sigqueue_send sig pid[times].\n");
}

int main(int argc,char**argv)
{
	pid_t pid;
	int sig;
	union sigval mysigval;
	int times=0;
	if(argc<3)
	{
		usage();
		return -1;
	}
	pid=atoi(argv[1]);
	sig=atoi(argv[2]);
	if(argc>=4)
	{
		times=atoi(argv[3]);
	}
	mysigval.sival_int=123;
	if(sig<0||sig>664||times<0)
	{
		usage();
		return -1;
	}
	int i=0;
	for(;i<times;i++){
		if(sigqueue(pid,sig,mysigval)!=0)
		{
			fprintf(stderr,"%s:sigqueue failed!\n",strerror(errno));
			return -3;
		}
	}
}
