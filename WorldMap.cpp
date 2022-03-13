#include "WorldMap.h"
#include <iostream>
#include <vector>
#include <cstdlib>


//�������羭�û�����ͼ
void WorldMap::buildWorldMoneyMap() {
    for (int i = 0; i < this->economicsMap.size(); i++) {
        for (int j = 0; j < this->economicsMap[0].size(); j++) {
            //����0~1֮���С����Ҳ�ǵ�ͼ�Ļ�������ֵ
            this->economicsMap[i][j] = this->resourceRate * double(rand()) / RAND_MAX;
        }
    }
}

//�������������ͼ
void WorldMap::buildWorldMap() {
    for (int i = 0; i < this->worldMap.size(); i++) {
        for (int j = 0; j < this->worldMap[0].size(); j++) {
            int value = rand() % 18;
            if (0 < value && value < 8)
                this->worldMap[i][j] = 0;
            else {
                this->worldMap[i][j] = value;//�յ�
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////



WorldMap::WorldMap(){
	//������Դ����
	this->resourceRate = 10;

    //vector�Ϳ��ӻ������겻һ��
    //����
    this->worldRow = this->WIN_WIDTH / this->size;
    //����
    this->worldCol = this->WIN_HEIGHT / this->size;

    this->worldMap = vector<vector<int>>(worldRow, vector<int>(worldCol));
    this->economicsMap = vector<vector<double>>(worldRow, vector<double>(worldCol));

    this->buildWorldMap();
    this->buildWorldMoneyMap();
}


/////////////////////////////////////////////////////////////////////
//���ĳ�ص�ͼ
int WorldMap::getworldMap(int i, int j) {
	return this->worldMap[i][j];
}

//����ĳ�ص�ͼ
void WorldMap::setworldMap(int i, int j, int value) {
	this->worldMap[i][j] = value;
}

//��������ͼ
void WorldMap::printworldMap() {
    cout << "#################�����ͼ#################" << endl;
    for (int i = 0; i < this->worldMap.size(); i++) {
        for (int j = 0; j < this->worldMap[0].size(); j++) {
            cout << this->worldMap[i][j] << "  ";
        }
        cout << endl;
    }
}
/////////////////////////////////////////////////////////////////////
//���ĳ�ؾ���
double WorldMap::getworldMoneyMap(int i, int j) {
    return this->economicsMap[i][j];
}

//����ĳ�ؾ���
void WorldMap::setworldMoneyMap(int i, int j, double value) {
    this->economicsMap[i][j] = value;
}

//������羭��
void WorldMap::printworldMoneyMap() {
    cout << "#################���õ�ͼ#################" << endl;
    for (int i = 0; i < this->economicsMap.size(); i++) {
        for (int j = 0; j < this->economicsMap.size(); j++) {
            cout << this->economicsMap[i][j] << "  ";
        }
        cout << endl;
    }
}

