
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding minimum in rotated sorted array
*/

int minuimumSortedRotated(vector<int>& a) {

	int left = 0, right = a.size() - 1;
    
    if (a[left] < a[right])
        return a[left];

	while (left <= right) {
        int mid = left + (right - left) / 2;

		if (mid > 0 && a[mid] < a[mid - 1])
			 return a[mid];

        else if (mid < a.size() -1 && a[mid] > a[mid + 1]) 
        	return a[mid + 1];
        

        if (a[0] < a[mid])	
        	  left = mid + 1;
        else
              right = mid - 1;	
	}
	return -1;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << minuimumSortedRotated(a) << endl;

    return 0;		
}