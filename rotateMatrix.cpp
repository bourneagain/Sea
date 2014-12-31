#include <iostream>
using namespace std;

int main(){
    
    int matrix[4][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
        cout << matrix[0][0];
    int n=4;
    for(int layer=0;layer<n/2;layer++){
        int first=layer;
        int last=n-1-layer;
        for(int i=first;i<last;i++){
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
          
        }
    }
    
    cout << matrix[0][0];
    return 0;
}