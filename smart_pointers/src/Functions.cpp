#include <iostream>
#include <string>
#include <memory>
#include "Entity.h"
#include "LineNo.h"
#include "Functions.h"

/* Raw Pointer */
Entity* SetNameWrapper(Entity* e, const std::string& name)
{
	PRINT_LINE_NUM
	e->SetName(name);
	Entity* p_b = e;
	return p_b;
}

/* Copy Constructor */
const Entity& SetNameWrapper(Entity& e, const std::string& name)
{
	PRINT_LINE_NUM
    e.SetName(name);
    return e;
}

/* Unique Pointer */
Entity* SetNameWrapper(std::unique_ptr<Entity> e, const std::string& name)
{
	PRINT_LINE_NUM
	e->SetName(name);
	Entity* p_b = e.get();
	return p_b; // With this statement, the pointer e, having the ownership of pointer , is released
}

/* Shared Pointer */
Entity* SetNameWrapper(std::shared_ptr<Entity> e, const std::string& name)
{
	PRINT_LINE_NUM
	e->SetName(name);
	Entity* p_b = e.get();
	return p_b; // With this statement, the pointer e, having the ownership of pointer , is released
}