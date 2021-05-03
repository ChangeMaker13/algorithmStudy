/*
* 2018114686 ������ ���� �� �ҽ� �ڵ带 �ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;

//#define DEBUG
#define FOR(i, n) for(int i = 0; i < n; i++)

struct JOB {
	int number;
	int deadline;
	int profit;
};

int n;
vector<JOB> jobs;

bool isFeasible(vector<JOB>& K) {
	for (int i = 0; i < K.size(); i++) {
		if (K[i].deadline < i + 1) return false;
	}
	return true;
}

//jobarr�� �ִ� job�� deadline�������� ���������� �ǵ��� newjob�� �����Ѵ�.
void InsertNewJob(vector<JOB>& jobarr, JOB newjob) {
	auto it = jobarr.begin();
	for (it; it != jobarr.end(); it++) {
		if ((*it).deadline > newjob.deadline)
			break;
	}
	
	jobarr.insert(it, newjob);
}

int Solve() {
	//profit���� �������� ����
	vector<JOB> J;
	vector<JOB> K;

	auto it = jobs.begin();
	J.push_back(*it);
	it++;
	//�ϳ��� ���ذ��鼭 feasible ���� Ȯ��
	for (it; it != jobs.end(); it++) {
		K.clear();
		K.resize(J.size());
		copy(J.begin(), J.end(), K.begin());

		//K�� ���ο� ���� �ֱ�
		InsertNewJob(K, *it);

		//���� feasible �ϴٸ� J���� �Ȱ��� �־��ش�
		if (isFeasible(K)) {
			InsertNewJob(J, *it);
		}
	}

	//���������� ���� ��ҵ��� ������ ��
	int result = 0;
	for (JOB job : J) {
		result += job.profit;
	}
	return result;
}

bool compareByProfit(JOB a, JOB b) {
	return a.profit > b.profit;
}

int main() {
	cin >> n;
	jobs.resize(n);
	int tmp;

	FOR(i, n) {
		jobs[i].number = i;
		cin >> tmp;
		jobs[i].deadline = tmp;
	}
	FOR(i, n) {
		cin >> tmp;
		jobs[i].profit = tmp;
	}

	sort(jobs.begin(), jobs.end(), compareByProfit);

	int result = Solve();
	printf("%d", result);
	
	return 0;
}