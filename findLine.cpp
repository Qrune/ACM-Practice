#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdint.h>
#define MAXN 100000
int x[MAXN];
int y[MAXN];
using namespace std;
bool online(int i, int p1, int p2){
	return (int64_t)(y[p2] - y[p1])*(int64_t)(x[i]-x[p1]) ==
		(int64_t)(y[i] - y[p1]) *(int64_t)(x[p2]-x[p1]);
}
int main(){
	int N,p,i,j,p1,p2;
	scanf("%d\n",&N);
	scanf("%d\n",&p);

	for (i=0; i < N; i++){
		scanf("%d %d\n",&x[i],&y[i]);
	}
	
	if (N==1){
		printf("possible");
		return 0;
	}
	
	srand(31337);
	for (i=0; i<500; i++){
		p1 = rand() % N;
		p2 = rand() % N;
		if (p1 == p2) continue;
		int count = 2;
		for (j=0; j<N; j++){
			if (j==p1 || j==p2){
				continue;
			}
			if (online(j,p1,p2)) count++;
		}
		if (count*100 >=p*N){
			printf("possible");
			return 0;
		}
	}
	printf("impossible");
	return 0;
}
