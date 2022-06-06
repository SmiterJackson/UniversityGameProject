#pragma once

#include "stdafx.cpp"

class AnimaData {
public:
    AnimaData();
    AnimaData(unsigned int _start, unsigned int _end, unsigned int _row, unsigned int _height, unsigned int _width, float _switchTime, bool _repeatable = false);
    ~AnimaData();

public:
    unsigned int start, end, row, height, width;
    float switchTime;
    bool repeatable;
};

class Animation {
public:
    Animation();
    Animation(const AnimaData& Data);
    ~Animation();

    void Initialize(const AnimaData& Data);
    void ResetAnimation();
    const sf::IntRect& update(float timeDiff, bool right = true);

    Animation operator= (const Animation& other)
    {
        if(&other != this)
        {
            this->img_token = other.img_token;
            this->start = other.start;
            this->end = other.end;
            this->row = other.row;
            this->current = other.current;
            this->time = other.time;
            this->switchTime = other.switchTime;
            this->repeatable = other.repeatable;
        }

        return *this;
    }
    const bool operator== (const Animation& other)
    {
        if (&other == this)
            return true;

        return false;
    }
    const bool operator!= (const Animation& other)
    {
        if (&other != this)
            return true;

        return false;
    }

private:
    sf::IntRect img_token;
    unsigned int start, end, row, current;
    float time, switchTime;
    bool repeatable;
};