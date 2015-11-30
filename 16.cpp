#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
using namespace std;
int abs(int a, int b) {
    if ( a > b) 
        return a - b;
    else
        return b-a;
}

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end()); 
  int min = nums[0] + nums[1] + nums[2];
  for(int i = 0; i + 2< nums.size(); ++i) {
    if(i > 0 && nums[i -1] == nums[i])
      continue;
    int j = i + 1;
    int k = nums.size() - 1;
    while(j < k) {
      int v = nums[i] + nums[j] + nums[k];
      if(abs(v, target) < abs(min, target))
        min = v;
      if(v < target)
        ++j;
      else if(v > target)
        --k;
      else {
        return target;
      }
    }
  }
  return min;
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
