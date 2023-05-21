#include<iostream>
#include<string>

using namespace std;


int c[1000][1000] = {0};
int color[1000] = {0};



int main(){
	int c_num = 0; // luu tru so mau can dung
	int n,m; // n la so dinh , m la so canh cua do thi
	scanf("%d%d",&n,&m);
	
	
	
	// su dung ma tran ke de luu tru do thi
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		c[x][y] = 1;
		c[y][x] = 1;
	}
	
	
	
	// to mau do thi,duyet lan luot cac dinh tu 1 den n
	for(int i=1;i<=n;i++){
		// tai dinh dau tien, ta to mau ung voi gia tri 1
		if (i == 1){
			color[i] = 1;
			c_num++;
			continue;
		}
		
		// tu cac dinh sau, duyet xem dinh do ke voi cac dinh nao va to mau nho nhat thoa man de bai
		int p[c_num+1] = {1,0};
		for (int j=1;j<i;j++){
			if (c[i][j] != 0){
				p[color[j]] = 1;
			}
		}
		for(int j=1;j<=c_num;j++){
			if (p[j] == 0){
				color[i] = j;
				break;
			}
		}
		if(color[i] == 0 ){
			color[i] = ++c_num;
		}	
	
	}
	cout << c_num;
}
