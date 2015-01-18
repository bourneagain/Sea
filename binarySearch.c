#include <stdio.h>
#include <stdlib.h>

int bs(int a[], int start, int end, int target){

	int mid=0;
	while(end >= start){
		mid = start + (end - start) / 2;
		if (a[mid] == target) {
			return mid;
		}else if(a[mid] > target){
			end = mid-1;
		} else{
			start = mid+1;
		}
	}
    return -1;

}
int main(){
	int a[10] = {};
	printf("%d\n", bs(a,0,1,-1));
	return 0;
}