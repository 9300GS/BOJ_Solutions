#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a[10];

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int s = 0;

    for(int i=n-1; i>=0 && k>0; i--)
    {
        if(k < a[i]) continue;
        s += k / a[i];
        k = k % a[i];
    }

    cout << s << "\n";

    return 0;
}