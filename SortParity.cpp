
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Parity wise Sorting
*/


vector<int> sortParityNaive(vector<int>& a){

	//Space Complexity : O(n)
	//Time Complexity : O(nlogn) 

    vector<pair<int,int>> par(a.size());
    for(int i = 0; i < a.size(); i++) 
         par[i] = make_pair(a[i] % 2, i);
    sort(par.begin(), par.end());
    
    for(int i = 0; i < a.size(); i++) 
    	  cout << par[i].first << " " << a[par[i].second] << endl;

    vector<int> res(a.size());
    for(int i = 0; i < par.size(); i++)
       res[i] = a[par[i].second];
    
    return res;    
}

vector<int> sortParityPointers(vector<int>& a){
    int ptr1 = 0, ptr2 = a.size()-1;

    while (ptr1 < ptr2) {
    	if (a[ptr1] % 2 == 0 && a[ptr2] % 2 == 0)
    		ptr1++;
    	else if(a[ptr1] % 2 != 0 && a[ptr2] % 2 != 0)
            ptr2--;
        else if(a[ptr1] % 2 == 0 && a[ptr2] % 2 != 0)
        	ptr1++, ptr2--;
        else if(a[ptr1] % 2 != 0 && a[ptr2] % 2 == 0){
        	swap(a[ptr1], a[ptr2]); ptr1++, ptr2--;
        }
    }
    return a;
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

    auto res = sortParityPointers(a);
    for(int i : res)
    	 cout << i << " ";

    /*code ends here*/
    
    return 0;		
}