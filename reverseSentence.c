#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str){
	char *rev,*ref;
	int l=0;
	char t;

	ref=str;

	while(*str!='\0'){
		str++;
		l++;
	}
    

	if(l == 0){
		printf("ERROR\n");
		return;
	}

	str--;// remove null character
	rev=str;

	while(rev>ref){
		t=*ref;
		*ref=*rev;
		*rev=t;
		rev--;ref++;
	}


	// got the last address

}

void transform(char *str){
	reverseString(str);
	char *t;
	char *s;
	char temp;
	char *ep;
	
	while(*str!= '\0') {
		t=str;
		while(*t != ' ' && *t != '\0'){
			t++;
		}
		ep=t+1;
		t--;
		while(t>str){
            temp=*str;
            *str=*t;
            *t=temp;
			str++;
			t--;
		}
        str=ep;
	}

}

int main(){

	char s[20] = "shyam is a good boy";
	transform(s);
	printf("%s\n", s);
	return 0 ;
}