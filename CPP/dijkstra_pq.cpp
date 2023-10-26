#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++) dist[i] = 1e9;
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

int main(){

// We need to provide the input accordingly
	// int V - total number of nodes;
	// vector<vecotr<int>> adj[V] - adjencency list of the nodes;
	// int S - source of the path;

	

	// int t; cin >> t;
	// while (t--) {
	// 	int V, E;
	// 	cin >> V >> E;
	// 	vector<vector<int>> adj[V];
	// 	int i=0;
	// 	while (i++<E) {
	// 		int u, v, w;
	// 		cin >> u >> v >> w;
	// 		vector<int> t1,t2;
	// 		t1.push_back(v); t1.push_back(w);
	// 		adj[u].push_back(t1);
	// 		t2.push_back(u);
	// 		t2.push_back(w);
	// 		adj[v].push_back(t2);
	// 	}
	// 	int S;
	// 	cin>>S;

	// 	vector<int> ans_dist;
	// 	ans_dist = dijkstra(V, adj, S);

	// 	for(int i=0;i<ans_dist.size();i++){
	// 		cout<<i<<"--"<< ans_dist[i]<<endl;
	// 	}
	// }
	return 0;
}

// void solve();
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
  
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("error.txt", "w", stderr);
//     freopen("output.txt", "w", stdout);
// #endif
  
//     ll t = 1;
//     /*is Single Test case?*/ cin >> t;
//     while (t--) {
//         solve();
//         cout << "\n";
//     }
  
//     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
//     return 0;
// }
// void solve()
// {
// 	ll n;
// 	cin>>n;
// }