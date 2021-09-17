//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

long long int N, K, L;
vector<long long int> citations;

bool check(long long int h) {
    long long int sum = 0;
    for (int i = 0; i < h; i++) {
        if (K + citations[i] < h) {
            return false;
        }
        if (h > citations[i]) {
            sum += (h - citations[i]);
        };
        if (sum > K * L) {
            return false;
        }
    }
    return true;
}

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        citations.push_back(0);
        cin >> citations[i];
    }
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());
    int lo = 0; 
    int hi = 1e5;
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    cout << lo-1;
}