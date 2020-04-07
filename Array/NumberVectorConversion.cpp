
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Convert a number to vector form
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

vector<int> incrementNumberReverseRepresentation(vector<int>& res) {
    int carry = 1;
    for (int i = res.size() - 1; i >= 0; i--) {
    	int t = carry;
    	carry = (res[i] + t) / 10;
    	res[i] = (res[i] + t) % 10;
    }

    if(carry)
    	res.insert(res.begin(), 1);

    return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> dig(n);

    for (int i = 0; i < n; i++)
    	  cin >> dig[i];

    auto res = incrementNumberReverseRepresentation(dig);
    for (int i : res)
       cout << i << " ";    
    
    return 0;		
}