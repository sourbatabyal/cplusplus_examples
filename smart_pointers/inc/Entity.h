#pragma once

#ifndef Entity_HH
#define Entity_HH

#include <iostream>
#include <string>

class Entity
{
private:
    std::string _name;
public:
    Entity();
    Entity(const Entity& other);
    Entity(const std::string& name);
    ~Entity();
    std::string GetName();
    void SetName(std::string name);
};

#endif // !Entity_HH