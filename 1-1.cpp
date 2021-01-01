
#include <iostraem>
using namespace std;

// ��ָoffer40-��С��k����
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		/*
		// ����1������ʱ�临�Ӷ�O(N*logN) �ռ临�Ӷ�O(logN)
		vector<int> ret(k,0);
		sort(arr.begin(),arr.end());
		for(int i=0;i<k;i++)
		{
		ret[i]=arr[i];
		}
		return ret;
		*/
		// ����2�����ȼ����С�ʱ�临�Ӷ�O(N*logk) �ռ临�Ӷ�O(logK)
		vector<int> ret(k, 0);
		if (k == 0)
		{
			return ret;
		}
		priority_queue<int> q;
		for (int i = 0; i<k; i++)
		{
			q.push(arr[i]);
		}

		for (int i = k; i<arr.size(); i++)
		{
			if (q.top() > arr[i])
			{
				q.pop();
				q.push(arr[i]);
			}
		}
		for (int i = 0; i<k; i++)
		{
			ret[i] = q.top();
			q.pop();
		}
		return ret;

	}
};

// ��ָoffer30-����min������ջ
class MinStack {
public:
	/** initialize your data structure here. */

	// ����һ������ջ��һ������ջ
	stack<int> data, help;
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		// ���x��data��help�ĵ�һ��Ԫ�أ�����xС�ڵ���help����СԪ�أ���ջ
		if (help.empty() || x <= help.top())
		{
			help.push(x);
		}
		if (x>help.top())
		{
			// ���x����help�е���СԪ�أ���help����ѹ��һ�����СԪ�أ���������ջԪ�ظ������
			int tmp = help.top();
			help.push(tmp);
		}
	}

	// ��ջ(�Ƴ�ջ��Ԫ��)
	void pop() {
		if (!data.empty() && !help.empty())
		{
			data.pop();
			help.pop();
		}
	}

	// ����ջ��Ԫ��
	int top()
	{
		return data.top();
	}

	int min() {
		return help.top();
	}
};

// ��ָoffer42-���������������
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// ��̬�滮
		// ״̬(������)��dp[i]��ʾ��nums[i]Ϊ��β����������������
		// ת�Ʋ���(�Դ���֦)����dp[i-1]<0,˵��dp[i-1]��dp[i]���������ף���dp[i-1]+nums[i]<=nums[i]
		// ״̬ת�Ʒ��̣���dp[i-1]>0,dp[i]=dp[i-1]+nums[i]
		//              ��dp[i-1]<=0,dp[i]=nums[i]
		int ret = nums[0];
		for (int i = 1; i<nums.size(); i++)
		{
			nums[i] += max(nums[i - 1], 0);
			ret = max(nums[i], ret);
		}
		return ret;
	}
};


int main()
{
	return 0;
}
