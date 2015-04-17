#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int reverse(int x) {
    bool f = x < 0;
    if(f)
        x *= -1;
    int r = 0;
    while(x) {
        int t = r;
        r *= 10;
        if(t != r / 10)
            return 0;
        r += x % 10;
        x /= 10;
    }
    if(f)
        r *= -1;
    return r;
}

int main(){
    cout<<reverse(1534236469)<<endl;
    cout<<reverse(153423);
    cout<<reverse(-123);
    cout<<reverse(0);
	return 1;
}
