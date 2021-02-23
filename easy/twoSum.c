#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums,int numsSize,int target,int* returnSize)
{
    int* res = malloc(2*sizeof(int));
    *returnSize = 2;
    
    for(int i = 0;i<numsSize;++i)
    {
        for(int j = 0;j<numsSize;++j)
        {
            if(i != j && nums[i]+nums[j] == target)
            {
                res[0] = i;res[1] = j;
                return res;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int numsSize = argc-2;
    int target; sscanf(argv[1],"%d",&target);
    int* nums = malloc(numsSize* sizeof(int));
    
    for(int i = 0; i < numsSize;++i) sscanf(argv[i+2],"%d",nums+i);

    int returnSize;
    
    int* res = twoSum(nums,numsSize,target,&returnSize);

    printf("target = %d\n",target);
    printf("numsSize = %d\n",numsSize);

    printf("res = [%d,%d]\n",res[0],res[1]);

    free(nums);
    free(res);
    return 0;
}
