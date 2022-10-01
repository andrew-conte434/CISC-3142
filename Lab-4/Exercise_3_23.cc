#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> numbers(10, 2);
	vector<int>::iterator iter;
	for(auto i: numbers){
		cout << i;
	}
	cout << endl;
	for(iter = numbers.begin(); iter != numbers.end(); ++iter){
		*iter = *iter * 2;
	}

	cout << "After iterator..." << endl;

	for(auto i: numbers){
		cout << i;
	}

	cout << endl;
}
