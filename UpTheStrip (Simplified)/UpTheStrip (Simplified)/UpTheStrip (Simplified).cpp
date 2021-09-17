//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<long long int> fenwick;

long long int lsb(long long int pos) {
    return pos & -pos;
}

void update(long long int pos, long long int val) {
    while (pos <= N) {
        fenwick[pos] += val;
        fenwick[pos] %= M;
        pos += lsb(pos);
    }
}

long long int query(long long int pos) {
    long long int sum = 0;
    while (pos > 0) {
        sum += fenwick[pos];
        sum %= M;
        pos -= lsb(pos);
    }
    return sum;
}

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */

    cin >> N >> M;
    
    for (int i = 0; i <= N; i++) {
        fenwick.push_back(0);
    }

    update(N, 1);
    for (int i = N; i > 0; i--) {
        update(1, query(i));
        update(i, -query(i));

        for (int j = 2; j <= i; j++) {
            update(i / j, query(i));
            update(i / j + 1, -query(i));
        }
    }
    cout << query(1);
}