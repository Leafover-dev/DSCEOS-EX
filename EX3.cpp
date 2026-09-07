#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    pid_t pid; int fd;
    pid = fork();	// Create child process
    if(pid < 0)
    {
        printf("Fork failed\n"); exit(1);
    }

    else if(pid == 0)
    {
        // Child process
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Executing ls command using exec\n"); execlp("ls","ls",NULL);
        exit(0);
    }

    else
    {
        // Parent process
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        wait(NULL); // Wait for child process
        printf("Child process completed\n");
        // Demonstrating close()
        fd = open("test.txt", O_RDONLY);
        if(fd >= 0)
        {
            printf("File opened successfully\n"); close(fd);
            printf("File descriptor closed\n");
        }
    }
    return 0;
}