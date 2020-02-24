#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Find the Kth largest element in array
*/


int findKthSmallestNaive(vector<int>& a,int k){
	
    //Naive Approach : Sort the array and return the Kth value in array
	sort(a.begin(), a.end());
    return a[k-1];
}

int findKthSmallestHashed(vector<int>& a,int k){

    //Approach : Hashing here we need to hash the array elements to hash array
    //later on we can get the smallest Kth element just by visiting through a for loop
    vector<int> hsh(1e5+10, 0);
    for(int i = 0; i < a.size(); i++) 
        hsh[a[i]] += 1;
    
    int cnt = 0;
    for(int i = 0; i < hsh.size();i++) {
        cnt += hsh[i];

        cout << "Value of count " << i << " " << cnt << endl;
        if (cnt >= k)
             return i;
    }
    return -1;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    
    int t; cin >> t;

    while (t--) {
        int n,k; cin >> n;
        vector<int> a(n); 
        for(int i = 0; i < n; i++)      
            cin >> a[i];

        cin >> k;
        cout << findKthSmallestHashed(a,k) << endl;    
    }
    /*code ends here*/
    
    return 0;		
}