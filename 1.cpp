#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> v;
	map<int, int> m;
	for(int i = 0; i < numbers.size(); ++i) 
		m[numbers[i]] = i;
	for(int i = 0;i<numbers.size() - 1;++i) {
		int left = target - numbers[i];
		map<int, int>::iterator it = m.find(left);
		if(it != m.end() && i < it->second) {
			v.push_back(i+1);
			v.push_back(it->second + 1);
			break;
		}
	}
	return v;
}

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(12);
	v.push_back(14);
	v.push_back(15);
	v.push_back(20);
	
	vector<int> r = twoSum(v, 27);
	cout<<r.size()<<r[0]<<r[1];

	return 1;
}
