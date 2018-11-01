/*题目：家族
Description
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，给出某个亲戚关系图，求任意给出的两个人
是否具有亲戚关系。 规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的
亲戚，y的亲戚也都是x的亲戚。
Input
第一行：三个整数n,m,p，（n< =5000,m< =5000,p< =5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1< =Mi，Mj< =N，表示Mi和Mj具有亲戚关系。 接下来p行：
每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
Output
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
题型：并查集的使用
题目思路：创建并查集
解题关键：创建并查集中的 find()函数，check()函数，和merge()函数，将有亲戚关系的人放到同一个集合中，然后判断
两个人是否有亲戚关系，只需要判断他们是否在同一个集合中，即是否有相同的祖先，如果是，则这两个人就具有亲戚关系

*/
#include<iostream>
using namespace std;
int ga[10005];
void build(int n){
	for (int i = 0; i < n;i++){
		ga[i] = i;
	}
}//初始化集合数组，每个人刚开始都是自己的祖先
int find(int x){ return ga[x] == x ? x:ga[x] = find(ga[x]); }//找到x点的祖先结点
bool check(int x, int y){ return find(x)==find(y); }//判断x,y是否有相同的子节点，如果有，则他们具有亲戚关系
void merge(int x, int y){ if (!check(x, y)) ga[ga[x]] = ga[y]; }//合并具有亲戚关系的人
int main(){
	int n, m, p;
	int a, b;
	scanf("%d%d%d",&n,&m,&p);
	build(n);
	for (int i = 0; i < m;i++){
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	for (int i = 0; i < p;i++){
		scanf("%d%d",&a, &b);
		if (check(a, b)) printf("YES\n");
		else printf("NO\n");
	}
}