/*
Leetcode.9 回文数
https://leetcode.cn/problems/palindrome-number/
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

bool isPalindrome(int x) {
	//整数转字符串自然可以
	//但是我们此处使用数学方法
	//任给一个数比如12544
	// 它除以10后取余数，就是4，末位 n = x%10
	// 这个数减去4，除以10，得到新的数1254 x=(x-n)/10,n=x%10
	// 再次取余，4即为第二位
	// x=(x-n)/10, n=x%10 5为第三位
	// 新数各位都将知道
	//这样依次反转后得到的新数如果等于原数，那么就返回1
	//首先负数直接返回0
	if (x < 0 || (x%10==0)&&(x!=0)) {
		return 0;
	}
	//注意避免溢出
	//但其实说实话
	//溢出的都不是回文数
	//但为了计算简单，直接强制类型转换吧（不转换也可以）
	long rx = 0, tmp = (long)x;
	int n = 0;
	//不清楚边界，最好是用while
	while (tmp!=0) {
		n = tmp % 10;
		rx = rx * 10 + n;
		tmp = (tmp - n) / 10;
	}
	if (rx == (long)x) {
		return 1;
	}
	else {
		return 0;
	}
	//但是如果最后一个数是0，反转后不是标准的形式，
	//那么直接在上面第一步if里排除

}

int main() {
	int xs[10] = { 0,121,1245,4554,-124,-12121,1234567899,12450,1210,1234 };
	for (size_t i = 0; i < 10; i++) {
		printf("%d 是否是回文数：%d\n", xs[i], isPalindrome(xs[i]));
	}
	return 0;
}