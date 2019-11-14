#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int CITYMAX = 1000 + 1;
const int BUSMAX = 1000000 + 1;
const int INF = 987654321;

int n, m;
int src, des;
vector<pair<int, int>> graph[CITYMAX];

// ���ͽ�Ʈ�� �˰����� ���� ���ؾ� �ϴ� ����
// �ڱ� �ڽź��� �� ���� ����ġ�� ���ذ��� ã�ƾ� �Ѵ�

vector <int> dijkstra(int start, int vertex)
{
	vector <int> distance(vertex, INF);// start�� �������� �Ÿ�
	distance[start] = 0;

	priority_queue<pair<int, int>> pq; //Cost, Vertex
	pq.push(make_pair(0, start)); // �ʱ� ���� ������

	while (!pq.empty())
	{
		int cost = -pq.top().first; //�Ÿ��� ��ȣ�� �ٲ� �Ÿ��� ���� ��������
		//pq�� priority queue �̹Ƿ� ���� ū ���� top�� ���� -> ��ȣ�� �ٲ���� �������� ���ĵ�

		int curVertex = pq.top().second; //vertex
		pq.pop();

		//�ּҰŸ� ã��
		if (distance[curVertex] < cost)
			continue;

		//�̿� ��� Ȯ��
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			int near = graph[curVertex][i].first;
			int nearDistance = cost + graph[curVertex][i].second;

			//�ּ� ��� �߽߰� ������Ʈ
			if (distance[near] > nearDistance)
			{
				distance[near] = nearDistance;
				//�Ÿ��� ��ȣ�� �ٲ� �Ÿ��� ���� ��������
				pq.push(make_pair(-nearDistance, near));

			}
		}
	}

	return distance;


}


int main(void)
{
	
	scanf_s("%d %d", &n, &m);
	n++; //������ȣ 1���� ����
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf_s("%d %d %d", &start, &end, &cost);
		graph[start].push_back(make_pair(end, cost));
	}

	scanf_s("%d %d", &src, &des);

	vector<int> result = dijkstra(src, n);

	printf("%d\n", result[des]);

	return 0;

}