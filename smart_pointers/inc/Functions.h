#pragma once

#ifndef Functions_HH
#define Functions_HH

#include <iostream>
#include <string>
#include <memory>
#include "Entity.h"

/* Raw Pointer */
Entity* SetNameWrapper(Entity* e, const std::string& name);

/* Copy Constructor */
const Entity& SetNameWrapper(Entity& e, const std::string& name);

/* Unique Pointer */
Entity* SetNameWrapper(std::unique_ptr<Entity> e, const std::string& name);

/* Shared Pointer */
Entity* SetNameWrapper(std::shared_ptr<Entity> e, const std::string& name);

#endif // !Functions_HH