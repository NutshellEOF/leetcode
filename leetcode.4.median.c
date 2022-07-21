/*
Leetcode.4 计算两个有序数组的中位数
https://leetcode.cn/problems/median-of-two-sorted-arrays/
*/


#include <malloc.h>
#include <math.h>
#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //以下仅为一种解法，它的时间复杂度已经不满足要求
    //题目要求：算法的时间复杂度应该为 O(log (m+n))
    //这是通过双指针合并数组，受启发于Leetcode.88
    int p1 = 0, p2 = 0;
    int* sorted;
    sorted = (int*)malloc((nums1Size+nums2Size) * sizeof(int));
    int cur;
    while (p1 < nums1Size || p2 < nums2Size) {
        if (p1 == nums1Size) {
            cur = nums2[p2++];
        }
        else if (p2 == nums2Size) {
            cur = nums1[p1++];
        }
        else if (nums1[p1] < nums2[p2]) {
            cur = nums1[p1++];
        }
        else {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }
    //合并后数组的起止范围为0~p1+p2-1

    /*
    以下为常规求中位数的方法，过于麻烦
    我们直接使用后文中的算法
    double median_dest = (double)(nums1Size+nums2Size) / 2;
    if (floor(median_dest+0.5)==median_dest) {
        return (double)(sorted[(int)median_dest - 1] + sorted[(int)median_dest]) / 2;
    }
    else {
        return sorted[(int)((nums1Size+nums2Size-1) / 2)];
    }*/

    //共有p1+p2个元素
    //所以我们可以这样
    //但是请不要忘了类型转换
    //下方有两处地方都需要类型转换并且每一处都不能漏
    double half = (double)(p1 + p2) / 2;
    return (double)(sorted[(int)floor(half - 0.4)] + sorted[(int)floor(half + 0.4)]) / 2;
    //因为half要么是整数要么是几点五
    //加上0.4的话
    //整数：floor(half+0.4)==half floor(half-0.4)==half-1
    //小数：floor(half+0.4)==half floor(half-0.4)==half
}

