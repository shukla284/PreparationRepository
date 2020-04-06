
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Sort an array of 0, 1, 2
*/


void sortThreeWay(vector<int>& a) {
    int ze = 0, on = 0, tw = a.size() - 1;
    while (on <= tw) 
    	if (a[on] == 0) 
    		swap(a[on++], a[ze++]);
    	else if (a[on] == 1)
    		on++;
    	else
    		swap(a[on], a[tw--]);
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) 
       cin >> i;

    sortThreeWay(a);

    for (int i : a)
    	 cout << i << " ";

    return 0;		
}