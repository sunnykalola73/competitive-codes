#include <bits/stdc++.h>
#define ll long long int

using namespace std;
// void solve();


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

void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);

int main(){

	Node* root =  new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	preOrder(root);

	return 0;
}

void preOrder(Node* root){
	if(root== NULL){
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

// void solve()
// {
// 	ll n;
// 	cin>>n;
// }

// int main()
// {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
  
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt", "r", stdin);
// //     freopen("error.txt", "w", stderr);
// //     freopen("output.txt", "w", stdout);
// // #endif
  
// //     ll t = 1;
// //     /*is Single Test case?*/ cin >> t;
// //     while (t--) {
// //         solve();
// //         cout << "\n";
// //     }
  
// //     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	
//     return 0;
// }