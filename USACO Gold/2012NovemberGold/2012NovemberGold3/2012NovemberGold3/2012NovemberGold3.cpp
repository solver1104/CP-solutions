//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAXN = 4e4 + 2;
const int neginf = -1e9;
int N, tmp, tmp1, tmpmax1, tmpmax2;
int maxdepth = 0;
char temp;
vector<int> adj[MAXN];
int vals[MAXN];
pair<pair<int, int>, pair<int, int>> maxdown[MAXN];
pair<pair<int, int>, pair<int, int>> mindown[MAXN];
int upmax[MAXN];
int upmin[MAXN];
pair<int, int> edges[MAXN];
int tour[MAXN];
int indext;

void dfs(int node = 0, int parent = -1) {
	maxdown[node].first = { vals[node], node };
	mindown[node].first = { vals[node], node };
	tour[node] = indext;
	indext++;
	for (int i : adj[node]) {
		if (i != parent) {
			dfs(i, node);
			tmp = vals[node] + maxdown[i].first.first;
			tmp1 = vals[node] + mindown[i].first.first;
			if (tmp > maxdown[node].first.first) {
				maxdown[node] = { {tmp, i}, maxdown[node].first };
			}
			else if (tmp > maxdown[node].second.first) {
				maxdown[node].second = { tmp, i };
			}
			if (tmp1 < mindown[node].first.first) {
				mindown[node] = { {tmp1, i}, mindown[node].first };
			}
			else if (tmp1 < mindown[node].second.first) {
				mindown[node].second = { tmp1, i };
			}
		}
	}
}

void dfs1(int node = 0, int parent = -1) {
	for (int i : adj[node]) {
		if (i != parent) {
			upmax[i] = max(upmax[i], upmax[node] + vals[i]);
			if (maxdown[node].first.second == i) upmax[i] = max(upmax[i], maxdown[node].second.first + vals[i]);
			else upmax[i] = max(upmax[i], maxdown[node].first.first + vals[i]);

			upmin[i] = min(upmin[i], upmin[node] + vals[i]);
			if (mindown[node].first.second == i) upmin[i] = min(upmin[i], mindown[node].second.first + vals[i]);
			else upmin[i] = min(upmin[i], mindown[node].first.first + vals[i]);
			dfs1(i,node);
		}
	}
}

int main()
{
	
	string problemName = "btree";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);
	indext = 0;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		adj[tmp - 1].push_back(i);
		adj[i].push_back(tmp - 1);
		edges[i - 1] = {i, tmp - 1};
	}

	for (int i = 0; i < N; i++) {
		cin >> temp;
		vals[i] = -1;
		if (temp == '(') vals[i] = 1;
		maxdown[i] = { {neginf, -1}, {neginf, -1} };
		mindown[i] = { { -neginf, -1 }, { -neginf, -1 } };
	}

	dfs();
	upmax[0] = neginf;
	upmin[0] = -neginf;
	dfs1();

	for (pair<int, int> x : edges) {
		tmp = x.first;
		tmp1 = x.second;
		if (tour[tmp] > tour[tmp1]) swap(tmp, tmp1);

		if (maxdown[tmp].first.second == tmp1) tmpmax1 = min(-mindown[tmp1].first.first, max(maxdown[tmp].second.first, upmax[tmp]));
		else tmpmax1 = min(-mindown[tmp1].first.first, max(maxdown[tmp].first.first, upmax[tmp]));
		if (mindown[tmp].first.second == tmp1) tmpmax2 = min(maxdown[tmp1].first.first, -(min(mindown[tmp].second.first, upmin[tmp])));
		else tmpmax2 = min(maxdown[tmp1].first.first, -(min(mindown[tmp].first.first, upmin[tmp])));

		maxdepth = max(maxdepth, tmpmax1);
		maxdepth = max(maxdepth, tmpmax2);
	}
	cout << maxdepth;
}