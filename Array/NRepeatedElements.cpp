
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : N repeated elements
*/


int getRepeatedElementBrute(vector<int>& a) {
	for(int i = 0; i < a.size(); i++){
		int cnt = 0;
		for(int j = 0; j < a.size(); j++) 
			 cnt += (a[j] == a[i]);
		if(cnt == (a.size() >> 1))
		   return a[i];	
	}
	return -1;
}

int getRepeatedElementHashing(vector<int>& a){

	//Time complexity : O(n)
	//Space Complexity : O(n)
	map<int,int> mp;
	for(int i = 0; i < a.size(); i++) 
		 mp[a[i]]++;
	for(auto i : mp){
		if(i.second == (a.size() >> 1))
			 return i.first;
	}	
	return -1;
}

int getRepeatedElementSorting(vector<int>& a){
    sort(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++) {
       int j = i + 1, cnt = 0;
       while (a[i] == a[j] && j < a.size()) j++;

       if(j - i == (a.size() >> 1))
       	  return a[i];
    }
    return -1;
}

int getRepeatedElementsBetterSorting(vector<int>& a){
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size() - 1 ; i++){
    	if(a[i] == a[i + 1])
    		 return a[i];
    }
    return -1;
}

int getRepeatedElementsNeighbour(vector<int>& a){
    //Very good observation based solution
    // we just need to check the neighbours at the different distances

    for(int ne = 1; ne <= 3; ne++){
    	for(int j = 0; j < a.size() - ne; j++)
    		if(a[j] == a[j + ne])
    			 return a[j];
    }
    return -1;
}

int getRepeatedElement(vector<int>& a){
	return getRepeatedElementBrute(a);
}
int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    /*code starts here*/
      
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
    	cin >> a[i];

    cout << getRepeatedElement(a) << endl;
    /*code ends here*/
    
    return 0;		
}