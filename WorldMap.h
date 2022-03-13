#pragma once
#include <vector>
using namespace std;


class WorldMap
{
private:
	
	/*����*/
	int size = 30;//���ҵ���Ԫ�صĴ�С�����Ӧ�÷���State������
	int worldRow;//���������
	int worldCol;//���������
	int resourceRate;//������Դ���������ڿ��Ը��ݲ�ͬ�ĵ�ͼ���в�ͬ����Դ����

	/*����*/
	void buildWorldMap();//�������������ͼ
	void buildWorldMoneyMap();//�������羭�û�����ͼ



public:

	/*����*/

	//���ڵĴ�СӦ����Game��
	
	int WIN_WIDTH = 900;//���ڵĿ��
	int WIN_HEIGHT = 900;//���ڵĸ߶�
	vector<vector<int>> worldMap;//���������ͼ
	vector<vector<double>> economicsMap;//�������羭�õ�ͼ

	/*����*/

	WorldMap();//���캯��
	int getworldMap(int i, int j);//���ĳ�ص�ͼ
	void setworldMap(int i, int j, int value); //����ĳ�ص�ͼ
	void printworldMap();//��������ͼ�������ã�
	double getworldMoneyMap(int i, int j);//���ĳ�ؾ���
	void setworldMoneyMap(int i, int j, double value);//����ĳ�ؾ���
	void printworldMoneyMap();//������羭�ã������ã�

};

