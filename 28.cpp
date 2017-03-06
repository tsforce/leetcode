#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
    if(needle.empty()) {
        return 0;
    } else if(haystack.length() < needle.length()) {
        return -1;
    }
    vector<int> l(needle.length(), 0);
    for(int i = 1; i< needle.length(); ++i) {
        int last = i-1;
        while(last >= 0) {
            if(l[last] == 0) {
                if(needle[0] == needle[i])
                    l[i] =1;
                break;
            } else {
                if(needle[l[last]] == needle[i]) {
                    l[i] = l[last] + 1;
                    break;
                }
                else
                    last = l[last] - 1;
            }
        } 
        //cout << "i = " << i << ", li = "<<l[i] <<endl;
    }
    int i = 0, j=0;
    while(i < haystack.length() && j < needle.length()) {
        cout <<"i = " << i;
        if(haystack[i] == needle[j]) {
            //cout <<"a"<<endl;
            ++i;
            ++j;
        } else if(j == 0) {
            //cout <<"b"<<endl;
            ++i;
        } else {
            //cout <<"c"<<endl;
            j = l[j-1];
        }
    }
    if (j == needle.length())
        return i -j;
    else 
        return -1;
}

int main(){
    cout<<strStr("mississippi", "issip")<<endl;
    /*
    cout<<strStr("abcdef", "cdf")<<endl;
    cout<<strStr("abcdefadflkkjasjflaskdfjaldf", "cdf")<<endl;
    cout<<strStr("abcdefadflkkjasjflaskdefjaldf", "defj")<<endl;
    */
	return 1;
}
