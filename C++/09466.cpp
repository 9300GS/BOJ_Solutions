#include <iostream>

using namespace std;

void dfs(int s);
void clearHistory(int n);
void clearDet(int n);

int choice[100001];
int visited[100001];
int determined[100001];

int cnt;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;

        clearDet(n);
        clearHistory(n);

        for(int j=1;j<=n;j++)
        {
            cin >> choice[j];
        }

        cnt = n;
        for(int j=1;j<=n;j++)
        {
            if(visited[j] == 0)
            {
                dfs(j);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}

void dfs(int s)
{
    visited[s] = 1;
    if(visited[choice[s]] == 1)
    {
        if(determined[choice[s]] == 0)
        {
            for(int i = choice[s]; i != s; i = choice[i])
            {
                cnt--;
            }
            cnt--;
        }
    }
    else
    {
        dfs(choice[s]);
    }
    determined[s] = 1;
}

void clearHistory(int n)
{
    for(int i=1;i<=n;i++)
    {
        visited[i] = 0;
    }
}

void clearDet(int n)
{
    for(int i=1;i<=n;i++)
    {
        determined[i] = 0;
    }
}