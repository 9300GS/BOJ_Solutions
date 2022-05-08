#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> rope;

    for(int i=1;i<=n;i++)
    {
        int temp;
        cin >> temp;
        rope.push_back(temp);
    }

    sort(rope.begin(), rope.end());

    int s = 0;
    for(int i=1;i<=n;i++)
    {
        s = max(s, rope[n-i] * i);
    }

    cout << s << "\n";

    return 0;
}