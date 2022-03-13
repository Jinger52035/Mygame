#include "Game.h"


//Static functions

//Initializer functions


//初始化窗口
void Game::initWindow()
{
    /*创建窗口*/
    
    this->window = new sf::RenderWindow(sf::VideoMode(this->Map.WIN_WIDTH, this->Map.WIN_HEIGHT), "The Game!");
    this->window->setFramerateLimit(60);
}

//初始化构造
Game::Game() {
    t1.loadFromFile("E:\\A\\开源游戏\\16_Games\\01 Tetris\\images\\army.png");
    this->s = new sf::Sprite(t1);
    this->initWindow();
}

//析构函数
Game::~Game() {
    delete this->window;
}

//关闭窗口
void Game::updateSFMLxEvents()
{
    while (this->window->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateSFMLxEvents();
}

void Game::render()
{
    if (FPS % 10 == 0) {
        FPS = 0;
        for (int j = 0; j < this->country.size(); j++) {
            this->country[j].addMoney(Map.economicsMap);
            this->country[j].extendField(Map.worldMap, Map.economicsMap);
            this->country[j].addArmy();
            for (int time = 0; time < this->country[j].warTime(); time++)
                this->country[j].attack(this->country, Map.worldMap, Map.economicsMap);
            this->country[j].addScience();
        }
    }
    this->window->clear(sf::Color::White);
    for (int i = 0; i < Map.worldMap.size(); i++) {
        for (int j = 0; j < Map.worldMap[0].size(); j++) {
            this->s->setTextureRect(sf::IntRect(Map.worldMap[i][j] * 30, 0, 30, 30));
            this->s->setPosition(i * 30, j * 30);
            this->window->draw(*this->s);
        }
    }

    this->window->display();
}

void Game::run()
{
    this->createState();

    for (int j = 0; j < country.size(); j++)
        this->country[j].buildField(Map.worldMap);
    this->FPS = 0;
    while (this->window->isOpen())
    {
        this->update();
        FPS++;
        this->render();
    }
}

//创建国家
void Game::createState()
{
    srand(time(0));
    //战国七雄
    vector<string> countryName = { "秦国","楚国","齐国","燕国","赵国","魏国","韩国" };
    //战国七雄的随机出生点（未做重复检测）
    vector<vector<int>> countryPosition;
    for (int i = 0; i < countryName.size(); i++) {
        vector<int> temp = { -1,-1 };
        temp[0] = rand() % this->Map.worldMap.size();
        temp[1] = rand() % this->Map.worldMap[0].size();
        cout << temp[0] << endl;
        cout << temp[1] << endl;
        countryPosition.push_back(temp);
    }
   this->country = {
        State(countryPosition[0][0],countryPosition[0][1],countryName[0],1),
        State(countryPosition[1][0],countryPosition[1][1],countryName[1],2),
        State(countryPosition[2][0],countryPosition[2][1],countryName[2],3),
        State(countryPosition[3][0],countryPosition[3][1],countryName[3],4),
        State(countryPosition[4][0],countryPosition[4][1],countryName[4],5),
        State(countryPosition[5][0],countryPosition[5][1],countryName[5],6),
        State(countryPosition[6][0],countryPosition[6][1],countryName[6],7)
    };
}
