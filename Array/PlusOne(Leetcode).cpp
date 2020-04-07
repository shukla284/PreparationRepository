
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Plus One (Leetcode)
*/


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

    int d; cin >> d;
    vector<int> dig(d);

    for (int i = 0; i < d; i++)
       cin >> dig[i];
    
    auto res = incrementNumberReverseRepresentation(dig);
    for (int i : dig)
    	 cout << i << " ";
    
    return 0;		
}