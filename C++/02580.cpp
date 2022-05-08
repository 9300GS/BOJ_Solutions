#include <iostream>
using namespace std;

void recv(int num);

int sudoku[9][9];
int horizontal[9][10] = {0,};
int vertical[9][10] = {0,};
int square[9][10] = {0,};

bool exit_flag = false;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int temp;
            cin >> temp;
            sudoku[i][j] = temp;
            horizontal[i][temp] = 1;
            vertical[j][temp] = 1;
            square[(i/3) * 3 + j/3][temp] = 1;
        }  
    }
    recv(0);

    return 0;
}

void recv(int num)
{
    int a = num / 9, b = num % 9;
    if(num == 9*9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit_flag = true;
        return;
    }
    if(sudoku[a][b] != 0)
    {
        return recv(num+1);
    }
    for(int i=1;i<=9;i++)
    {
        if(!horizontal[a][i] && !vertical[b][i] && !square[(a/3)*3+b/3][i])
        {
            sudoku[a][b] = i;
            horizontal[a][i] = 1;
            vertical[b][i] = 1;
            square[(a/3)*3+b/3][i] = 1;

            recv(num + 1);

            sudoku[a][b] = 0;
            horizontal[a][i] = 0;
            vertical[b][i] = 0;
            square[(a/3)*3+b/3][i] = 0;
        }
        if(exit_flag) return;
    }
}