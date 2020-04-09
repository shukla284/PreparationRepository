
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Number of subarray having the product less than k
*/


int subarrayProductLessThanK_Naive(vector<int>& a, int k) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {

    	int64_t mul = 1;
    	for (int j = i; j < a.size(); j++) {
    		mul *= a[j];

    		if (mul < k)
    			  res++;
    		else
    		     break;	
    	}	
    }
    return res;
}

int subarrayProductLessThanK_SlidingWindow(vector<int>& a, int k) {
	int res = 0, left = 0, right = 0;
	int64_t pro = a[left];

	while (left < a.size() && right < a.size()) {

        if (pro < k) {
        	right++;

        	if (right >= left)
        		res += (right - left);
        	if (right < a.size())
                pro *= a[right];
        }

        else 
        	pro /= a[left], left++;
	}
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

    cout << subarrayProductLessThanK_SlidingWindow(a, k) << endl;
    return 0;		
}