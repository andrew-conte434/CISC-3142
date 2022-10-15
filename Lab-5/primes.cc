#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> primes{2};
	for(int i = 3; i <= 100; i++){
		bool isPrime = true;
		for(int prime : primes){
			if(i % prime == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			primes.push_back(i);
		}

	}
	cout << "Primes between 3 and 100: " << endl;
	for(auto iter = primes.begin(); iter != primes.end(); ++iter){
		cout << *iter << ' ';
	}
	cout << endl;
	return 0;
}
