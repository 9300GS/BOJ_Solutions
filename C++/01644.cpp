#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> sieve(n+1, 1);
    sieve[1] = 0;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(sieve[i] == 0) continue;

        for(int j=2;i*j<=n;j++)
        {
            sieve[i*j] = 0;
        }
    }

    vector<int> prime;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i] == 1)
        {
            prime.push_back(i);
        }
    }

    int s = 0;
    if(prime.size() > 0)
    {
        int front = 0, back = 0, sum = prime[0];
        while(1)
        {
            if(sum <= n)
            {
                if(sum == n)
                {
                    s++;
                }
                back++;
                if(back > prime.size()-1) break;
                sum += prime[back];
            }
            else
            {
                sum -= prime[front];
                front++;
                if(front > prime.size()-1) break;
            }
        }
    }    

    cout << s << "\n";
    return 0;
}