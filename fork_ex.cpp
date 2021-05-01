#include <iostream>
#include <unistd.h>
using namespace std;

#define TOTALFORK 5 // 생성할 총 프로세스 수

int main(int argc, char *arv[]){
    pid_t pid, d_pid;
    int status;
    pid = fork();

    if(pid == 0){ // in Context of CHILD
        execl("/bin/ls", "ls", "-l", (char *)0); // execute excel after fork().
        cout << "Child forked without execl." << endl;
        exit(-1);
    }
    else if(pid > 0){   // in Context of PARENT
        cout << "[Parent]pid: " << pid << endl;
        d_pid = wait(&status);
        cout << "[Parent]exit status of task " << d_pid << " is " << status;
    }
    else{
        cout << "fork error" << endl;
    }
}
