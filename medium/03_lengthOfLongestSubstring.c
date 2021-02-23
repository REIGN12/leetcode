#include<stdio.h>
// 输入包括英文字母，数字，符号，空格
#define NUM (126-32+1)
int lengthOfLongestSubstring(char* s)
{
    if(!*s) return 0;
    // albet for booking idx
    int albet[NUM]; for(int i = 0;i<NUM;++i)albet[i] = -1;
    int i=0,j=0;
    albet[s[0]-' '] = 0;
    int res = 0;
    while (1)
    {
        // move j
        while (s[++j] && albet[s[j]-' ']<0) albet[s[j]-' '] = j;
        // update res
        if(j-i > res) res = j-i;
        // break condition
        if(!s[j]) break;
        // move i
        i = albet[s[j]-' '] + 1;
        // update albet
        for(int l = 0;l<NUM;++l)
        {
            if (albet[l] < i) albet[l] = -1;
        }
        albet[s[i]-' '] = i;    
        albet[s[j]-' '] = j;    
    }
    return res;
}

int main(int argc, char* argv[])
{
    int res = lengthOfLongestSubstring(argv[1]);
    printf("%d\n",res);
    return 0;
}