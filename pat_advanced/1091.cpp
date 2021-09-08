#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int row_max=1300;
const int col_max=130;
const int z_max=65;
int a[row_max][col_max][z_max],m,n,slice,t,total=0,X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1};
bool flag[row_max][col_max][z_max]={false};
struct node{
	int x,y,z;
};
queue<node> q;
bool judge(int x,int y,int z){
	if(x<0||x>=m||y<0||y>=n||z<0||z>=slice)return false;
	if(a[x][y][z]==0||flag[x][y][z]==true)return false;
	return true;
}
int bfs(int x,int y,int z){
	int now=0;
	node n;
	n.x=x,n.y=y,n.z=z;
	q.push(n);
	flag[x][y][z]=true;
	now++;
	while(!q.empty()){
		n=q.front();
		q.pop();
		for(int i=0;i<6;i++){
			node temp;
			temp.x=n.x+X[i],temp.y=n.y+Y[i],temp.z=n.z+Z[i];
			if(judge(temp.x,temp.y,temp.z)){
				q.push(temp);
				now++;
				flag[temp.x][temp.y][temp.z]=true;
			}
		}
	}
	if(now>=t)return now;
	return 0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("1.txt","r",stdin);
	#endif
	scanf("%d%d%d%d",&m,&n,&slice,&t);
	for(int z=0;z<slice;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				scanf("%d",&a[x][y][z]);
			}
		}
	}
	for(int z=0;z<slice;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				if(a[x][y][z]==1&&flag[x][y][z]==false){
					total+=bfs(x,y,z);
				}
			}
		}
	}
	printf("%d",total);
	return 0;
}
