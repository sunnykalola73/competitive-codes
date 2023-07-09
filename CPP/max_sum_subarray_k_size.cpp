#include <bits/stdc++.h>
#define ll long long int

using namespace std;
void solve();
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
        solve();
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
void solve()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

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