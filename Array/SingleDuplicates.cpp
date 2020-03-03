
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Single Repeated Element
*/

int getSingleDuplicate(vector<int>& a){
	long long sum = 0;

	// Range of elements: 1 - n
	// Total number of elements : n + 1 = a.size()
	int n = a.size() - 1;
	for(int i = 0; i < a.size(); i++)
		 sum += a[i];
    return (sum - ((n * (n + 1) ) >> 1));
}

int getSingleDuplicateXOR(vector<int>& a){
    int xorr = 0;
    for(int i = 0; i < a.size(); i++)
       xorr ^= a[i];

    for(int i = 1; i < a.size(); i++)
       xorr ^= i;

    return xorr;
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

    cout << getSingleDuplicateXOR(a) << endl;        
    /*code ends here*/
    
    return 0;		
}