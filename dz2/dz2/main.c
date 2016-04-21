#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 10000
struct el
{
    char str[MAX_N];
    struct el * next;
    int num;
};
int get(char a)
{
    if(a - 'a' >= 0)
        return a - 'a';
    return a - 'A';
}
int check(char * a, char * b)
{
    int end;
    if (strlen(a) < strlen(b))
        end = (int)strlen(a);
    else
        end = (int)strlen(b);
    for(int i = 0; i < end; i++)
    {
        int m = get(a[i]);
        int n = get(b[i]);
        if(m != n)
        {
            if(n < m)
                return -1;
            return 1;
        }
    }
    if(end == strlen(a))
        return 1;
    return -1;
    
}
struct el * add(struct el * x, struct el * p, struct el ** q)
{
    if(!p)
    {
        p = x;
        *q = x;
    }
    else
    {
        int f = 0;
        struct el * pp = p;
        struct el * d = NULL;
        while(pp)
        {
            if(check(pp->str, x->str) < 0)
            {
                if(d == NULL)
                {
                    x -> next = p;
                    p = x;
                }
                else
                {
                    x->next = pp;
                    d->next = x;
                }
                f = 1;
                break;
            }
            else
            {
                d = pp;
                pp = pp->next;
                
            }
        }
        if(!f)
        {
            (*q)->next = x;
            *q = x;
        }
    }
    return p;
}
int main()
{
    char s[MAX_N];
    fgets(s, MAX_N, stdin);
    int len = (int)strlen(s);
    //rdkprintf("%s", s);
    int t = 0;
    struct el * p = NULL;
    struct el * q = NULL;
    int check1 = 0;
    // check numbers of uppercase letters
    int err = 0;//checker
    if(s[len - 2] != '.') err = 1;
    int k = 0;
    for(int i = 0; i < len - 1; i++)
    {
        
        if(s[i] - 'a' < 0)
            check1++;
       // printf("%d", check1);
    if(((s[i] - 'A' >= 0) && (s[i] - 'A' < 26))||(s[i] == '.')||(s[i]==','));else
            err = 1;
        //printf("%d", err);
        if(s[i] == ',' || s[i] == '.')
        {
            
            if(check1 <= 6 && check1); else
                err = 1;
            
            struct el * x = malloc(sizeof(struct el));
            x -> next = NULL;
            memcpy(x -> str, s + t, i - t);
            t = i + 1;
            x->num = k;
            k++;
            p = add(x, p, &q);
        }
        check1 = 0;
    }
    struct el * q1 = p;
    
    if(err)
      printf("error"); else
    while(p)
    {
        printf("%d ", p->num);
        int leng = (int)strlen(p->str);
        
        for(int i = 0; i < leng; i++)
        {
            printf("%c", p->str[i]);
        }
        printf("\n");
        
        p = p->next;
    }
    struct el * d = q1;
    while(q1)
    {
        d = q1;
        
        q1 = q1->next;
        free(d);
        
    }
}