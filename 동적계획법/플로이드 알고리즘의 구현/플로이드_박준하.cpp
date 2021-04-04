/*
* 2018114686 ������ ���� �� �ҽ� �ڵ带 �ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 130
#define INF -1

int N, M;
int D[MAX][MAX];	//����� ���̸� ����
int P[MAX][MAX];	//��θ� �����ϱ� ���� ���
int T;

//�׷����� ǥ���ϴ� ��� ���
void Printgraph(int graph[][MAX]) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (graph[i][j] == INF)
				printf("INF ");
			else
				printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

//s���� d������ ��θ� s�� d�� �����ϰ� ������� ���
void Print_throughPath(int s, int d) {
	if (P[s][d] == 0) return;

	Print_throughPath(s, P[s][d]);
	printf("%d ", P[s][d]);
	Print_throughPath(P[s][d], d);
}

//s�� d�� ������ ���
void PrintPath(int s, int d) {
	printf("%d ", s);
	Print_throughPath(s, d);
	printf("%d ", d);
}

void Floyd() {
	int d, i, j;
	for (d = 1; d < N + 1; d++) {
		for (i = 1; i < N + 1; i++) {
			for (j = 1; j < N + 1; j++) {
				if (D[i][d] == INF || D[d][j] == INF)
					continue;

				if (D[i][j] == INF ||
					D[i][j] > D[i][d] + D[d][j])
				{
					D[i][j] = D[i][d] + D[d][j];
					P[i][j] = d;
				}
			}
		}
	}
}

int main() {
	//�Է� �� �ʱ�ȭ
	scanf("%d %d", &N, &M);
	memset(D, INF, sizeof(D));
	memset(P, 0, sizeof(P));

	for (int i = 0; i < N + 1; i++) {
		D[i][i] = 0;
	}

	for (int m = 0; m < M; m++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		D[u][v] = w;
	}

	//�÷��̵� �˰��� ���� �� ���
	Floyd();

	Printgraph(D);
	Printgraph(P);

	//�׽�Ʈ ���̽��� ��������, �������� �Է��� ��� Ž��
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int s, d;
		scanf("%d %d", &s, &d);
		PrintPath(s, d);

		if (D[s][d] == INF)
			printf("INF");
		else
			printf("%d\n", D[s][d]);
	}

	return 0;
}