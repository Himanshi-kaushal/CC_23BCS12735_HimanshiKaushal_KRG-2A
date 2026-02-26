#include <bits/stdc++.h>
using namespace std;

const int base=256;
int myhash(const string s){
    int result=0;
    for(int i=0;i<s.size();i++){
        result= result*base +  (s[i]-'a' +1) ;
    }  
    return result;
}

int main() {
    string text="acbdabchd"; 
    string pat="abc"; 
    int n=text.size(); int m=pat.size();

    int hashtxt= myhash(text.substr(0,m));
    int hashpat= myhash(pat);
    int power=1;
    for(int i=0;i<m-1;i++) power *= base;

    for(int i=0;i<= n-m; i++){
        if(hashtxt==hashpat){
             if (text.substr(i, m) == pat)   cout<< "pattern found at index "<<i ;
        }
        if(i <n-m){
            hashtxt -= (text[i] -'a' +1) *power;
            hashtxt = hashtxt *base;
            hashtxt += (text[i+m] -'a' +1);
        }
    }
    return 0;
}
