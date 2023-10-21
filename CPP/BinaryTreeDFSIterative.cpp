#include <bits/stdc++.h>
#define ll long long int

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	} 
};

vector<int> preOrder(Node* root);
vector<int> inOrder(Node* root);
vector<int> postOrder1stack(Node* root);
vector<int> postOrder2stack(Node* root);

int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	vector<int>ans = preOrder(root);

	cout<<"Pre-Order-Iterative:"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	ans = inOrder(root);
	cout<<"In-Order-Iterative:"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	ans = postOrder2stack(root);
	cout<<"post-Order-2-stack-Iterative:"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	ans = postOrder1stack(root);
	cout<<"post-Order-1-stack-Iterative:"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;

}

vector<int> preOrder(Node* root){
	vector<int> ans;
	if(!root) return ans;

	stack<Node*>st;
	st.push(root);

	while(!st.empty()){
		root =  st.top();
		st.pop();
		ans.push_back(root->data);
		if(root->right) st.push(root->right);
		if(root->left)	st.push(root->left);
	}
	return ans;
}

vector<int> inOrder(Node* root){
	vector<int> ans;
	stack<Node*> st;
	Node* node = root;

	while(true){
		if(node != NULL){
			st.push(node);
			node = node->left;
		}
		else {
			if(st.empty()) break;
			node = st.top();
			st.pop();
			ans.push_back(node->data);
			node = node->right;
		}
	}
	return ans;
}

vector<int> postOrder2stack(Node* root){
	vector<int> ans;
	if(!root) return ans;
	stack<Node*> st1, st2;
	st1.push(root);
	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);

		if(root->left) st1.push(root->left);
		if(root->right) st1.push(root->right);
	}
	while(!st2.empty()){
		ans.push_back(st2.top()->data);
		st2.pop();
	}
	return ans;
}

vector<int> postOrder1stack(Node* root){
	vector<int> ans;
	if(!root) return ans;
	stack<Node*> st;
	Node* cur = root;

	while(cur != NULL || !st.empty()){
		if(cur != NULL){
			st.push(cur);
			cur = cur -> left;
		}
		else {
			Node* tmp = st.top()->right;
			if(tmp== NULL){
				tmp = st.top();
				st.pop();
				ans.push_back(tmp->data);
				while(!st.empty() && tmp == st.top()->right){
					tmp = st.top();
					st.pop();
					ans.push_back(tmp->data);
				}
			}
			else cur = tmp;
		}
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