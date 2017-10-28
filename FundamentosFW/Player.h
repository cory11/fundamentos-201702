#pragma once
#include "Human.h"
#include "InputManager.h"
#include "Gun.h"
#include <vector>
#include "Camera2D.h"

using namespace std; 

class Player : public Human
{
private:
	InputManager* _inputManager;
	vector<Gun*> _guns;
	int camera2D;
	Camera2D* _camera2D;
	int _currentGun;
	vector<Bullet>* _bullets;

public:

	void addGun(Gun* gun);
	Player();
	~Player();
	void init(float speed, glm::vec2 position, InputManager* inputManager,Camera2D* _camera2D, vector<Bullet>* bullets);
	void update(const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies,
		float deltaTime);
};

