
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Cloasest integer with same weight such that
              if y is answer then x != y, |x - y| = min, weight (x) = weight (y)
*/

uint64_t closestIntegerWeighted(uint64_t n) {
	const int size = sizeof(n) * 8; 

	// We would try to minimize the differing bits that we wish to exchange.
	// In order to find such a bit we need to go thrugh the bit size and get the reversal done.
	for (int i = 0; i < size; i++) 
		 if (((n >> i) & 1) != ((n >> (i + 1) ) & 1)) {
		 	n ^= (1 << i) | (1 << (i + 1));
            return n;
         }
    cout << "Invalid Number : no differing bits found";
    return 0;     
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int64_t n; cin >> n;
    cout << bitset<64>(n) << endl;
    auto res = closestIntegerWeighted(n);
    cout << bitset<64>(res) << endl;
    cout << res << endl;
    
    return 0;		
}