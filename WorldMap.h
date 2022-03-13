#pragma once
#include <vector>
using namespace std;


class WorldMap
{
private:
	
	/*变量*/
	int size = 30;//国家地盘元素的大小，这个应该放在State类里面
	int worldRow;//世界的行数
	int worldCol;//世界的列数
	int resourceRate;//基础资源倍数，后期可以根据不同的地图进行不同的资源倍数

	/*函数*/
	void buildWorldMap();//构造世界基础地图
	void buildWorldMoneyMap();//构造世界经济基础地图



public:

	/*变量*/

	//窗口的大小应放在Game类
	
	int WIN_WIDTH = 900;//窗口的宽度
	int WIN_HEIGHT = 900;//窗口的高度
	vector<vector<int>> worldMap;//定义世界地图
	vector<vector<double>> economicsMap;//定义世界经济地图

	/*函数*/

	WorldMap();//构造函数
	int getworldMap(int i, int j);//获得某地地图
	void setworldMap(int i, int j, int value); //设置某地地图
	void printworldMap();//输出世界地图（调试用）
	double getworldMoneyMap(int i, int j);//获得某地经济
	void setworldMoneyMap(int i, int j, double value);//设置某地经济
	void printworldMoneyMap();//输出世界经济（调试用）

};

