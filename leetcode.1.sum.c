#include <malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* p = (int*)malloc(sizeof(int) * 2);
	int i1 = 0, i2 = 0;
	for (; i1 < numsSize; ++i1) {
		for (i2 = i1 + 1; i2 < numsSize; ) {
			if ((nums[i1] + nums[i2]) == target) {
				p[0] = i1;
				p[1] = i2;
				goto DONE;
			}
			++i2;
		}
	}
DONE:;

	*returnSize = 2;
	return p;
}
