#pragma once

#include "../Headers/animation.h"

AnimaData::AnimaData():
    start(0), end(0), row(0), coefficient(0), switchTime(0), repeatable(false)
{};
AnimaData::AnimaData(unsigned int Start, unsigned int End, unsigned int Row, unsigned int Coefficient, float SwitchTime, bool _repeatable):
    start(Start), end(End), row(Row), coefficient(Coefficient), switchTime(SwitchTime), repeatable(_repeatable)
{};
AnimaData::~AnimaData()
{
};

Animation::Animation() :
    img_token(), start(0), end(0), row(0), current(0), time(0.0), switchTime(0.0), repeatable(false)
{};
Animation::Animation(const AnimaData& Data) :
    img_token(), start(Data.start), end(Data.end), row(Data.row), current(0), time(0.0), switchTime(Data.switchTime), repeatable(Data.repeatable)
{
    current = start;

    img_token.width = Data.coefficient;
    img_token.height = Data.coefficient;
};
Animation::~Animation()
{
}

void Animation::Initialize(const AnimaData& Data)
{
    this->start = Data.start;
    this->end = Data.end;
    this->row = Data.row;
    this->switchTime = Data.switchTime;

    current = start;

    img_token.width = Data.coefficient;
    img_token.height = Data.coefficient;
}
void Animation::ResetAnimation()
{
    this->current = 0;
};
const sf::IntRect& Animation::update(float timeDiff, bool right)
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