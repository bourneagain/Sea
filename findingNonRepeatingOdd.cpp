#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int arr[], int n) {
        // Initialize result
        int result = 0;
        
        int x, sum;
        
        // Iterate through every bit
        for (int i = 0; i < 32; i++)
        {
            // Find sum of set bits at ith position in all
            // array elements
            sum = 0;
            x = (1 << i);
            for (int j=0; j< n; j++ )
            {
                if (arr[j] & x)
                    sum++;
            }
            
            // The bits with sum not multiple of 3, are the
            // bits of element with single occurrence.
            if (sum % 4)
                result |= x;
        }
        
        return result;
    }
};
int main(){
    Solution a;
    int b[] ={2,2,2,2,15,5,5,5,5};
    cout <<     a.singleNumber(b, 9);
}
