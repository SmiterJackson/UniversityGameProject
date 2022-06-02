#pragma once

#include "../Headers/animation.h"

AnimationDataType::AnimationDataType():
    start(0), end(0), row(0), coefficient(0), switchTime(0)
{
};
AnimationDataType::AnimationDataType(unsigned int Start, unsigned int End, unsigned int Row, unsigned int Coefficient, float SwitchTime):
    start(Start), end(End), row(Row), coefficient(Coefficient), switchTime(SwitchTime)
{
};
AnimationDataType::~AnimationDataType()
{
};

Animation::Animation() :
    img_token(), start(0), end(0), row(0), current(0), time(0.0), switchTime(0.0)
{
}
Animation::Animation(AnimationDataType& Data) :
    img_token(), start(Data.start), end(Data.end), row(Data.row), current(0), time(0.0), switchTime(Data.switchTime)
{
    current = start;

    img_token.width = Data.coefficient;
    img_token.height = Data.coefficient;
}
Animation::~Animation()
{
}

void Animation::Initialize(const AnimationDataType& Data)
{
    this->start = Data.start;
    this->end = Data.end;
    this->row = Data.row;
    this->switchTime = Data.switchTime;

    current = start;

    img_token.width = Data.coefficient;
    img_token.height = Data.coefficient;
}

const sf::IntRect& Animation::update(float timeDiff, bool right)
{
    time += timeDiff;

    if (time >= switchTime)
    {
        time -= switchTime;
        current++;

        if (current >= end)
            current = start;
    }

    img_token.top = row * img_token.height;

    if (right)
    {
        // l� o recorte da textura da esquerda � direita
        img_token.left = current * img_token.width;
        img_token.width = abs(img_token.width);

        return img_token;
    }
    // l� o recorte da textura da direita � esquerda (invertida)
    img_token.left = (current + 1) * abs(img_token.width);
    img_token.width = -abs(img_token.width);

    return img_token;
}