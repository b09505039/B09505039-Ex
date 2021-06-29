#include <stdio.h>
#include <math.h>

int board[8], count=0;

void print(int n)                               //把所有解印出來，每一個解包含皇后"Q"跟空白的地方"-"
{
    int i, j;
    printf("\nSolution %d:\n", ++count);

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int check(int row, int col)                     //檢查皇后
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (board[i] == col)                    //已經有皇后了
            return 0;                           //回傳false
        else if (abs(board[i] - col) == abs(i - row))   
            return 0;
    }
    return 1;
}

void queen(int row, int n)                      //找出皇后的位置
{
    int col;
    for (col = 1; col <= n; ++col)
    {
        if (check(row, col))
        {
            board[row] = col;
            if (row == n)                       //到最後一列，印出結果
                print(n);
            else
                queen(row + 1, n);              
        }
    }
}
int main()
{
    queen(1, 8);
    return 0;
}