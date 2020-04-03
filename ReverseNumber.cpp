
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Reverse Number (including the negative numbers)
*/

int64_t reversedNumber(int64_t n){
    //first thing is to consider about the sign of the number; then perform any operations
    // in order to determine the sign the comparison with the zeroes is enough thing to consider.

    int sign = (n < 0) ? -1 : +1;
    int64_t res = 0; n = abs(n);

    while (n) 
        res = (res * 10) + (n % 10), n /= 10;
    
    return (sign == -1) ? -res : res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int64_t n; cin >> n;
    cout << reversedNumber(n) << endl;  
    
    return 0;		
} 