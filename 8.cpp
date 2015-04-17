#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int atoi(string str) {
    if(str.empty())
        return 0;
    int j = 0;
    bool f = true;
    while(str[j] == ' '| str[j] == '\t')
        ++j;
    if(str[j] == '-') {
        ++j;
        f = false;
    } else if(str[j] == '+') {
        ++j;
    }
    double r = 0;
    int max = ~(1 << (sizeof(int)* 8 - 1) );
    int i = str.size() - 1;
    while(str[i] == ' '| str[i] == '\t')
        --i;
    for(;j <= i; ++j) {
        if(str[j] >= '0' && str[j] <= '9')
            r = r*10 + str[j] - '0';
        else
            break;
   }
    if(f && r > max)
        return max;
    if(!f && r > max)
        r = max + 1;
    if(!f)
        r *= -1;
    return r;
}

int main(){
    cout<<atoi("    10522545459")<<endl;
	return 1;
}
