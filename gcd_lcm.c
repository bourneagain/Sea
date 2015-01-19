#include <stdio.h>

int gcd(int a,int b){
	while(b!=0){
		if(a>b){
			a=a-b;
		}else{
			b=b-a;
		}
	}
	return a;
}

int max(int a,int b){
	return (a>b)? a:b;
}
int lcm(int a,int b){
	int m = max(a,b);
	while(1){
		if (m%a == 0  && m%b == 0) {
			return m;
		}
		m++;
	}
}


int main(){
	printf("%d\n", gcd(5,10));
	printf("%d\n", lcm(5,10));
	return 0;
}