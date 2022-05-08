#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> sieve(2000001, 1);
    sieve[0] = sieve[1] = 0;

    vector<int> prime;
    for(int i=2;i<=2000000;i++)
    {
        if(sieve[i] == 0) continue;
        else prime.push_back(i);

        for(int j=i*2;j<=2000000;j+=i)
        {
            sieve[j] = 0;
        }
    }

    while(t-- > 0)
    {
        long long a, b;
        cin >> a >> b;

        long long sum = a + b;

        bool found = true;
        if(sum < 4)
        {
            found = false;
        }
        else if (sum % 2 != 0)
        {
            long long y = sum - 2;
            for(int i=0; (long long)prime[i]*prime[i] <= y && i < prime.size(); i++)
            {
                if(y % prime[i] == 0)
                {
                    found = false;
                    break;
                }
            }
        }

        if(found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}