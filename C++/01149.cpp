#include <iostream>

using namespace std;

int min_r[1001];
int min_g[1001];
int min_b[1001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    min_r[0] = min_g[0] = min_b[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        min_r[i] = r + min(min_g[i-1], min_b[i-1]);
        min_g[i] = g + min(min_b[i-1], min_r[i-1]);
        min_b[i] = b + min(min_r[i-1], min_g[i-1]);
    }
    int s = min(min(min_r[n], min_g[n]), min_b[n]);
    cout << s << "\n";

    return 0;
}