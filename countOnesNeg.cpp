#include <iostream>
int test(unsigned int num){
	int n=0;
	//std::cout << num << std::endl;
	while(num){
		//std::cout << num << std::endl;
		if (num&1)
			n++;
		num=num>>1;
		
	}
	return n;
}


int NumOnesInBinary(int number) {
	int numOnes = 0; 
	while (number) {
		number = number & (number - 1);
		numOnes++; 
	}
	return numOnes; 
}

int main(){
	std::cout  << test(-1);
	std::cout  << NumOnesInBinary(-1);
}
