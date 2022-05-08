#include <iostream>

using namespace std;

int p[10001];
int s[10001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }

    s[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int max_cost = 0;
        for(int j=1;j<=i;j++)
        {
            max_cost = max(max_cost, s[i-j] + p[j]);
        }

        s[i] = max_cost;
    }

    cout << s[n] << "\n";

    return 0;
}