#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<string> svec;
	string input;
	do {
		cin >> input;
		svec.push_back(input);
	}while(input != "stop");

	for(auto &i : svec){
		cout << i << endl;
	}
}
