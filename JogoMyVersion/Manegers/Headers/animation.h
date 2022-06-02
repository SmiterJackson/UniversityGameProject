#pragma once

#include "stdafx.cpp"

class AnimationDataType {
public:
    AnimationDataType();
    AnimationDataType(unsigned int _start, unsigned int _end, unsigned int _row, unsigned int _coefficient, float _switchTime, bool _repeatable = false);
    ~AnimationDataType();

public:
    unsigned int start, end, row, coefficient;
    float switchTime;
    bool repeatable;
};

class Animation {
public:
    Animation();
    Animation(const AnimationDataType& Data);
    ~Animation();

    void Initialize(const AnimationDataType& Data);
    void ResetAnimation();
    const sf::IntRect& update(float timeDiff, bool right = true);

    Animation operator= (const Animation& animation)
    {
        if(&animation != this)
        {
            this->img_token = animation.img_token;
            this->start = animation.start;
            this->end = animation.end;
            this->row = animation.row;
            this->current = animation.current;
            this->time = animation.time;
            this->switchTime = animation.switchTime;
            this->repeatable = animation.repeatable;
        }

        return *this;
    }

private:
    sf::IntRect img_token;
    unsigned int start, end, row, current;
    float time, switchTime;
    bool repeatable;
};