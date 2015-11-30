#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include <algorithm>
#include <utility>
using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target) {
  vector<vector<int> > r;
  if(nums.size() < 4)
    return r;
  sort(nums.begin(), nums.end());
  map<int, vector<pair<int, int> > > m;
  for(int i = 0; i < nums.size(); ) {
    for(int j = i + 1; j < nums.size(); ) {
      int c = nums.size();
      while(j < c -3 && nums[j-1] == nums[j])
        ++j;
      int delta = target - nums[i] - nums[j];
      int p = j + 1;
      int q = nums.size() - 1;
      while(p < q) {
        if(delta == nums[p] + nums[q]) {
          vector<int> v;
          v.push_back(nums[i]);
          v.push_back(nums[j]);
          v.push_back(nums[p]);
          v.push_back(nums[q]);
          r.push_back(v);
          ++p;
          while(p < nums.size() && nums[p-1] == nums[p])
            ++p;
          --q;
        } else if(delta < nums[p] + nums[q])
          --q;
        else 
          ++p;
      }
      ++j;
      while(j < nums.size()&& nums[j-1] == nums[j]) 
        ++j;
    }
    ++i;
    while(i < nums.size()&& nums[i-1] == nums[i]) 
      ++i;
  }
  return r;
}
vector<vector<int> > fourSum2(vector<int>& nums, int target) {
  vector<vector<int> > r;
  if(nums.size() < 4)
    return r;
  sort(nums.begin(), nums.end());
  map<int, vector<pair<int, int> > > m;
  for(int i = 0; i < nums.size(); ++i) {
    for(int j = i + 1; j < nums.size(); ++j) {
      vector<pair<int, int> > &s = m[nums[i] + nums[j]];
      s.push_back(make_pair(i, j));
    }
  }
  for(int i = 0; i < nums.size(); ++i) {
    for(int j = i + 1; j < nums.size(); ++j) {
      int delta = target - nums[i] - nums[j];
      vector<pair<int, int> > &s = m[delta];
      for(int k = 0; k < s.size(); ++k) {
        if(s[k].first > j) {
          vector<int> v;
          v.push_back(nums[i]);
          v.push_back(nums[j]);
          v.push_back(nums[s[k].first]);
          v.push_back(nums[s[k].second]);
          r.push_back(v);
        }
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
  //threeSum(s);
  cout<<s.size();

    return 1;
}
