#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
using namespace std;
bool isValid(string s) {
  if(s.size() %  2 == 1)
    return false;
  stack<char> v;
  for(int i = 0; i< s.size(); ++i) 
    if(v.empty())
      v.push(s[i]);
    else if( (v.top() ==  '(' && s[i] == ')') ||
        (v.top() ==  '[' && s[i] == ']') ||
        (v.top() ==  '{' && s[i] == '}') )
      v.pop();
    else if( s[i] == ')' ||  s[i] == ']' || s[i] == '}')
      return false;
    else
      v.push(s[i]);
  return v.empty();
}


int main(){
  cout<<isValid("()");
	return 1;
}
