
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010;

int n, m;
int h[N], w[N]; // 存储长，宽

bool check(int mid)
{
	LL res = 0; // 记录边长为mid的巧克力数量
	for (int i = 0; i < n; i++)
	{
		res += (LL)h[i] / mid * (w[i] / mid); // 每一块可以分成的边长为a的巧克力数量
		if (res >= m)  // 大于要求数量，返回真
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d%d", &h[i], &w[i]);

	int l = 1, r = 1e5; // 小巧克力边长一定在1-100000之间
	while (l < r) // 二分小巧克力边长范围，找到符合要求的最大值
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	printf("%d\n", r);
	return 0;
}

// 区间合并
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int m, n;
struct Segment
{
	int l, r;
	bool operator< (const Segment& t) const
	{
		return l < t.l;
	}
}seg[N];

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> seg[i].l >> seg[i].r;
	sort(seg, seg + n);

	int sum = 0;
	int L = seg[0].l, R = seg[0].r;
	for (int i = 1; i < n; i++)
	if (seg[i].l <= R) R = max(R, seg[i].r);
	else
	{
		sum += R - L + 1;
		L = seg[i].l, R = seg[i].r;
	}
	sum += R - L + 1;
	cout << m + 1 - sum << endl;

	return 0;
}
