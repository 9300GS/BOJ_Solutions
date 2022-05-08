#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pos(n);
    for(int i=0;i<n;i++)
    {
        cin >> pos[i];
    }

    int gap = pos[1] - pos[0];
    for(int i=1;i<pos.size();i++)
    {
        gap = gcd(pos[i] - pos[i-1], gap);
    }

    cout << (pos.back()-pos.front()) / gap - pos.size() + 1 << "\n";
    return 0;
}

int gcd(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if(b == 0) return a;

    return gcd(b, a%b);
}