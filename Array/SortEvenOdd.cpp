
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/

void sortEvenOdd(vector<int>& a) {
	int e = 0, o = a.size() - 1;
	while ( e < o ) {
		if (a[e] % 2 == 0)
			 e++;
		else 
		     swap(a[e], a[o--]);	
	}
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) 
       cin >> i;

    sortEvenOdd(a);
    for (int i : a)
    	  cout << i << " ";

    return 0;		
}