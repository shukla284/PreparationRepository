
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Check whether points are rectangle
              This is inspired by Stack Overflow solution to the problem : Find if 4 points form rectangle
              Link : https://stackoverflow.com/questions/2303278/find-if-4-points-on-a-plane-form-a-rectangle
*/

class Double{
   public :
       int x; 

       Double(double x) {
          this->x = x;
       }
};

bool operator!= (const Double& a, const Double& b) {
    return (abs(a.x - b.x) > 1e-6);
}

int checkRectangle(vector<pair<double, double>>& pts) {
    double cx = 0, cy = 0;
    for (auto i : pts) 
    	 cx += i.first, cy += i.second;
    cx /= 4.0, cy /= 4.0;
    
    double dis = (cx - pts[0].first) * (cx - pts[0].first) + (cy - pts[0].second) + (cy - pts[0].second);
    for (auto i : pts)
        if (dis != ((cx - i.first) * (cx - i.first) + (cy - i.second) * (cy - i.second)) )
        	return false;
    
    return true;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    vector<pair<double, double>> pts(4);
    for (int i = 0; i < 4; i++)
        cin >> pts[i].first >> pts[i].second;

    cout << checkRectangle(pts) << endl;       
    
    return 0;		
}