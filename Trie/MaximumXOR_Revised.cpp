
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum XORs
*/

struct TrieNode {
	TrieNode * left, *right;
	TrieNode() {
		left = nullptr, right = nullptr;
	}
};

void insertTrie(TrieNode*& root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
 		if (bit == 0) {
 			if (curr -> left == nullptr)
 				curr -> left = new TrieNode();
 			curr = curr -> left;
 		}	 
		else {
			if (curr -> right == nullptr)
				curr -> right = new TrieNode();
			curr = curr -> right;
		}	
	}
}

int searchTrieActual(TrieNode* root, int val) {
	int ans = 0;
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;

		/*cout << "Bit" << i << " " << bit << endl;
		cout << (curr->left == nullptr) << " " << (curr -> right == nullptr) << endl;*/
		if (bit == 1)
			if (curr -> right == nullptr) 
				 return -1;
			else 
				curr = curr -> right, ans += (1 << i);
		else  
		    if (curr -> left == nullptr)
		    	return -1;
		    else 
		    	curr = curr -> left;  
	}
	return ans;
}

int searchTrie(TrieNode* root, int val) {

	TrieNode* curr = root;
	long long ans = 0;

	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
  		if (bit == 1) {
			if (curr -> left == nullptr)
				curr = curr -> right;
			else 
			    curr = curr -> left, ans += (1 << i);
		}	
		else {
			if (curr -> right == nullptr)
		    	curr = curr -> left;
		    else 
		        curr = curr -> right, ans += (1 << i);	
		}		
	}
	return ans;
}

int maximumXOR(vector<int>& a) {

	TrieNode* root = new TrieNode();
	for (int i = 0; i < a.size(); i++) 
		insertTrie(root, a[i]);

	int ans = numeric_limits<int>:: min();
	for (int i = 0; i < a.size(); i++) 
		ans = max(ans, searchTrie(root, a[i]));
	
	return ans;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

 	int n; cin >> n;
 	vector<int> a(n); 
 	for (int i = 0; i < n; i++)
 	   cin >> a[i];

 	cout << maximumXOR(a) << endl;       
    
    return 0;		
}