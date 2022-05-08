#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> list(n);

    for(int i=0;i<n;i++)
    {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    vector<int> prime(list.back() + 1);
    fill(prime.begin(), prime.end(), 1);
    prime[0] = prime[1] = 0;

    for(int i=2;i<=sqrt(list.back());i++)
    {
        if(prime[i] == 0) continue;
        for(int j=i*i;j<=list.back();j+=i)
        {
            prime[j] = 0;
        }
    }
    
    int result = 0;
    for(int i=0;i<list.size();i++)
    {
        if(prime[list[i]] == 1) result++;
    }

    cout << result << "\n";

    return 0;
}