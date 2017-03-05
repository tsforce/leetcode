#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2)
        return;
    int max = nums.back();
    for(auto it = nums.end() -2 ; it >= nums.begin(); --it) {
        if(max <= *it) {
            max = *it;
        } else {
            sort(it + 1, nums.end());
            auto up = upper_bound(it + 1, nums.end(), *it);
            int tmp = *up;
            *up = *it;
            *it = tmp;
            return;
        }
    }
    sort(nums.begin(), nums.end());
    return;
}


int main(){
    vector<int> words;
    words.push_back(1);
    words.push_back(1);
    words.push_back(5);
    nextPermutation(words);
    for(auto i = words.begin(); i != words.end(); ++i)
        cout << *i <<endl;

    words.clear();

    return 1;
}
