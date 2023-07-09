#include <bits/stdc++.h>

using namespace std;

#define R 3
#define C 3

void prefixSum2D(int a[][C]){
	// This is a efficient soln for NxN matrix other wise we need to add more corner cases.
	for(int j=0;j<R;j++){
		for(int i=1;i<C;i++){
			a[i][j] +=a[i-1][j];
		}
	}
	for(int i=0;i<C;i++){
		for(int j=1;j<R;j++){
			a[i][j] +=a[i][j-1];
		}
	}

	for(int i=0;i<C;i++){
		for(int j=0;j<R;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}

void BruteForce2D(int a[][C]){
	// This is a brute force approach
	int psa[R][C];
	
	psa[0][0]= a[0][0];

	for(int i=1;i<C;i++)
		psa[0][i] = psa[0][i-1] + a[0][i];
	for(int i=1;i<R;i++)
		psa[i][0]= psa[i-1][0] + a[i][0];
	for(int i=1;i<R;i++){
		for(int j=1;j<C;j++){
			psa[i][j]= psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
		}
	}

	for(int i=1;i<R;i++){
		for(int j=0;j<C;j++) {
			cout <<psa[i][j]<< " ";

		}
		cout <<endl;
	}
}

int main(int argc, char const *argv[])
{
	//Input for Efficient soln
	int a[R][C] = {{10,20,30},
                     {5, 10, 20},
                     {2, 4, 6}
                    };
    prefixSum2D(a);

	// Input for Brute force soln
	// int a[R][C] = { { 1, 1, 1, 1, 1 },
    //                 { 1, 1, 1, 1, 1 },
    //                 { 1, 1, 1, 1, 1 },
    //                 { 1, 1, 1, 1, 1 } };
    // BruteForce2D(a);
	
	return 0;
}