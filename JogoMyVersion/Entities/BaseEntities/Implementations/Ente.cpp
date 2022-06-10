#include "../Headers/Ente.h"

// STATIC INITIALIZATION
unsigned int Ente::id = 0;

// CONSTRUCTORS
Ente::Ente() :
	own_id(++id)
{};
Ente::~Ente()
{};