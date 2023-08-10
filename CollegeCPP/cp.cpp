#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;  cin>> t;
	while(t--){
	    int n,k,l;
	    cin >> n>>k>>l;
	    vector<int> m;
	    vector<int> lis;
        vector<int> tR;
	    int mi,li;
	    for(int i=0; i<n; i++){
	        cin >> mi;
	        m.push_back(mi);
	        cin >> li;
	        lis.push_back(li);
	    }
	    for(int i=0; i<m.size(); i++){
			if(lis[i] == l){
				tR.push_back(m[i]);
			}
		}
	    if(tR.size() == 0){
	        cout << "-1" << endl;
	    }
	    else{
	        sort(tR.begin(), tR.end(), greater<int>());
	        int sol=0;
    	    for(int i=0; i<k; i++){
    	        sol += tR[i];
    	    }
    	    cout << sol << endl;
    	    }
	}
	return 0;
}
