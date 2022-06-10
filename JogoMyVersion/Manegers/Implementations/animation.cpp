#include "../Headers/animation.h"
using namespace traits;

Animated::Animation::AnimaData::AnimaData() :
    start(0), end(0), row(0), height(0), width(0), switchTime(0.f), repeatable(false)
{};
Animated::Animation::AnimaData::AnimaData(unsigned int Start, unsigned int End, unsigned int Row, unsigned int _height, unsigned int _width, float SwitchTime, bool _repeatable) :
    start(Start), end(End), row(Row), height(_height), width(_width), switchTime(SwitchTime), repeatable(_repeatable)
{};
Animated::Animation::AnimaData::~AnimaData()
{
};

// Classe Adaptada da original, pelo canal Hilze Vonck 
Animated::Animation::Animation() :
    img_token(), start(0), end(0), row(0), current(0), time(0.0), switchTime(0.0), repeatable(false)
{};
Animated::Animation::Animation(const AnimaData& Data) :
    img_token(), start(Data.start), end(Data.end), row(Data.row), current(0), time(0.0), switchTime(Data.switchTime), repeatable(Data.repeatable)
{
    current = start;

    img_token.width = Data.width;
    img_token.height = Data.height;
};
Animated::Animation::~Animation()
{
}

void Animated::Animation::Initialize(const AnimaData& Data)
{
    this->start = Data.start;
    this->end = Data.end;
    this->row = Data.row;
    this->switchTime = Data.switchTime;

    current = start;

    img_token.width = Data.width;
    img_token.height = Data.height;
}
void Animated::Animation::ResetAnimation()
{
    this->current = 0;
};
const sf::IntRect& Animated::Animation::update(float timeDiff, bool right)
{
    time += timeDiff;

    // Caso o lapso de tempo seja igual ou maior que o previsto, definido na criação da animação, alterna o recorte da animação
    if (time >= switchTime)
    {
        time -= switchTime;

        if (current < end)  // alterna até no máximo a última imagem da uma animação dada
            current++;

        if (repeatable) // Caso seja animação de loop como 'Idle', repete o loop
        {
            if (current >= end)
                current = start;
        }
    }

    img_token.top = row * img_token.height;

    if (right)
    {
        // lê o recorte da textura da esquerda à direita
        img_token.left = current * img_token.width;
        img_token.width = abs(img_token.width);

        return img_token;
    }
    // lê o recorte da textura da direita à esquerda (invertida)
    img_token.left = (current + 1) * abs(img_token.width);
    img_token.width = -abs(img_token.width);

    return img_token;
}

Animated::Animated() :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const std::vector<Animation>& _animationVec) :
	animationVec(_animationVec), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const VecAnimaValues& _animationVec) :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{
	size_t diff = this->animationVec.capacity() - this->animationVec.size();
	this->animationVec.reserve(diff + _animationVec.size());

	for (unsigned int i = 0; i < _animationVec.size(); ++i)
		this->animationVec.emplace_back(_animationVec[i]);
};
Animated::~Animated()
{};

// Descartado

/*
Slipery::Slipery(const float _coefficient) :
	friction_coefficient(_coefficient)
{};
Slipery::~Slipery()
{};

//////////////////////////////////////////////////////////////////////////////////////

ForcesAtDirect::ForcesAtDirect(const float _surface_acceler, const bool dir_is_right) :
	surface_acceler(_surface_acceler), dir_is_right(dir_is_right)
{};
ForcesAtDirect::~ForcesAtDirect()
{};

void ForcesAtDirect::InvertDirection()
{
	this->dir_is_right = !this->dir_is_right;
};
*/