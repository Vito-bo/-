

#if 0
// 1-货仓选址
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, q[N];

int main()
{
	cin >> n;
	for (int i = 0; i<n; i++) cin >> q[i];
	sort(q, q + n);
	int ret = 0;
	for (int i = 0; i<n; i++)
		ret += abs(q[i] - q[n / 2]);
	cout << ret << endl;
	return 0;
}


// 2-数字三角形
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;

int n;
int f[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= i; j++)
		cin >> f[i][j];
	for (int i = n - 1; i>0; i--)
	for (int j = 1; j <= i; j++)
		f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
	cout << f[1][1] << endl;
	return 0;
}


// 3-蛇形走位
#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int q[N][N];

int main()
{
	cin >> n >> m;

	// 定义x坐标，y坐标的偏移量
	int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = 0, y = 0;
	// 顺时针走4个方向0->1->2->3
	int d = 1;
	for (int i = 1; i <= n*m; i++)
	{
		q[x][y] = i;
		// 下一次要走的坐标
		int a = x + dx[d], b = y + dy[d];
		if (a<0 || a >= n || b<0 || b >= m || q[a][b])
		{
			d = (d + 1) % 4;
			a = x + dx[d], b = y + dy[d];
		}
		x = a, y = b;
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			cout << q[i][j] << " ";
		cout << endl;
	}
	return 0;
}

#endif


// 红与黑-宽搜写法
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

// 深搜写法
#include <iostream>

using namespace std;

const int N = 25;

int n, m;
char g[N][N];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{
	int res = 1;
	g[x][y] = '#';
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '.')
			res += dfs(a, b);
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
		cout << dfs(x, y) << endl;
	}

	return 0;
}