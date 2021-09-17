
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#pragma warning(disable : 4996)

using namespace std;

int main()
{


    int ans = 0;
    int length;
    char sequence[100];
    int seq_num;

    FILE* finput = fopen("whereami.in", "rt");
    fscanf(finput, "%d", &length);
    fgets(sequence, 100, finput);

    string seq = string(sequence);

    cout << seq;

    seq_num = length;
    
    while (seq_num > 1) {
        ans++;
        map<string,int> strings;
        for (int i = 0; i < length - ans; i++) {
            string substring = seq.substr(i, i + ans-1);
            strings[substring] ++;
        }
        int maximal = 0;
        for (auto& kvp : strings) {
            int val = kvp.second;
            if (val > maximal) {
                maximal = val;
            }
        }
        seq_num = maximal + 1;
    }
    

    fclose(finput);



    FILE* foutput = fopen("whereami.out", "wt");

    fprintf(foutput, "%d\n", ans);

    fclose(foutput);
}

