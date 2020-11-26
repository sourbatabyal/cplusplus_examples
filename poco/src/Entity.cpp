#include "Entity.h"

Entity::Entity()
    : _name("Unknown")
{
    std::cout << "ctor " << _name << std::endl;
}

Entity::Entity(const Entity& other)
    : _name(other._name)
{
    std::cout << "copy ctor " << _name << std::endl;
}
Entity::Entity(const std::string& name)
    : _name(name)
{
    std::cout << "ctor(arg) " << _name << std::endl;
}
Entity::~Entity()
{
    std::cout << "dtor " << _name << std::endl;
}

std::string Entity::GetName()
{
	// throw std::exception("OOO");
    return _name;
}

void Entity::SetName(std::string name)
{
    _name = name;
}