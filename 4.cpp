#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
using namespace std;

int findK(int a[], int p, int q, int b[], int x, int y, int k) {
cout<< p<< ", "<<q<< ", "<<x<<" , "<<y<<" , "<<k<<endl;
    if(p >= q)
        return b[x + k];
    else if(x >= y)
        return a[p + k];
    int ma = (q - p) >> 1;
    int *pt = std::lower_bound (b+x, b+y, a[p + ma]);
    int mb = pt - b - x;
cout<<ma<<" , "<<mb<<endl;
    if(ma + mb == k)
        return a[p + ma];
    else if(ma + mb  < k)
        return findK(a, p+ma+1, q, b, x+mb, y, k -ma -mb -1);
    else   
        return findK(a, p, p+ma,  b,x,  x+mb, k);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    bool b = (m + n) % 2;
    int mid = (m + n) >> 1;
    if(b) 
        return findK(A, 0, m, B, 0, n, mid);
    else
        return (findK(A, 0, m, B, 0, n, mid) + findK(A, 0, m, B, 0, n, mid - 1) ) / 2.0;
    
    
}

int main(){
    //int a[] = {1, 2, 3, 4,5, 6, 7};
    int a[] = {1, 2, 3, 4, 6};
    //int b[] = {4,5, 6, 7, 8, 19 , 28, 29, 30,31};
    int b[] = {5};
    cout<<findMedianSortedArrays(a, 5, b, 1);
	return 1;
}
