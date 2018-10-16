#include <iostream>
#include <string.h>
#include "Devices.h"
using namespace std;

int Device::IsServiceable() {
	return isServiceable;
}

void Device::Connect(string bus) {
	this->bus = bus;
}

Device::Device() {};
Device::~Device() {};

MotionDevice::MotionDevice() {};
MotionDevice::~MotionDevice() {};

CombatDevice::CombatDevice() {};
CombatDevice::~CombatDevice() {};

HyperDrive::HyperDrive() {};
HyperDrive::~HyperDrive() {};

void HyperDrive::Start(int power) {
	speed = power * 10;
	cout << "Moving by means of hyperdrive with speed: " << to_string(speed) << endl;
}

void HyperDrive::Stop() {
	speed = 0;
	cout << "Moving has stopped by hyperdrive." << endl;
}

Engine::Engine() {};
Engine::~Engine() {};

void Engine::Start(int power) {
	speed = power;
	cout << "Moving by means of engine with speed: " << to_string(speed) << endl;
}

void Engine::Stop() {
	speed = 0;
	cout << "Moving has stopped by engine." << endl;
}

LaserCannon::LaserCannon() {};
LaserCannon::~LaserCannon() {};

void LaserCannon::Fire(int power) {
	cout << "Shot by laser with power: " + to_string(power) << endl;
}

ProtonTorpedoLauncher::ProtonTorpedoLauncher() {};
ProtonTorpedoLauncher::~ProtonTorpedoLauncher() {};

void ProtonTorpedoLauncher::Fire(int power) {
	cout << "Launch proton tourpedos with power : " + to_string(power) << endl;
}