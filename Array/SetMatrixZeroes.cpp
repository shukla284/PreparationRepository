
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


void setMatrixZeroes(vector<vector<int>>& mat) {


    vector<int> rz(mat.size()), cz(mat[0].size());
    for (int i = 0; i < mat.size(); i++)
    	  for(int j = 0; j < mat[i].size(); j++)
    	  	   if (mat[i][j] == 0)
    	  	   	   rz[i] = 1, cz[i] = 1;

    for(int i = 0; i < rz.size(); i++) 
    	if (rz[i] == 1) 
    		 for(int j = 0; j < mat[i].size(); j++)
    		 	 mat[i][j] = 0;

    for (int j = 0; j < cz.size(); j++) 
    	if (cz[j] == 1) 
    		 for (int i = 0; i < mat.size(); i++)
    		 	  mat[i][j] = 0;		 	
}

void setMatrixZeroesSpaceEfficient(vector<vector<int>>& mat){
    int dum = numeric_limits<int>::max();
    for(int i = 0; i < mat.size(); i++)
    	for(int j = 0; j < mat[0].size(); j++) 
    		if (mat[i][j] == 0) {
    			 for(int r = 0; r < mat.size(); r++)
    			 	   if (mat[r][j] != 0)
    			 	     	mat[r][j] = dum;

    			 for(int c = 0; c < mat[0].size(); c++)
    			       if (mat[i][c] != 0)  
    			         mat[i][c] = dum;	
    		}	

    for (int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[0].size(); j++)
             if (mat[i][j] == dum)
                 mat[i][j] = 0;	
}

void setMatrixZeroesTimeEfficient(vector<vector<int>>& mat) {
    
    bool cz = false;

    for(int i = 0; i < mat.size(); i++) {
    	cz |= (mat[i][0] == 0); 
    	for (int j = 1; j < mat[0].size(); j++) 

    	    if (mat[i][j] == 0) 
    	    	 mat[i][0] = 0, mat[0][j] = 0; 		
    }	
    

    for (int i = 1; i < mat.size(); i++)
    	 for (int j = 1; j < mat[0].size(); j++)
               if (mat[i][0] == 0 || mat[0][j] == 0)
               	  mat[i][j] = 0;

    if (mat[0][0] == 0)
       for (int j = 0; j < mat[0].size(); j++)
          mat[0][j] = 0;
      
    if (cz)
       for (int i = 0; i < mat.size(); i++)
          mat[i][0] = 0;  
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, m; cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    	 for(int j = 0; j < m; j++)
    	 	  cin >> mat[i][j];

    setMatrixZeroesTimeEfficient(mat);

    for (auto i : mat) {
    	for(int j : i)
    		  cout << j << " ";
    	cout << endl;	
    }	 	

    return 0;		
}