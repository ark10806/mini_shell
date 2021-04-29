//hi
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> oper_que;
string command_line;

int main(){
	while(true){
		cout << "12161161_shell$";
		getline(cin, command_line);
		cout << command_line;
		
		for(int i=0; i<command_line.size(); i++){
			if(command_line[i]==' '){ 
				oper_que.push(command_line.substr(0,i));
			}
		}

		for(int i=0; i<oper_que.size(); i++){
			//cout << '['  << oper_que.front() << ']' <<  endl;
			oper_que.pop();
			//cout << oper_que.pop() << endl;
		}
	}

	return 0;
}
