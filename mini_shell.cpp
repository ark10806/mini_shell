/*
g++ -std=c++11 mini_shell.cpp
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

queue<string> history_que;
map<int, string> history_map;
int line_num = 0;
string command_line;
string tmp;

void record(string str_comm){
	history_map.push(str_comm);
	
	if(history_que.size() > 100){
		history_que.pop();
	}
	line_num++;
}

void show_history(){
	int i = -history_que.size();
	while(!history_que.empty()){
		cout << ' ' << line_num + i << '\t' << history_que.front() << endl;
		history_que.pop();
		i++;
	}
}

void Parser(vector<string> &vec, string str_comm){
	record(str_comm);

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
	else if (vec[0] == "history") { show_history(); }
	else { cout << "fork" << endl; }

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
