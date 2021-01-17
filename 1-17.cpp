
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010;

int n, m;
int h[N], w[N]; // �洢������

bool check(int mid)
{
	LL res = 0; // ��¼�߳�Ϊmid���ɿ�������
	for (int i = 0; i < n; i++)
	{
		res += (LL)h[i] / mid * (w[i] / mid); // ÿһ����Էֳɵı߳�Ϊa���ɿ�������
		if (res >= m)  // ����Ҫ��������������
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d%d", &h[i], &w[i]);

	int l = 1, r = 1e5; // С�ɿ����߳�һ����1-100000֮��
	while (l < r) // ����С�ɿ����߳���Χ���ҵ�����Ҫ������ֵ
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	printf("%d\n", r);
	return 0;
}

// ����ϲ�
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
