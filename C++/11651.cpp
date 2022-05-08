#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Coordinate
{
public:
    int x, y;
    Coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool compare(const Coordinate &a, const Coordinate &b)
{
    if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<Coordinate> list;

    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        list.push_back(Coordinate(x,y));
    }

    sort(list.begin(), list.end(), compare);

    for(int i=0;i<n;i++)
    {
        cout << list[i].x << " " << list[i].y << "\n";
    }
    
    return 0;
}