/*
g++ -std=c++11 mini_shell.cpp
*/

#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <set>
#include "history.cpp"
using namespace std;

string command_line;
string tmp;
Circular_list hist_list;
set<string> built_set;
set<string>::iterator built_end;
string oper_head;

pid_t pid;
int status;

void init(){
	/* 
		by using "stl::set", We can search the input operation is wheter BUILT-IN or NOT-BUILT-IN FUNCTIONS 
		in O(log n)-time.
	*/
	built_set.insert("quit");
	built_set.insert("history");
	built_set.insert("help");
	built_end = built_set.end();
}

bool is_built_in_funcs(string oper){
	return built_end != built_set.find(oper);
}

void Parser(vector<string> & vec, string str_comm){
	hist_list.insert_circular(str_comm);
	int str_iter = -1;
	for(int i=0; i<str_comm.size(); i++){
		if(str_comm[i]==' ') continue;
		else{
			str_iter = i;
			for(int j=i; j<str_comm.size(); j++){
				if(j == str_comm.size()-1){
					cout << "Caught" << endl;
					vec.push_back(str_comm.substr(str_iter, j-str_iter+1));
					i = j;
					break;
				}
				if(str_comm[j]==' '){
					vec.push_back(str_comm.substr(str_iter, j-str_iter));
					i = j;
					break;
				}
			}
		}

	}
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << ", ";
	}
	cout << endl;
}


void executer(const vector<string> vec){
	oper_head = vec[0];

	if (is_built_in_funcs(oper_head)){ // When the input command is built-in functions. -> not fork().
		
		if(oper_head == "quit") { exit(0); }
		else if(oper_head == "history") { hist_list.get_history(); }
		else if(oper_head == "help") { cout << "man" << endl;}
	}
	else{ // When the input command is not built-in functions. -> fork()
		pid = fork();
		string st = "/bin/";
		if(pid > 0){
			if(vec[vec.size()-1][vec[vec.size()-1].size()-1] == '&'){
				cout << "Parent not waiting" << endl;
			}
			else{
				cout << "Parent waiting" << endl;
				wait(&status);
			}
		}
		else if(pid == 0){
			char c0[10];
			char c1[10];
			char c2[10];

			strcpy(c0, (st+vec[0]).c_str());
			strcpy(c1, vec[0].c_str());
			strcpy(c2, vec[1].c_str());
			
			if(vec.size()==1){
				execl(c0, vec[0].c_str(), (char *)0);
			}
			else if(vec.size()==2){
				execl(c0, c1, c2, (char *)0);
			}
			cout << "Child done!" << endl;
			exit(-1);
		}
		else{
			cout << "fork failed!" << endl;
		}
	}
}

int main(){
	init();
	vector<string> oper;
	while(true){
		oper.clear();
		cout << "12161161_shell$ ";
		getline(cin, command_line);

		
		Parser(oper, command_line);
		executer(oper);
	}

	return 0;
}
