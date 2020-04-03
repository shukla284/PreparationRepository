
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Fast exponentiation
*/

double exponent(double n, int64_t m) {
   // computing n ^ m;

   double res = 1.0;
   if (m < 0) n = (1.0 / n), m = -m;

   while (m) {
   	  if (m & 1) 
         res *= n; 
      n *= n, m >>= 1;
   }
   return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    double n; int64_t m; cin >> n >> m;
    cout << exponent(n, m) << endl;   
    
    return 0;		
}