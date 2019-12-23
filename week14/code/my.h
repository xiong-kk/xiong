#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include "err_exit.h"
#define check_error(return_val,msg){\
if(return_val!=0){\
	fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
	exit(-1);\
}\
}
