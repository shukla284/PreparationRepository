
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Add Binary Strings
*/

string addBinaryStrings(string a, string b) {
	string res = "";
	int sum = 0;

	int ptr1 = a.length() - 1, ptr2 = b.length() - 1;
	while (ptr1 >= 0 || ptr2 >= 0 || sum == 1) {

		sum += ((ptr1 >= 0) ? a[ptr1] - '0' : 0);
		sum += ((ptr2 >= 0) ? b[ptr2] - '0' : 0);

		res = char(sum % 2+ '0') + res;
		sum /= 2;

		ptr1--, ptr2--;
	}
	return res;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    string a, b; cin >> a >> b;
    cout << addBinaryStrings(a, b) << endl;    
    
    return 0;		
}