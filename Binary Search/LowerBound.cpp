
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding the lower bound of a number in array
*/

// Lower bound can be understood as lowest position where the element can be inserted
// without distrubing the order of the array.
int lowerBound(vector<int>& a, int x) {
	int left = 0, right = a.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
        
        // If my present element is greater then the answer will be at left.
		if (a[mid] >= x) 
		   right = mid;
		else
		   left = mid + 1;    
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
    
    cout << lowerBound(a, x) << endl;
    return 0;		
}