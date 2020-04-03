
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Testing the palindrome number 
*/

bool isPalindromeNumberString(int64_t n) {
    auto res = to_string(n);


    int i = 0, j = res.length() - 1;

    while (i < j) {
    	 if (res[i] != res[j])
    	 	 return false;
         i++, j--;
    }	 	
    return true;
}

bool isPalindromeNumber(int64_t n) {
	int dig = floor(log10(n)) + 1;
	int hipow = pow(10, dig - 1);

	for (int i = 0; i < (dig / 2); i++) {
		int hi_dig = (n / hipow), lo_dig = (n % 10);

		if (hi_dig != lo_dig)
			return false;

		// changing the powers of the numbers
		n %= hipow, n /= 10, hipow /= 100; 
	}
	return true;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int64_t n; cin >> n;
    cout << isPalindromeNumberString(n) << endl;
    
    return 0;		
}