#include<iostream>
#include<vector>
#include<map>
using namespace std;

string longestPalindrome(string s) {
    if(s.empty())
        return s;
    int st = 0, len = 0;
    for(int i = 0; i < s.size(); ++i) {
        int j = 1;
        for(; i - j >= 0 && i + j < s.size(); ++j)
            if(s[i-j] != s[i+j]) 
                break;
        if(j - 1 > len) {
            len = j - 1;
            st = i;
        }
    }

    int st2 = 0, len2 = 0;
    for(int i = 0; i < s.size() - 1; ++i) {
        int j = 0;
        for(; i - j >= 0 && i + j + 1 < s.size(); ++j)
            if(s[i-j] != s[i+j+1])
                break; 
        if( j > len2) {
            len2 = j;
            st2 = i;
        }
    }
    if(len * 2 + 1 > len2 * 2)
        return s.substr(st-len, len * 2 + 1);
    else
        return s.substr(st2 - len2 + 1, len2 * 2);
            
}

int main(){
    string s("asdfasdfabcabccba");
    cout<<longestPalindrome(s);
	return 1;
}
