# Dynamic Programming (동적 프로그래밍)

## DP = 분할정복기법 + 메모이제이션

---------------------------------------------------------------------------------------------------------------

### ?분할정복기법? (N^2의 시간)

 큰 문제를 잘게 쪼개서 여러 개의 문제로 나누어 푸는 기법.
 
 하지만, 동일한 data를 불필요하게 반복적으로 계산함 (모든 경우의수가 다른 정렬 빼고)
 
 너무 오래걸림!!
 
### ?메모이제이션?

 이미 구한답을 저장해 두는것.
 
-------------------------------------------------------------------------------------------------------------------
 
## Dynamic Programming은 다음 가정하에 사용.

   1. 큰문제를 작은문제로 나눌 수 있을 때  -> **분할정복**
   
★ 2. 작은문제에서 구한 정답(배열에 저장)을 그 문제를 포함하는 큰 문제에서도 동일하게 이용 가능 할 때 -> **메모이제이션**


---------------------------------------------------------------------------------------------------------------
![1003](https://user-images.githubusercontent.com/29946480/51738221-f60fe000-20d1-11e9-944f-92bcc96f6ab5.JPG)
----------------------------------------------------------------------------------------------------------------
### Fail(시도1)

```c
#include<cstdio>
#include<cstdlib>

int zero;
int one;
int d[100];


int fibonacci(int n) {

	//zero = 0;
	//one = 0;

    if (n == 0) {
		//printf("0");
	zero++;
        return 0;
    }
	if (n == 1) {
		//printf("1");
	one++;
        return 1;
    } 
	if (d[n] != 0)
		return d[n];
	
	return d[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int T,N;
	int temp[100][2];
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		scanf("%d", &N);
		zero = one = 0;
		fibonacci(N);
		temp[T][0] = zero;
		temp[T][1] = one;
		
	}
	
	for (int i = 0; i < T; i++)
		printf("%d %d\n", temp[T][0], temp[T][1]);

	system("pause");
	return 0;
}
```
- 기저조건 0이 호출되는 수 와 기저조건 1이 호출되는 수의 경우를 나누어서 생각해줘야함!!

- 그리고 main에서 temp[T][0]하니 당연히 마지막 수만 계속 출력됨.

---------------------------------------------------------------------------------------------------------------------------
# 맞았다!!!!!>_<

```c
#include<cstdio>
#include<cstdlib>

int ans[50][5];

int fibo_0(int n)                  //기저조건0을 호출한 수
{
	
	if (n == 0) {
		ans[0][0] = 1;
		return  ans[0][0]; //기저조건
	}
	else if (n == 1)
	{
		ans[1][0] = 0;
		return ans[1][0]; //기저조건
	}
	else if (ans[n][0] != 0)   //ans배열에 (쪼개진 작은계산의)결과 값이 저장되어 있으면 그대로 호출
		return ans[n][0]; 
	else                      //ans배열에(쪼개진 작은계산의)결과 값이 저장되어 있지 않을 때
	{
		ans[n][0] = fibo_0(n-1) + fibo_0(n-2);   // 재귀함수 호출
		return ans[n][0];
	}
}

int fibo_1(int n)                  //기저조건1을 호출한 수
{  

	if (n == 0) {
		ans[0][1] = 0;
		return ans[0][1];
	}

	if (n == 1) {
		ans[1][1] = 1;
		return ans[1][1];
	}
	
	if (ans[n][1] != 0)
		return ans[n][1];
	else
	{
		ans[n][1] = fibo_1(n - 1) + fibo_1(n - 2);
		return ans[n][1];
	}
}



int main()
{
	int T;
	int fin[50][5];   // fibo_0(N),fibo_1(N)함수를 불렀을 때 결과 값을 저장할 배열
	//int n[41];      // 입력 값 저장배열

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		//n[i] = N; //입력 값 N을 배열n에 저장.
		fin[i][0]= fibo_0(N);
		fin[i][1] = fibo_1(N);
	
	}

	for (int j = 0; j < T; j++)
	{
		printf("%d %d\n", fin[j][0],fin[j][1]);
	}

	system("pause");
	return 0;
}
```
---------------------------------------------------------------------------------------------------------------------------
### ↓↓다른 사람의 코드(DP 사용 안한거)↓↓

```cpp
#include<iostream>
#include<vector>
using namespace std;
 

int count0, count1;
vector<int> count0_vec, count1_vec;
 
int fibo(int n) {
    if (n == 0) {
        count0++;
        return 0;
    }
    else if (n == 1) {
        count1++;
        return 1;
    }
    else
        return fibo(n - 1) + fibo(n - 2);
}
 
int main() {
    int T, N;
 
    // 데이터 입력 및 문제 해결
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        count1 = count0 = 0;
        fibo(N);
        count0_vec.push_back(count0);
        count1_vec.push_back(count1);
    }
 
    // 결과 출력
    for (int idx = 0; idx < count0_vec.size(); idx++)
        printf("%d %d\n", count0_vec[idx], count1_vec[idx]);
 
    return 0;
}

```
---------------------------------------------------------------------------------------
