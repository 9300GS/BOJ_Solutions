#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int digit_min = 0;
    int digit_max = 9;

    int stack_min = 0, stack_max = 0;
    vector<int> result_max, result_min;

    for(int i=0;i<k;i++)
    {
        char op;
        cin >> op;

        if(op == '>')
        {
            for(int i=stack_max;i>=0;i--)
            {
                result_max.push_back(digit_max - i);
            }
            digit_max -= stack_max + 1;
            stack_max = 0;

            stack_min++;
        }
        else if(op == '<')
        {
            stack_max++;

            for(int i=stack_min;i>=0;i--)
            {
                result_min.push_back(digit_min + i);
            }
            digit_min += stack_min + 1;
            stack_min = 0;
        }
    }
    for(int i=stack_max;i>=0;i--)
    {
        result_max.push_back(digit_max - i);
    }
    for(int i=stack_min;i>=0;i--)
    {
        result_min.push_back(digit_min + i);
    }


    for(int i=0;i<result_max.size();i++)
    {
        cout << result_max[i];
    }
    cout << "\n";
    for(int i=0;i<result_min.size();i++)
    {
        cout << result_min[i];
    }
    cout << "\n";

    return 0;
}