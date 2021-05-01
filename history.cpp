#include <iostream>
#include <list>

class Circular_list{
// Executes insert, delete in O(1)-time.
private:
    std::list<std::string> lt;
    std::list<std::string>::iterator iter;
    int total_idx;
    int size;
    int CAPACITY=10;
    bool is_full;
public:
    Circular_list(){
        iter = lt.begin();
        total_idx = 0;
        size = 0;
        is_full = false;
    }
    void insert_circular(std::string strs){
        if((total_idx % CAPACITY)==0 && total_idx != 0) { 
            iter = lt.begin();
            is_full = true;
        }
        if(is_full){
            lt.erase(iter);
            iter++;
            lt.insert(iter, strs);
        }
        else{ lt.push_back(strs); }
        total_idx++;
    }
    void get_history(){
        int cnt;
        if (total_idx < CAPACITY || total_idx % CAPACITY==0){ 
            // When the list.size() is less than CAPACITY or the iterator is multiples of 100. -> Starts from idx-0.
            cnt = 0;
            int rewind = total_idx % CAPACITY;
            if(total_idx % CAPACITY == 0)
                rewind = CAPACITY;
            for(auto iter=lt.begin(); iter!=lt.end(); iter++){
                std::cout << ' ' << (total_idx - rewind + cnt) << '\t' << *iter << std::endl;
                cnt++;
            }
        }
        else{
            // When the iterator is not multiples of 100 and list.size() is CAPACITY -> Starts from current iterator.
            cnt = total_idx % CAPACITY;
            for(auto i=0; i<CAPACITY; i++){
                std::cout << ' ' << (total_idx - CAPACITY + i) << '\t' << *iter << std::endl;
                if((cnt + 1) % CAPACITY == 0) { iter = lt.begin(); }
                else { iter++; }
                cnt++;
            }
        }
    }
};



/*
# mini_shell

 -mini_shell waits until the user enter a command.  
 -The command is parsed into a command token. ("ls -al" -> "ls", "-al")  
 -If the command is built-in command then execute the command without calling fork().  
 -If the command is not a built-in command then It runs process by calling system call fork() and mini_shell waits until the process ends.
    (if it is running in the background[&] then mini_shell do not wait.)
 -Repeat the above procedures until the user enters [quit].
 
 **built-in commands**
  1. [quit]: terminates mini_shell
  2. [history]: print 10 command lines entered by the latest user.
  3. [help]: print manual

*/