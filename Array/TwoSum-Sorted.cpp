
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Two Sum with sorted array
*/
pair<int,int> getSumPairs(vector<int>& a,int s) {
	int ptr1 = 0, ptr2 = a.size()-1;
	while (ptr1 < ptr2) {
		if(a[ptr1] + a[ptr2] < s)
			 ptr1++;
		else if(a[ptr1] + a[ptr2] > s)
		     ptr2--;	
		else
		     return make_pair(a[ptr1], a[ptr2]); 
	}
	return make_pair(-1,-1);
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
    
    int s; cin >> s;
    auto res = getSumPairs(a,s);

    cout << res.first << " " << res.second << endl;
    /*code ends here*/
    
    return 0;		
}