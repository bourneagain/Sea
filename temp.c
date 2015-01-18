#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str){
	printf("ERE  E %s",str);
	char *rev,*ref;
	int l=0;
	char t;

	ref=str;

	while(str){
		str++;
		l++;
	}
	if(l == 0){
		printf("ERROR\n");
		return;
	}

	str--;// remove null character
	rev=str;

	while(ref!=rev){
		t=*ref;
		*ref=*rev;
		*rev=t;
		rev++;ref++;
	}


	// got the last address

}

void transform(char *str){

}

int main(){

	char *s = "shyam";
	printf("%s\n", s);
	reverseString(s);
	printf("%s\n", s);

	return 0 ;
}