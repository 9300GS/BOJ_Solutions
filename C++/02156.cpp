#include <iostream>

using namespace std;

int wine[10001];
int s[10001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> wine[i];
    }

    s[0] = 0;
    s[1] = wine[1];
    s[2] = wine[1] + wine[2];
    for(int i=3;i<=n;i++)
    {
        s[i] = max(max(s[i-3] + wine[i-1] + wine[i], s[i-2] + wine[i]), s[i-1]);
    }

    cout << s[n] << "\n";

    return 0;
}