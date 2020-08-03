
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Subarray with maximum XOR
*/

struct TrieNode {
	TrieNode *left, *right;
	TrieNode(): left(nullptr), right(nullptr) {};
};

void insertTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			if (curr -> right == nullptr)
				 curr -> right = new TrieNode();
			curr = curr -> right;	
		}
		else {
			if (curr -> left == nullptr)
				 curr -> left = new TrieNode();
			curr = curr -> left;	
		}
	}
}

int queryTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	int ans = 0;

	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
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

int subarrayMaximum(vector<int>& a) {
	int ans = numeric_limits<int>::min();
	TrieNode* root = new TrieNode();

	int curr = 0;  
	insertTrie(root, curr);

	for (int i = 0; i < a.size(); i++) {
		insertTrie(root, curr);
		ans = max(ans, queryTrie(root, pre));
	}
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

    cout << subarrayMaximum(a) << endl;
    return 0;		
}