#include <iostream>
#include <list>

class Circular_list{
// Executes insert, delete in O(1)-time.
private:
    std::list<std::string> lt;
    std::list<std::string>::iterator iter;
    std::list<std::string>::iterator tmp_iter;
    int total_idx;
    int size;
    int CAPACITY=100;
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
            tmp_iter = iter++;
            lt.erase(tmp_iter);
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
