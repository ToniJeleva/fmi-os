#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>

int main ()
{
        int pd[2];
        pipe(pd);
        char c[3];
        int forkit=fork();
 
	if (forkit < 0) {
         	err(1,"Error");
        }
 
         if(forkit>0){
          	write(pd[1],"sth",3);
         }else {
         	int bytes_read=read(pd[0],&c,100);
           	write(1,&c,bytes_read);
         }
exit(0);
}
