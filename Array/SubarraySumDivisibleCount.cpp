
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Count Subarrays with sum divisible by k
*/

int countSubarraySumDivisible(vector<int>& a,int k) {
   // current sum for the iterations 
   int curr_sum = 0;
   
   // counting remainders : initilised to 0
   vector<int> mods(k,0);

   for (int i = 0; i < a.size(); i++)
   	    curr_sum += a[i], mods[((curr_sum % k) + k) % k]++;
   
   int res = 0;

   // adding the combinations of the limits using C(n, 2)
   for (int i = 0; i < k; i++)
   	   if (mods[i])
   	   	   res += (mods[i] * (mods[i] - 1)) >> 1;

   // add the divisible sums directly	   	
   res += mods[0];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    	  cin >> a[i];

    cout << countSubarraySumDivisible(a, k) << endl;
    return 0;		
}