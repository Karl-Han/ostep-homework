#include<unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x = 100;
    int pid = fork();
    if (pid < 0)
    {
        // something goes wrong
        printf("Something goes wrong when forking");
        return 1;
    }
    else if(pid == 0){
        // child process
        printf("Child(%d): x is %d before change\n", getpid(), x);
        x = 200;
        printf("Child(%d): x is %d after change\n", getpid(), x);
    }
    else{
        // parent process
        printf("Parent(%d): x is %d before change\n", getpid(), x);
        x = 101;
        printf("Parent(%d): x is %d after change\n", getpid(), x);
    }
    return 0;
}
