#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int s[10001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for(int i=0;i<n;i++)
    {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());

    fill(s, s+10001,0);
    s[0] = 1;

    for(int i=0;i<coin.size();i++)
    {
        for(int j=1;j<=k;j++)
        {            
            if(j-coin[i] < 0) continue;
            s[j] += s[j-coin[i]];
        }
    }
    
    cout << s[k] << "\n";
    return 0;
}