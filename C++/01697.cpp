#include <iostream>
#include <queue>
using namespace std;

void bfs();
bool valid(int p);

int n, k;
bool visited[100001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0;i<=100000;i++)
    {
        visited[i] = false;
    }

    bfs();
    
    return 0;
}

void bfs()
{
    queue<pair<int, int>> q;

    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty())
    {
        int p = q.front().first;
        int t = q.front().second;
        q.pop();

        if(p == k)
        {
            cout << t << "\n";
            break;
        }

        if(p-1 >= 0 && !visited[p-1])
        {
            q.push(make_pair(p-1, t+1));
            visited[p-1] = true;
        }

        if(p < k)
        {
            if(p+1 <= 100000 && !visited[p+1])
            {
                q.push(make_pair(p+1, t+1));
                visited[p+1] = true;
            }

            if(p*2 <= 100000 && !visited[p*2])
            {
                q.push(make_pair(p*2, t+1));
                visited[p*2] = true;
            }
        }
    }
}