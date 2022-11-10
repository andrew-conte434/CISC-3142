#include<iostream>
using namespace std;
int main() {
	string word1, word2;
	cin >> word1;
	cin >> word2;

	string larger = "The strings are equal";

	if(word1 != word2){
		if(word1 > word2){
			larger = word1;
		} else {
			larger = word2;
		}
	}

	cout << larger;

	return 0;
}
