#include<stdio.h>
#include<stdlib.h>

// try to design an algorithm of O(log(l1+l2))
double findMedianSortedArrays(int* nums1,int nums1Size,int* nums2,int nums2Size)
{
    double res;
    if((nums1Size+nums2Size) % 2 == 1)
    {
        const int half = (nums1Size+nums2Size)/2;
        // consider l1 first
        int small = 0, big = nums1Size-1;
        int mid = (small+big)/2;
        while (small<big)
        {
            if( (half-mid-1>=nums2Size) || ( (half-mid-1==nums2Size-1) && (nums1[mid]<nums2[nums2Size-1]) ) ) small = mid;
            else if((half-mid<0) || ((half-mid==0)&&(nums1[mid]>nums2[0])) ) big = mid;
            else  

            
        }
        

    }
    
    return res;
}


int main(int argc, char* argv[])
{

    return 0;
}