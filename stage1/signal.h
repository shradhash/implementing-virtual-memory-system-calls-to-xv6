#ifndef XV6_SIGNAL
#define XV6_SIGNAL

#define SIGKILL	0
#define SIGFPE	1
#define SIGSEGV 2  //Shradha

#define PROT_READ 0    //Shradha
#define PROT_WRITE 1   //Shradha

typedef struct 
{
  uint addr;
  uint type;
}siginfo_t;   //Shradha

typedef void (*sighandler_t)(int, siginfo_t);

#endif
