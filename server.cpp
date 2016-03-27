// server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <list>
using namespace std;
struct xiangmu {
	int p = 0;//优先级
	int t = 0;//提出时间
	int d = 0;//归属部门
	int num;//任务编号
};//对每一个项目都建立如此属性
list <xiangmu>lianbiao;//建立电脑中存放列表；
void put_into_list(xiangmu now);
void delete_a_task(xiangmu now,int x);
int main()
{
	int pr, ti, de;
	char sx;//任务属性
	xiangmu now;
	list<xiangmu>::iterator i;
	scanf("%d %d %d %c\n", &pr, &ti, &de, &sx);
	now.p = pr;
	now.t = ti;
	now.d = de;
	now.num = 1;
	lianbiao.push_back(now);
	int number = 1;
	while (scanf("%d ", &pr) && pr != 0) {
		scanf("%d %d %c", &ti, &de, &sx);
		number++;
		now.p = pr;
		now.t = ti;
		now.d = de;
		now.num = number;
		int x;
		if (sx == 'C') put_into_list(now);
		if (sx == 'D') {
			scanf("%d", &x);
			delete_a_task(now, x);
		}
	}
	while (lianbiao.size() > 0) {
		cout << lianbiao.front().num << endl;
		lianbiao.pop_front();
	}
    return 0;
}
void put_into_list(xiangmu now) {
	list<xiangmu> ::iterator i;
	xiangmu temp;
	bool p = true;
		for (i = lianbiao.begin(); i != lianbiao.end(); i++) {
			temp = *i;
			if (now.p < temp.p){
				lianbiao.insert(i, now);
				p = false;
				break;
			}
			else if (now.p == temp.p && now.t < temp.t){
				lianbiao.insert(i, now);
				p = false;
				break;
			}
			else if (now.p == temp.p && now.t == temp.t && now.d < temp.d) {
				lianbiao.insert(i, now);
				p = false;
				break;
			}
		}
		if (p == true) lianbiao.push_back(now);
		//cout << now.t << lianbiao.front().t << endl;
		if (now.t > lianbiao.front().t) {
			cout << lianbiao.front().num << endl;
			lianbiao.pop_front();
		}
}
void delete_a_task(xiangmu now, int x) {
	list<xiangmu>::iterator i;
	xiangmu temp;
	for (i = lianbiao.begin();i != lianbiao.end();i++) {
		temp = *i;
		if (now.d == temp.d && x == temp.t) {
			lianbiao.erase(i);
			break;
		}
	}
}

