#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int m, n, k;
int paper[101][101];
int visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in_range(int x, int y) { return (x>0 && x<=n && y>0 && y<=m); }

int bfs(pair<int,int> v)
{
    queue<pair<int,int>> q;
    q.push(v);
    visited[v.first][v.second] = 1;

    int ret = 0;
    while(!q.empty())
    {
        ret++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(in_range(nx, ny) && paper[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx,ny));
            }
        }
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            paper[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    
    for(int p=0;p<k;p++)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int q=x1;q<x2;q++)
        {
            for(int r=y1;r<y2;r++)
            {
                paper[q+1][r+1] = 1;
            }
        }
    }

    vector<int> result;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(paper[i][j] == 0 && visited[i][j] == 0) result.push_back(bfs(make_pair(i, j)));
        }
    }

    cout << result.size() << "\n";

    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}