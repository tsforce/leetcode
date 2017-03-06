#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include "ListNode.hpp"
using namespace std;
int removeElement(vector<int>& nums, int val) {                           
  sort(nums.begin(), nums.end());
  typedef vector<int>::iterator iter;
  std::pair<iter, iter> bound = equal_range(nums.begin(), nums.end(), val);
  if(bound.first != nums.end())
    nums.erase(bound.first, bound.second);
  return nums.size();
}


int main(){
	return 1;
}
