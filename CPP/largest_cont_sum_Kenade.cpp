#include <bits/stdc++.h>
#define ll long long int

using namespace std;
void solve(int arr[], int);
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

    	 int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
 		 int n = sizeof(a) / sizeof(a[0]);
 
        solve(a, n);
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
void solve(int a[], int size)
{
	int max_so_far = INT_MIN, max_end_here =0;

	for(int i=0;i<size;i++){
		max_end_here += a[i];
		max_so_far = max(max_so_far, max_end_here);

		if(max_end_here < 0)
			max_end_here =0;

	} 

	cout<<max_so_far<<endl;
}