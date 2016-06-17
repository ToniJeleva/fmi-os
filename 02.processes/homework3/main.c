#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>

int main (int argc, char* argv[])
{  
	if(argc!=2){
        err(99,"Wrong number of parameters.");
        }

	int fd;
	int statistics[256];

	int i;
	for(i=0;i<256;i++){
		statistics[i]=0;
	}

 	if ((fd = open(argv[1], O_RDONLY)) == -1){
		err(99, "Can not open file.");
        }

	char buffer[4096];
	int readNum;
        while((readNum = read(fd, &buffer, sizeof(buffer)))>0){
         	int j;
		for(j=0;j<readNum;j++){
			statistics[(int)buffer[j]]+=1;
		}
	}

	int k;
	for(k=0;k<256;k++){
		if(statistics[k]>0){
         	printf("Byte %d , Count %d\n",k,statistics[k]);

		}	
	}

 
    exit(0);
}
