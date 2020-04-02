
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Computing parity of large number of words
*/

int computeParityEfficient(int64_t x, unordered_map<int,int>& lookup) {
    //masking, shifting and calculating the parity one be one of mask_size
    const int mask = 0xFFFF, mask_size = 16;

    return lookup[(x >> (3 * mask_size))] ^ 
           lookup[mask & (x >> (2 * mask_size))] ^ 
           lookup[mask & (x >> mask_size)] ^ lookup[mask & x]; 
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int64_t x; cin >> x;
    unordered_map<int,int> lookup;

    // create lookup table
    // getting the number of set bits. 
    for (int i = 0, mask_size = 16; i < (1 << mask_size); i++)
        lookup[i] = (__builtin_popcount(i) & 1);
    
    
    // now shift and compute the partiy of the different parts of bit words 
    for(int i = 0; i < x; i++)
    	 cout << i << " " << computeParityEfficient(i, lookup) << endl;
    
    return 0;		
}