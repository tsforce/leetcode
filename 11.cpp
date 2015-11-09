#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int maxArea(vector<int>& height) {
    if (height.size() < 2 )
        return 0;
    int i = 0, j = height.size() -1;
    int max = 0;
    while(i < j) {
        if (height[i] <= 0) {
            ++i;
            continue;
        }
        if(height[j] <= 0) {
            --j;
            continue;
        }
        int h = height[i] < height[j] ? height[i] : height[j];
        int a = h * (j - i);
        max = max > a ? max : a;
        if (height[i] < height[j])
            ++i;
        else
            --j;
    }
    return max;
}

int main(){
    /*
    cout<<isMatch("aa","a")<<endl;
    cout<<   isMatch("aa","aa") <<endl;
    cout<<   isMatch("aaa","aa")<<endl;
    cout<<   isMatch("aa", "a*")<<endl;
    cout<<   isMatch("aa", ".*")<<endl;
    cout<<   isMatch("ab", ".*")<<endl;
    */
	return 1;
}
