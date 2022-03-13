#include <cstdlib>
#include <iostream>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

#include "WorldMap.h"
#include "State.h"


class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	WorldMap Map;
	vector<State> country;
	sf::Texture t1;
	int FPS;
	sf::Sprite* s;

	//初始化窗口
	void initWindow();

public:
	//初始化构造
	Game();

	//析构函数
	virtual ~Game();

	//Functions
	void updateSFMLxEvents();
	void update();
	void render();
	void run();

	//创建国家
	void createState();
};