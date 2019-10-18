#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1000 + 1;

int m, n;
vector<int> graph[MAX];
bool visited[MAX];

void DFS(int node) {
	visited[node] = true; //�湮������ ǥ��

	for (int i = 0; i < graph[node].size(); i++) {
		//graph �����ŭ �湮
		int next = graph[node][i];
		//node�� ����� �ٸ� ������ �湮�Ѵ�
		if (!visited[next])
			DFS(next);
	}

}


// ���� ���� �׷����� ���� ���
int main(void)
{
	int n, m; //n:������ ���� m: ������ ����
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {

		int node1, node2;
		scanf("%d %d", &node1, &node2);

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	
	}

	int cnt = 0;

	for (int i=1; i<=n; i++)
		if (!visited[i])
		{
			DFS(i);
			cnt++;
		}

	printf("%d", cnt);


	return 0;
}