
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Searching in rotated sorted array
*/

int searchRotatedSorted(vector<int>& a, int x) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
    	int mid = left + (right - left) / 2;

    	if (a[mid] == x)
    		return mid;
    	
    	if (a[left] <= a[mid]) {
    		if (x <= a[mid] && x >= a[left])
    			 right = mid - 1;
    		else 
    		     left = mid + 1;	
    	}

    	else {
    		if (x <= a[right] && a[mid] <= x)
    			 left = mid + 1;
    		else 
    		     right = mid - 1;	
    	} 	
    }
    return -1;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << searchRotatedSorted(a, x) << endl;

    return 0;		
}