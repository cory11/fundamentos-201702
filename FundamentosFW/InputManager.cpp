#include "InputManager.h"

void InputManager::pressKey(unsigned int keyCode) {
	_keyMap[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode) {
	_keyMap[keyCode] = false;
}

void InputManager::update() {
	for (auto& it: _keyMap) {
		_previousKeyMap[it.first] = it.second;
	}
}

bool InputManager::isKeyDown(unsigned int keyCode) {
	auto it = _keyMap.find(keyCode);
	if (it != _keyMap.end()) {
		return it->second;
	}
	else {
		return false;
	}
}

bool InputManager::isKeyPressed(unsigned int keyCode) {
	auto it = _keyMap.find(keyCode);
	if (it != _keyMap.end()) {
		return it->second;
	}
	return false;
}

void InputManager::setMouseCoords(float x, float y) {
	_mouseCoords.x = x;
	_mouseCoords.y = y;
}

bool InputManager::wasKeyDown(unsigned int keyCode) {
	auto it = _previousKeyMap.find(keyCode);
	if (it != _previousKeyMap.end()) {
		return it->second;
	}
	else {
		return false;
	}
}

InputManager::InputManager():_mouseCoords(0.0f,0.0f)
{
}


InputManager::~InputManager()
{
}
