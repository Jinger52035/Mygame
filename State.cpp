#include "State.h"
#include <iostream>
using namespace std;

//��ʧ����
void State::loseFie(int i, int j) {
	vector<vector<int>>::iterator Iter;
	for (Iter = this->field.begin(); Iter != this->field.end();Iter++) {
		if ((*Iter)[0] == i && (*Iter)[1] == j) {
			this->field.erase(Iter);
			break;
		}
	}
}

//��ʼ��������
State::State(int i, int j, string name, int color) {
	this->buyRate = 1;
	this->money = 10000;
	this->science = 100;
	this->army = 0;
	vector<int> temp = {i,j};
	this->field.push_back(temp);
	this->name = name;
	this->color = color;
	this->militarism = 100;
}

//��ʼ������
void State::buildField(vector<vector<int>>& worldMap) {
	for (int i = 0; i < this->field.size(); i++) {
		worldMap[this->field[i][0]][this->field[i][1]] = this->color;
	}
}

//��ƽ��չ ��ƽ��չ�����ȷ�չ���õ���ߵĵ���
void State::extendField(vector<vector<int>>& worldMap, vector<vector<double>>& economicsMap) {
	double maxResource = 0;
	vector<int> maxField = { -1, -1 };
	for (int i = 0; i < this->field.size(); i++) {
		int X = this->field[i][0];
		int Y = this->field[i][1];

		int Xt[] = { -1,1,0,0 };
		int Yt[] = { 0,0,-1,1 };
		for (int j = 0; j < 4; j++) {
			int newX = X + Xt[j];
			int newY = Y + Yt[j];
			if (newX >= 0 && newY >= 0 && newX < worldMap.size() && newY < worldMap[0].size() && (worldMap[newX][newY]==0|| worldMap[newX][newY]>7)) {
				if (economicsMap[newX][newY] > maxResource) {
					maxResource = economicsMap[newX][newY];
					maxField[0] = newX;
					maxField[1] = newY;
					break;
				}
			}
		}
	}
	if (maxField[0] == -1) {
		cout << "###############################################" << endl;
		cout << "####" << this->name << "�޷���ƽ����[û�пյ�]" << endl;
	}
	else if (this->money > this->buyRate * maxResource) {
		vector<int> temp = { maxField[0] , maxField[1] };
		this->field.push_back(temp);
		worldMap[maxField[0]][maxField[1]] = this->color;
		this->money -= this->buyRate * maxResource;
		cout << "###############################################" << endl;
		cout << "####" << this->name << "�����˵�" << maxField[0] << "��" << maxField[1] << "�յ�" << endl;
		cout << "-" << this->buyRate * maxResource<<"���" << endl;
	}
	else {
		cout << "###############################################" << endl;
		cout <<"####" << this->name << "�޷���ƽ����[ûǮ]" << endl;
	}
		
	
}

double State::militarismRate()
{
	return this->militarism / (this->militarism + 100.0);
}

//����һ�������
void State::addMoney(vector<vector<double>>& economicsMap) {
	for (int i = 0; i < this->field.size(); i++) {
		this->money += economicsMap[this->field[i][0]][this->field[i][1]];
	}
	cout << "###############################################" << endl;
	this->check();
	cout << this->name << "��������:" << this->money << endl;
}

double State::scientismRate()
{
	return this->science/(this->science+100.0);
}

//�������
void State::addArmy() {
	this->militarism += 100;
	this->army += 1000;
	int armyMonry = this->money / (3.0-this->militarismRate());
	this->money -= armyMonry;
	this->army += armyMonry;
	cout << "###############################################" << endl;
	cout << "����+"<< armyMonry + 100<< endl;
	cout << "�ܾ���������" << this->army << endl;
	this->check();
}

//ս�������ݴ������ӹ������أ�
void State::attack(vector<State>& country, vector<vector<int>>& worldMap,vector<vector<double>>& economicsMap) {
	vector<int> warField = { -1, -1 };
	double maxResource = 0;
	for (int i = 0; i < this->field.size(); i++) {
		int X = this->field[i][0];
		int Y = this->field[i][1];

		int Xt[] = { -1,0,1,0 };
		int Yt[] = { 0,-1,0,1 };

		for (int j = 0; j < 4; j++) {
			int newX = X + Xt[j];
			int newY = Y + Yt[j];
			if (newX >= 0 && newY >= 0 && newX < worldMap.size() && newY < worldMap[0].size()&&worldMap[newX][newY]!=this->color&& worldMap[newX][newY]!= 0&& worldMap[newX][newY]<8) {
				if (economicsMap[newX][newY] > maxResource) {
					maxResource = economicsMap[newX][newY];
					warField[0] = newX;
					warField[1] = newY;
					break;
				}
			}
		}
	}
	this->check();
	if (warField[0] == -1) {
		cout << "####" << this->name << "�޷�ս������[û������]" << endl;
		this->army /= 2;
		this->army /= 2;
		this->army /= 2;
	}
	else if (this->army >= country[worldMap[warField[0]][warField[1]]-1].army) {
		this->militarism += 100;
		string enemy = country[worldMap[warField[0]][warField[1]] - 1].name;

		vector<int> temp = { warField[0] , warField[1] };

		country[worldMap[warField[0]][warField[1]] - 1].loseFie(warField[0], warField[1]);
		int reparations = country[worldMap[warField[0]][warField[1]] - 1].money / (2 - this->militarismRate());

		this->money += reparations;
		cout << "###############################################" << endl;
		cout << this->name << "���ս�����+" << reparations << endl;

		country[worldMap[warField[0]][warField[1]] - 1].army /= (2 - this->militarismRate());
		this->army /= (5 - this->militarismRate());
		cout << "��ʧ�������" << endl;
		cout << "�ܾ�������" << this->army << endl;

		cout << "####" << this->name << "��ս��" << enemy << "�����˵�" << warField[0] << " " << warField[1] << "�յ�" << endl;
		this->field.push_back(temp);
		worldMap[warField[0]][warField[1]] = this->color;
		this->check();
	}
	else {

		string enemy = country[worldMap[warField[0]][warField[1]] - 1].name;

		if (this->field.size() < 450) {
			int reparations = this->money / (2 - this->militarismRate());
			country[worldMap[warField[0]][warField[1]] - 1].money += reparations;
			cout << "###############################################" << endl;
			cout << "ս��ʧ�ܣ����-" << reparations << endl;
			country[worldMap[warField[0]][warField[1]] - 1].army /= 2;
		}

		
		cout << "####" << this->name<<"��"<< enemy << "ս��ʧ��" << endl;
		this->check();
	}	
}

//���ӿƼ�
void State::addScience() {
	int addSci = this->money / 10;
	this->money -= addSci;
	this->science +=  (addSci*(1 + this->scientismRate()));
	this->check();
	cout << "###############################################" << endl;
	cout << "Ͷ�ʿƼ�" << "-" << addSci << endl;
}

//ս������
int State::warTime() {
	if (this->field.size() > 450) {
		return 10;
	}
	if (this->scientismRate() >= 0.9)
		return 9;
	if (this->scientismRate() >= 0.8)
		return 8;
	if (this->scientismRate() >= 0.7)
		return 7;
	if (this->scientismRate() >= 0.6)
		return 6;
	if (this->scientismRate() >= 0.5)
		return 5;
	if (this->scientismRate() >= 0.4)
		return 4;
	if (this->scientismRate() >= 0.3)
		return 3;
	if (this->scientismRate() >= 0.2)
		return 2;
	return 1;
}

void State::check()
{	
	int maxValue = 10000;
	if (this->field.size() > 450) {
		maxValue = 20000;
		this->army += 100;
	}

	if (this->money > maxValue)
		this->money = maxValue;
	if (this->science > maxValue)
		this->science = maxValue;
	if (this->army > maxValue)
		this->army = maxValue;
}

