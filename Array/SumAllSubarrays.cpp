
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Sum of all subarrays 
*/

int sumAllSubarraysNaive(vector<int>& a) {
	int64_t res = 0;
	for (int i = 0; i < a.size(); i++) {
		int sub_sum = 0;
		for (int j = i; j < a.size(); j++) {
			// sum of subarray starting from i and ending at j
			// running a for loop for the same

			sub_sum += a[j];
			res += sub_sum;
		}
	}
	return res;
}

int sumAllSubarraysPrefixSum(vector<int>& a) {
	vector<int64_t> pre(a.size(), 0);
	int64_t res = 0;

	for (int i = 0; i < a.size(); i++)
		 pre[i] = (i == 0) ? a[0] : pre[i - 1] + a[i];

	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < a.size(); j++) 
			 res += (i == 0) ? pre[j] : pre[j] - pre[i - 1];
	}	
	return res;
}

int sumAllSubarraysEfficient(vector<int>& a) {
    int64_t res = 0;

    // there will be exactly (i + 1) starting point of all the subarrays possible 
    // that can contain the ith element, while there would be exactly (n - i) ending points

    // Time complexity : O(n)
    // Space Complexity : O(1)

    for (int i = 0; i < a.size(); i++) 
    	 res += (a[i] * (i + 1) * (a.size() - i));
    return res;	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << sumAllSubarraysEfficient(a) << endl;
    return 0;		
}