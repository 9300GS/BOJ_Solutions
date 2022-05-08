#include <iostream>
#include <algorithm>

using namespace std;

int s[1001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(s, s+1001, 0);
    s[0] = 1; s[1] = 1;

    int n;
    cin >> n;

    for(int i=2;i<=n;i++)
    {
        s[i] = (s[i-1] + 2 * s[i-2]) % 10007;
    }
    
    cout << s[n]<< "\n";

    return 0;
}