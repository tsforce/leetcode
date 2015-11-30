#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
using namespace std;
vector<string> letterCombinations(string digits) {
  string v[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
  vector<string> r;
  if(digits.size() == 0)
    return r;
  int i = digits[0] - '0';
  string s = v[i];
  if(digits.size() == 1) {
    for(int i = 0; i < s.size(); ++i) {  
      r.push_back(s.substr(i, 1));
    }
    return r;
  }
  vector<string> n = letterCombinations(digits.substr(1));
  for(int i = 0; i < s.size(); ++i) {  
    for(int j = 0; j < n.size(); ++j) 
      r.push_back(s.substr(i,1) + n[j]);
  }
  return r;

}

int main(){
  vector<int> s;
//  s.push_back(-1);
 // s.push_back(0);
  //s.push_back(1);
  //threeSum(s);
  cout<<s.size();

    return 1;
}
