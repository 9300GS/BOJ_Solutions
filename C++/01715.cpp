#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> cards;

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;
        cards.push(input);
    }

    int s = 0;
    while(cards.size() >= 2)
    {
        int a, b;
        a = cards.top();
        cards.pop();
        b = cards.top();
        cards.pop();

        s += a+b;
        cards.push(a+b);
    }

    cout << s << "\n";

    return 0;
}