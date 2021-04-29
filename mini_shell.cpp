//hi
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string command_line;

void Parser(vector<string> &vec, string str_comm){
	int iter = 0;
	for(int i=0; i<str_comm.size(); i++){
		if(str_comm[i] == ' '){
			vec.push_back(str_comm.substr(iter,i-iter));
			iter = i+1;
		}
	}
}

int main(){
	while(true){
		vector<string> oper;
		cout << "12161161_shell$";
		getline(cin, command_line);

		Parser(oper, command_line);

		for(int i=0; i < oper.size(); i++){
			string s = oper[i];
			cout << s << endl;
		}
	}

	return 0;
}
