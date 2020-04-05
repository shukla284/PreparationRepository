
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum Non Negative Subarray
*/

vector<int> maximumNonNegativeSubarray(vector<int>& a) {
	vector<int> res;
	pair<int,int> curr = {0,0}, ridx = {-1,-1};
    int max_sum = 0, curr_sum = 0;

    while (curr.second < a.size()) {
    	if (a[curr.second] < 0)
    		 curr.first = curr.second + 1, curr_sum = 0;

        else {
             curr_sum += a[curr.second];

             if (curr_sum > max_sum) {
                 max_sum = curr_sum;
                 ridx.first = curr.first, ridx.second = curr.second;
             }

             else if (curr_sum == max_sum)
                  if (curr.second - curr.first + 1 > ridx.second - ridx.first + 1)
                  	   ridx.first = curr.first, ridx.second = curr.second;
        }
        curr.second++;		 
    }

    for (int i = ridx.first; i <= ridx.second; i++)
    	 res.emplace_back(a[i]);
    return res;	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto res = maximumNonNegativeSubarray(a);
    for (int i : res)
    	  cout << i << " ";

    return 0;		
}