const int MOD = 1e9 + 7;
struct TrieNode {
	TrieNode *left, *right;
	int counts;

	TrieNode(): left(nullptr), right(nullptr), counts(0) {};
};

void insertTrie(TrieNode*& root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;

		if (bit == 1) {
			if (!curr -> right)
				curr -> right = new TrieNode();
			curr = curr -> right;
			curr -> counts++;
		}
		else {
			if (!curr -> left) 
				curr -> left = new TrieNode();
			curr = curr -> left;
			curr -> counts++;
		}
	}
}

int queryTrie(TrieNode* root, int val, int k) {
	int ans = 0;
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int vbit = (val >> i) & 1;
		int kbit = (k >> i) & 1;

		if (vbit) {
			if (kbit) {
				if (curr -> right)
				     ans = (ans + (curr -> right -> counts) % MOD) % MOD;
				if (curr -> left) 
					 curr = curr -> left;
				else
				     break;	
			}
			else {
				if (curr -> right)
				 	curr = curr -> right;
				else 
				    break; 
			}	 
		}
		else {
			if (!kbit) {
				if (curr -> left)
					curr = curr -> left;	
				else 
					break;
			}
			else { 
			   if (curr -> left)
				   ans = (ans + (curr -> left -> counts % MOD)) % MOD;
			   if (curr -> right) 
			   	   curr = curr -> right;
			   else 
			       break;	
			}	
		}
	}
	return ans;
}

int solve(vector<int> &a, int b) {
    int pre = 0, ans = 0;
	TrieNode* root = new TrieNode();

	insertTrie(root, pre);
	for (int i = 0; i < a.size(); i++) {
		pre ^= a[i];
		int q = queryTrie(root, pre, b);
		insertTrie(root, pre);
		ans = (ans + q) % MOD;
	}
	return ans;
}
