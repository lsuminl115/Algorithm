#include <stdio.h>
#include <stdlib.h>
int n,arr[500001],sort[500001];
void mergesort(int left, int right)
{
    int mid = (left + right) / 2, i = left, j = mid + 1, k = left, t;

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            sort[k] = arr[i];
            i++;
        }
        else
        {
            sort[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid)
    {
        for(t = j; t <= right; t++)
        {
            sort[k] = arr[t];
            k++;
        }
    }
    else
    {
        for(t = i; t <= mid; t++)
        {
            sort[k] = arr[t];
            k++;
        }
    }

    for(t = left; t <= right; t++)
    {
        arr[t] = sort[t];
    }
}
void merge(int left, int right)
{
    int mid = (left + right) / 2;
    if(left < right)
    {
        merge(left, mid);
        merge(mid + 1, right);
        mergesort(left, right);
    }
}

int f(int x)
{
    int l = 1;
    int r = n;
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(arr[mid] < x)
        {
            l = mid + 1;
        }
        else if(arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,m,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge(1,n);

    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(f(a)) printf("1 ");
        else printf("0 ");
    }
    return 0;
}
