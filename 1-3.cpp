
#include <iostream>
using namespace std;

#if 0
// 剑指offer39-数组中出现次数超过一半的数字
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int flag = nums[0];
		int count = 1;    //哨兵位
		for (int i = 1; i<len; i++)
		{
			if (count == 0)
				flag = nums[i];
			// 如果一样，则为友军，count+1
			if (flag == nums[i])
			{
				count++;
			}
			// 否则为敌军，count-1
			else
			{
				count--;
			}

		}
		return flag;
	}
};

//力扣606--根据二叉树创建字符串
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	string _tree2str(TreeNode* root, string& strRet)
	{
		if (nullptr == root)
			return strRet;
		// 先遍历根节点
		strRet += to_string(root->val);

		//根节点的左子树
		if (nullptr == root->left)
		{
			if (nullptr != root->right)
				strRet += "()";
		}
		else
		{
			strRet += "(";
			_tree2str(root->left, strRet);
			strRet += ")";
		}

		//根节点的右子树
		if (nullptr == root->right);
		else
		{
			strRet += "(";
			_tree2str(root->right, strRet);
			strRet += ")";
		}
		return strRet;
	}
	string tree2str(TreeNode* t)
	{
		string strRet;
		_tree2str(t, strRet);
		return strRet;
	}
};
#endif

#if 0
// 快速排序--分治
// 快速排序是不稳定的  时间复杂度O(N*logN)
// 1.先确定分界点：q[l]   q[l+r>>1]  q[r]
// 2.调整区间：小于等于x的在左半边，大于等于x的在右边
// 3.递归处理左右两段
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
int main()
{
	int arr[] = { 2, 5, 1, 7, 6, 3, 9, 4, 8 };
	quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
#endif 

// 归并排序--分治---双指针
// 归并排序是稳定的。  时间复杂度O(NlogN)
// 1.确定分界点：mid=(l+r)>>1
// 2.递归排序左边和右边
// 3.归并两个有序的数组,合二为一
#include <iostream>
using namespace std;

const int N = 100010;
int q[N], tmp[N];
int n;

void merge_sort(int q[], int l, int r)
{
	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

	int i = l, j = mid, k = 0;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else
			tmp[k++] = q[j++];
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (int i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
}

int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> q[i];

	merge_sort(q, 0, n - 1);

	for (int i = 0; i<n; i++)
		cout << q[i] << " ";
	return 0;

}