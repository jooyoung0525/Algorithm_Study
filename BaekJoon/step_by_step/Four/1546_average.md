![average](https://user-images.githubusercontent.com/29946480/56297226-44aca380-6130-11e9-8bac-72e31123f635.PNG)

-----------------------------------------------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>


int main()
{
	int N,i;
	int score[1000] = { 0 };   // 런타임에러 날 수 있으니까 배열크기 넉넉하게!
	int hap = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);
		hap += score[i];     //점수 입력받고 바로바고 더해주기
	}
	
	int M = score[0];  // 최댓값 구할때 기준을 배열0번째 수로 정해줌

	for (i = 1; i < N; i++)
	{
		if (M < score[i]) {  // score[i]가 기준의 수 M 보다 클때
			M = score[i];      // 최댓값은 score[i]가 된다.
		}
		
		
	}

	double avg = (double) hap / N;  // ☆★실수와 정수 계산에서 형변환 해주지 않으면 제대로 계산이 되지 않는다!
                                        // 점수들의 평균구하기    

	double ans = (double) avg / M * 100; // 새로운 평균식으로 다시 계산

	printf("%f", ans);
	



	//system("pause");
	return 0;
}
```
