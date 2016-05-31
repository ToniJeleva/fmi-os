#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
        int fd;
        int i=1;        //броят на символи за нов редове
        char c;

	while(i<argc){
        if ( ( fd = open(argv[i], O_RDONLY) ) == -1 ){
                write(2, "File failed to open in read mode\n", 33);
                exit(-1);
        }

        while ( read(fd, &c, 1) ){

                write(1, &c, 1);
	}
        close(fd);
 	i=i+1;
	}
}
