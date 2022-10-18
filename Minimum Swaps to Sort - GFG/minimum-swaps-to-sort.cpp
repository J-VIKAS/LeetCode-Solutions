//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
    
    vector<int> parent;
	
	void union_(int a, int b){
	    int pa = find(a);
	    int pb = find(b);
	    parent[pa] = pb;
	}
	
	int find(int a){
	    if ( parent[a] == a ) return a;
	    return parent[a] = find(parent[a]);
	}
	
	int minSwaps(vector<int>&nums){
	    parent.clear();
	    int n = nums.size(), arr[100001] = {INT_MAX}, ans = 0, freq[1000001] = {0};
	    for ( int i = 0; i<1000001; i++ )    parent.push_back(i);
	    for ( int i = 0; i<n; i++ ) arr[i] = nums[i];
	    sort(arr,arr+n);
	    for ( int i = 0; i<n; i++ ) union_(arr[i],nums[i]);
	    for ( int i = 0; i<n; i++ ) find(nums[i]);
	    for ( int i = 0; i<n; i++ ) freq[ find(nums[i]) ]++;
	    for ( int i = 0; i<1000001; i++ ){
	        if ( freq[i] ) ans += (freq[i]-1);
	    } return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends