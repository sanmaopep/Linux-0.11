#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t child[5];

    for(int i = 0; i < 5; i++){
        child[i] = fork();

        if(child[i] < 0){
            printf("error occurred in forking");
        }else if(child[i]==0){
            // CHILD
            sleep(i + 1);
            // 子进程退出，不会再次触发fork
            return 0;
        }
        printf("create Child PID %d \n",child[i]);
    }

    printf("let's wait for children over \n");
    // 等待五个子进程退出
    for(int i = 0; i < 5;i++){
        pid_t pid = wait(NULL);
        printf("PID %d over \n",pid);
    }
}