#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include "ListNode.hpp"
using namespace std;
int removeDuplicates(vector<int>& nums) {
  if(nums.size() < 2)
    return nums.size();
  vector<int>::iterator f1, f2;
  f1 = nums.begin();
  f2 = nums.begin();
  ++f2;
  while(f2 < nums.end()) {
    if(*f2 != *f1) {
      ++f1;
      *f1 = *f2;
    }
    ++f2;
  }
  ++f1;
  nums.erase(f1, nums.end()); 
  return nums.size();
}

int main(){
	return 1;
}
