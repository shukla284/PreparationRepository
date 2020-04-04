
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Check whether two rectangles (aligned with axes) overlap
*/


bool overlapRectangles(pair<int,int>& tl1, pair<int,int>& tl2, pair<int,int>& br1, pair<int,int>& br2) {
    // Check if there's two rectangles are out of the overlap condition.
    // Check whether they are either left of one another or top of other.
    return !(tl1.first > br2.first || tl2.first > br1.first || tl1.second < br2.second || tl2.second < br1.second);
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    pair<int,int> tl1, tl2, br1, br2;
    cin >> tl1.first >> tl1.second >> br1.first >> br1.second;
    cin >> tl2.first >> tl2.second >> br2.first >> br2.second;

    cout << overlapRectangles(tl1, tl2, br1, br2) << endl;

    return 0;		
}