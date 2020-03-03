
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Find two non repeating numbers.
*/

pair<int,int> getNonDuplicates(vector<int>& a){
	int xorr = 0;
	pair<int,int> res = make_pair(0,0);

	for(int i = 0; i < a.size(); i++)
		 xorr ^= a[i];

	// res.first ^ res.second = xorr till now
	//find first significant bit in order to partition the numbers into two different sets
    
    // Correctness : The xorr cannot be zero since there are two elements with different bits.
	// Since it is not zero there will be at least one significant bit.	
    int msb_dist = xorr & ~(xorr - 1);

    //Now start the partition, in each partition there will be only one element, which is not repeated.
    // Since the xorr isn't zero there must be significant bit which differentiates them.
    for(int i = 0; i < a.size(); i++)
       if (a[i] & msb_dist)
           res.first ^= a[i];
       else
           res.second ^= a[i];

    return res;           		
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	 cin >> a[i];

    auto res = getNonDuplicates(a);
    cout << res.first << " " << res.second << endl;

    /*code ends here*/
    
    return 0;		
}