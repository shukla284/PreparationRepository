
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Sum of all subsequences of array
*/


int sumAllSubsequences(vector<int>& a) {
    // Number of subsequences in which an element can appear = 2 ^ (n - 1)
    // Since each of the time in subsequnes either that element will be present or not
    // so there is exactly two possibilities for each element at all : 2

    int64_t res = 0;
    for (int i = 0; i < a.size(); i++)
    	 res += (1 << (a.size() - 1)) * a[i];
    return res;	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
       cin >> a[i];

    cout << sumAllSubsequences(a) << endl;

    return 0;		
}