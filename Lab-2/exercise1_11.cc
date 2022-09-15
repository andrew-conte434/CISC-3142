#include<iostream>

int main()
{
	std::cout << "Please enter two numbers...";
	int x = 0, y = 0;
	std::cin  >> x >> y;
	int larger = 0, smaller = 0;
	if(x >= y){
		larger = x;
		smaller = y;
	} else {
		larger = y;
		smaller = x;
	}
	std::cout<<"The values between " << x << " and " << y << " are:"
		<<std::endl;
	for(int i = smaller; i < larger; i++){
		std::cout << i << " ";
	}
	std::cout<<std::endl;
	std::cout << "And now with a while loop..." << std::endl;
	int value = smaller;
	while(value < larger) {
		std::cout << value << " ";
		value++;
	}
	std::cout<<std::endl;
	return 0;
}
