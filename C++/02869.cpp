#include <iostream>
using namespace std;
int main(void)
{
    long long a, b, v;
    cin >> a >> b >> v;
    cout << (v-b)/(a-b) + ((v-b)%(a-b) == 0 ? 0 : 1) << "\n";
    return 0;
}