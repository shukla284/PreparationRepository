
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


vector<int> getIntersection(vector<int>& a,vector<int>& b){
	vector<int> res;
	int ptr1 = 0, ptr2 = 0;

	while (ptr1 < a.size() && ptr2 < b.size()) {
		if(a[ptr1] == b[ptr2])
			 res.push_back(a[ptr1]), ptr1++, ptr2++;
		else {
			if(a[ptr1] <= b[ptr2])
				ptr1++;
			else
				ptr2++;
		}	
	}
	return res;
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++)
       cin >> a[i];
    for(int i = 0; i < m; i++)
       cin >> b[i];

    auto res = getIntersection(a,b);
    for(int i : res)
       cout << i << " ";

    /*code ends here*/
    
    return 0;		
}