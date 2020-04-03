
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/

uint32_t reverseBitsNaive(uint32_t& n) {
    int i = 0, j = 31;
    while ( i < j ) {
    	if (((n >> i) & 1) != ((n >> j) & 1)) {
    		 int mask = (1 << i) | (1 << j);
    		 n ^= mask;


    	}
    	i++, j--;
    } 
    return n;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    uint32_t n; cin >> n;

    cout << bitset<32>(n) << endl;
    cout << reverseBitsNaive(n) << endl;
    cout << bitset<32>(n) << endl;

    return 0;		
}