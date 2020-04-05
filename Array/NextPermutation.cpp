
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/

void nextPermuatation(vector<int>& a) {
	int pos = 0;
	for (int i = 1; i < a.size(); i++)
		  if (a[i - 1] < a[i]) pos = i;
	
	if (pos) {
       pos--; int nl = 0;
		for (int i = a.size() - 1; i >= pos; i-- )
	    	if (a[pos] < a[i]) {nl = i; break;} 	
	    swap(a[pos], a[nl]);
	    pos++;
	}
	reverse(a.begin()+ pos, a.end());
}	

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
       cin >> a[i];

    nextPermuatation(a);
    for(int i : a)
    	  cout << i << " ";

    return 0;		
}