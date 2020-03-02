
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 665. Non-decreasing Array
*/

bool checkPossible(vector<int>& a){
	if(a.size() <= 1)
           return true;
       
        int cnt = 0, idx = -1;
        for(int i = 0; i < a.size()-1; i++){
           if(a[i] > a[i+1])
               cnt++, idx = i;
        }
       
        //cout << a[idx] << endl;
       
        if(cnt == 0)
             return true;
       
        else if(cnt >= 2)
             return  false;
        else
             return (idx == 0) || (idx == a.size() - 2) || (a[idx - 1] <= a[idx + 1]) || (a[idx] <= a[idx + 2]);
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
       cin >> a[i];
   
    cout << checkPossible(a) << endl;        
    /*code ends here*/
    
    return 0;		
}