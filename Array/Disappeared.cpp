
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 448. Find All Numbers Disappeared in an Array (leetcode)
*/


vector<int> getDisappeared(vector<int>& a){

	//Time Complexity : O(nlog(n))
	//Space Complexity : O(1)

	//Spare Wrong approach - it was mis interpreted thinking such that I tried to go 
	//via the distance between the elements but it didn't worked for some obvious cases.

    vector<int> res;

    sort(a.begin(), a.end());
    for(int i = 0; i < a.size() - 1; i++){
       for(int j = a[i] + 1; j < a[i+1]; j++)
       	  res.emplace_back(j);
    }
    return res;
}

vector<int> getDisappearedCorrect(vector<int>& a){
	vector<int> res;
	for(int i = 0; i < a.size(); i++){
       int idx = abs(a[i]) - 1;

       if(a[idx] > 0)
       	  a[idx] *= -1;       	
	}

	for(int i = 0; i < a.size(); i++)
		 if(a[i] > 0) 
		 	  res.emplace_back(i + 1);
	return res;	 	
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++)
    	 cin >> a[i];

    auto dis = getDisappeared(a);
    for(int i : dis)
        cout << i << " ";

    /*code ends here*/
    
    return 0;		
}