#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int maxint = 2147483647;


int bitcount(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

double dist(double a, double b, double x, double y) {
    return hypot(a - x, b - y);
}

bool testspeed(double speed, int n, double kn, vector<double> x, vector<double> y, vector<double> s) {
    vector<vector<double>> dp;
    vector<double> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(maxint);
    }
    for (int i = 0; i < 1 << n; i++) {
        dp.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        if (dist(0, 0, x[i], y[i]) <= speed * s[i]) {
            dp[1 << i][i] = dist(0, 0, x[i], y[i]) / speed;
        }
        else {
            dp[1 << i][i] = maxint;
        }
    }

    for (int i = 1; i < 1 << n; i++) {
        int bits = bitcount(i);
        if (bits == 1) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (k == j) {
                        continue;
                    }
                    if (i & (1 << k)) {
                        if (((dp[i ^ (1 << j)][k]) != maxint) && (dp[i ^ (1 << j)][k] + dist(x[j], y[j], x[k], y[k]) / (speed * pow(kn, bits - 1)) <= s[j])) {
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + dist(x[j], y[j], x[k], y[k]) / (speed * pow(kn, bits - 1)));
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if ((dp[(1 << n) - 1][i]) != maxint) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    double k, tmp1, tmp2, tmp3;
    cin >> n;

    vector<double> x, y, s;

    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        x.push_back(tmp1);
        y.push_back(tmp2);
        s.push_back(tmp3);
    }
    cin >> k;

    double low = 0;
    double high = 1000000000;
    double middle;
    double change = 0.001;

    while (high - low > change) {
        middle = (high + low) / 2;
        if (testspeed(middle, n, k, x, y, s)) {
            high = middle;
        }
        else {
            low = middle;
        }
    }
    cout << setprecision(5) << low;
}