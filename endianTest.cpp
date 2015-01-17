#include <iostream>

int Endianness(void)
{
union {
int thelnteger;
char singleByte; 
}endianTest;

endianTest.thelnteger = 1;
return endianTest.singleByte; 
}

int main(){
	std::cout << "sam";
	std::cout << Endianness();
}