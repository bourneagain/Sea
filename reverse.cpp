#include <iostream>
using namespace std;
void reverseString(char *str){
	char *ptr=str;
	char tmp;

	if(str){
		while(*ptr){
			ptr++;
		}
		ptr--;

		while(str < ptr){
			tmp=*str;
			*str=*ptr;
			*ptr=tmp;
			str++;
			ptr--;
		}

	}
	return;	
}

int main(){

	char a[]="shyam";
	cout << a << endl;
	reverseString(a);
	cout << a << endl;


}
