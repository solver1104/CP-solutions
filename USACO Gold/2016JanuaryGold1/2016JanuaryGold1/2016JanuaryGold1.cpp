//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 5e4 + 5;
int N, leftpointer, rightpointer;
long double loc[MAX];
long double curmin = 1e9;
long double leftdp[MAX], rightdp[MAX];

int main()
{
	
	string problemName = "angry";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> loc[i];
	}
	sort(loc, loc + N);
	fill(leftdp, leftdp + N, curmin);
	fill(rightdp, rightdp + N, curmin);
	leftdp[0] = 0;
	for (int i = 1; i < N; i++) {
		if (leftdp[i - 1] - 1 >= leftdp[lower_bound(loc, loc + N, loc[i] - leftdp[i - 1]) - loc]) leftdp[i] = leftdp[i - 1];
		else leftdp[i] = max(leftdp[i - 1] + 1, loc[i] - loc[i - 1]);
	}

	rightdp[0] = 0;
	for (int i = 1; i < N; i++) {
		if (rightdp[i - 1] - 1 >= rightdp[N - (upper_bound(loc, loc + N, loc[N - i - 1] + rightdp[i - 1]) - loc)]) rightdp[i] = rightdp[i - 1];
		else rightdp[i] = max(rightdp[i - 1] + 1, loc[N - i] - loc[N - i - 1]);
	}

	leftpointer = 0;
	rightpointer = N - 1;

	while (rightpointer - leftpointer > -1) {
		curmin = min(curmin, max((loc[rightpointer] - loc[leftpointer]) / 2, max(leftdp[leftpointer], rightdp[N - 1 - rightpointer]) + 1));
		if (leftdp[leftpointer + 1] < rightdp[N - rightpointer]) leftpointer++;
		else rightpointer--;
	}
	
	cout << fixed << setprecision(1) << curmin;
}
