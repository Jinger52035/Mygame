#pragma once
#include <string>
#include <vector>
using namespace std;

class State
{
private:
	double buyRate;//扩土比率

	double money;//国家初始经济

	int science;//国家初始科技水平
	
	vector<vector<int>> field;//国家领土

	string name;//国家名称

	int color;//国家颜色

	double army;//军队数量

	double militarism;//军国主义比例

	void loseFie(int i, int j);//丢失地盘

	double militarismRate();

	double scientismRate();

public:
	State(int i,int j,string name,int color);//初始化构造器

	void buildField(vector<vector<int>>& worldMap);//初始化地盘

	void extendField(vector<vector<int>>& worldMap,vector<vector<double>>& economicsMap);//和平扩展

	void addMoney(vector<vector<double>>& economicsMap);//国家一年的收入

	void addArmy();//扩充军队

	void attack(vector<State>& country, vector<vector<int>>& worldMap,vector<vector<double>>& economicsMap);//战争

	void addScience();//增加科技

	int warTime();//战争次数

	void check();//三个数据
};

