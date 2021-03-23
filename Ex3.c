#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

struct content
{
    int progress;
    char name[10];
    int lastscore;
    int thisscore;
    
}Content[5];

char *names[10] = {"BLAKE","ODIN", "JADA", "KELVIN", "KALEB", "PIPER", "JAYSON", "JULIAN", "ANDI", "ABBY"};

int compare_progress(int n, int m)
{
    if (n == m)
        return 0;
    else if (n < m)
        return 1;
    else if (n > m)
        return -1;
}

int compare(const void *a, const void *b)
{
    struct content *pt1 = (content*)a;
    struct content *pt2 = (content*)b;
    int d = compare_progress(pt1->progress, pt2->progress);
    if (d == -1)
        return -1;
    else if (d == 1)
        return 1;
    
    //return (*(int *)a - *(int *)b);
}

void SWAP(char* p1, char* p2, int width){
	int i = 1;
	for(i = 1; i <= width; i++){
		char tmp = *p1;
		*p1++ = *p2;
		*p2++ = tmp;
	}
	
}

void bubbleSort(void *base, int n, size_t width, int (*compare)(const void *, const void *)){
	int i = 0, j, temp;
	for(i = 0; i < n; i++){
		for(j = n-1; j > i; j--){
			temp = (compare)((char*)(base + j*width), (char*)(base + (j-1)*width));
			if(temp == -1){
				SWAP((char*)(base + j*width), (char*)(base + (j-1)*width), width);
			}
		}
	}
}

void selectionSort(void *base, int n, size_t width, int (*compare)(const void *, const void *)){
	int i = 0, j, tmp;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if((compare)((char*)(base + i*width), (char*)(base + (j)*width)) > 0){
				SWAP((char*)(base + i*width), (char*)(base + (j)*width), width);
			}
		}
	}
}

// void insertionSort(void *base, int n, size_t width, int (*compare)(const void *, const void *)){
	
//     int i, wall, j;
//     for (i = 1; i < n; i++) {
//         wall = (char*)(base + i*width);
//         j = i - 1;
//         while (j >= 0 && (char*)(base + j*width) > wall) {
//             //arr[j + 1] = arr[j];
//             SWAP((char*)(base + j*width), (char*)(base + (j-1)*width), width);
//             j = j - 1;
//         }
//         (char*)(base + j*width) = wall;
//     }
// }

// void ranname(char *Name[])
// {
//     int j;
//     j = rand()%10;
//     Name[0] = names[j];
// }

swap(char *p, char *q)
{
    while (*p != '\0')
    {
        *q++ = *p++;
    }
    *q = '\0';
}

int main()
{
    FILE *writefile, *readfile;
    int i, j;
    char *Name[1];
    writefile = fopen("C:\\data.txt", "w");       //寫入
    readfile = fopen("C:\\data.txt", "r");        //讀取
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i)
    {
        //隨機生成
        Content[i].lastscore = (rand() % 100);
        Content[i].thisscore = (rand() % 100);
        Content[i].progress = Content[i].thisscore - Content[i].lastscore;
        j = rand()%10;
        Name[0] = names[j];
        swap(Name[0], Content[i].name);
        //Content[i].name = names[j];
        //ranname(Name);
        //Content[i].name = ;
    }


    //看要哪一種
    bubbleSort(Content, 5, sizeof(content), compare);
    selectionSort(Content, 5, sizeof(content), compare);
    //insertionSort(Content, 5, sizeof(content), compare);

    printf("progress    name    score   last score\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%8d%8s%9d%13d\n", Content[i].progress, Content[i].name, Content[i].thisscore, Content[i].lastscore);
    }

    if (writefile == NULL || writefile == NULL)   //檔案不存在
    {
        printf("There's no file!\n");
    }
    else
    {
        fprintf(writefile, "progress    name    score   last score\n");
        for (int i = 0; i < 5; i++)
        {
            fprintf(writefile, "%8d%8s%9d%13d\n", Content[i].progress, Content[i].name, Content[i].thisscore, Content[i].lastscore);    //寫入檔案
        }
    }

    fclose(writefile);
    fclose(readfile);

    return 0;
}