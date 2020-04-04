
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Overlap Rectangle Area 
*/

int overlapRectangleArea(pair<int,int>& bl1, pair<int,int>& tr1, pair<int,int>& bl2, pair<int,int>& tr2) {
    int ra1 = (abs(tr1.first - bl1.first) * abs(tr1.second - bl1.second));
    int ra2 = (abs(tr2.first - bl2.first) * abs(tr2.second - bl2.second));

    if ((max(bl1.second, bl2.second) < min(tr1.second, tr2.second)) && (max(bl1.first, bl2.first) < min(tr1.first, tr2.first)))
		return (ra1 + ra2) - abs(max(bl1.second, bl2.second) - min(tr1.second, tr2.second)) * abs(max(bl1.first, bl2.first) - min(tr1.first, tr2.first));
	else
		return ra1 + ra2;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    pair<int,int> bl1, tr1, bl2, tr2; 
    cin >> bl1.first >> bl1.second >> tr1.first >> tr1.second;
    cin >> bl2.first >> bl2.second >> tr2.first >> tr2.second;

    cout << overlapRectangleArea(bl1, tr1, bl2, tr2) << endl;
    return 0;		
}