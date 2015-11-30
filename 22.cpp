#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
using namespace std;

void find(int n, int left, int right, vector<string> &r, const string& s) {
  if(left == n){
    string str = s + string(left - right, ')');
    r.push_back(str);
    return;
  } else if ( left == right) {
    string str = s + "(";
    find(n, left + 1, right, r, str);
  } else {
    string str1 = s + "(";
    find(n, left + 1, right, r, str1);
    string str2 = s + ")";
    find(n, left, right + 1, r, str2);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> r;
  if(n <= 0)
    return r;
  find(n, 1, 0, r, "(");
}


int main(){
  vector<string> r = generateParenthesis(3);
  for(int i = 0 ; i < r.size(); ++i)
    cout<<r[i]<<endl;
	return 1;
}
