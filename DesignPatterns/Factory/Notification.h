#pragma once
#include <iostream>
#include <string>

class Notification
{
public:
    Notification() = default;
    virtual ~Notification() = default;

    virtual void send(const std::string &msg) = 0;
};