#include "Player.h"
#include <SDL\SDL.h>


void Player::init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera2D, vector<Bullet>* bullets) {
	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	_bullets = bullets;
	_camera2D = camera2D;
	_currentGun = -1;
	color.set(0, 0, 185, 255);
}
void Player::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies, 
	float deltaTime) {
	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
	
	glm::vec2 mouseCoords = _inputManager->getMouseCoords();
	mouseCoords = _camera2D->convertScreenToWorl(mouseCoords);

	glm::vec2 centerPosition = _position + glm::vec2(AGENT_RADIUS);
	
	_direction = glm::normalize(mouseCoords - centerPosition);

	if (_currentGun !=-1) {
		_guns[_currentGun]->update(_inputManager->isKeyDown(SDL_BUTTON_LEFT), centerPosition, _direction, *_bullets, deltaTime);
	}

	collideWithLevel(levelData);
}

void Player::addGun(Gun* gun) {
	_guns.push_back(gun);
	if (_currentGun== -1) {
		_currentGun = 0;
	}
}


Player::Player()
{
}


Player::~Player()
{
}
