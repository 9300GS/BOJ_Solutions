#include <iostream>
#include <vector>
using namespace std;

int n, m;
int chicken_num;
int minimal_chicken_dist = 99999999;
vector<pair<int, int>> houses, chickens_candidate, chickens;

void recv(int chicken_no);
int dist(pair<int, int> house, pair<int, int> chicken);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp;
            cin >> temp;
            if(temp == 1) houses.push_back(make_pair(i, j));
            else if(temp == 2) chickens_candidate.push_back(make_pair(i,j));
        }
    }
    chicken_num = chickens_candidate.size();

    recv(0);
    cout << minimal_chicken_dist << "\n";
    return 0;
}

int dist(pair<int, int> house, pair<int, int> chicken)
{
    return abs(house.first - chicken.first) + abs(house.second - chicken.second);
}

void recv(int chicken_no)
{
    if(chicken_no == chicken_num)
    {
        if(chickens.size() != m) return;

        int dist_total = 0;
        for(int i=0;i<houses.size();i++)
        {
            int min = 99999999;
            for(int j=0;j<chickens.size();j++)
            {
                int d = dist(houses[i], chickens[j]);
                if(d < min) min = d;
            }
            dist_total += min;
        }
        if(dist_total < minimal_chicken_dist) minimal_chicken_dist = dist_total;
        return;
    }

    recv(chicken_no + 1);

    chickens.push_back(chickens_candidate[chicken_no]);
    recv(chicken_no + 1);
    chickens.pop_back();

    return;
}