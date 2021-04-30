#include <iostream>
#include <unistd.h>
using namespace std;

#define TOTALFORK 5 // 생성할 총 프로세스 수

int main(int argc, char **argv){
    pid_t pids[TOTALFORK], pid;
    int process_num = 0;
    int state;

    while(process_num < TOTALFORK){
        pids[process_num] = fork();

        if(pids[process_num] < 0){
            cout << "fork failed!" << endl;
            return -1;
        }
        else if(pids[process_num] == 0){   // 자식 프로세스
            cout << "child: " << getpid() << endl;
            sleep(1);
            exit(0);
        }
        else {  // 부모 프로세스
            cout << "parent: " << getpid() << " | child: " << pids[process_num] << endl;
        }
        process_num++;
    }
    return 0;
}