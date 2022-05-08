#include <iostream>

using namespace std;

int fibonacci_0[41];
int fibonacci_1[41];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fibonacci_0[0] = fibonacci_1[1] = 1;
    fibonacci_0[1] = fibonacci_1[0] = 0;

    for(int i=2;i<=40;i++)
    {
        fibonacci_0[i] = fibonacci_0[i-1] + fibonacci_0[i-2];
        fibonacci_1[i] = fibonacci_1[i-1] + fibonacci_1[i-2];
    }

    int t;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;

        cout << fibonacci_0[n] << " " << fibonacci_1[n] << "\n";
    }
       
    return 0;
}