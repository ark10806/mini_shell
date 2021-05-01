#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
    string s = "string";
    char c[10];
    strcpy(c, s.c_str());
    cout << c << endl;
}