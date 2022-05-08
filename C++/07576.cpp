#include <iostream>
#include <queue>

using namespace std;

class V
{
public:
    int x, y, d;
    V(int x, int y, int d)
    {
        this->x = x; this->y = y; this->d = d;
    }
};

int m, n;
int tomato_left;
int box[1001][1001];
int riped[1001][1001];
queue<pair<int, int>> tomato_init;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs();
bool inRange(int x, int y)
{
    return (x>0 && x<=n && y>0 && y<=m);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    tomato_left = m * n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> box[i][j];
            if(box[i][j] == 1)
            {
                tomato_init.push(make_pair(i, j));
            }
            else if(box[i][j] == -1)
            {
                tomato_left--;
            }

            riped[i][j] = 0;
        }
    }

    bfs();

    return 0;
}

void bfs()
{
    queue<V> q;

    while(!tomato_init.empty())
    {
        pair<int, int> t = tomato_init.front();
        tomato_init.pop();
        q.push(V(t.first, t.second, 0));
        riped[t.first][t.second] = 1;
    }

    while(!q.empty())
    {
        V v = q.front();
        q.pop();

        tomato_left--;
        if(tomato_left == 0)
        {
            cout << v.d << "\n";
        }

        for(int i=0;i<4;i++)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];

            if(inRange(nx, ny) && box[nx][ny] == 0 && riped[nx][ny] == 0)
            {
                q.push(V(nx, ny, v.d+1));
                riped[nx][ny] = 1;
            }
        }
    }
    if(tomato_left > 0) cout << -1 << "\n";
}