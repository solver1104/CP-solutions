

// USACO2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int capacity1, capacity2, capacity3, milk1, milk2, milk3;
    int swap;

    FILE* finput = fopen("mixmilk.in","rt");
    fscanf(finput, "%d %d", &capacity1, &milk1);
    fscanf(finput, "%d %d", &capacity2, &milk2);
    fscanf(finput, "%d %d", &capacity3, &milk3);
    fclose(finput);

    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            swap = min(milk1, capacity2 - milk2);
            milk1 -= (swap);
            milk2 += (swap);
        }
        if (i % 3 == 1) {
            swap = min(milk2, capacity3 - milk3);
            milk2 -= (swap);
            milk3 += (swap);
        }
        if (i % 3 == 2) {
            swap = min(milk3, capacity1 - milk1);
            milk3 -= (swap);
            milk1 += (swap);
        }
    }
    FILE* foutput = fopen("mixmilk.out","wt");

    fprintf(foutput, "%d\n%d\n%d", milk1, milk2, milk3);
    fclose(foutput);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
