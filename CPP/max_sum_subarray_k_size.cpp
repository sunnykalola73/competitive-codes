#include <bits/stdc++.h>
#define ll long long int

using namespace std;
void solveBruteForce(int arr[], int n, int k);
void slidingWindow(int arr[], int n, int k);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
  
    ll t = 1;
    /*is Single Test case?*/ cin >> t;
    while (t--) {
    	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	    int k = 4;
	    int n = sizeof(arr) / sizeof(arr[0]);
        // solve();
        // solveBruteForce(arr, n, k);
        slidingWindow(arr, n, k);
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void slidingWindow(int arr[], int n, int k) {
	if(n<k){
		cout<<"Invalid"<<endl; 
		return;
	}

	int max_sum = 0;
	for(int i=0;i<k;i++)
		max_sum +=arr[i];

	int windowSum = max_sum;
	for(int i=k;i<n;i++){
		windowSum += arr[i] - arr[i-k];
		max_sum = max(max_sum, windowSum);
	}

	cout<<max_sum<<endl;
}

void solveBruteForce(int arr[], int n, int k) {
	// This is a Brute force approach that uses 2 loops to sinf soln.

    int max_sum = INT_MIN;

    for(int i=0;i<n-k+1;i++){
    	int temp = 0;
    	for(int j=0;j<k;j++){
    		temp +=arr[i+j];
    	}
    	max_sum= max(max_sum, temp);
    }

    cout<<max_sum<<endl;


}