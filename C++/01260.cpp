#include <iostream>
#include <queue>
using namespace std;

const int vertex_max = 1001;
int graph[vertex_max][vertex_max];
int visited[vertex_max];

int n, m, v;

void dfs(int v);
void bfs(int v);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        visited[i] = 0;
    }
    dfs(v);
    cout << "\n";
    for(int i=1;i<=n;i++)
    {
        visited[i] = 0;
    }
    bfs(v);
    cout << "\n";
    
    return 0;
}

void dfs(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for(int i=1;i<=n;i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}   

void bfs(int v)
{
    queue<int> q;

    cout << v << " ";
    visited[v] = 1;
    q.push(v);

    while(!q.empty())
    {
        v = q.front();
        q.pop();

        for(int i=1;i<=n;i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}