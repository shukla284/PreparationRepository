
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Degree of Array (leetcode)
*/


int degreeSubarrayHashing(vector<int>& a){

   //Time Complexity : O(nlog(n))
   //Space Complexity : O(n)

   map<int,int> fidx, lidx;
   map<int,int> freq;

   int mx = numeric_limits<int>::max();
   for(int i = 0; i < a.size(); i++){
   	  freq[a[i]]++;
      if(fidx.find(a[i]) == fidx.end())
      	 fidx[a[i]] = i;
   }

   for(int i = a.size()-1; i >= 0; i--)
   	  if(lidx.find(a[i]) == lidx.end())
   	  	lidx[a[i]] = i;
   
   int mxf = -1;   
   for(auto i : freq)
      mxf = max(mxf, i.second);

   for(auto i : freq){
   	  if(i.second == mxf)
   	  	 mx = min(mx, lidx[i.first] - fidx[i.first] + 1);	
   }
   return mx;
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
    cout << degreeSubarrayHashing(a) << endl;

    /*code ends here*/
    
    return 0;		
}