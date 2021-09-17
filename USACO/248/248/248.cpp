//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 248;
int N;
int num[MAX];
int dp[MAX][MAX];
int maxval = 0;
int leftpointer;

int main()
{
	
	string problemName = "248";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	fin.tie(0);

	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			dp[j][i + j] = num[j];
			leftpointer = j + 1;
			for (int k = leftpointer; k <= i + j; k++) {
				if (dp[leftpointer][k] == dp[j][i + j]) {
					dp[j][i + j] ++;
					leftpointer = k + 1;
				}
			}
			maxval = max(maxval, dp[j][i + j]);
		}
	}
	fout << maxval;
}