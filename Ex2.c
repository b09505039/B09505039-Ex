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



void ranname(char *Name[])
{
    int j;
    j = rand()%10;
    Name[0] = names[j];
}

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



    qsort(Content, 5, sizeof(content), compare);

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