#include <iostream>
#include <cstring>
using namespace std;

void recv(int row);

int result = 0;
int board[15];
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(board, 100, sizeof(board));
    cin >> n;
    recv(0);

    cout << result << "\n";

    return 0;
}

void recv(int row)
{
    if(row == n)
    {
        result++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        bool valid = true;

        for(int j=1;j<=row;j++)
        {
            if(board[row-j] == i || board[row-j] == i+j || board[row-j] == i-j)
            {
                valid = false;
                break;
            }
        }

        if(valid)
        {
            board[row] = i;
            recv(row+1);
            board[row] = 100;
        } 
    }
    return;
}

