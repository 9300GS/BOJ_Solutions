#include <iostream>

using namespace std;

int min_calc[1000001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    min_calc[1] = 0;
    min_calc[2] = min_calc[3] = 1;

    for(int i=4;i<=1000000;i++)
    {
        min_calc[i] = 999999999;
        if(i%3 == 0) min_calc[i] = min(min_calc[i], min_calc[i/3]+1);
        if(i%2 == 0) min_calc[i] = min(min_calc[i], min_calc[i/2]+1);
        min_calc[i] = min(min_calc[i], min_calc[i-1]+1);
    }
    
    int n;
    cin >> n;

    cout << min_calc[n] << "\n";
       
    return 0;
}