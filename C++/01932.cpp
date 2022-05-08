#include <iostream>

using namespace std;

int triangle[500][500];
int max_sum[500][500];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin >> triangle[i][j];
            if(i == n-1) max_sum[i][j] = triangle[i][j];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            max_sum[i][j] = triangle[i][j] + max(max_sum[i+1][j], max_sum[i+1][j+1]);
        }
    }

    cout << max_sum[0][0] << "\n";

    return 0;
}