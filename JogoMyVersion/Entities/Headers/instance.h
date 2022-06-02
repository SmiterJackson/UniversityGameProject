#pragma once

#include "stdafx.cpp"

class Instance {
public:
	Instance();
	~Instance();

	const unsigned int Getid() { return own_id; };

	virtual void Execute() { std::cout << "Execute from (" << own_id << ") instance class." << std::endl; };

protected:
	const unsigned int own_id;

private:
	static unsigned int id;
};