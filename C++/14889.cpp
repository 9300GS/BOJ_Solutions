#include <iostream>
#include <vector>
using namespace std;

int stat[21][21];
int n;
int team1_total = 0, team2_total = 0;
int min_difference = 99999999;
vector<int> team1, team2;

void recv(int num);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> stat[i][j];
        }
    }

    recv(1);
    cout << min_difference << "\n";

    return 0;
}

void recv(int num)
{
    if(num > n)
    {
        int difference = abs(team1_total - team2_total);
        if(difference < min_difference) min_difference = difference;
        return;
    }
    if(team1.size() < n/2)
    {
        int stat_inc = 0;
        for(int i=0;i<team1.size();i++)
        {
            stat_inc += (stat[team1[i]][num] + stat[num][team1[i]]);
        }
        team1.push_back(num);
        team1_total += stat_inc;

        recv(num+1);

        team1.pop_back();
        team1_total -= stat_inc;
    }
    if(team2.size() < n/2)
    {
        int stat_inc = 0;
        for(int i=0;i<team2.size();i++)
        {
            stat_inc += (stat[team2[i]][num] + stat[num][team2[i]]);
        }
        team2.push_back(num);
        team2_total += stat_inc;

        recv(num+1);

        team2.pop_back();
        team2_total -= stat_inc;
    }
}