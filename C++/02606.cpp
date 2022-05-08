#include <iostream>
#include <queue>
using namespace std;

void dfs(int v);
bool valid(int p);

int n, e;
int s = 0;
int graph[101][101];
int visited[101];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    for(int i=0;i<101;i++)
    {
        visited[i] = 0;
        for(int j=0;j<101;j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1);
    cout << s << "\n";
    
    return 0;
}

void dfs(int v)
{
    visited[v] = 1;

    for(int i=1;i<=n;i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            s++;
            dfs(i);
        }
    }
}  