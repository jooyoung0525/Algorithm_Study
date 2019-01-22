#include<cstdio>
#include<cstdlib>



int main() {


	int N;
	int cnt = 0;
	scanf("%d", &N);

	int Line[20001] = { 0 };

	for (int i = 1; i <= N; i++) {

		scanf("%d", &Line[i]);

	}


	for (int j = 1; j <= N; j++) {

		if (j != Line[j])
			cnt++;
	}

	printf("%d", cnt);



	system("pause");
	return 0;

}
