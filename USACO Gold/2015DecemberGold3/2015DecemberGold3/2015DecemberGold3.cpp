//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 1e3 + 2;
const int INTMAX = 1e9;
int N, M, tmpx, tmpy, tmpsmell, tmpxx, tmpyy;
int maze[MAX][MAX];
int dp[MAX][MAX][2];
queue<pair<int, pair<int,int>>> q;
pair<int, pair<int, int>> tmp;

int checkmove(int x, int y, int smell) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	if (maze[x][y] == 0) return 0;
	if (maze[x][y] == 1) return 1;
	if (maze[x][y] == 2) return 1;
	if (maze[x][y] == 3) {
		if (smell) {
			return 1;
		}
		else {
			return 0;
		}
	}
	return 2;
}

int main()
{
	
	string problemName = "dream";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			dp[i][j][0] = INTMAX;
			dp[i][j][1] = INTMAX;
		}
	}

	dp[0][0][0] = 0;
	q.push({ 0, {0, 0} });

	while (q.size()) {
		tmp = q.front();
		tmpx = tmp.second.first;
		tmpy = tmp.second.second;
		tmpsmell = tmp.first;
		q.pop();

		if (checkmove(tmpx + 1, tmpy, tmpsmell) == 1) {
			if (maze[tmpx + 1][tmpy] == 2) {
				if (dp[tmpx + 1][tmpy][1] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx + 1][tmpy][1] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ 1, {tmpx + 1, tmpy} });
				}
			}
			else {
				if (dp[tmpx + 1][tmpy][tmpsmell] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx + 1][tmpy][tmpsmell] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ tmpsmell, {tmpx + 1, tmpy} });
				}
			}
		}
		if (checkmove(tmpx - 1, tmpy, tmpsmell) == 1) {
			if (maze[tmpx - 1][tmpy] == 2) {
				if (dp[tmpx - 1][tmpy][1] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx - 1][tmpy][1] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ 1, {tmpx - 1, tmpy} });
				}
			}
			else {
				if (dp[tmpx - 1][tmpy][tmpsmell] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx - 1][tmpy][tmpsmell] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ tmpsmell, {tmpx - 1, tmpy} });
				}
			}
		}
		if (checkmove(tmpx, tmpy + 1, tmpsmell) == 1) {
			if (maze[tmpx][tmpy + 1] == 2) {
				if (dp[tmpx][tmpy + 1][1] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx][tmpy + 1][1] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ 1, {tmpx, tmpy + 1} });
				}
			}
			else {
				if (dp[tmpx][tmpy + 1][tmpsmell] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx][tmpy + 1][tmpsmell] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ tmpsmell, {tmpx, tmpy + 1} });
				}
			}
		}
		if (checkmove(tmpx, tmpy - 1, tmpsmell) == 1) {
			if (maze[tmpx][tmpy - 1] == 2) {
				if (dp[tmpx][tmpy - 1][1] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx][tmpy - 1][1] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ 1, {tmpx, tmpy - 1} });
				}
			}
			else {
				if (dp[tmpx][tmpy - 1][tmpsmell] > dp[tmpx][tmpy][tmpsmell] + 1) {
					dp[tmpx][tmpy - 1][tmpsmell] = dp[tmpx][tmpy][tmpsmell] + 1;
					q.push({ tmpsmell, {tmpx, tmpy - 1} });
				}
			}
		}

		if (checkmove(tmpx + 1, tmpy, tmpsmell) == 2) {
			tmpxx = tmpx;
			tmpyy = tmpy;
			tmpx+= 2;
			while (checkmove(tmpx, tmpy, 0) == 2) {
				tmpx++;
			}
			if (checkmove(tmpx, tmpy, 0) == 0) {
				tmpx--;
			}
			if (maze[tmpx][tmpy] == 2) {
				if (dp[tmpx][tmpy][1] > dp[tmpxx][tmpyy][tmpsmell] + tmpx - tmpxx) {
					dp[tmpx][tmpy][1] = dp[tmpxx][tmpyy][tmpsmell] + tmpx - tmpxx;
					q.push({ 1, {tmpx, tmpy} });
				}
			}
			else {
				if (dp[tmpx][tmpy][0] > dp[tmpxx][tmpyy][tmpsmell] + tmpx - tmpxx) {
					dp[tmpx][tmpy][0] = dp[tmpxx][tmpyy][tmpsmell] + tmpx - tmpxx;
					q.push({ 0, {tmpx, tmpy} });
				}
			}
			tmpx = tmpxx;
			tmpy = tmpyy;
		}
		
		if (checkmove(tmpx - 1, tmpy, tmpsmell) == 2) {
			tmpxx = tmpx;
			tmpyy = tmpy;
			tmpx -= 2;
			while (checkmove(tmpx, tmpy, 0) == 2) {
				tmpx--;
			}
			if (checkmove(tmpx, tmpy, 0) == 0) {
				tmpx++;
			}
			if (maze[tmpx][tmpy] == 2) {
				if (dp[tmpx][tmpy][1] > dp[tmpxx][tmpyy][tmpsmell] + tmpxx - tmpx) {
					dp[tmpx][tmpy][1] = dp[tmpxx][tmpyy][tmpsmell] + tmpxx - tmpx;
					q.push({ 1, {tmpx, tmpy} });
				}
			}
			else {
				if (dp[tmpx][tmpy][0] > dp[tmpxx][tmpyy][tmpsmell] + tmpxx - tmpx) {
					dp[tmpx][tmpy][0] = dp[tmpxx][tmpyy][tmpsmell] + tmpxx - tmpx;
					q.push({ 0, {tmpx, tmpy} });
				}
			}
			tmpx = tmpxx;
			tmpy = tmpyy;
		}

		if (checkmove(tmpx, tmpy + 1, tmpsmell) == 2) {
			tmpxx = tmpx;
			tmpyy = tmpy;
			tmpy += 2;
			while (checkmove(tmpx, tmpy, 0) == 2) {
				tmpy ++;
			}
			if (checkmove(tmpx, tmpy, 0) == 0) {
				tmpy--;
			}
			if (maze[tmpx][tmpy] == 2) {
				if (dp[tmpx][tmpy][1] > dp[tmpxx][tmpyy][tmpsmell] + tmpy - tmpyy) {
					dp[tmpx][tmpy][1] = dp[tmpxx][tmpyy][tmpsmell] + tmpy - tmpyy;
					q.push({ 1, {tmpx, tmpy} });
				}
			}
			else {
				if (dp[tmpx][tmpy][0] > dp[tmpxx][tmpyy][tmpsmell] + tmpy - tmpyy) {
					dp[tmpx][tmpy][0] = dp[tmpxx][tmpyy][tmpsmell] + tmpy - tmpyy;
					q.push({ 0, {tmpx, tmpy} });
				}
			}
			tmpx = tmpxx;
			tmpy = tmpyy;
		}

		if (checkmove(tmpx, tmpy - 1, tmpsmell) == 2) {
			tmpxx = tmpx;
			tmpyy = tmpy;
			tmpy -= 2;
			while (checkmove(tmpx, tmpy, 0) == 2) {
				tmpy--;
			}
			if (checkmove(tmpx, tmpy, 0) == 0) {
				tmpy++;
			}
			if (maze[tmpx][tmpy] == 2) {
				if (dp[tmpx][tmpy][1] > dp[tmpxx][tmpyy][tmpsmell] + tmpyy - tmpy) {
					dp[tmpx][tmpy][1] = dp[tmpxx][tmpyy][tmpsmell] + tmpyy - tmpy;
					q.push({ 1, {tmpx, tmpy} });
				}
			}
			else {
				if (dp[tmpx][tmpy][0] > dp[tmpxx][tmpyy][tmpsmell] + tmpyy - tmpy) {
					dp[tmpx][tmpy][0] = dp[tmpxx][tmpyy][tmpsmell] + tmpyy - tmpy;
					q.push({ 0, {tmpx, tmpy} });
				}
			}
		}
	}

	if (min(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]) == INTMAX) cout << -1;
	else cout << min(dp[N - 1][M - 1][0], dp[N-1][M-1][1]);
}