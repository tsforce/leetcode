#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
string intToRoman(int num) {
    string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
    int value[] =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
    string r;
    while(num > 0) {
        for(int i = 0;; ++i) {
            if (num >= value[i]) {
                num -= value[i];
                r = r + symbol[i];
                break;
            }
        }
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
    cout<<intToRoman(100)<<endl;
	return 1;
}
