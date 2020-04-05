
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, m; cin >> n >> m;
    vector<int> a(n,0), d(a.size() + 1, 0);
    d[0] = a[0];
  
    vector<pair<pair<int,int>, int>> b(m);
    for(int i = 0; i < m;  i++) 
       cin >> b[i].first.first >> b[i].first.second >> b[i].second;

    for(int i = 0; i < m; i++) {
    	d[b[i].first.first - 1] += b[i].second, d[b[i].first.second] -= b[i].second; 

    }
    
    a[0] = d[0];
    for (int i = 1; i < a.size(); i++) 
        a[i] = d[i] + a[i - 1];
    
    for (int i = 0; i < a.size(); i++)
    	 cout << a[i] << " ";

    return 0;		
}