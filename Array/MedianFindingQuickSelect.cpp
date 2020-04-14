
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Quick Select Algorithm for median finding
*/

int partitionFunction(vector<int>& a, int l, int r) {
    int piv = a[r], i = l, j = l;
    while (j < a.size()) {
    	if (a[j] < piv) 
    		swap(a[i++], a[j]);
    	j++;
    }
    swap(a[i], a[r]);
    return i;
            
}

int randomPartitionIndex(vector<int>& a, int l, int r) {
    int piv = rand() % (r - l + 1);
    swap(a[l + piv], a[r]);
    return partitionFunction(a, l, r);
}

void medianPartitionHelper(vector<int>& a, int l, int r, int k, int& mid1, int& mid2) {
    if (l <= r) {
    	int partition_idx = randomPartitionIndex(a, l, r);

    	if(partition_idx == k) {
    		mid2 = a[partition_idx];
    		if (mid1 != -1)
    			 return;
    	}

    	else if(partition_idx == k - 1){
            mid1 = a[partition_idx];
            if (mid2 != -1)
            	 return;
    	}

    	if (partition_idx >= k)
    		 return medianPartitionHelper(a, l, partition_idx - 1, k, mid1, mid2);
    	else 
    	     return medianPartitionHelper(a, partition_idx + 1, r, k, mid1, mid2);	
    }
    return;
}

double getMedian_Partition(vector<int>& a) {
	int mid1 = -1.0, mid2 = -1.0;
	medianPartitionHelper(a, 0, a.size() - 1, (a.size() >> 1), mid1, mid2);
	cout << mid1 << " " << mid2 << endl;
	return (a.size() & 1) ? mid2 : (mid1 + mid2) / 2.0;	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i: a)
        cin >> i;

    cout << getMedian_Partition(a) << endl;
    return 0;		
}