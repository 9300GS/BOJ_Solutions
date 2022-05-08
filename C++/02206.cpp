#include <iostream>
#include <queue>
#include <string>

using namespace std;

class V
{
    public:
    int x, y, dist;
    bool wall_break_used;

    V(int a, int b, int d, bool w)
    {
        x = a; y = b; dist = d; wall_break_used = w;
    }
};

int n, m;
int maze[1001][1001];
int visited[1001][1001][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(V start);
bool inRange(int x, int y)
{
    return (x>0 && x<=n && y>0 && y<=m);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        for(int j=1;j<=m;j++)
        {
            maze[i][j] = s[j-1] - '0';
            visited[i][j][0] = visited[i][j][1] = 0;
        }
    }

    bfs(V(1, 1, 1, false));

    return 0;
}

void bfs(V start)
{
    queue<V> q;
    bool reached_end = false;

    q.push(start);
    visited[start.x][start.y][maze[start.x][start.y]] = 1;

    while(!q.empty())
    {
        V v = q.front();
        q.pop();

        if(v.x == n && v.y == m)
        {
            cout << v.dist << "\n";
            reached_end = true;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];

            if(inRange(nx, ny))
            {
                if(maze[nx][ny] == 0)
                {
                    if(v.wall_break_used == false && visited[nx][ny][false] == 0)
                    {
                        q.push(V(nx, ny, v.dist+1, false));
                        visited[nx][ny][false] = 1;
                    }
                    else if(v.wall_break_used == true && visited[nx][ny][true] == 0)
                    {
                        q.push(V(nx, ny, v.dist+1, true));
                        visited[nx][ny][true] = 1;
                    }
                }
                else if(v.wall_break_used == false)
                {
                    q.push(V(nx, ny, v.dist+1, true));
                    visited[nx][ny][true] = 1;
                }
            }
        }
    }
    if(!reached_end) cout << -1 << "\n";
}