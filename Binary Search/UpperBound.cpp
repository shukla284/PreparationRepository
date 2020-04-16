
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding the upper bound
*/

int upperBound(vector<int>& a, int x) {
	int left = 0, right = a.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;

		if (a[mid] <= x)
			left = mid + 1;
		else 
			right = mid;
	}
	return left;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
       cin >> a[i];   
    
    cout << upperBound(a, x) << endl;
    return 0;		
}