#pragma once
#include <string>
#include <vector>
using namespace std;

class State
{
private:
	double buyRate;//��������

	double money;//���ҳ�ʼ����

	int science;//���ҳ�ʼ�Ƽ�ˮƽ
	
	vector<vector<int>> field;//��������

	string name;//��������

	int color;//������ɫ

	double army;//��������

	double militarism;//�����������

	void loseFie(int i, int j);//��ʧ����

	double militarismRate();

	double scientismRate();

public:
	State(int i,int j,string name,int color);//��ʼ��������

	void buildField(vector<vector<int>>& worldMap);//��ʼ������

	void extendField(vector<vector<int>>& worldMap,vector<vector<double>>& economicsMap);//��ƽ��չ

	void addMoney(vector<vector<double>>& economicsMap);//����һ�������

	void addArmy();//�������

	void attack(vector<State>& country, vector<vector<int>>& worldMap,vector<vector<double>>& economicsMap);//ս��

	void addScience();//���ӿƼ�

	int warTime();//ս������

	void check();//��������
};

