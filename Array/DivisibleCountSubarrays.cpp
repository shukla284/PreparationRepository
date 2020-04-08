
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Count Subarrays divisible by k
*/

int countSubarraysDivisible(vector<int>& a, int k) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < a.size(); j++) {
			int64_t prod = 1;
            for (int k = i; k <= j; k++)
            	 prod *= a[k];

            if (prod % k == 0)
               cnt++;	
		}
	}
	return cnt;
}
 
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int&  i : a)
       cin >> i;
   
    cout << countSubarraysDivisible(a, k) << endl;

    return 0;		
}