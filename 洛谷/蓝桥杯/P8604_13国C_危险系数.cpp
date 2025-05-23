#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, sum=0;
vector<vector<int>> g(1001);
vector<bool> b(1001, false);
vector<int> cnt(1001);

void dfs(int start) {
    if (start == y) {
        sum ++;
        for (int i=1; i<=n; i++)
            if (b[i]) cnt[i] ++;
    } else {
        for (auto& u : g[start])
        {
            if (!b[u]) {
                b[u] = true;
                dfs(u);
                b[u] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    cin>>x>>y;
    b[x] = true;
    dfs(x);
    
    int ans=0;
    if (sum == 0) {
        cout << -1;
        return 0;
    } else {
        for (int i=1; i<=n; i++)
            if (cnt[i] == sum) ans ++;
    }
    cout<<ans-2; //排除起点&终点
    
    return 0;
}