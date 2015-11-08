#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
  vector<vector<int> > r;
  sort(nums.begin(), nums.end()); 
  for(int i = 0; i + 2< nums.size(); ++i) {
    if(i > 0 && nums[i -1] == nums[i])
      continue;
    int a = nums[i];
    int j = i + 1;
    int k = nums.size() - 1;
    while(j < k) {

      if(nums[j] + nums[j + 1] + a > 0 ||
         nums[k] + nums[k - 1] + a < 0)
        break;
      else if(nums[j] + nums[k] + a < 0)
        ++j;
      else if(nums[j] + nums[k] + a > 0)
        --k;
      else {
        vector<int> s;
        s.push_back(a);
        s.push_back(nums[j]);
        s.push_back(nums[k]);
        r.push_back(s);
        do {
          ++j;
        } while (j < k && nums[j-1] == nums[j]);
        --k;
      }
    }
  }
  return r;
}

int main(){
  vector<int> s;
//  s.push_back(-1);
 // s.push_back(0);
  //s.push_back(1);
  threeSum(s);
  cout<<s.size();

    return 1;
}
