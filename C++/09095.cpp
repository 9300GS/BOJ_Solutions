#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int recv(int s);
int cache[12];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    memset(cache, -1, sizeof(cache));
    for(int i=0;i<t;i++)
    {
        cin >> n;
        cout << recv(n) << "\n";
    }

    return 0;
}

int recv(int s)
{
    int result = 0;
    if(s == 0) return 1;
    for(int i=1;i<=3;i++)
    {
        if(s - i >= 0)
        {
            if(cache[s - i] == -1)
            {
                cache[s - i] = recv(s - i);
            }     
            result += cache[s - i];
        }
    }
    return result;
}

