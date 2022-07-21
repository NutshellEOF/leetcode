/*
Leetcode.4 �������������������λ��
https://leetcode.cn/problems/median-of-two-sorted-arrays/
*/


#include <malloc.h>
#include <math.h>
#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //���½�Ϊһ�ֽⷨ������ʱ�临�Ӷ��Ѿ�������Ҫ��
    //��ĿҪ���㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n))
    //����ͨ��˫ָ��ϲ����飬��������Leetcode.88
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
    //�ϲ����������ֹ��ΧΪ0~p1+p2-1

    /*
    ����Ϊ��������λ���ķ����������鷳
    ����ֱ��ʹ�ú����е��㷨
    double median_dest = (double)(nums1Size+nums2Size) / 2;
    if (floor(median_dest+0.5)==median_dest) {
        return (double)(sorted[(int)median_dest - 1] + sorted[(int)median_dest]) / 2;
    }
    else {
        return sorted[(int)((nums1Size+nums2Size-1) / 2)];
    }*/

    //����p1+p2��Ԫ��
    //�������ǿ�������
    //�����벻Ҫ��������ת��
    //�·��������ط�����Ҫ����ת������ÿһ��������©
    double half = (double)(p1 + p2) / 2;
    return (double)(sorted[(int)floor(half - 0.4)] + sorted[(int)floor(half + 0.4)]) / 2;
    //��ΪhalfҪô������Ҫô�Ǽ�����
    //����0.4�Ļ�
    //������floor(half+0.4)==half floor(half-0.4)==half-1
    //С����floor(half+0.4)==half floor(half-0.4)==half
}

