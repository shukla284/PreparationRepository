
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Beautiful Array (Leetcode)
*/

bool isBeautifulArray(vector<int>& a){
    bool res = false;
    for(int i = 0; i < a.size(); i++){
    	for(int j = i+1; j < a.size(); j++){
    		for(int k = i+1; k < j; k++)
    			if(a[k]*2 == (a[i] + a[j]))
    				 return false;
    	}
    }
    return true;
}

void shuffle(vector<int>& a, int s, int e){
    if((e - s) <= 1)
    	 return;
    
    vector<int> odd, even;
    for(int i = s; i <= e; i++){
    	if((i + 1 - s) & 1)
           odd.emplace_back(a[i]);
        else
           even.emplace_back(a[i]);
    }

    copy(odd.begin(), odd.end(), a.begin()+s);
    copy(even.begin(), even.end(), a.begin()+odd.size()+s);

    int mid = ((e - s) >> 1) + s;
    shuffle(a,s,mid);
    shuffle(a,mid+1,e);
}


vector<int> getBeautiful(int n){
    vector<int> res;
    for(int i = 1; i <= n; i++)
    	res.emplace_back(i);

    shuffle(res,0,n-1);
    return res;
}


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n; cin >> n;
    auto res = getBeautiful(n);

    for(int i : res)
    	 cout << i << " ";

    /*code ends here*/
    
    return 0;		
}