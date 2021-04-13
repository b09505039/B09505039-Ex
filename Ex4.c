#include <stdio.h>
#include <string.h> 
void swap(char* x, char* y) ;

void permute(char* a, int l, int r) ;

void combinationUtil(char arr[], char data[], int start, int end, int index, int r);

void printCombination(char arr[], int n, int r)
{
    char data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        printf("combinations:(");
        for (int j=0; j<r; j++)
            printf("%c ", data[j]);
        printf("%c)",8);
        printf("\npermutations:");
        permute(data, 0, r-1);
        printf("\n");
        return;
    }
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 
void swap(char* x, char* y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void permute(char* a, int l, int r) 
{ 
    int i; 
    if (l == r) {
        printf("(");
        for (int j=0; j<r+1; j++)
            printf("%c ", a[j]);
        printf("%c)",8);
        }
    else { 
        for (i = l; i <= r; i++) { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r); 
            swap((a + l), (a + i)); 
        } 
    } 
} 

int main()
{
    printf("enter the distinct objects:");
    char arr[10];
    scanf("%s", arr); 
    int n = strlen(arr);
    int r;
    printf("enter the k:");
    scanf("%d", &r);
    printCombination(arr, n, r);
}