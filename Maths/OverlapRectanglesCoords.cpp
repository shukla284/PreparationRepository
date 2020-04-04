
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Check if two rectangles overlap here the coordinates are different.
              Here top right and bottom left coords are given rather than top left and bottom right.
*/

bool overlapRectangles (pair<int,int>& bl1, pair<int,int>& tr1, pair<int,int>& bl2, pair<int,int>& tr2) {
	// Now again by using elemination try to rule out the cases in which the reactangles
	// cannot overlap, where we think of the cases like in previous cases.

	return !(tr2.first <= bl1.first || tr1.first <= bl2.first || tr1.second <= bl2.second  || tr2.second <= bl1.second);
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    pair<int,int> tr1, tr2, bl1, bl2;
    cin >> bl1.first >> bl1.second >> tr1.first >> tr1.second;
    cin >> bl2.first >> bl2.second >> tr2.first >> tr2.second;
    
    cout << overlapRectangles(bl1, tr1, bl2, tr2) << endl;
    return 0;		
}