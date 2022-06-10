#include "../Headers/printable.h"
using namespace traits;

Printable::Printable() :
	texture(), faceRight(true)
{};
Printable::Printable(const sf::Texture& texture, const bool FacesRight) :
	texture(texture), faceRight(FacesRight)
{};
Printable::Printable(const std::string fileName, const bool FacesRight) :
	texture(), faceRight(FacesRight)
{
	this->texture.loadFromFile(fileName);
};
Printable::~Printable()
{};

void Printable::InvertTextureOrientation()
{
	this->faceRight = !this->faceRight;
};