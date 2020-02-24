
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Array Rotation
*/

vector<int> getRotated(vector<int>& a,int r) {
	vector<int> res(a.size());
	for(int i = 0; i < a.size(); i++)
        res[i] = a[(i+r) % a.size()];

	return res;
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int t; cin >> t;

    while (t--) {
       int n,r; cin >> n >> r;
       vector<int> a(n); 
       for(int i = 0; i < n; i++) 
         	cin >> a[i];

       auto res = getRotated(a,r);

       for(int i : res)
        	 cout << i << " ";
       cout << endl; 	
    }
    /*code ends here*/
    
    return 0;		
}