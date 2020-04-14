
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Sliding Window median of size k.
*/

// Naive way of finding the median
// Requiring the sorting of the given array and O(n log(n)) time
// for (n - k + 1) windows : O(n**2 log(n)) in worst case.
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


//This is the another linear time method of finding the median
// This requires the quickselect algorithm in which the partition is made
// Recursive calls are made to find the Kth largest element.
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

// The random partition function drives itself using the normal partition function
// This requies the things like call to the rand() function for getting the 
// random value for the pivot to be used.
int randomPartitionIndex(vector<int>& a, int l, int r) {
    int piv = rand() % (r - l + 1);

    // swapping and changing the array for the further call to the partition function.
    swap(a[l + piv], a[r]);
    return partitionFunction(a, l, r);
}

void medianPartitionHelper(vector<int>& a, int l, int r, int k, int& mid1, int& mid2) {
    if (l <= r) {
        // The partititon index is the index upon which the lesser elements 
        // are kept on one side of the value and larger ones on the right of it.
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
        
        // The recursive calls are made either to search at the left or right 
        // for getting the values of the Kth largest element.
    	if (partition_idx >= k)
    		 return medianPartitionHelper(a, l, partition_idx - 1, k, mid1, mid2);
    	else 
    	     return medianPartitionHelper(a, partition_idx + 1, r, k, mid1, mid2);	
    }
    return;
}

// This is the main method that is used to find the median actually by making
// calls to the helper function using the Kth largest element logic.

// for getting the median here we want the (N/ 2)th largest element.
//in each window of k we are using O(k) time, total of (n - k + 1) windows will 
// incur the complexity of O(nk).
double getMedian_Partition(vector<int>& a, int i, int k) {

    int mid1 = -1, mid2 = -1;
    vector<int> alt; 
    for (int x = i; x <= (i + k - 1); x++)
         alt.emplace_back(a[x]);

    medianPartitionHelper(alt, 0, k - 1, (k >> 1), mid1, mid2);
    return (k & 1) ? mid2 : ((mid1 + mid2) / 2.0);
}

vector<double> slidingWindowMedian(vector<int>& a, int k) {
	if (k == 0)
		 throw "Invalid window size";
	else if (k == 1) {
		vector<double> res;
		for (int i : a)
			res.emplace_back(i);
		return res;
	}
	else {
		vector<double> res;
		for (int i = 0; i + k <= a.size(); i++) {
			res.emplace_back(getMedian_Partition(a, i, k));	
		}
	    return res;
	}

}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];   
    
    auto res = slidingWindowMedian(a, k);
    for (auto i : res)
    	  cout << i << " ";

    return 0;		
}  