#pragma once

#include "stdafx.cpp"

// Classe Adaptada da original, pelo canal Hilze Vonck 
class Animation
{
public:
    class AnimaData
    {
    public:
        AnimaData();
        AnimaData(const unsigned int _start, const unsigned int _end, const unsigned int _row, const unsigned int _height, 
                    const unsigned int _width, const float _switchTime, const bool _repeatable = false);
        ~AnimaData();

    public:
        unsigned int start, end, row, height, width;
        float switchTime;
        bool repeatable;
    };

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