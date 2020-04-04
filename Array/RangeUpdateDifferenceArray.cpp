
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/

vector<int> createDifferenceArray(vector<int>& a) {
    vector<int> dif(a.size() + 1, 0);
    dif[0] = a[0]; 
    for (int i = 1; i < a.size(); i++)
         dif[i] = (a[i] - a[i - 1]);

    return dif;      
}

vector<int> createResultArray(vector<int>& a, vector<int>& dif) {
    a[0] = dif[0];
    for (int i = 1; i < a.size(); i++) 
    	a[i] = dif[i] + a[i - 1];
    return a;
}

void updateDifferenceArray(vector<int>& dif, int l, int r, int x) {
    dif[l] += x, dif[r + 1] -= x;
} 

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    auto dif = createDifferenceArray(a);

    int q; cin >> q;
    while (q--) {
    	// assuming 0 based indexing
    	int l, r, x; cin >> l >> r >> x;

    	updateDifferenceArray(dif, l, r, x);
    }
    
    auto res = createResultArray(a, dif);
    for (int i : res)
    	 cout << i << " ";

    return 0;		
}