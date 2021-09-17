// USACO3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#pragma warning(disable : 4996)
#pragma warning(disable : 6001)
#pragma warning(disable : 4477)

using namespace std;

int main()
{
    int points[3] = { 0,0,0 };
    int lines;
    int current_shell[3] = {0, 1, 2 };
    int current_data[3] = {0,0,0};
    FILE* finput = fopen("shell.in", "rt");
    if (finput == nullptr) {
        printf("Failed to open input file shell.in\n");
        return -1;
    }

    fscanf(finput, "%d", &lines);
    for (int i = 0; i < lines; i++) {
        fscanf(finput, "%d %d %d", &current_data[0], &current_data[1], &current_data[2]);
        for (int j = 0; j < 3; j++) {
            if (current_shell[j] == current_data[0] - 1) {
                current_shell[j] = current_data[1] - 1;
            }
            else {
                if (current_data[1] - 1 == current_shell[j]) {
                    current_shell[j] = current_data[0] - 1;
                }
            }
            if (current_data[2] - 1 == current_shell[j]) {
                points[j] ++;
            }
        }
    }
    fclose(finput);
    FILE* foutput = fopen("shell.out", "wt");
    fprintf(foutput, "%d\n", max(max(points[0], points[1]),points[2]));
    fclose(foutput);
    return 0;
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
