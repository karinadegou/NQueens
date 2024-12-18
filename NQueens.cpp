#include <bits/stdc++.h>

#define ll int

using namespace std;

vector<ll> current;

void backtrack(ll n, vector<ll>& tri, vector<vector<vector<ll>>>& ban, vector<vector<ll>>& ans)
{
    if (tri.size() == n)
    {
        ans.push_back(current);
        return;
    }

    ll level = tri.size();
    for (ll i = 1; i <= n; i++)
    {
        if (find(ban[0][level].begin(), ban[0][level].end(), i) != ban[0][level].end() ||
            find(ban[1][level].begin(), ban[1][level].end(), i) != ban[1][level].end() ||
            find(ban[2][level].begin(), ban[2][level].end(), i) != ban[2][level].end())
        {
            continue;
        }

        tri.push_back(i);
        for (ll j = level + 1; j <= n; j++) {
            if (i + j - level <= n)
                ban[0][j].push_back(i + j - level);
            ban[1][j].push_back(i);
            if (i - j + level >= 0)
                ban[2][j].push_back(i - j + level);
        }

        backtrack(n, tri, ban, ans);

        for (ll j = level + 1; j <= n; j++) {
            if (i + j - level <= n)
                ban[0][j].pop_back();
            ban[1][j].pop_back();
            if (i - j + level >= 0)
                ban[2][j].pop_back();
        }
        tri.pop_back();
    }
}

vector<vector<ll>> solveNQueens(ll n)
{
    vector<vector<ll>> ans;
    vector<vector<vector<ll>>> ban(3, vector<vector<ll>>(n + 1));
    backtrack(n, current, ban, ans);
    return ans;
}

void printQ(const vector<vector<ll>>& solveNQueens)
{
    for (const auto& column : solveNQueens)
    {
        for (const auto& ele : column)
        {
            cout << fixed << setw(5) << ele;
        }
        cout << endl;
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> solutions = solveNQueens(n);
    printQ(solutions);
    return 0;
}
