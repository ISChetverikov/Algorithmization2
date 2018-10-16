#pragma once
#include <string>

using namespace std;

class Device
{
public:
	Device();
	~Device();

private:
	string bus;

protected:
	bool isServiceable = false;

public:
	void Connect(string bus);

	int IsServiceable();
};

class MotionDevice : public Device
{
public:
	MotionDevice();
	~MotionDevice();

protected:
	int speed = 0; 

public:
	virtual void Start(int power) = 0;
	virtual void Stop() = 0;

};

class CombatDevice : public Device
{
public:
	CombatDevice();
	~CombatDevice();

 

public:
	virtual void Fire(int power) = 0;
};

class HyperDrive final : public MotionDevice
{
public:
	HyperDrive();
	~HyperDrive();


public:
	void Start(int power) override;
	void Stop() override;
};

class Engine final : public MotionDevice
{
public:
	Engine();
	~Engine();

private:
public: 
	void Start(int power) override;
	void Stop() override;

};

class LaserCannon final : public CombatDevice
{
public:
	LaserCannon();
	~LaserCannon();

private:
public:
	void Fire(int power) override;
};

class ProtonTorpedoLauncher final : public CombatDevice {
public:
	ProtonTorpedoLauncher();
	~ProtonTorpedoLauncher();

private:
public:
	void Fire(int power) override;
};
