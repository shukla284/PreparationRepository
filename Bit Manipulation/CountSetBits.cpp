
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, cnt = 0; cin >> n;

    while (n)    
    	cnt += (n & 1), n >>= 1;
    
    cout << cnt << endl;
    
    return 0;		
}
