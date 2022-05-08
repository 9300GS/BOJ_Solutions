#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int>> low;
    priority_queue<int, vector<int>, greater<int>> high;
    int median;

    int n;
    cin >> n;

    cin >> median;
    cout << median << "\n";
    for(int i=1;i<n;i++)
    {
        int input;
        cin >> input;
        
        if(input >= median) high.push(input);
        else low.push(input);

        if(low.size() > high.size())
        {
            while(low.size() > high.size())
            {
                high.push(median);
                median = low.top();
                low.pop();
            }
        }
        else if(high.size() > low.size()+1)
        {
            while(high.size() > low.size()+1)
            {
                low.push(median);
                median = high.top();
                high.pop();
            }
        }

        cout << median << "\n";
    }

    return 0;
}