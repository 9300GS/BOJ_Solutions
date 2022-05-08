#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_request(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second != b.second) return (a.second < b.second);
    else return (a.first < b.first);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t-- > 0)
    {
        int n, m;
        cin >> n >> m;

        int booked[1001] = {0,};

        vector<pair<int,int>> request;
        for(int i=0;i<m;i++)
        {
            int a, b;
            cin >> a >> b;
            request.push_back(make_pair(a,b));
        }
        sort(request.begin(), request.end(), comp_request);

        int s = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=request[i].first;j<=request[i].second;j++)
            {
                if(booked[j] == 0)
                {
                    booked[j] = 1;
                    s++;
                    break;
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}