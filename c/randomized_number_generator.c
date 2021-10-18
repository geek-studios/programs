#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t stop;

void inthand(int signum) {
    stop = 1;
}

int main(int argc, char **argv) {

    signal(SIGINT, inthand);

    while (!stop)
	{
          srand(time(0) % rand());
   	      printf("%d\n", rand());
   	      fflush(stdout);
   	      sleep(1);
	}

    printf("exiting safely\n");
    exit(EXIT_SUCCESS);

   return(0);
}
