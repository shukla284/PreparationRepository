
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum Gap in sorted order
*/

class Bucket{
 public:
    bool used;
    int max_value, min_value;

    Bucket(bool used, int max_value, int min_value) {
    	this->used = used;
    	this->max_value = max_value;
    	this->min_value = min_value;
    }
};

int maximumSortedGap(vector<int>& a) {
    if (a.size() < 2) 
    	 return 0;

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    int bs = max(1, (mx - mn) / ((int)a.size() - 1));
    int bn = (mx - mn) / bs + 1;

    vector<Bucket> buckets(bn, Bucket(false, numeric_limits<int>::min(), numeric_limits<int>::max()));
    for (int i : a) {
    	int bnum = (i - mn) / bs;

        buckets[bnum].used = true;
        buckets[bnum].max_value = max(i, buckets[bnum].max_value);
        buckets[bnum].min_value = min(i, buckets[bnum].min_value);
    }
    
    int prev_max = 0, gap = 0;
    for (int i = 1; i < buckets.size(); i++) 
    	if (buckets[i].used) 
    		 gap = max(gap, buckets[i].min_value - buckets[prev_max].max_value), prev_max = i;
    
    return gap;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << maximumSortedGap(a) << endl;

    return 0;		
}