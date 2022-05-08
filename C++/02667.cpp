#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(pair<int,int> v);

int visited[25][25];
int map[25][25];
int n;
int cnt_plex = 0;
int cnt_house;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++)
    {
        string line;
        cin >> line;
        for(int j=0;j<n;j++)
        {
            map[i][j] = line[j] - '0';
            visited[i][j] = 0;
        }
    }

    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j] == 0)
            {
                visited[i][j] = 1;
            }
            else if(visited[i][j] == 0)
            {
                cnt_house = 0;
                cnt_plex++;
                bfs(make_pair(i, j));
                ans.push_back(cnt_house);
            }
        }
    }

    cout << cnt_plex << "\n";
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << "\n";
    }
    
    return 0;
}

void bfs(pair<int,int> v)
{
    queue<pair<int,int>> q;

    q.push(v);
    visited[v.first][v.second] = 1;
    map[v.first][v.second] = cnt_plex;
    cnt_house++;

    while(!q.empty())
    {
        v = q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int x_next = v.first + x[i];
            int y_next = v.second + y[i];

            if(x_next < 0 || x_next >= n) continue;
            if(y_next < 0 || y_next >= n) continue;
            if(visited[x_next][y_next] == 1) continue;
            if(map[x_next][y_next] != 0)
            {
                q.push(make_pair(x_next, y_next));
                visited[x_next][y_next] = 1;
                map[x_next][y_next] = cnt_plex;
                cnt_house++;
            }
        }
    }
}