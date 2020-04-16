
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Guess the number
*/

int number;

int guess(int x) {
    if (number < x)
    	 return 1;
    else if (number > x) 
         return -1;
    else
         return 0;     	
}

int getNumberGuess(int n) {
	int left = 0, right = n;
	while (left <= right) {
       int mid = left + (right - left) / 2;

       if (guess(mid) == 0)
       	   return mid;

       else if (guess(mid) == -1)
       	   left = mid + 1;

       else 
           right = mid - 1;	
	}
	return -1;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    number = rand() % 100;
    cout << getNumberGuess(n) << endl;   
    
    return 0;		
}