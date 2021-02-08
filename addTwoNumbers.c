#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2)
{
    int carry = 0;
    struct ListNode* res = malloc(sizeof(struct ListNode));
    struct ListNode* tmp = res;

    while (1)
    {
        tmp->val = l1->val+l2->val+carry;
        if(tmp->val>=10){tmp->val-=10; carry=1;}
        else carry = 0;
        if((l1->next==NULL) && (l2->next==NULL) && !carry)
        {
            tmp->next = NULL;
            break;
        }
        else
        {
            if(l1->next == NULL) l1->val = 0;
            else l1 = l1->next;
            if(l2->next == NULL) l2->val = 0;
            else l2 = l2->next;

            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
    }
    return res;
}
    /*
    int s = l1->val+l2->val+carry;
    tmp->val = s%10; carry = s/10;
    // 小心惰性求值的trick
    while ((l1 = l1->next)!=NULL && (l2 = l2->next)!=NULL)
    {
        tmp->next = malloc(sizeof(struct ListNode));
        tmp = tmp->next;
        s = l1->val+l2->val+carry;
        tmp->val = s%10; carry = s/10;
    }
    if(l1==NULL)
    {
        while((l2 = l2->next)!=NULL)
        {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
            s = l2->val+carry;
            tmp->val = s%10;carry=s/10;
        }
    }
    else
    {
        do
        {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
            s = l1->val+carry;
            tmp->val = s%10;carry=s/10;
        } while ((l1=l1->next)!=NULL);
    }
    if(carry)
    {
        tmp->next = malloc(sizeof(struct ListNode));
        tmp->next->val = 1;
        tmp->next->next = NULL;
    }
    else tmp->next = NULL;
    */


// for testing;

struct ListNode* Constructor(char* s)
{
    // first reverse the string
    int length = strlen(s);
    for(int i = 0; i<length/2;i++)
    {
        char tmp = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = tmp;
    }

    struct ListNode* res = malloc(sizeof(struct ListNode));
    struct ListNode* tmp = res;
    tmp->val = *s -'0';
    while (*(++s))
    {
        tmp->next = malloc(sizeof(struct ListNode));
        tmp = tmp->next;
        tmp->val = *s - '0';
    }
    tmp->next = NULL;

    return res;
}

void ltos(struct ListNode* l,char* s)
{
    while(l!=NULL) 
    {
        sprintf(s,"%d",l->val);
        s++;l = l->next;
    }
    *s = 0;
}
void Traverse(struct ListNode* l)
{
    char s[100];
    ltos(l,s);
    int length = strlen(s);
    for(int i = length-1;i>=0;--i)printf("%c",s[i]);
}


int main(int argc, char* argv[])
{
    //char s1[100] = "15";
    //char s2[100] = "999";
    struct ListNode* l1 = Constructor(argv[1]/**/);
    struct ListNode* l2 = Constructor(argv[2]/**/);
    Traverse(l1);printf(" + ");
    Traverse(l2);printf(" = ");

    Traverse(addTwoNumbers(l1,l2));printf("\n");
    return 0;
}