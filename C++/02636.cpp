#include <iostream>
#include <queue>

using namespace std;

int n, m;
int cheese[100][100];
int visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int,int>> q;

bool in_range(int x, int y) { return (x>=0 && x<n && y>=0 && y<m); }

void bfs()
{
    queue<pair<int,int>> temp;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(in_range(nx, ny) && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                if(cheese[nx][ny] == 1)
                {
                    temp.push(make_pair(nx, ny));
                    cheese[nx][ny] = 0;
                }
                else q.push(make_pair(nx,ny));
            }
        }
    }

    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> cheese[i][j];
            visited[i][j] = 0;
        }
    }

    q.push(make_pair(0,0));
    int time = 0;
    int cheese_left;
    while(!q.empty())
    {
        cheese_left = q.size();
        time++;
        bfs();
    }
    cout << time-1 << "\n";
    cout << cheese_left << "\n";

    return 0;
}