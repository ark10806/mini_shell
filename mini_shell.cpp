/*
g++ -std=c++11 mini_shell.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include "history.cpp"
using namespace std;

string command_line;
string tmp;
Circular_list cir_list;

void Parser(vector<string> &vec, string str_comm){
	cir_list.insert_circular(str_comm);
	int iter = 0;
	if (str_comm == "quit"){
		exit(0); // 프로그램이 정상적으로 종료.
	}
	for(int i=0; i<str_comm.size(); i++){
		if(str_comm[i] == ' '){
			vec.push_back(str_comm.substr(iter,i-iter));
			iter = i+1;
		}
	}
	vec.push_back(str_comm.substr(iter));
}

void executer(const vector<string> vec){
	if (vec[0] == "quit") {	exit(0); } 	// process end normaly
	else if (vec[0] == "history") { cir_list.get_history(); }
	else { cout << "fork" << endl; }
	cir_list.get_history();
}

int main(){

	while(true){
		vector<string> oper;
		cout << "12161161_shell$ ";
		getline(cin, command_line);

		
		Parser(oper, command_line);
		executer(oper);
	}

	return 0;
}
