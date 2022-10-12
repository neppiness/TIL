#include <bits/stdc++.h>
using namespace std;

int n;
int sq[224];
bool isfound = 0;

void solve(int no, int lim, int tot) {
  if(no == 1) {
    if(binary_search(sq + 1, sq + 224, tot))
      isfound = 1;
    return;
  }
  for(int i = lim; i != 0; i--)
    solve(no - 1, i, tot - sq[i]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i < 224; i++)
    sq[i] = i*i;

  cin >> n;
  int lim = (int)sqrt(n);
  for(int i = 1; i < 4; i++) { // don't need to calculate when i is 4
    solve(i, lim, n);
    if(isfound) {
      cout << i;
      return 0;
    }
  }
	cout << 4;
}

/*
Super easy solution

#include<cstdio>
#include<cmath>

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i*i<=n;i++)
		if(i*i==n){
			printf("1\n");
			return 0;
		}
	
	for(int i=1;i*i<=n;i++)
		for(int j=i;j*j<=n;j++)
			if(i*i+j*j==n){
				printf("2\n");
				return 0;
			}
	
	for(int i=1;i*i<=n;i++)
		for(int j=i;j*j<=n;j++)
			for(int k=j;k*k<=n;k++)
				if(i*i+j*j+k*k==n){
					printf("3\n");
					return 0;
				}
	
	printf("4\n");
	return 0;
}
*/