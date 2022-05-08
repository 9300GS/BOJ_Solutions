#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare_end(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> schedule;
    for(int i=0;i<n;i++)
    {
        int start, end;
        cin >> start >> end;
        schedule.push_back(make_pair(start, end));
    }
    sort(schedule.begin(), schedule.end(), *compare_end);

    int end_time = 0;
    int s = 0;
    for(int i=0;i<n;i++)
    {
        if(schedule[i].first >= end_time)
        {
            end_time = schedule[i].second;
            s++;
        }
    }

    cout << s << "\n";

    return 0;
}