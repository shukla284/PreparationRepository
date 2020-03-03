
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Double Repeated Elements
*/

pair<int,int> getDoubleRepeatedElements(vector<int>& a){
	int xorr = 0;
	int n = a.size() - 2;
	
    // XORing all the elements of the array.
	for(int i = 0; i < a.size(); i++)
		 xorr ^= a[i];
    
    //Range of the elements to take in array : 1 to n
	// Distinct elements : n-2
	//XORing with the original numbers in order to counter the elements repeated twice
		
	for(int i = 1; i <= n; i++)
	    xorr ^= i;

    // Till now we got the res.first ^ res.second
    // Now the problem is similar to the no repated problem.

    // get the different sets based on the masb
    // getting the MSB using relation : xorr & ~(xorr - 1)
    
    int msb = (xorr & ~(xorr - 1));
    
    pair<int,int> res = make_pair(0,0);

    for(int i = 0; i < a.size(); i++)        
    	if (msb & a[i])
    		res.first ^= a[i];
    	else
    		res.second ^= a[i];
    
    for(int i = 1; i <= n; i++)
    	if (msb & i)
    		res.first ^= i;
    	else
    		res.second ^= i;

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

    auto res = getDoubleRepeatedElements(a);
    cout << res.first << " " << res.second << endl;

    /*code ends here*/
    
    return 0;		
}