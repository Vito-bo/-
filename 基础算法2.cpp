

#if 0
// 1.前缀和
/*
	输入一个长度为n的整数序列。
	接下来再输入m个询问，每个询问输入一对l, r。
	对于每个询问，输出原序列中从第l个数到第r个数的和。
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
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + q[i]; // 前缀和
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
// 二维前缀和
//输入一个n行m列的整数矩阵，再输入q个询问，每个询问包含四个整数x1, y1, x2, y2，表示一个子矩阵的左上角坐标和右下角坐标。
//对于每个询问输出子矩阵中所有数的和。
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
		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];  //求前缀和

	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]); //求部分和
	}
	return 0;
}

#endif

#if 0
// 一维差分
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

	for (int i = 1; i <= n; i++) b[i] += b[i - 1]; //求差分数组b的前缀和
	for (int i = 1; i <= n; i++) 
		printf("%d ", b[i]);

	return 0;
}

#endif 

#if 0
// 二维差分--差分矩阵
#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;

// a[N]：原矩阵  b[N]：差分矩阵
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

	// 求前缀和
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	// 输出操作后的矩阵
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	return 0;
}
#endif





// 二进制中1的个数
#include <iostream>
using namespace std;
// 把一个整数减去1，再与原整数相与，会把原整数的最右边的1变成0
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

// 方法1：具体的做法可以让n与1相与，然后让1左移，然后重复让n与左移后的1相与
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

// 求负数的补码。二进制打印
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