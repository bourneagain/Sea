#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        // try DP start-to-end
        vector<vector<string> > best ( s.length()+1, vector<string>()  );
        
        best[0].push_back("");
        cout<<"here"<<endl;
        for(int i = 1; i<= s.length(); i++)
        {

            for(int j = 0; j<i; j++)
            {
                // look back for every j<i
                string substr = s.substr(j,i-j);
                if(dict.count(substr)>0)
                {
                    for(int k = 0; k<best[j].size(); k++)
                    {
                                    cout << best[j][k];
                        // kth solution of string[0:j]
                        if(best[j][k]=="")
                        {
                            cout <<"je"<<endl;
                            best[i].push_back(substr);
                        }
                        else
                        {
                            cout <<"push" << endl;
                            best[i].push_back(best[j][k] + " " + substr);
                        }
                    }
                }
            }
        }
        cout << "pl";
        
        return best[s.length()];
    }
};

int main(){
    Solution a;
    std::unordered_set<std::string> dict ( {"sam","sung","samsung","shyam","the","man","test","is","god"} );

    vector<string> s = a.wordBreak("samsung",dict);
        cout << endl<<"done";
    for (std::vector<string>::iterator it = s.begin() ; it != s.end(); ++it){
        cout << *it<<endl;
    }

    return 0;
}
