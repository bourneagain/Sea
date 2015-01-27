#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the function below.
 */

string  checkPalindrom(int start, int end, string s){
    int n = s.size();
    while(start > 0 && end<=(n-1)){
        if(s[start] == s[end]){
            start--;
            end++;
        }
    }
    start++;
    end--;
    string ret;
    if(start == end){
        ret = "";
    }else{
        ret = s.substr(start, end-start+1);
    }
    return ret;
}

int palindrome(string str) {
    int sum =0 ;
    string s1,s2;
    map<string, int> m;
    for(int i=0;i<str.size()-1;i++){
        s1 = checkPalindrom(i,i,str);
        if (s1.compare("") != 0 && m.find(s1) == m.end()){
            m.insert(pair<string,int>(s1,1));
            sum++;
        }
    s2 = checkPalindrom(i,i+1,str);
    if (s2.compare("") !=0 && m.find(s2) == m.end()){
        m.insert(pair<string,int>(s2,1));
        sum++;
    }
    }
return sum;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _str;
    getline(cin, _str);
    
    res = palindrome(_str);
    fout << res << endl;
    
    fout.close();
    return 0;
}

