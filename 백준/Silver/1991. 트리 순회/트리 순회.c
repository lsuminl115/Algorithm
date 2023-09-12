#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char left;
    char right;
};
struct Node node[99];
void f1(char c)
{
    printf("%c",c);
    if(node[c].left!='.') f1(node[c].left);
    if(node[c].right!='.') f1(node[c].right);
}
void f2(char c)
{
    if(node[c].left!='.') f2(node[c].left);
    printf("%c",c);
    if(node[c].right!='.') f2(node[c].right);
}
void f3(char c)
{
    if(node[c].left!='.') f3(node[c].left);
    if(node[c].right!='.') f3(node[c].right);
    printf("%c",c);
}
int main()
{
    char ch,a='A';
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf(" %c",&ch);
        scanf(" %c %c",&node[ch].left,&node[ch].right);
    }
    f1(a);
    puts("");
    f2(a);
    puts("");
    f3(a);
    return 0;
}
