#include <bits/stdc++.h>
#define ll long long int

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(){
		data =0;
		left = NULL;
		right = NULL;
	}

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;	
	}
};

vector<vector<int>> BFS(Node* root);
int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	vector<vector<int>>res = BFS(root);

	cout<<"BFS:"<<endl;
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

vector<vector<int>> BFS(Node* root){
	vector<vector<int>> ans;
	if( root == NULL) return ans;
	queue<Node*>q;
	// since we have screate a queue of type Node* we can push the while root node into it.
	q.push(root);
	
	while(!q.empty()){
		int size = q.size();
		vector<int> level;
		for(int i=0;i<size;i++){
			Node* node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
			level.push_back(node->data);
		}
		ans.push_back(level);
	}
	return ans;
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