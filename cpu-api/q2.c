#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
// int open (const char* Path, int flags [, int mode ]); 

// Revelent manual: https://linux.die.net/man/3/open
// GeeksforGeeks open: https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

int main(int argc, char const *argv[])
{
    // Assume that file has been created
    int fd = open("q2_temp", O_WRONLY);
    // int fd = open("q2_temp", O_RDWR);
    int pid = fork();

    if(pid == 0){
        // child process
        printf("(%d): before operation\n", getpid());

        // char buf[32] = "\0";
        // size_t count = read(fd, buf, 32);
        // if (count == -1)
        // {
        //     fprintf(stderr, "(%d): Error in read from the fd\n", getpid());
        //     return 1;
        // }
        // printf("(%d)Finish reading(%lu bytes) and buf is %s\n", getpid(), count, buf);
        char buf1[32] = "This is child\n\0";
        size_t count = write(fd, buf1, 32);
        printf("(%d)Finish writing(%lu bytes)\n", getpid(), count);
        
        printf("(%d): after operation\n", getpid());
    }
    else if(pid > 0){
        // parent process
        printf("Parent(%d)\nChild(%d)\n", getpid(), pid);

        char buf[32] = "This is parent\n\0";
        printf("(%d): before operation\n", getpid());
        size_t count = write(fd, buf, 32);
        if (count == -1)
        {
            fprintf(stderr, "(%d): Error in read from the fd\n", getpid());
            return 1;
        }
        printf("(%d): after operation\n", getpid());

        wait(NULL);
        printf("Finish waiting for Child(%d)\n", pid);

        close(fd);
    }

    else if (pid < 0)
    {
        // something goes wrong
        printf("Something goes wrong when forking");
        return 1;
    }
    return 0;
}
