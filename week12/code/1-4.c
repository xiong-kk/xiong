#include "test.h"

#define MSG "OMG,I catch the signal SIGINT\n"
#define MSG_END "OK,finished process signal SIGINT\n"

int do_heavy_work()
{
	int i;
	int k;
	srand(time(0));
	for(i=0;i<1000000;i++)
	k=rand()%123456;
	return 0;
}
void signal_handler(int signal)
{
	write(2,MSG,strlen(MSG));
	do_heavy_work();
	write(2,MSG_END,strlen(MSG_END));

}

int main()
{
	char input[1024]={0};
	if(signal(SIGINT,signal_handler)==SIG_ERR)
	{
		printf("signal failed\n");
		return 1;
	}
	puts("input a string:");
	if(fgets(input,sizeof(input),stdin)==NULL)
	{
		perror("fgets error!\n");
		return 2;
		
	}else{
		printf("you entered:%s",input);

	}
	return 0;
}
