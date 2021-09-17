// USACOSilver2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N, K;
    cin >> N >> K;
    int tmpX, tmpY;
    vector <unordered_map<int,int>> x;
    unordered_map<int, int> temp;
    vector<int> end;
    unordered_map<int,int> can_visit;
    unordered_map<int, int> end_visited;
    int curr_vertex;
    int times,num;
    int tmp1, tmp2;
    
    for (int i = 0; i < N; i++) {
        temp.clear();
        temp[i] = 1;
        x.push_back(temp);
        end.push_back(i);
    }

    for (int i = 0; i < K; i++) {
        cin >> tmpX >> tmpY;
        x[end[tmpX-1]][tmpY-1] = 1;
        x[end[tmpY-1]][tmpX-1] = 1;
        tmp1 = end[tmpY - 1];
        tmp2 = end[tmpX - 1];
        end[tmpX - 1] = tmp1;
        end[tmpY - 1] = tmp2;
    }

    for (int i = 0; i < N; i++) {
        can_visit.clear();
        curr_vertex = i;
        times = 0;
        num = 0;
        end_visited.clear();
        end_visited[i] = 1;
        while (times != 2) {
            if (end_visited[curr_vertex]) {
                times++;
            }
            end_visited[curr_vertex] = 1;
            
            for (auto j : x[curr_vertex]) {
                if (can_visit[j.first] != 1) {
                    can_visit[j.first] = 1;
                    num++;
                }
            }
            curr_vertex = end[curr_vertex];
            x[i] =can_visit;
        }
        end[i] = i;
        cout << num << "\n";
    }
    
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
