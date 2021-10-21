#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	unsigned int N, S, i, j;
	cin>>S>>N;
	
	vector<int> w(N + 1);
	for (i = 1; i <= N; ++i) cin>>w[i];
	
	vector<int> v(S + 1, 0);
	vector< vector<int> > matrix(N + 1, v);
	
	for (i = 1; i <= N; ++i)
		for (j = 0; j <= S; ++j) {
			matrix[i][j] = matrix[i-1][j];
			if ((j >= w[i]) && (matrix[i-1][j-w[i]]+w[i] > matrix[i][j]))
				matrix[i][j] = matrix[i-1][j-w[i]]+w[i];
		}
	
	cout<<matrix[N][S];
	return 0;
}