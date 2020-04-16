
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding the square root of X to nearest integer.
*/

int squareRootInteger(int n) {
	if (n < 0)
		  return -1;
		
	int left = 0, right = n;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if ((mid * mid) <= n && (mid + 1) * (mid + 1) > n)
			 return mid;

		else if ((mid * mid) < n)
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
    cout << squareRootInteger(n) << endl;    
    
    return 0;		
}