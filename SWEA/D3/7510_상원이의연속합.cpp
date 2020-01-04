//투포인터알고리즘 복습

#include<iostream>

using namespace std;

int T;
int arr[10000000] = { 0 };

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			arr[i] = i + 1;
		}

		int left = 0; int right = 0; int cnt = 0;
		int hap = arr[0];

		while (left<=right && right < N)
		{
			if (hap < N)
			{
				right++;
				hap += arr[right];
			}
			else if (hap == N) //합이 내가 원하던수와 같을경우
			{
				cnt++; //카운트해줌
				right++;
				hap += arr[right];
			}
			else if (hap > N)
			{
				hap -= arr[left];
				left++;

				if (left > right&& left < N) //예외일경우 처리반드시필요
				{
					right = left;
					hap = arr[left];
				}
			}
		}

		cout<<'#'<<q<<' '<<cnt<<endl;
	}


	return 0;
}
