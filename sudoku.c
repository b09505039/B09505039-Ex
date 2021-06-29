#include <stdio.h>
#include <stdlib.h>
 
int check(int sudoku[9][9], int row, int col, int num)                  //檢查預設的值是否正確
{   
    int i = 0;
    for (i = 0; i < 9; i++){
        if (sudoku[row][i] == num){                                     //如果某行有重複的數字，不行
            return 0;
        }
    }
    for (i = 0; i < 9; i++){
        if (sudoku[i][col] == num){                                     //如果某列有重複的數字，不行
            return 0;
        }
    }

    int Row3 = row - row % 3;                                           
    int Col3 = col - col % 3;
   
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (sudoku[i + Row3][j + Col3] == num){                     //檢查再九宮格裡面有沒有重複的數字
                return 0;
            }
        }
    }
    return 1;
}

int solve(int sudoku[9][9], int row, int col)
{
    if (row == 9 - 1 && col == 9){                                      //如果行數到了第九行就代表全部都結束了
        return 1;               
    }

    if (col == 9)                                                       //讀到第九列之後，換到下一行
    {
        row++;
        col = 0;
    }

    if (sudoku[row][col] > 0){                                          //如果某行某列已經確定不是預設的0之後，就可以往下一列執行
        return solve(sudoku, row, col + 1);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (check(sudoku, row, col, i)==1)                              //開始確認所預設帶入的值是否正確
        {
            sudoku[row][col] = i;                                       //確認後就把該位置放入假設的值

            if (solve(sudoku, row, col + 1)==1)                         //也要確認在這樣的情況下，下一列是否也正確
                return 1;
        }

        sudoku[row][col] = 0;                                           //假設錯誤，把預設改回0再繼續試
    }
    return 0;
}
 
int main()
{
    FILE *file;
	file = fopen("C:\\sudoku.csv", "r");
	char c;
    int sudoku[9][9]={0};

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			fscanf(file, "%c", &c);
            
			if(c == ',' || c == '\n'){                                  //因為csv檔適用逗號隔開的，所以遇到逗號或是換行時，要在往下一個找
				j--;
			}
			else{
				if('0' <= c && c <= '9'){                               //打讀到的字元轉換成數值
					sudoku[i][j] = c - '0';
				}
				else{
					sudoku[i][j] = 0;                                   //底線的部分先用0來代替
				}	
            }
		}
	}
    solve(sudoku, 0, 0);                                                //進入函數中開始檢查
    for (int i = 0; i < 9; i++)                                         //最後再一併印出結果
    {
        for (int j = 0; j < 9; j++)
            printf("%d ",sudoku[i][j]);
        printf("\n");
    }
   
    fclose(file);

    return 0;
}