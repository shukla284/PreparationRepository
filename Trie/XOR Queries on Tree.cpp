
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Queries on Tree
*/

struct TrieNode {
	TrieNode *left, *right;
	int valid;
	TrieNode() : left(nullptr), right(nullptr), valid(0) {};
};

void insertTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			if (!curr -> right) 
				curr -> right = new TrieNode();
			curr = curr -> right;
			curr -> valid++;
		}
		else {
			if (!curr -> left)
				 curr -> left = new TrieNode();
			curr = curr -> left;
			curr -> valid++;
		}
	}
}

int queryTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	int ans = 0;

	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			if (!curr -> left || curr -> left && !curr -> left -> valid) 
				 curr = curr -> right;	 
			else if (curr -> left) 
			     curr = curr -> left, ans += (1 << i);	 	     
		}
		else {
 			if (!curr -> right ||  curr-> right && !curr -> right -> valid) 
				curr = curr -> left;
		    else if (curr -> right)
		        curr = curr -> right, ans += (1 << i);
		}
	}
	return ans;
}

void removeTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;

		if (bit) {
			 if (curr -> right) {
			 	 curr = curr -> right, curr -> valid--;
			 }
		}
			 
		else {
		     if (curr -> left) {
		         curr = curr -> left, curr -> valid--;	 	
		     }
		}     
	}
}

bool searchTrie(TrieNode* root, int val) {
	TrieNode* curr = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			if (!curr -> right)
				 return false;
			else if (curr -> right -> valid) {
			     curr = curr -> right;	
			}     
			else 
			     return false; 
		}
		else {
			if (!curr -> left)
				return false;
			else if (curr -> left -> valid) {
				 curr = curr -> left;
			}	 
			else 
			     return false;	
		}
	}
	return true;
}

void dfs(int s, TrieNode* root, map<int, vector<int>>& qr, vector<vector<int>>& g, vector<int>& e, vector<bool>& vis, vector<int>& ans) {
	vis[s] = true;
	insertTrie(root, s);

	for (int i : qr[s]) 
		ans[i] = queryTrie(root, e[i]);
	for (auto i : g[s]) 
		 if (!vis[i])
		 	 dfs(i, root, qr, g, e, vis, ans);	 	

	removeTrie(root, s);	 	
}

vector<int> queryTrees(vector<int>& par, vector<int>& d, vector<int>& e) {
	int n = par.size(), q = d.size();
	
	vector<bool> vis(par.size() + 2, false);
	vector<int> ans(q, -1);

	map<int, vector<int>> qr;
	for (int i = 0; i < q; i++) 
		qr[d[i]].emplace_back(i);
	 
	
	vector<vector<int>> g(par.size() + 2);
	for (int i = 0; i < par.size(); i++) {
		g[par[i]].emplace_back(i + 2);
		g[i + 2].emplace_back(par[i]);
	}

	TrieNode* root = new TrieNode();	
	dfs(1, root, qr, g, e, vis, ans);

	return ans;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

 	int n; cin >> n;
 	vector<int> par(n - 1); 
 	for (int i = 0; i < n - 1; i++)
 	   cin >> par[i];

 	int q; cin >> q;
 	vector<int> d(q), e(q);
 	for (int i = 0; i < q; i++)
 	   cin >> d[i];
 	for (int i = 0; i < q; i++)
 	   cin >> e[i];

 	auto ans = queryTrees(par, d, e);
 	for (int i : ans) 
 	   cout << i << " ";
 	cout << endl;            
    
    return 0;		
}
