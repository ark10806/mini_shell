#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    set<string> s;
    s.insert("a");
    s.insert("b");
    s.insert("c");

    if(s.find("a") != s.end()){
        cout << "a: I'm here" << endl;
    }
    else{
        cout << "a: not found" << endl;
    }


    if(s.find("f") != s.end()){
        cout << "f: I'm here" << endl;
    }
    else{
        cout << "f: not found" << endl;
    }

    return 0;
}