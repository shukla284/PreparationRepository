
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Rotate Matrix bhy 90 degrees
*/

void rotateMatrix(vector<vector<int>>& mat) {
	int layers = (mat.size() >> 1);

	for (int i = 0; i < layers; i++) {
		for (int j = i; j < mat.size() - i - 1; j++) {

			 // store the top row elements
			 int tmp = mat[i][j];

			 // move the right element to top row's correct position (last ith position) 
			 mat[i][j] = mat[j][mat.size() - i - 1];

			 // move the last row elements to the rightmost column
			 mat[j][mat.size() - i - 1] = mat[mat.size() - i - 1][mat.size() - j - 1];

			 // move the left most column to the last row 
			 mat[mat.size() - i - 1][mat.size() - j - 1] = mat[mat.size() - j - 1][i];

			 // assign the correct stored value to the leftmsot row.
			 mat[mat.size() - j - 1][i] = tmp;
		}
	}
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for(auto& i : mat)
    	 for (int& j : i)
    	 	 cin >> j ;

    rotateMatrix(mat);

    for(auto i : mat) {
    	for(int j : i)
    		  cout << j << " ";
    	cout << endl;	
    }

    return 0;		
}
