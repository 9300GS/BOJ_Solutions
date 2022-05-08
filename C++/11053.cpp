#include <iostream>

using namespace std;

int seq[1001];
int s[1001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> seq[i];
    }

    int sol = 0;
    for(int i=1;i<=n;i++)
    {
        s[i] = 1;
        for(int j=i-1;j>=1;j--)
        {
            if(seq[j] < seq[i])
            {
                s[i] = max(s[i], s[j]+1);
            }
        }
        sol = max(sol, s[i]);
    }

    cout << sol << "\n";

    return 0;
}