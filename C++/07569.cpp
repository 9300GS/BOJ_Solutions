#include <iostream>
#include <queue>

using namespace std;

class V
{
public:
    int x, y, z, d;
    V(int x, int y, int z, int d)
    {
        this->x = x; this->y = y; this->z = z; this->d = d;
    }
};

int m, n, h;
int tomato_left;
int box[101][101][101];
int riped[101][101][101];
queue<V> tomato_init;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs();
bool inRange(int x, int y, int z)
{
    return (x>0 && x<=n && y>0 && y<=m && z>0 && z<=h);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    tomato_left = m * n * h;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin >> box[j][k][i];
                if(box[j][k][i] == 1)
                {
                    tomato_init.push(V(j, k, i, 0));
                }
                else if(box[j][k][i] == -1)
                {
                    tomato_left--;
                }

                riped[j][k][i] = 0;
            }
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
        V t = tomato_init.front();
        tomato_init.pop();
        q.push(t);
        riped[t.x][t.y][t.z] = 1;
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

        for(int i=0;i<6;i++)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            int nz = v.z + dz[i];

            if(inRange(nx, ny, nz) && box[nx][ny][nz] == 0 && riped[nx][ny][nz] == 0)
            {
                q.push(V(nx, ny, nz, v.d+1));
                riped[nx][ny][nz] = 1;
            }
        }
    }
    if(tomato_left > 0) cout << -1 << "\n";
}