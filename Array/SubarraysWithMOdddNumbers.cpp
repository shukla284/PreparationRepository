
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Subarrays with m odd numbers
*/

int subarraysWithOdd_Naive(vector<int>& a, int m) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
    	for (int j = i; j < a.size(); j++){

    		int cnt = 0;
    	    for (int k = i; k <= j; k++)
    	    	 cnt += (a[k] & 1);

    	    res += (cnt == m);
    	}    
    }
    return res;
}

int subarraysWithOdd_AlterNaive(vector<int>& a, int m) {
   int res = 0;
   for (int i = 0; i < a.size(); i++) {
   	  int cnt = 0;
   	  for (int j = 0; j < a.size(); j++)
   	  	   cnt += (a[j] & 1), res += (cnt == m);
   }
   return res;
}

int subarraysWithOdd_Efficient(vector<int>& a, int m) {
    int res = 0, curr_odd = 0;
    vector<int> cnt_odd(a.size());
    
    for (int i = 0; i < a.size(); i++) {
    	cnt_odd[curr_odd]++;
    	curr_odd += (a[i] & 1);

    	if (curr_odd >= m)
    		 res += (cnt_odd[curr_odd - m]);
    }
    return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];

    cout << subarraysWithOdd_Efficient(a, m) << endl;
    return 0;		
}