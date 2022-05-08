#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    int gcd, lcm;

    int a = n, b = m;
    while(1)
    {
        if(a < b)
        {
            int temp = b; b = a; a = temp;
        }
        a %= b;
        if(a == 0)
        {
            gcd = b;
            break;
        }
    }
    lcm = (n/gcd) * (m/gcd) * gcd;
    cout << gcd << "\n" << lcm << "\n";
    return 0;
}