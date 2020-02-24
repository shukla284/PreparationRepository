
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Find the common elements in 3 ayys (sorted)
*/


vector<int> getCommonElements(vector<int>& a,vector<int>& b,vector<int>& c) {
	
	vector<int> res;
    int ptr1 = 0, ptr2 = 0, ptr3 = 0;
    while (ptr1 < a.size() && ptr2 < b.size() && ptr3 < c.size()) {
        
        //cout << a[ptr1] << " " << b[ptr2] << " " << c[ptr3] << endl;
    	if(a[ptr1] == b[ptr2] && a[ptr1] == c[ptr3]){
           res.push_back(a[ptr1]); 
           ptr1++, ptr2++, ptr3++; 
    	}

    	else {
    		if(a[ptr1] <= b[ptr2] && a[ptr1] <= c[ptr3])
    			ptr1++;
    		else if(b[ptr2] <= a[ptr1] && b[ptr2] <= c[ptr3])
    			ptr2++;
    		else if(c[ptr3] <= a[ptr1] && c[ptr3] <= b[ptr2])
    			ptr3++;
    	}
    }
	return res;
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n,m,o; cin >> n >> m >> o;
    vector<int> a(n), b(m), c(o);
    for(int i = 0; i < n; i++) 
    	cin >> a[i];
    for(int i = 0; i < m; i++)
    	cin >> b[i];
    for(int i = 0; i < o; i++) 
    	cin >> c[i];
    
    auto res = getCommonElements(a,b,c);
    for(int i : res)
    	 cout << i << " ";
    /*code ends here*/
    
    return 0;		
}
