
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding K closest elements
*/


int getHighestIndex(vector<int>& a, int x) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
    	int mid = left + (right - left) / 2;

    	if (x >= a[mid])
    		left = mid + 1;
    	else 
    		right = mid - 1;
    } 
    return left;
}

int getLowestIndex(vector<int>& a, int x) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
    	int mid = left + (right - left) / 2;

    	if (a[mid] >= x)
    	    right = mid - 1;
    	else 
    		left = mid + 1;
    }
    return left;
}

vector<int> findingKClosest(vector<int>& a, int k, int x) {
	if (a.size() <= k)
		 return a;

    int idx = getLowestIndex(a, x);
    
    int left = idx - 1 , right = idx;
    cout << idx << endl;
    cout << left << " " << right << endl;

    vector<int> res;

    while (k) {
    	// getting the closer of the two elements.
    	int leftDiff = (left >= 0) ? abs(a[left] - x) : numeric_limits<int>::max();
    	int rightDiff = (right < a.size()) ? abs(a[right] - x) : numeric_limits<int>::max();
        
    	if (leftDiff <= rightDiff)
    		left--;
    	else
    		right++;
    	k--;
    }

    for (int i = left + 1; i < right; i++)
    	 res.emplace_back((a[i]));

    return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
       cin >> a[i];    
    
    auto res = findingKClosest(a, k, x);
    for (int i : res)
    	 cout << i << " ";

    return 0;		
}