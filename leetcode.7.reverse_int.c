#include <stdio.h>
#include <limits.h>

int reverse(int x) {

	long rx = 0;
	//���ѭ��������з�ת���ⱻ10��������Ĺ���
	while (x!=0) {
		rx = rx * 10 + x % 10;
		x = (x - x % 10) / 10;
	}
	//����Ҫ�ж��Ƿ����
	if (rx < INT_MIN || rx > INT_MAX) {
		rx = 0;
	}
	return (int)rx;
}

int main() {
	long testarr[10] = { 0,1090009999,140,1245,-3265,-25,-5400,1234567899,-1234567899,10000 };
	for (size_t i = 0; i < 10; i++) {
		
		printf("%d�ķ�ת��: %d\n", testarr[i], reverse(testarr[i]));
	}
	return 0;
}