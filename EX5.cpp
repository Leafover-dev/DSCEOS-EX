#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2]; pid_t pid;
    char write_msg[50] = "Hello from Parent Process"; char read_msg[50];
    pipe(fd);	// Create pipe
    pid = fork();	// Create child process
    if(pid > 0)
    {
        // Parent process
        close(fd[0]); // Close read end
        write(fd[1], write_msg, strlen(write_msg)+1);

        printf("Parent sent message: %s\n", write_msg);
    }
    else
    {
        // Child process
        close(fd[1]); // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received message: %s\n", read_msg);
    }
    return 0;
}