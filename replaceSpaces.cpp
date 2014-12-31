#include <iostream>
#include <string>
using namespace std;
void Rep_Str(char *str)
{
    size_t strleng = strlen(str);
    int spaceCount=0;
    for(int i=0;i<strleng;i++){
        if (str[i]==' ')
            spaceCount++;
    }
    
    int newstrleng = strleng + 2*spaceCount;
    str[newstrleng]='\0';
    newstrleng--;
    for(int i=strleng-1;i>0;i--){
        if(str[i] != ' '){
            str[newstrleng]=str[i];
            newstrleng--;
        }else if(str[i] == ' '){
            str[newstrleng--] = '0';
            str[newstrleng--] = '2';
            str[newstrleng--] = '%';
        }
    }
    printf("%s",str);
}

int main(){
    char s[20]="This bad  shyam";
    Rep_Str(s);
}
