#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int getValue(string s) {
    string symbol[] =   {"M","D", "C", "L","X","V","I"};    
    int value[] =       {1000,500, 100,  50,10, 5, 1}; 
    for(int i = 0;; ++i) 
        if(s == symbol[i])
            return value[i];
}
int romanToInt(string s) {
    int r = 0;
    for(int i = 0; i < s.length(); ++i) { 
        int v = getValue(string(1, s[i]));
        if (i + 1 < s.length() ) {
            int vn = getValue(string(1, s[i+1]));
            if (v < vn )
                r -= v;
            else
                r += v;
        } else 
            r += v;
    }
    return r;
}

int main(){
    /*
    cout<<   isMatch("aa","aa") <<endl;
    cout<<   isMatch("aaa","aa")<<endl;
    cout<<   isMatch("aa", "a*")<<endl;
    cout<<   isMatch("aa", ".*")<<endl;
    cout<<   isMatch("ab", ".*")<<endl;
    */
    cout<<romanToInt("XCV")<<endl;
    cout<<romanToInt("MCMLXXXIV")<<endl;
	return 1;
}
