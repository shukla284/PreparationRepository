
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Generate Spiral Matrix
*/

vector<vector<int>> generateSpiralMatrix(int n) {
	int column_count = n, row_count = n - 1;
	int r = 0, c = 0, val = 1;
   
    vector<vector<int>> res(n, vector<int>(n));
	while (column_count && row_count) {
       
       //left -> right filling
       for (int i = 0; i < column_count; i++)
       	   res[r][c++] = val++;

       column_count--, c--, r++;
       
       // up -> down filling
       for (int i = 0; i < row_count; i++)
       	   res[r++][c] = val++;

       row_count--, r--, c--;
       

       // right -> left filling
       for (int i = 0; i < column_count; i++)
       	   res[r][c--] = val++;

       column_count--, c++, r--;


       // down -> up
       for (int i = 0; i < row_count; i++) 
           res[r--][c] = val++;

       row_count--, r++, c++;
	} 
	if (n & 1) 
		 res[n >> 1][n >> 1] = val;
	return res;	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    auto res = generateSpiralMatrix(n);
    
    for (auto i : res) {
    	for (int j : i)
    		 cout << j << " " ;
    	cout << endl;	 	
    }

    return 0;		
}