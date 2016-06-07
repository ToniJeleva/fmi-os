#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
	int status;
        int fd1;
        char c[2];
        if ( (fd1 = open(argv[1], O_CREAT | O_RDWR,0777)) == -1 ){
                        write(2, "Operation open failed!", 27);
                        exit(1);
                }

	if (fork() > 0) {
	wait(&status);
         printf("father\n");
         fd1=open(argv[1],O_RDWR);
 	while ( read(fd1, &c, 2) ){
              write(1,&c,2); 
               //printf("%s",c);
                printf("\n");
        }
} else {
		
			printf("son\n");
                        write(fd1,"foobar",6);
                        close(fd1);	
	}
close(fd1);
exit(0);
}
