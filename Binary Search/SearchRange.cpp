
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Range search for an element
*/

int getInitialLimit(vector<int>& a, int x) {
   int left = 0, right = a.size() - 1, ans = -1;
   while (left <= right) {
      int mid = left + (right - left) / 2;

      if (a[mid] == x) {
      	 ans = mid, right = mid - 1;
      }

      else if (a[mid] < x)
      	 left = mid + 1;
      else
         right = mid - 1;	
   }
   return ans;
}

int getFinalLimit(vector<int>& a, int x) {
   int left = 0, right = a.size() - 1, ans = -1;
   while (left <= right) {
   	  int mid = left + (right - left) / 2;

   	  if (a[mid] == x) {
   	  	 ans = mid, left = mid + 1;
   	  }
   	  else if (a[mid] < x)
   	  	 left = mid + 1;
   	  else
   	     right = mid - 1;	
   }
   return ans;
}

pair<int, int> rangeSearch(vector<int>& a, int x) {
   pair<int,int> res_idx = {-1,-1};
   res_idx.first = getInitialLimit(a, x);
   res_idx.second = getFinalLimit(a, x);

   return res_idx;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];   
    

    auto res = rangeSearch(a, x);
    cout << res.first << " " << res.second << endl;
    return 0;		
}