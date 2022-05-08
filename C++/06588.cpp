#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> sieve(1000001, 1);
    sieve[0] = sieve[1] = 0;

    for(int i=2;i<=1000;i++)
    {
        if(sieve[i] == 0) continue;

        for(int j=i*2;j<=1000000;j+=i)
        {
            sieve[j] = 0;
        }
    }

    while(1)
    {
        int n;
        cin >> n;
        if(n == 0) break;

        bool found = false;
        int a = 3, b = n - 3;

        while(a <= b)
        {
            if(sieve[a] == 1 && sieve[b] == 1)
            {
                found = true;
                break;
            }
            a += 2;
            b -= 2;
        }

        if(found) cout << n << " = " << a << " + " << b << "\n";
        else cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}