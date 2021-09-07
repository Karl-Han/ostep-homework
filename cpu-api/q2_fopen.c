#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

// Revelent manual: https://linux.die.net/man/3/open

int main(int argc, char const *argv[])
{
    FILE* file = fopen("temp_q2", "r+");
    int pid = fork();

    if(pid == 0){
        // child process
        printf("Child(%d): before operation\n", getpid());
        fprintf(file, "This is from child process\n");
        printf("Child(%d): after operation\n", getpid());
        
    }
    else if(pid > 0){
        // parent process
        printf("Parent(%d): before operation\n", getpid());
        fprintf(file, "This is from parent process\n");
        printf("Parent(%d): after operation\n", getpid());

        // It never print, since it stops before wait
        wait(NULL);
        printf("Finish waiting for Child(%d)\n", pid);

        fclose(file);
    }

    else if (pid < 0)
    {
        // something goes wrong
        printf("Something goes wrong when forking");
        return 1;
    }
    return 0;
}
