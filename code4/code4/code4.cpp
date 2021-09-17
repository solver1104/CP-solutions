
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

    int N, K, ans;

    ans = 0;

    FILE* finput = fopen("gymnastics.in", "rt");
    fscanf(finput, "%d %d", &K, &N);

    vector< vector<int> > m;

    for (int i = 0; i < K; i++) {
        vector<int> line;
        for (int j = 0; j < N; j++) {
            int num;
            fscanf(finput, "%d", &num);
            line.push_back(num);
        }

        m.push_back(line);
    }

    fclose(finput);

    for (int a = 0; a < N; a++) {
        for (int b = a+1; b < N; b++) {
            int checking = 2;
            int positions1;
            int positions2;
            bool consistent = true;
            for (int x = 0; x < K; x++) {
                for (int y = 0; y < N; y++) {
                    if (m[x][y] == a+1) {
                        positions1 = y;
                    }
                    if (m[x][y] == b+1) {
                        positions2 = y;
                    }
                }
                if (checking == 2) {
                    if (positions1 > positions2) {
                        checking = 0;
                    }
                    else {
                        checking = 1;
                    }
                }
                else {
                    if (positions1 > positions2 && checking == 1) {
                        consistent = false;
                    }
                    if (positions1 < positions2 && checking == 0) {
                        consistent = false;
                    }
                }
            }
            if (consistent == true) {
                ans++;
            }
        }
    }

    FILE* foutput = fopen("gymnastics.out", "wt");

    fprintf(foutput, "%d\n", ans);

    fclose(foutput);
}

