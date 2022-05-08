#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;

    for(int i=0;i<c;i++)
    {
        string p;
        int n;
        deque<string> x;

        cin >> p;
        cin >> n;

        string array;
        cin >> array;
        
        string temp = "";
        for(int j=0;j<array.length();j++)
        {
            if(isdigit(array[j]))
            {
                temp += array[j];
            }
            else
            {
                if(!temp.empty())
                {
                    x.push_back(temp);
                }
                temp = "";
            }
        }

        bool reversed = false;
        bool error = false;

        for(int j=0;j<p.size();j++)
        {
            if(p[j] == 'R')
            {
                reversed = !reversed;
            }
            else if(x.size() > 0)
            {
                if(reversed) x.pop_back();
                else x.pop_front();
            }
            else
            {
                error = true;
                break;
            }
        }

        if(error)
        {
            cout << "error\n";
            continue;
        }

        cout << "[";

        int result_size = x.size();
        for(int j=0;j<result_size;j++)
        {
            if(reversed)
            {
                cout << x.back();
                x.pop_back();
            }
            else
            {
                cout << x.front();
                x.pop_front();
            }
            if(j != result_size - 1) cout << ",";
        }
        cout << "]\n";
    }
}