
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/

int64_t swapBits(int64_t n, int i, int j) {

	//We will be swapping the bits iff they are different. 
    // We can 4 possibilities at ith and jth position. (1,1), (1,0), (0,0), (0,1)

    // Of these possibilities we have just to ensure the thins about (1,0) and (0, 1).

    if (((n >> i) & 1) != ((n >> j) & 1)) {
    	int64_t mask = (1 << i) | (1 << j);
       
        // XORing will flip the bits since xoring with 1 toggles the bit.
        // that is why we tested the bits in the first place to change if they are different.
    	n ^= mask;
    }
    return n;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, i, j; cin >> n >> i >> j;
    cout << swapBits(n, i,j); 
    
    return 0;		
}
