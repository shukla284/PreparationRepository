
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : First Bad Version (Leetcode)
*/

int badVersion;

int isBadVersion(int x) {
	return (badVersion <= x);
}

int firstBadVersion(int n) {
    int left = 0, right = n, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid) && !isBadVersion(mid - 1))
        	return mid;

        else if (isBadVersion(mid))
        	right = mid - 1;

        else 
            left = mid + 1;
    }
    return ans;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    
    badVersion = rand() % n;
    cout << "Present bad version " << badVersion << endl;
    cout << firstBadVersion(n) << endl;
    return 0;		
}