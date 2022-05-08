#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> prime(n+1);

    fill(prime.begin(), prime.end(), 1);
    prime[0] = prime[1] = 0;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(prime[i] == 0) continue;
        for(int j=i*i;j<=n;j+=i)
        {
            prime[j] = 0;
        }
    }
    
    int result = 0;
    for(int i=m;i<=n;i++)
    {
        if(prime[i] == 1) cout << i << "\n";
    }

    return 0;
}