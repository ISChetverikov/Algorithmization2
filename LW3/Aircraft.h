#pragma once
#include "Machine.h"

class Aircraft : public Machine
{
public:
	Aircraft();
	~Aircraft();

protected:
	int bonus = 3;
private:

};
