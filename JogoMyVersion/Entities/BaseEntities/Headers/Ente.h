#pragma once

#include "stdafx.cpp"

class Ente {
public:
	Ente();
	~Ente();

	const unsigned int Getid() { return own_id; };

	virtual void Execute() = 0; //{ std::cout << "Execute from (" << own_id << ") instance class." << std::endl; };

protected:
	const unsigned int own_id;

private:
	static unsigned int id;
};