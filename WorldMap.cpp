#include "WorldMap.h"
#include <iostream>
#include <vector>
#include <cstdlib>


//构造世界经济基础地图
void WorldMap::buildWorldMoneyMap() {
    for (int i = 0; i < this->economicsMap.size(); i++) {
        for (int j = 0; j < this->economicsMap[0].size(); j++) {
            //生成0~1之间的小数，也是地图的基础生长值
            this->economicsMap[i][j] = this->resourceRate * double(rand()) / RAND_MAX;
        }
    }
}

//构造世界基础地图
void WorldMap::buildWorldMap() {
    for (int i = 0; i < this->worldMap.size(); i++) {
        for (int j = 0; j < this->worldMap[0].size(); j++) {
            int value = rand() % 18;
            if (0 < value && value < 8)
                this->worldMap[i][j] = 0;
            else {
                this->worldMap[i][j] = value;//空地
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////



WorldMap::WorldMap(){
	//基础资源倍数
	this->resourceRate = 10;

    //vector和可视化的坐标不一致
    //行数
    this->worldRow = this->WIN_WIDTH / this->size;
    //列数
    this->worldCol = this->WIN_HEIGHT / this->size;

    this->worldMap = vector<vector<int>>(worldRow, vector<int>(worldCol));
    this->economicsMap = vector<vector<double>>(worldRow, vector<double>(worldCol));

    this->buildWorldMap();
    this->buildWorldMoneyMap();
}


/////////////////////////////////////////////////////////////////////
//获得某地地图
int WorldMap::getworldMap(int i, int j) {
	return this->worldMap[i][j];
}

//设置某地地图
void WorldMap::setworldMap(int i, int j, int value) {
	this->worldMap[i][j] = value;
}

//输出世界地图
void WorldMap::printworldMap() {
    cout << "#################世界地图#################" << endl;
    for (int i = 0; i < this->worldMap.size(); i++) {
        for (int j = 0; j < this->worldMap[0].size(); j++) {
            cout << this->worldMap[i][j] << "  ";
        }
        cout << endl;
    }
}
/////////////////////////////////////////////////////////////////////
//获得某地经济
double WorldMap::getworldMoneyMap(int i, int j) {
    return this->economicsMap[i][j];
}

//设置某地经济
void WorldMap::setworldMoneyMap(int i, int j, double value) {
    this->economicsMap[i][j] = value;
}

//输出世界经济
void WorldMap::printworldMoneyMap() {
    cout << "#################经济地图#################" << endl;
    for (int i = 0; i < this->economicsMap.size(); i++) {
        for (int j = 0; j < this->economicsMap.size(); j++) {
            cout << this->economicsMap[i][j] << "  ";
        }
        cout << endl;
    }
}

