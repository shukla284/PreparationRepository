
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n; 
    cout << bitset<8>(n) << endl;

    //We will be swapping the bits iff they are different. 
    // We can 4 possibilities at ith and jth position. (1,1), (1,0), (0,0), (0,1)

    // Of these possibilities we have just to ensure the thins about (1,0) and (0, 1).

    int i, j; cin >> i >> j;
    // once the bits are taken we can extract out the bits at these positions as well.
    
    
    if (((n >> i) & 1) != ((n >> j) & 1)){
    	int mask = (1 << i) | (1 << j); n ^= mask;
    }

    cout << n << endl;
    cout << bitset<8>(n) << endl;
    return 0;		
}