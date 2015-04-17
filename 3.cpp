#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.size() < 2)
        return s.size();
    int max = 0;
    int i = 0, j = 1;
    while(i < s.size() && j < s.size()) {
        string left = s.substr(i, j - i);
        std::size_t found = left.find(s[j]);
        if (found!=std::string::npos) {
            if(j - i > max) 
                max = j - i;
            i += found + 1;
        }
        ++j;
    }
    if(j - i > max )
        max = j - i;
    return max;
}

int main(){
    string s("abcabcd");
    cout<<lengthOfLongestSubstring(s);

	return 1;
}
