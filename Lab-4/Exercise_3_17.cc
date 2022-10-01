#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<string> svec;
	string input, temp = "";
	getline(cin, input);
	for(int i = 0; i < input.length(); i++){
		if(input[i] == ' '){
			svec.push_back(temp);
			temp = "";
		} else if(i == input.length() - 1){
			temp += input[i];
			svec.push_back(temp);
			temp = "";
		} else {
			temp += input[i];
		}
	}

	for(int i = 0; i < svec.size(); i++){
		temp = svec[i];
		temp[0] = toupper(temp[0]);
		svec[i] = temp;
	}
	int wordCount = 0;
	for(auto word: svec){
		cout << word << " ";
		wordCount++;
		if(wordCount == 8){
			cout << endl;
			wordCount = 0;
		}
	}
	return 0;
}
