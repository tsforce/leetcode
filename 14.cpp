#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0 ) {
        return "";
    }
    string c = strs[0];
    for(int i = 1; i < strs.size(); ++i) {
        int j = 0;
        for(; j < c.length() && j < strs[i].length(); ++j) {
            if(c[j] != strs[i][j])
                break;
        }
        if(j == 0)
            return "";
        else if(j < c.size())
            c = c.substr(0, j);
    }
    return c;
}

int main(){
    return 1;
}
