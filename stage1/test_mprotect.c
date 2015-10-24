#include "types.h"
#include "user.h"

int *p;

void handler(int signum, siginfo_t info)
{
	printf(1,"Handler called, error address is 0x%x\n", info.addr);
        //printf(1,"Handler called, type is %d\n", info.type);   //Shradha
        //printf(1,"Handler called, signum is %d\n", signum);   //Shradha
	if(info.type == PROT_READ)
	{
		printf(1,"ERROR: Writing to a page with insufficient permission.\n");
		mprotect((void *) info.addr, sizeof(int), PROT_READ | PROT_WRITE);
                //printf(1,"Back to handler \n");
	}
	else
	{
		printf(1, "ERROR: Didn't get proper exception, this should not happen.\n");
		exit();
	}
        //printf(1,"Quiting from Handler to Restorer to Main\n");
} 
int main(void)
{
        int status = 0;

	signal(SIGSEGV, handler);  
 	p = (int *) malloc(sizeof(int));
        status  = mprotect((void *)p, sizeof(int), PROT_READ);
 	*p=100;
 	printf(1, "COMPLETED: value is %d, expecting 100!\n", *p);
 	
 	exit();
}
