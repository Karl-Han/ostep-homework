#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    // int fd = open("q2_temp", O_RDWR);
    int pid = fork();

    if(pid == 0){
        // child process
        printf("(%d): before operation\n", getpid());

        int ret = execl("/bin/ls", "/bin/ls", NULL);

        // The following never execute because it returns
        printf("(%d): ret = %d", getpid(), ret);

        printf("(%d): after operation\n", getpid());
    }
    else if(pid > 0){
        // parent process
        printf("Parent(%d)\nChild(%d)\n", getpid(), pid);
        printf("(%d): before operation\n", getpid());

        wait(NULL);
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
