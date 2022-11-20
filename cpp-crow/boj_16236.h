#pragma once

#include <bits/stdc++.h>

using namespace std;

namespace boj_16236
{
    class Solver
    {
    public:
        Solver(int n, int arr_[20][20]);
        ~Solver();
        int solve();

    private:
        void init();
        int bfs();

        int N;
        static int arr[20][20];
        int now_val = 2;
        int cnt = 0;

        pair<int, int> now;
        queue<pair<int, int>> q;
        vector<pair<int, int>> candidates;
        static bool visited[20][20];

        static const pair<int, int> diffs[4];
    };

};
