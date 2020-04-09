
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Number of Subarray with given XOR
*/

int suabrrayWithGivenXOR_Naive(vector<int>& a, int k){
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
    	int curr_xor = 0;
    	for (int j = i; j < a.size(); j++)
    		 curr_xor = curr_xor xor a[j], res += (curr_xor == k);
    }
    return res;
}

int suabrrayWithGivenXOR_Efficient(vector<int>& a, int k) {
	int res = 0, curr_xor = 0;
	unordered_map<int,int> cnt_xor;
    
    // Iterate for all the elements in array
	for (int i = 0; i < a.size(); i++) {

		// XOR value till the current prefix
        curr_xor ^= a[i];

        // if there is some deformity that is the difference from the usual then try to
        // find the irregulairity of that XOR if found anywhere before since that will form the next beginnning.
        if (cnt_xor.find(curr_xor ^ k) != cnt_xor.end())
        	res += cnt_xor[curr_xor ^ k];

        cnt_xor[curr_xor]++;
	}
    
    // add the XORs which are directly equal to the required value.
	res += cnt_xor[k];
	return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << suabrrayWithGivenXOR_Efficient(a, k) << endl;

    return 0;		
}