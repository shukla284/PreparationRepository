
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description :  Sorted Squares of array
*/

vector<long long> getSquaresSortedNaive(vector<int>& a){
    vector<long long> res(a.size());
    for(int i = 0; i < a.size(); i++) 
    	res[i] = (a[i] * a[i]) ;
    sort(res.begin(), res.end());
    return res;
}

vector<long long> getSquaresSortedPointers(vector<int>& a){

	//Time Complexity : O(n)
	//Space Complexity : O(1)
	
    vector<long long> res;
    
    int pos = -1;
    for(int i = 0; i < a.size() - 1; i++)
    	  if(a[i] <= 0 && a[i + 1] > 0) {
    	  	  pos = i; break;
    	  }
   
    int ptr1, ptr2;
    if(pos == -1){
    	if(a[0] <= 0)
    		ptr1 = a.size()-1, ptr2 = a.size();
    	else 
    		ptr2 = 0, ptr1 = -1;
    }
    
    else 
    	ptr1 = pos, ptr2 = pos + 1;

    while (ptr1 >= 0 && ptr2 < a.size()){
    	if(abs(a[ptr1]) < abs(a[ptr2]))
    		res.emplace_back(a[ptr1] * a[ptr1]), ptr1--;
    	else
    		res.emplace_back(a[ptr2] * a[ptr2]), ptr2++;
    }

    while (ptr1 >= 0) 
    	res.emplace_back(a[ptr1] * a[ptr1]), ptr1--;

    while (ptr2 < a.size()) 
    	res.emplace_back(a[ptr2] * a[ptr2]), ptr2++;

    return res;

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

    auto res = getSquaresSortedPointers(a);
    for(auto i : res)
    	cout << i << " ";

    /*code ends here*/
    
    return 0;		
}