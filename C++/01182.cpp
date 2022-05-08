#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recv(int sum, int step, int p);
int result = 0;
int s;
vector<int> z;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> s;

    z.assign(n, 0);
    for(int i=0;i<n;i++)
    {
        cin >> z[i];
    }

    recv(0, n, 0);

    cout << result << "\n";

    return 0;
}

void recv(int sum, int step, int p)
{
    if(step == 0)
    {
        if(sum == s && p != 0) result++;
        return;
    }
    recv(sum + z[step-1], step-1, p+1);
    recv(sum, step-1, p);
}

