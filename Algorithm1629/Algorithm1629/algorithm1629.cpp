#include<stdio.h>
#include<math.h>

//문제에서 제시한 2147483647는 int의 max값
//분할 정복을 통해 재귀 호출을 사용하여 결과를 만들어냄

long long op(int A, int B, int C) {

	if (B == 1)
		return A;

	else
	{
		long long temp = op(A, B / 2, C);

		//B가 홀수일 경우 A를 한번 더 곱해야함

		if (B % 2 == 1)
			return ((temp * temp) % C * A) % C;
		else
			return (temp * temp) % C;
	}


}


int main(void) {

	int A, B, C;
	long long result;

	printf("A,B,C 입력\n");
	scanf_s("%d %d %d", &A, &B, &C);

	result = op(A, B, C);
	printf("%lld", result);


	return 0;

}