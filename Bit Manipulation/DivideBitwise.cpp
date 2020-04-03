
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Calculating value of quotient of (n /m) using bitwise operator
*/


uint64_t divideBitwise(uint64_t n, uint64_t m) {
    uint64_t q = 0, pow = sizeof(n) * 8;
    uint64_t ly = (m << pow);

    while (n >= m) {
    	 while (ly > n) ly >>= 1, pow--;
    	 q += (1 << pow), n -= ly;
    }
    return q;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    uint64_t n, m; cin >> n >> m;

    if (m == 0)
    	 throw "Not a valid divisor";
    cout << divideBitwise(n, m) << endl;	
    
    return 0;		
}