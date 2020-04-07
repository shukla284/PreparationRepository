
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Increment Number in vector format
*/

vector<int> vectorRepresentation(int64_t n) {
	vector<int> res;
	while (n)
		 res.emplace_back(n % 10), n /= 10;
	return res;	
}


vector<int> incrementNumber(int64_t n) {
    int carry = 1;
    auto res = vectorRepresentation(n);
    
    for (int i = 0; i < res.size(); i++) {
    	int t = carry;
    	carry = (res[i] + t) / 10;
    	res[i] = (res[i] + t) % 10;
    }
    
    if (carry)
    	res.emplace_back(1);

    return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    auto res = incrementNumber(n);

    reverse(res.begin(), res.end());
    for (int i : res)
    	 cout << i << " ";
    
    return 0;		
}