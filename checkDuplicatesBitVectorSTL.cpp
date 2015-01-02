#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset
#include <vector>

using namespace std;
void checkDuplicates(vector<int> &array);

void checkDuplicates(vector<int> &array) {
    bitset<32000> bs;
    for (int i = 0; i < array.size(); i++) {
        int num = array[i];
        int num0 = num - 1;
        if (bs.test(num0))
            cout << num << endl;
        else
            bs.set(num0);
        }
}

int main(){
    cout << "hi";
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(412);
    a.push_back(2);
    checkDuplicates(a);
    
    return 0;
}
