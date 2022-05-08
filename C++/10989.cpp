#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, temp;
    int* count = new int[10000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        count[temp-1]++;
    }
    
    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            cout << i + 1 << "\n";
        }
    }
    
    return 0;
}