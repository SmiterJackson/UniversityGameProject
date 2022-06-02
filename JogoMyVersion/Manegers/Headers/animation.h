#pragma once

#include "stdafx.cpp"

class AnimationDataType {
public:
    AnimationDataType();
    AnimationDataType(unsigned int Start, unsigned int End, unsigned int Row, unsigned int Coefficient, float SwitchTime);
    ~AnimationDataType();

public:
    unsigned int start, end, row, coefficient;
    float switchTime;
};

class Animation {
public:
    Animation();
    Animation(AnimationDataType& Data);
    ~Animation();

    void Initialize(const AnimationDataType& Data);
    const sf::IntRect& update(float timeDiff, bool right = true);

private:
    sf::IntRect img_token;
    unsigned int start, end, row, current;
    float time, switchTime;
};