
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Number of subarrays with even sum
*/

int subarrayEvenSum_Naive(vector<int>& a) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < a.size(); j++){
            
            int curr_sum = 0;
            for (int k = i; k <= j; k++)
            	 curr_sum += a[k];

            res += (curr_sum % 2 == 0);
     	}
	}
	return res;
}

int subarrayEvenSum_AlterNaive(vector<int>& a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
    	int sum = 0;
    	for (int j = i; j < a.size(); j++) 
    		 sum += a[j], res += (sum % 2 == 0);
    }
    return res;
}

int subarrayEvenSum_Efficient(vector<int>& a) {
	vector<int> mods({1,0});
	int curr_sum = 0;

	for (int i = 0; i < a.size(); i++)
		 curr_sum = ((curr_sum + a[i]) % 2 + 2) % 2, mods[curr_sum]++;
	return ((mods[0] * (mods[0] - 1)) >> 1) + ((mods[1] * (mods[1] - 1)) >> 1);	 	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << subarrayEvenSum_Efficient(a) << endl;
    return 0;		
}