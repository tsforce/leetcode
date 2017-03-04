#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<limits.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;
    else if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    else if(dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    else if(divisor > dividend && dividend >=0)
        return 0;
    else if(divisor < dividend && dividend <=0)
        return 0;
    if (divisor == INT_MIN && dividend == INT_MIN)
        return 1;
    else if (divisor == INT_MIN)
        return 0;
    bool minus = false;
    int sum = 0;
    if (dividend < 0 && divisor < 0) {
        if (dividend == INT_MIN) {
            sum = 1;
            dividend = divisor - dividend;
        } else {
            dividend = 0- dividend;
        }
        divisor = 0 - divisor;
    } else if (dividend < 0) {
        minus = true;
        if (dividend == INT_MIN) {
            sum = 1;
            dividend = 0 - divisor - dividend;  
        } else {
            dividend = 0- dividend;
        }
    } else if (divisor < 0) {      
        minus = true;    
        divisor = 0 - divisor;
    }
    int i = divisor, j = 1;
    while (i <= dividend && i << 1 > 0) {
        i = i << 1;
        j = j << 1;
    }
    while (j > 0 && dividend > 0) {
        if(dividend >= i) {
            sum += j;
            dividend -= i;
        }
        i = i >> 1;
        j = j >> 1;
    }
    if (minus) 
        sum = 0 - sum;
    return sum;
}

int main(){
    /*
    cout<<strStr("mississippi", "issip")<<endl;
    cout<<strStr("abcdef", "cdf")<<endl;
    cout<<strStr("abcdefadflkkjasjflaskdfjaldf", "cdf")<<endl;
    cout<<strStr("abcdefadflkkjasjflaskdefjaldf", "defj")<<endl;
    */
    cout<<divide(2147483647,2)<<endl;
    cout<<divide(-2147483647, 2) <<endl;
    cout<<divide(-2147483648, 2) <<endl;  
    cout<<divide(-2147483648, 3) <<endl;  
    cout<<divide(-2147483647, -2147483647) <<endl;
    cout<<divide(-1020450018,2091335377) <<endl;
    cout<<divide(3, -10) <<endl;
    cout<<divide(-8, 4) <<endl;
    cout<<divide(-8, -4) <<endl;
    cout<<divide(801, -4) <<endl;
    cout<<divide(801, 0) <<endl;
	return 1;
}
