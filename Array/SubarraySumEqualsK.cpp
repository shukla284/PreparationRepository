
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Subarray Sum that are equal to K
*/

int subarraySumEqualsK_Naive(vector<int>& a, int k) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < a.size(); j++) {
			int sub_sum = 0;
            
            // take the case of the subarray i to j and calculat the sum for it.
			for (int m = i; m <= j; m++)
				 sub_sum += a[m];
            
            // increment the result if there are required sum K found
			res += (sub_sum == k);
		}
	}
	return res;
}

int subarraySumEqualsK_Efficient(vector<int>& a, int k) {
	int res = 0, curr_sum = 0;
	unordered_map<int,int> cnt_sum;

	for (int i = 0; i < a.size(); i++) {
		// Maintain the current sum of the array traversal
		curr_sum += a[i];

		// find it out if any such sum exists beforehand, if yes then result would
		// be updated since we can use that subarray to make up that sum as well.
		if (cnt_sum.find(curr_sum - k) != cnt_sum.end())
			 res += cnt_sum[(curr_sum - k)];
        
        // update the map corresposndiing to the current sum
		cnt_sum[curr_sum]++	;
	}
    
    // the result would be also including the required itself.
	res += cnt_sum[k];
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

    cout << subarraySumEqualsK_Naive(a, k) << endl;
    return 0;		
}