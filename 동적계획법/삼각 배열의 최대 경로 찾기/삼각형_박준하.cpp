/*
* 2018114686 ������ ���� �� �ҽ� �ڵ带 �ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 130

int N;
int T[MAX][MAX];	//���� �Է� ��
int D[MAX][MAX];	//����� ���� ����
int P[MAX][MAX];	//��� Ž����

void Solve() {
	//�Ʒ��� ���� ������� ��ȸ
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < i+1; j++) {
			//�ٷξƷ�, ������ �Ʒ� �� ū ���� ����
			if (D[i+1][j] <= D[i+1][j + 1]) {
				P[i][j] = j + 1;
				D[i][j] += D[i + 1][j + 1];
			}
			else {
				P[i][j] = j;
				D[i][j] += D[i + 1][j];
			}
		}
	}
}

void PrintPath() {
	printf("%d ", T[0][0]);
	int nextIdx = P[0][0];
	for (int i = 1; i < N; i++) {
		printf("%d ", T[i][nextIdx]);
		nextIdx = P[i][nextIdx];
	}
}

int main() {
	//�ʱ�ȭ �� �Է�
	memset(T, 0, sizeof(T));
	memset(D, 0, sizeof(D));
	memset(P, 0, sizeof(P));

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < i+1; j++) {
			scanf("%d", &D[i][j]);
			T[i][j] = D[i][j];
		}
	}
	
	//�˰��� ���� �� ���
	Solve();

	printf("%d\n", D[0][0]);
	PrintPath();

	return 0;
}