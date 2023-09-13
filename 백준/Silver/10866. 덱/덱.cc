#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <string.h>
int main()
{
    deque<int> d;
    int n,i,k;
    char arr[30];
    char *ptr;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
        gets(arr);

        if(!strcmp(arr,"pop_front"))
        {
            if(d.empty()) printf("-1\n");
            else
            {
                printf("%d\n",d.front());
                d.pop_front();
            }
        }
        else if(!strcmp(arr,"pop_back"))
        {
            if(d.empty()) printf("-1\n");
            else
            {
                printf("%d\n",d.back());
                d.pop_back();
            }
        }
        else if(!strcmp(arr,"size"))
        {
            printf("%d\n",d.size());
        }
        else if(!strcmp(arr,"empty"))
        {
            if(d.empty()) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(arr,"front"))
        {
            if(d.empty()) printf("-1\n");
            else printf("%d\n",d.front());
        }
        else if(!strcmp(arr,"back"))
        {
            if(d.empty()) printf("-1\n");
            else printf("%d\n",d.back());
        }
        else
        {
            ptr = strtok(arr," ");
            if(!strcmp(ptr,"push_front"))
            {
                ptr = strtok(NULL," ");
                k = atoi(ptr);
                d.push_front(k);
            }
            else
            {
                ptr = strtok(NULL," ");
                k = atoi(ptr);
                d.push_back(k);
            }
        }
    }
    return 0;
}
