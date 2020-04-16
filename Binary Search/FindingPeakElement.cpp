
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding peak element in series of number
*/

int peakElement(vector<int>& a) {
	int left = 0, right = a.size() -1;
	while (left <= right) {
       int mid = left + (right - left) / 2;

       if ((mid == 0) || (mid == a.size() - 1) || (a[mid] > a[mid + 1] && a[mid] > a[mid - 1]))
       	 return mid;

       else if (a[mid] < a[mid + 1])
         left = mid + 1;

       else 
         right = mid;  	
	}
	return -1;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;   
    
    cout << peakElement(a) << endl; 
    return 0;		
}