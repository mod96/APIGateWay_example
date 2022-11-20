#include "boj_16236.h"

int boj_16236::Solver::arr[20][20];
const pair<int, int> boj_16236::Solver::diffs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool boj_16236::Solver::visited[20][20];

boj_16236::Solver::Solver(int n, int arr_[20][20])
    : N(n), now_val(2), cnt(0)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = arr_[i][j];
            if (arr[i][j] == 9)
            {
                now = {i, j};
                arr[i][j] = 0;
            }
        }
    }
}

boj_16236::Solver::~Solver()
{
}

int boj_16236::Solver::solve()
{
    int res = 0;
    int tmp = 0;
    while (tmp = bfs())
    {
        res += tmp;
        tmp = 0;
    }
    return res;
}

void boj_16236::Solver::init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
    q = queue<pair<int, int>>();
    candidates = vector<pair<int, int>>();
}

int boj_16236::Solver::bfs()
{
    init();
    visited[now.first][now.second] = true;
    q.push(now);
    int level = 0;
    while (q.size() > 0)
    {
        int length = q.size();
        for (int i = 0; i < length; i++)
        {
            pair<int, int> node = q.front();
            q.pop();
            for (auto d : diffs)
            {
                int x = node.first + d.first,
                    y = node.second + d.second;
                if (0 <= x && x < N && 0 <= y && y < N && !visited[x][y] && arr[x][y] <= now_val)
                {
                    if (0 < arr[x][y] && arr[x][y] < now_val)
                    {
                        candidates.push_back({x, y});
                    }
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        level++;
        if (candidates.size() > 0)
        {
            pair<int, int> targ = *min_element(candidates.begin(), candidates.end());
            arr[targ.first][targ.second] = 0;
            now = {targ.first, targ.second};
            cnt++;
            if (cnt == now_val)
            {
                now_val++;
                cnt = 0;
            }
            return level;
        }
    }
    return 0;
}
