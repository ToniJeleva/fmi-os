#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
        int fd1;
        int status;
        if ( (fd1 = open(argv[1], O_CREAT | O_RDWR,0777)) == -1 ){
                        exit(1);
                }

	if (fork() > 0) {
         wait(&status);
         printf("father\n");
         fd1=open(argv[1],O_RDWR|O_APPEND);
              write(fd1,"foo",3); 
		close(fd1);
	} else {
		        fd1=open(argv[1],O_RDWR|O_APPEND);
			printf("son\n");
                        write(fd1,"bar",3);
                        close(fd1);	
	}
close(fd1);
exit(0);
}
