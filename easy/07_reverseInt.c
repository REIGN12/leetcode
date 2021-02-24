#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// use bit-wise operator
const int MAX_INT = (unsigned)(-1) >> 1;
const int MIN_INT = ~MAX_INT;
const int L = 10;

inline char* Int2s_r(int x);
inline int isBounded(char* xs);

// first change to string
// caller free the mem
char* Int2s_r(int x)
{
    char* res = malloc((L+2) * sizeof(char));
    if(!x)
    {
        res[0] = '0';
        res[1]=0;
    }
    else
    {
        int i = 0;
        unsigned num; // 注意到最小的负数，其相反数不能用 Int32 表示！
        if(x<0){res[i++]='-';num = (unsigned)(~x)+1;}
        else num = x;
        int tmp;int c = 0;
        do
        {
            tmp = num%10;
            if(c || tmp)
            {
                res[i++] = '0' + tmp;
                c++;
            }
        } while (num/=10);
        res[i] = 0;
    }
    return res;
}
int isBounded(char* xs)
{
    int res = 0;
    char max_s[L+2];
    sprintf(max_s,"%d",MAX_INT);
    char min_s[L+2];
    sprintf(min_s,"%d",MIN_INT);
    if(xs[0] != '-')
    {
        if(strlen(xs) < L) res = 1;
        else
        {
            int i = 0;
            while(xs[i] == max_s[i]) i++;
            if(xs[i] < max_s[i]) res = 1;
        }
    }
    else
    {
        if(strlen(xs) < L+1) res = 1;
        else
        {
            int i = 1;
            while(xs[i] == min_s[i]) i++;
            if(xs[i] < min_s[i]) res = 1;
        }
    }
    return res;
}

int reverse(int x)
{
    int res;
    char* xs = Int2s_r(x);
    // 先判断是否越界
    if(!isBounded(xs)) res = 0;
    else sscanf(xs,"%d",&res);       
    free(xs);
    return res;
}

int main(int argc, char* argv[])
{
    /*
    int t = MIN_INT;
    printf("%u\n",(unsigned)(-t));
    */
    int tmp;//sscanf(argv[1],"%d",&tmp);
    tmp = 10;//-2147483648;
    printf("%d\n",tmp);
    printf("%d\n",MIN_INT);
    printf("%d\n",MAX_INT);
    int test = reverse(tmp);
    printf("%d\n",test);
    return 0;
}