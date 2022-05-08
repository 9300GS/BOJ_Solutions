#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long min, max;
    cin >> min >> max;

    vector<int> squarenn(1000001, 1);
    for(long long i=2;i<1000001;i++)
    {
        long long square = i * i;
        if(square > max) break;

        long long d = min / square;
        if(min % square != 0) d++;

        for(long long j=square*d;j<=max;j+=square)
        {
            long long k = j-min;
            if(k < 0 || k > max-min)
            {
                continue; 
            }
            squarenn[k] = 0;
        }
    }

    int s=0;
    for(int i=0;i<max-min+1;i++)
    {
        if(squarenn[i] == 1) s++;
    }

    cout << s << "\n";
    return 0;
}