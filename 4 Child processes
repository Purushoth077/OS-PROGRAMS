#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void printNumbers(pid_t pid, int start, int step) {
    printf("Child process %d: ", pid);
    for (int i = start; i <= 100; i += step) {
        printf("%d ", i);
    }
    printf("\n");
}
int main() {
    pid_t pid[4];

    for (int i = 0; i < 4; i++) { 
        if (pid[i] == 0) {
            switch (i) {
                case 0:
                    printNumbers(getpid(), 1, 2); 
                    break;
                case 1:
                    printNumbers(getpid(), 2, 2); 
                    break;
                case 2:
                    printNumbers(getpid(), 3, 3);  
                    break;
                case 3:
                    printNumbers(getpid(), 5, 5); 
                    break;
                default:
                    break;
            }
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        printf("Parent process: Created child process with ID %d\n", pid[i]);
    }
    return 0;
}
