#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1000 + 1;

int m, n;
vector<int> graph[MAX];
bool visited[MAX];

void DFS(int node) {
	visited[node] = true; //방문했음을 표시

	for (int i = 0; i < graph[node].size(); i++) {
		//graph 사이즈만큼 방문
		int next = graph[node][i];
		//node에 연결된 다른 정점을 방문한다
		if (!visited[next])
			DFS(next);
	}

}


// 방향 없는 그래프의 연결 요소
int main(void)
{
	int n, m; //n:정점의 갯수 m: 간선의 갯수
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