

#include <iostream>
#include <algorithm>
using namespace std;

#if 0

//˫ָ�뷨����˼·��
1.�ȱ����������
2.Ѱ�ҵ����ԣ�������ָ��֮�����ϵ
3.�ٲ����Ż�

// ˫ָ�뷨  ����������ظ������и���
const int N = 100010;
int n;
int a[N], s[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ret = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		s[a[i]]++;
		while (s[a[i]]>1)
		{
			s[a[j]]--;
			j++;
		}

		ret = max(ret, i - j + 1);
	}
	cout << ret << endl;
	return 0;
}


// 2.˫ָ�뷨 ������Ԫ�ص�Ŀ���
const int N = 100010;
int n, m, x;
int a[N], b[N];

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i<n; i++) scanf("%d", &a[i]);
	for (int j = 0; j<m; j++) scanf("%d", &b[j]);

	for (int i = 0, j = m - 1; i<n; i++)
	{
		while (j >= 0 && (a[i] + b[j])>x)
			j--;
		if (a[i] + b[j] == x)
		{
			printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}
#endif
#if 0

// #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

// ��ɢ������
int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l<r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c });

		alls.push_back(x);
	}

	for (int i = 0; i<m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({ l, r });

		alls.push_back(l);
		alls.push_back(r);
	}

	// ȥ��
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());


	// �������
	for (auto item : add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}

	// ����ǰ׺��
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	// ����ѯ��
	for (auto item : query)
	{
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
#endif

// ����ϲ�
// 1.��������˵�����
// 2.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII>& segs)
{
	vector<PII> res;

	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
	{
		if (ed<seg.first)
		{
			if (st != -2e9) res.push_back({ st, ed });
			st = seg.first, ed = seg.second;
		}
		else
		{
			ed = max(ed, seg.second);
		}
	}
	if (st != -2e9) res.push_back({ st, ed });

	segs = res;
}


int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({ l, r });
	}

	merge(segs);
	cout << segs.size() << endl;

	return 0;
}


