#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int *a, *b;

    cin >> n;
    a = new int[n];
    b = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    int s = 0;
    for(int i=0;i<n;i++)
    {
        s += a[i] * b[n-1-i];
    }
    cout << s << "\n";

    delete[] a, b;

    return 0;
}