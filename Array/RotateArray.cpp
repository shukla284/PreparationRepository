
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 189. Rotate Array
*/

vector<int> rotateArraySeperate(vector<int>& a, int k){
    vector<int> res(a.size());
    for(int i = 0; i < a.size(); i++){
    	res[(i + k) % a.size()] = a[i];
    }
    return res;
}
vector<int> rotateArrayReverse(vector<int>& a, int k){
	k = k  % a.size();

	reverse(a.begin(), a.end());
	reverse(a.begin(), a.begin()+ k);		
	reverse(a.begin()+k, a.end());
	return a;
}
vector<int> rotateArrayCyclic(vector<int>& a, int k){
    k = k % a.size();

    int ele = 0;
    for(int s = 0; ele < a.size(); s++){
    	int curr = s, prev = a[s];

    	do{
           int nxt = (curr + k) % a.size();
           int tmp = a[nxt];

           a[nxt] = prev;
           prev = tmp;

           curr = nxt;
           ele++;
    	}while (curr != s);
    }
    return a;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n, k ; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	 cin >> a[i];

    auto res = rotateArrayCyclic(a, k);
    for(int i : res)
       cout << i << " ";	
    /*code ends here*/

    return 0;		
}