#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

bool check(const string& s, const string& p, int i, int j) {
    if(i == s.length() && j == p.length())
       return true;
    else if(i != s.length() && j == p.length()) {
        return false; 
    }
    while( i < s.length() && j < p.length() ) {
        if(p[j]  ==  '.'&& !(j+1 < p.length() && p[j+1] == '*') ) {
            ++i;
            ++j;
        } else if (p[j]  ==  '.'&& j+1 < p.length() && p[j+1] == '*') {
            return check(s, p, i+1, j) || check(s, p, i, j+2);
        } else if (p[j] == '*') {
            return false; 
        } else if(p[j] == s[i] && !(j+1 < p.length() && p[j+1] == '*') ) {
            return check(s, p, i+1, j+1);
        } else if( p[j] == s[i] &&j+1 < p.length() && p[j+1] == '*') {
            return  check(s, p, i+1, j) || check(s, p, i, j+2);
        } else if(p[j] != s[i] && !(j+1 < p.length() && p[j+1] == '*') ) {
            return false;
        } else if( p[j] != s[i] &&j+1 < p.length() && p[j+1] == '*') {
            return  check(s, p, i, j+2);
        } else {
            return false;
        }
    }
    if(i == s.length() && j == p.length())
       return true;
    else if(i != s.length() && j == p.length()) {
        return false; 
    } else if(j+1 < p.length() && p[j+1] == '*') {
        return check(s, p, i, j+2);
    } else 
        return false;
}

bool isMatch(string s, string p) {
    if(p.empty() && s.empty()) 
       return true;
    else if(p.empty() && !s.empty())
       return false; 
    else 
        return check(s, p, 0, 0);
}

int main(){
    /*
    cout<<isMatch("aa","a")<<endl;
    cout<<   isMatch("aa","aa") <<endl;
    cout<<   isMatch("aaa","aa")<<endl;
    cout<<   isMatch("aa", "a*")<<endl;
    cout<<   isMatch("aa", ".*")<<endl;
    cout<<   isMatch("ab", ".*")<<endl;
    */
    cout<<   isMatch("aab", "c*a*b") <<endl;
	return 1;
}
