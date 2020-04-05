
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum Subarray Sum
*/

int maxSubarraySum(vector<int>& a) {
	int curr = 0, mx = 0;
	for (int i = 0; i < a.size(); i++) {
		curr = max(curr + a[i], 0);
		mx = max(mx, curr);
	}
	return mx;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
       cin >> a[i];

    cout << maxSubarraySum(a) << endl;
    return 0;		
}