


// 1.红与黑
#include <iostream>
#include <queue>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 25;

int n, m;
char g[N][N];

int bfs(int sx, int sy)
{
	queue<PII> q;
	q.push({ sx, sy });
	g[sx][sy] = '#';
	int res = 0;

	int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

	while (q.size())
	{
		auto t = q.front();
		q.pop();
		res++;

		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.') continue;
			g[x][y] = '#';
			q.push({ x, y });
		}
	}
	return res;
}

int main()
{
	while (cin >> m >> n, n || m)
	{
		for (int i = 0; i < n; i++) cin >> g[i];
		int x, y;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (g[i][j] == '@')
		{
			x = i;
			y = j;
		}
		cout << bfs(x, y) << endl;
	}

	return 0;
}



// 广度优先搜索
#include <iostream>
#include <queue>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 25;

int n, m;
char g[N][N];

int bfs(int sx, int sy)
{
	queue<PII> q;
	q.push({ sx, sy });
	g[sx][sy] = '#';
	int res = 0;

	int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

	while (q.size())
	{
		auto t = q.front();
		q.pop();
		res++;

		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.') continue;
			g[x][y] = '#';
			q.push({ x, y });
		}
	}
	return res;
}

int main()
{
	while (cin >> m >> n, n || m)
	{
		for (int i = 0; i < n; i++) cin >> g[i];
		int x, y;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (g[i][j] == '@')
		{
			x = i;
			y = j;
		}
		cout << bfs(x, y) << endl;
	}

	return 0;
}

// 2.剪绳子
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int w[N];

bool check(double mid)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += w[i] / mid;
	return cnt >= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <n; i++) cin >> w[i];

	double l = 0, r = 1e9;
	while (r - l > 1e-4)
	{
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}

	printf("%.2lf\n", r);
	return 0;
}
