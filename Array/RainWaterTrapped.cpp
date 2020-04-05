
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Rain Water Trapped problem
*/

int waterTrapped(vector<int>& a) {
	int64_t ans = 0;

	for (int i = 0; i < a.size(); i++) {
		int lmx = 0, rmx = 0;
		for (int j = i - 1; j >=0; j--)
			 lmx = max(lmx, a[j]);
		for(int j = i + 1; j < a.size(); j++)
             rmx = max(rmx, a[j]);

        if (min(lmx, rmx) > a[i])
        	ans += min(lmx, rmx) - a[i];
        //cout << ans << endl;    
	}
	return ans;
}

int waterTrappedSingleInnerIteration(vector<int>& a) {
    int ans = 0, lmx = 0;

    for (int i = 0; i < a.size(); i++) {
    	int rmx = 0;

    	lmx = max(lmx, a[i]);
        for (int j = i + 1; j < a.size(); j++)
        	 rmx = max(rmx, a[j]);

        if (min(lmx, rmx) > a[i])
             ans += min(lmx, rmx) - a[i];    	 
    }
    return ans;
}


int waterTrappedSingleInnerImproved(vector<int>& a) {
    int ans = 0, lmx = 0;

    vector<int> rmx(a.size(), 0); 
    rmx[a.size() - 1] = a[a.size() - 1];
      
    for (int i = a.size() - 2; i >= 0; i--) 
         rmx[i] = max(a[i], rmx[i + 1]);
    
    for (int  i = 1; i < a.size() - 1; i++) {
    	if (min(lmx, rmx[i + 1]) > a[i])
    		 ans += min(lmx, rmx[i + 1]) - a[i];

        lmx = max(lmx, a[i]);
    }
    return ans;
}

int waterTrappedSpaceEfficient(vector<int>& a) {
    // setting up the pointers : these will help to find the direction of water deposit
    // if there's the right boundary that can hold the water  (height[left] < height[right])
    // then we need to use this boundary using left boundary since it is smaller.

    // The vice versa case that is if our right boundary isn't that competent then
    // height[left] >= height[right] which may be a case that may counter the previous condition
    // this means that we need to use the right boundary for our purpose and that may only happen if we
    // have the view over the right pointer as well. 
    int lmax = 0, rmax = 0, left = 0, right = a.size() - 1, trap = 0;

    while (left < right) {
        if (a[left] < a[right]) {
            
            // if it is smaller than left maximum then use it to trap
            if (lmax > a[left]) 
            	 trap += (lmax - a[left]);
            else
                 lmax = max(lmax, a[left]);
            left++;     	
        }

        else {
        	// if it is smaller then use it for trap
            if (rmax > a[right])
            	 trap += (rmax - a[right]);
            else
                 rmax = max(rmax, a[right]);
            right--;     	
        }
    }
    return trap;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    cout << waterTrappedSpaceEfficient(h) << endl;       
    
    return 0;		
}