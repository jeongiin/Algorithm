#include<stdio.h>
#include<math.h>

//�������� ������ 2147483647�� int�� max��
//���� ������ ���� ��� ȣ���� ����Ͽ� ����� ����

long long op(int A, int B, int C) {

	if (B == 1)
		return A;

	else
	{
		long long temp = op(A, B / 2, C);

		//B�� Ȧ���� ��� A�� �ѹ� �� ���ؾ���

		if (B % 2 == 1)
			return ((temp * temp) % C * A) % C;
		else
			return (temp * temp) % C;
	}


}


int main(void) {

	int A, B, C;
	long long result;

	printf("A,B,C �Է�\n");
	scanf_s("%d %d %d", &A, &B, &C);

	result = op(A, B, C);
	printf("%lld", result);


	return 0;

}