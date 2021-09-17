//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;

int N;
vector<long long int> fenwick;

long long int lsb(long long int pos) {
    return pos & -pos;
}

void update(long long int pos, long long int val) {
    while (pos <= N) {
        fenwick[pos] += val;
        pos += lsb(pos);
    }
}

long long int query(long long int pos) {
    long long int sum = 0;
    while (pos > 0) {
        sum += fenwick[pos];
        pos -= lsb(pos);
    }
    return sum;
}

int N1;
vector<long long int> fenwick1;

void update1(long long int pos, long long int val) {
    while (pos <= N1) {
        fenwick1[pos] += val;
        pos += lsb(pos);
    }
}

long long int query1(long long int pos) {
    long long int sum = 0;
    while (pos > 0) {
        sum += fenwick1[pos];
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

    int t, n, q, l, r;
    cin >> t;

    char tmp;
    for (int i = 0; i < t; i++) {
        fenwick.clear();
        fenwick1.clear();
        cin >> n >> q;
        for (int j = 0; j < n / 2; j++) {
            fenwick.push_back(0);
            fenwick1.push_back(0);
            N = n / 2;
            N1 = n / 2;
        }
        if (n % 2 == 1) {
            fenwick.push_back(0);
            N++;
        }
        fenwick.push_back(0);
        fenwick1.push_back(0);
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 43) {
                if (j % 2 == 0) {
                    update1(j / 2 + 1, 1);
                }
                else {
                    update((j + 1) / 2, 1);
                }
            }
            else {
                if (j % 2 == 0) {
                    update1(j / 2 + 1, -1);
                }
                else {
                    update((j + 1) / 2, -1);
                }
            }
        }

        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            if ((r - l) % 2 == 0) {
                cout << 1 << "\n";
            }
            else {
                if (query(r/2) - query((l - 1)/2) == query1((r + 1)/2) - query1((l + 1)/2)) {
                    cout << 0 << "\n";
                }
                else {
                    cout << 2 << "\n";
                }
            }
        }
    }
}
