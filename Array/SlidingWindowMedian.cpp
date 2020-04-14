
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Sliding Window median of size k.
*/

double getMedian_Naive(vector<double>& a, int i, int k) {
	if (k == 1)
		 return *(a.begin() + i);
	else if (k == 2){
	     cout << *(a.begin() + i) << " " << *(a.begin() + i + 1) << endl;
	     cout << (*(a.begin() + i) + *(a.begin() + i + 1)) / 2.0 << endl;
	     return (*(a.begin() + i) + *(a.begin() + i + 1)) / 2.0;	
    }

    sort(a.begin() + i, a.begin() + i + k);
    
    return (k & 1) ? *(a.begin() + i + (k >> 1)) : (*(a.begin() + i + (k >> 1) - 1) + *(a.begin() + (k >> 1))) / 2.0;
}

vector<double> slidingWindowMedian_Naive(vector<double>& a, int k) {
	if (k == 0)
		 throw "Invalid window size";
	else if (k == 1)
	     return a;
	else {
		vector<double> res;
		for (int i = 0; i + k <= a.size(); i++) {
			res.emplace_back(getMedian_Naive(a, i, k));	
		}
	    return res;
	}

}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];   
    
    auto res = slidingWindowMedian_Naive(a, k);
    for (auto i : res)
    	  cout << i << " ";

    return 0;		
}