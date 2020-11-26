#include <iostream>
#include <string>
#include <memory>
#include "Entity.h"
#include "Functions.h"

void One_1_Ownership_Copied() {
	std::shared_ptr<Entity> p_a = nullptr;
	std::shared_ptr<Entity> p_b = nullptr;
	
	p_a = std::make_shared<Entity>(); /* Initialize p_a */
	p_b = p_a;
	
	std::cout << std::endl;
	std::cout << "p_a.use_count() : " << p_a.use_count() << std::endl;
	std::cout << "p_b.use_count() : " << p_b.use_count() << std::endl;
	
	std::cout << std::endl;
	std::cout << "p_a : " << p_a << std::endl;
	std::cout << "p_b : " << p_b << std::endl;
	
	std::cout << std::endl;
	if (p_a != nullptr) { // this condition will get satisfied as is a shared pointer
		std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // Will work !
	}
	if (p_b != nullptr) {
		std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // Will work !
	}
}

void One_1_Ownership_Moved() {
	std::shared_ptr<Entity> p_a = nullptr;
	std::shared_ptr<Entity> p_b = nullptr;
	
	p_a = std::make_shared<Entity>(); /* Initialize p_a */
	p_b = std::move(p_a); // ownership moved from p_a to p_b
	
	std::cout << std::endl;
	std::cout << "p_a.use_count() : " << p_a.use_count() << std::endl;
	std::cout << "p_b.use_count() : " << p_b.use_count() << std::endl;
	
	std::cout << std::endl;
	std::cout << "p_a : " << p_a << std::endl;
	std::cout << "p_b : " << p_b << std::endl;
	
	std::cout << std::endl;
	if (p_a != nullptr) { // this condition will not get satisfied as ownership is moved
		std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // Will not work !
	}
	if (p_b != nullptr) { // this condition will get satisfied as ownership is with p_b
		std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // Will not work !
	}
}

void Three_3_Several_Uses_Copy_And_Move() {
	std::shared_ptr<Entity> p_a = nullptr;
	std::shared_ptr<Entity> p_b = nullptr;
	
	p_a = std::make_shared<Entity>(); /* Initialize p_a */
	p_b = p_a;
	
	std::cout << std::endl;
	std::cout << "p_a.use_count() : " << p_a.use_count() << std::endl;
	std::cout << "p_b.use_count() : " << p_b.use_count() << std::endl;
	
	std::cout << std::endl;
	std::cout << "p_a : " << p_a << std::endl;
	std::cout << "p_b : " << p_b << std::endl;
	
	std::cout << std::endl;
	if (p_a != nullptr) { // this condition will get satisfied as is a shared pointer
		std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // Will work !
	}
	if (p_b != nullptr) {
		std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // Will work !
	}
	
	/* By Raw Pointer */
	std::cout << std::endl << ">>>>>>>>>>>>>>>>>>>>>By Raw Pointer<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	SetNameWrapper(p_b.get(), "Raw Pointer");
	std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl;
	std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl;
	
	/* By Copy Constructor */
	std::cout << std::endl << ">>>>>>>>>>>>>>>>>>>>>By Shared Pointer Constructor<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	SetNameWrapper(*(p_b.get()), "Copy Constructor");
	std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl;
	std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl;
	
	/* By Shared Pointer Copy */
	std::cout << std::endl << ">>>>>>>>>>>>>>>>>>>>>By Shared Pointer Copy<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	Entity* e = SetNameWrapper(p_b, "Shared Pointer Copy");
	std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // This is possible now.
	std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // This is possible now.
	std::cout << "e->GetName() : " << e->GetName() << std::endl; // This is also possible now.
	
	/* By Shared Pointer Move */
	std::cout << std::endl << ">>>>>>>>>>>>>>>>>>>>>By Shared Pointer Move<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	Entity* e2 = SetNameWrapper(std::move(p_b), "Shared Pointer Move");
	std::cout << "p_a.use_count() : " << p_a.use_count() << std::endl;
	std::cout << "p_b.use_count() : " << p_b.use_count() << std::endl;
	std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // This is possible now.
	// std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // This is not possible now.
	std::cout << "e->GetName() : " << e2->GetName() << std::endl; // This is also not possible now.
}

int main(int argc, char const *argv[])
{
	One_1_Ownership_Copied();
	// One_1_Ownership_Moved();
	Three_3_Several_Uses_Copy_And_Move();
    return 0;
}


