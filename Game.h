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

	//��ʼ������
	void initWindow();

public:
	//��ʼ������
	Game();

	//��������
	virtual ~Game();

	//Functions
	void updateSFMLxEvents();
	void update();
	void render();
	void run();

	//��������
	void createState();
};