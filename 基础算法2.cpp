

#if 0
// 1.ǰ׺��
/*
	����һ������Ϊn���������С�
	������������m��ѯ�ʣ�ÿ��ѯ������һ��l, r��
	����ÿ��ѯ�ʣ����ԭ�����дӵ�l��������r�����ĺ͡�
*/
#include <iostream>
using namespace std;

const int N = 100010;
int q[N], sum[N];
int n, m;


int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) cin >> q[i];
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + q[i]; // ǰ׺��
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}
#endif

#if 0
// ��άǰ׺��
//����һ��n��m�е���������������q��ѯ�ʣ�ÿ��ѯ�ʰ����ĸ�����x1, y1, x2, y2����ʾһ���Ӿ�������Ͻ���������½����ꡣ
//����ÿ��ѯ������Ӿ������������ĺ͡�
#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];


int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];  //��ǰ׺��

	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]); //�󲿷ֺ�
	}
	return 0;
}

#endif

#if 0
// һά���
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) insert(i, i, a[i]);
	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}

	for (int i = 1; i <= n; i++) b[i] += b[i - 1]; //��������b��ǰ׺��
	for (int i = 1; i <= n; i++) 
		printf("%d ", b[i]);

	return 0;
}

#endif 

#if 0
// ��ά���--��־���
#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;

// a[N]��ԭ����  b[N]����־���
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		insert(i, j, i, j, a[i][j]);

	while (q--)
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	// ��ǰ׺��
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	// ���������ľ���
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	return 0;
}
#endif





// ��������1�ĸ���
#include <iostream>
using namespace std;
// ��һ��������ȥ1������ԭ�������룬���ԭ���������ұߵ�1���0
int main()
{
	int n;
	cin >> n;
	
	int cnt = 0;
	while(n){
		cnt++;
		n=n&(n-1);
	}
	cout << cnt;
}
#if 0

// ����1�����������������n��1���룬Ȼ����1���ƣ�Ȼ���ظ���n�����ƺ��1����
int main()
{
	int n;
	cin >> n;
	int flag = 1;
	int count = 0;
	while (flag != 0)
	{
		if ((flag&n)!=0)
			count++;
		flag = flag << 1;
	}
	cout << count;
	return 0;
}


int lowbit(int x)
{
	return x&-x;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int ret = 0;
		while (x)
		{
			x -= lowbit(x);
			ret++;
		}
		cout << ret << " ";
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

// �����Ĳ��롣�����ƴ�ӡ
int main()
{
	int n = 5;
	int x = -n;
	for (int i = 31; i >= 0; i--)
		cout << (x >> i & 1);
	cout << endl;
	return 0;
}

#endif