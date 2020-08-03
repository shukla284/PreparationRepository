
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Finding the shortest prefix that is unique
*/

struct TrieNode {
	vector<TrieNode*> childs;
	int counts;
	bool eow;

	TrieNode() {
		childs = vector<TrieNode*>(26, nullptr);
		counts = 0;
		eow = false;
	}
};

void insertTrie(TrieNode*& root, string s) {
	auto curr = root;
	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (curr->childs[idx] == nullptr) 
			curr->childs[idx] = new TrieNode();
		curr = curr->childs[idx];
		curr->counts++;
	}
}

string findPrefixTrie(TrieNode*& root, string s) {
	auto curr = root;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (curr->childs[idx] == nullptr)
			return ans;
		else if (curr->counts == 1)
			return ans;
		else 
			curr = curr->childs[idx], ans += s[i];
	}
	return ans;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

 	int n; cin >> n;
 	vector<string> a(n); 
 	for (int i = 0; i < n; i++) 
 	   cin >> a[i];
 	
 	TrieNode* root = new TrieNode();
 	for (int i = 0; i < n; i++)
 		insertTrie(root, a[i]);
 	vector<string> ans(n);
 	for (int i = 0; i < n; i++)
 		 ans[i] = findPrefixTrie(root, a[i]);

    for (auto i : ans)
    	 cout << i << endl;

    return 0;		
}
