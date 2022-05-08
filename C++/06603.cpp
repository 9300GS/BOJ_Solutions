#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> s;
void recv(int* pick, int k);
void recv(int* pick, int k, int step);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        s.clear();
        int k;

        cin >> k;
        if(k == 0) return 0;

        for(int i=0;i<k;i++)
        {
            int temp;
            cin >> temp;
            s.push_back(temp);
        }
        int pick[6];

        recv(pick, k);
        cout << "\n";
    }

    return 0;
}

void recv(int* pick, int k)
{
    for(int i = 0; i <= k - 6; i++)
    {
        pick[0] = i;
        recv(pick, k, 1);
    }
    return;
}

void recv(int* pick, int k, int step)
{
    if(step == 6)
    {
        for(int i=0;i<6;i++)
        {
            cout << s[pick[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = pick[step-1] + 1; i <= k - (6-step); i++)
    {
        pick[step] = i;
        recv(pick, k, step+1);
    }
    return;
}

