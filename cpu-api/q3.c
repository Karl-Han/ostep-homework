#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    // int fd = open("q2_temp", O_RDWR);
    int pid = fork();

    if(pid == 0){
        // child process
        printf("(%d): before operation\n", getpid());

        printf("Hello");

        printf("(%d): after operation\n", getpid());
    }
    else if(pid > 0){
        // parent process
        printf("Parent(%d)\nChild(%d)\n", getpid(), pid);
        printf("(%d): before operation\n", getpid());

        sleep(2);
        printf("Goodbye");

        printf("(%d): after operation\n", getpid());
        printf("Finish waiting for Child(%d)\n", pid);
    }

    else if (pid < 0)
    {
        // something goes wrong
        printf("Something goes wrong when forking");
        return 1;
    }
    return 0;
}
