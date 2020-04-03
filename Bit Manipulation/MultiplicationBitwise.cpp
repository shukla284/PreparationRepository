
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Multiply two unsigned integers without using arithmetic operations.
              We cannot use multiply, add, sub, divide, comparison for our cause.
*/


uint64_t addBitwise(uint64_t n, uint64_t m) {
    uint64_t carry;
    while (m) {
       carry = (n & m);
       n = (n ^ m); m = carry << 1;
    }
    return n;
}

uint64_t multiplyBitwise(uint64_t n, uint64_t m) {
    uint64_t res = 0;

    while (n) {
    	if (n & 1) 
    		 res = addBitwise(res, m);
    	n >>= 1, m <<= 1;	
    }
    return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    uint64_t n, m; cin >> n >> m;
    cout << multiplyBitwise(n, m) << endl;   
    
    return 0;		
}