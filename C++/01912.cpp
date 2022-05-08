#include <iostream>
#include <algorithm>

using namespace std;

int s[100000];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> s[0];

    int seq_max = s[0];
    for(int i=1;i<n;i++)
    {
        int temp;
        cin >> temp;

        s[i] = max(s[i-1] + temp, temp);
        if(seq_max < s[i]) seq_max = s[i];
    }
    
    cout << seq_max << "\n";

    return 0;
}