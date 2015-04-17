#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

string convert(string s, int nRows) {
    if(nRows < 2)
        return s;
    string r;
    int n = s.size() / ( 2 * nRows - 2) + (s.size () %  ( 2 * nRows - 2) == 0 ? 0 : 1);
    for(int i = 0 ; i< nRows ; i++) {
        for(int j = 0; j < n; ++j) {
            if(i == 0){
                r += s[(2*nRows - 2) * j];
            } else {
                int left =   ( 2 * nRows - 2) * j + i ;
                int right =   ( 2 * nRows - 2) * (j + 1) - i;
                if( left < s.size())
                    r += s[left];
                if(right > left && right < s.size())
                    r += s[right];
            }
        }    
    }
    return r;
}

int main(){
    string s("PAYPALISHIRING");
    cout<<convert(s, 3);
	return 1;
}
