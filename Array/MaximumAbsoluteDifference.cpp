
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum Absolute difference (values and indices)
*/

int maximumAbsoluteDifference(vector<int>& a) {
    int mx1 = numeric_limits<int>::min(), mx2 = numeric_limits<int>::min();
    int mn1 = numeric_limits<int>::max(), mn2 = numeric_limits<int>::max();

    for (int i = 0; i < a.size(); i++) {
    	mx1 = max(mx1, a[i] + i);
    	mn1 = min(mn1, a[i] + i);
    	mx2 = max(mx2, a[i] - i);
    	mn2 = min(mn2, a[i] - i);
    }

    return max(mx1 - mn1, mx2 - mn2);
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n); 
    for(int i = 0; i < n; i++)
       cin >> a[i];

    cout << maximumAbsoluteDifference(a) << endl;

    return 0;		
}