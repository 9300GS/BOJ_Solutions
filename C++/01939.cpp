#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<vector<pair<int,ll>>> bridges;
int visited[10001];

int n, m;

bool bfs(int start, int end, ll weight)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty())
    {
        int a = q.front();
        q.pop();

        if(a == end) break;

        for(int i=0;i<bridges[a].size();i++)
        {
            int next = bridges[a][i].first;
            ll cap = bridges[a][i].second;
            if(cap >= weight && visited[next] == 0)
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    if(visited[end] == 1) return true;
    else return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<=n;i++)
    {
        vector<pair<int,ll>> temp;
        bridges.push_back(temp);
    }

    ll min_weight = 0, max_weight = 0;
    for(int i=0;i<m;i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        bridges[a].push_back(make_pair(b, c));
        bridges[b].push_back(make_pair(a, c));
        max_weight = max(max_weight, c);
    }

    int a, b;
    cin >> a >> b;

    ll s = 0;
    while(min_weight <= max_weight)
    {
        ll mid = (min_weight + max_weight) / 2;
        for(int i=1;i<=n;i++)
        {
            visited[i] = 0;
        }
        bool valid = bfs(a, b, mid);

        if(valid == true)
        {
            s = mid;
            min_weight = mid + 1;
        }
        else
        {
            max_weight = mid - 1;
        }
    }

    cout << s << "\n";

    return 0;
}