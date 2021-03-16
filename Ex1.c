#include <stdio.h>
#include <string.h>

void BubbleSort(char a[], int len)       
{                                                   
    int i, j, temp;
    for (i = 0; i < len - 1; i++)               
        for (j = 0; j < len - 1 - i; j++)       
	    if (a[j] > a[j + 1])                
	    {
	        temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
	    }
}

void insertionSort(char arr[], int len)
{
    int i, wall, j;
    for (i = 1; i < len; i++) {
        wall = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > wall) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = wall;
    }
}

void swap(char *newmin, char *first) 
{ 
    char temp = *newmin; 
    *newmin = *first; 
    *first = temp; 
} 
  
void selectionSort(char arr[], int len) 
{ 
    int i, j, min; 
  
    for (i = 0; i < len-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < len; j++) 
          if (arr[j] < arr[min]) 
            min = j; 

        swap(&arr[min], &arr[i]); 
    } 
} 

int main() 
{ 
    int i, n = 100;
    char al[20];
    char array[n];
    printf("Which algorithm do you need?\n");
    scanf("%s", al);

    if (al[0]=='b')
    {
        printf("Enter your data:\n");
        scanf("%s", array);         //gets(array);
        BubbleSort(array, strlen(array));
        for (i = 0; i < strlen(array); ++i)
		    printf("%c ", array[i]);
    }
    else if (al[0]=='i')
    {
        printf("Enter your data:\n");
        scanf("%s", array);         //gets(array);
        insertionSort(array, strlen(array));
        for (i = 0; i < strlen(array); ++i)
		printf("%c ", array[i]);
    }
    else if (al[0]=='s')
    {
        printf("Enter your data:\n");
        scanf("%s", array);         //gets(array);
        selectionSort(array, strlen(array));
        for (i = 0; i < strlen(array); ++i)
		    printf("%c ", array[i]);
    }
    else
    {
        printf("Sorry, we don't have that algorithm.\n");
    }
    
    //puts(array);
	return 0;
}
