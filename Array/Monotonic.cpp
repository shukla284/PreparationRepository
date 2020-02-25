
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description :  Monottonic Array
*/

bool testIncreasing(vector<int>& a){
    for(int i = 0; i < a.size() - 1; i++)
    	 if(a[i] > a[i + 1])
    	 	return false;
    return true;	 
}

bool testDecreasing(vector<int>& a){
    for(int i = 0; i < a.size() - 1; i++)
    	 if(a[i] < a[i + 1])
    	 	return false;
    return true;	 
}

int testMonotonic(vector<int>& a){
	return testIncreasing(a) || testDecreasing(a);
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
       cin >> a[i];

    cout << testMonotonic(a) << endl;     
    /*code ends here*/
    
    return 0;		
}