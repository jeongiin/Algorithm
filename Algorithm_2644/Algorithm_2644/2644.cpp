#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int MAX = 100+1;

int m, n, p1, p2;
int r1 = 0; //relationship
int r2 = 0;

vector<int> vec[MAX];//vector�� �迭
queue <int> q;
vector<int> visited(101,0); //visited�� ���� �����ϰ� �̿��ؾ� �ϹǷ� vector�� ó���� (vector�� �޸𸮰� �ڵ����� �Ҵ�Ǵ� �迭) - 0���� �� ���� 101�� �Ҵ�


int main(void)
{
	//n:������ ���� m: ������ ����
	scanf_s("%d", &n);
	scanf_s("%d %d", &p1, &p2);
	scanf_s("%d", &m);

	for (int i = 0; i < m; i++) {

		int node1, node2;
		scanf_s("%d %d", &node1, &node2);

		vec[node1].push_back(node2);//����� ���� -> ��� �������� ã�Ƶ� ���踦 ����� �� ����
		vec[node2].push_back(node1);

	}

	q.push(p1);

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		if (p == p2) { //p2���� ���踦 ��� ã���� ��
			break;
		}

		for (int i = 0;  i < vec[p].size(); i++) { //bfs���
			if (!visited[vec[p][i]]) {
				visited[vec[p][i]] = visited[p] + 1;
				q.push(vec[p][i]);
			}
		}
	}

	if (visited[p2] != 0)
		printf("%d", visited[p2]);
	else
		printf("-1");

	return 0;
}