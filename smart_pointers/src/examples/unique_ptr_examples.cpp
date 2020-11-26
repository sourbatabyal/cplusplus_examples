#include <iostream>
#include <string>
#include <memory>
#include "Entity.h"
#include "Functions.h"

void One_1_OwnershipTransfer() {
	std::unique_ptr<Entity> p_a = nullptr;
	std::unique_ptr<Entity> p_b = nullptr;
	
	p_a = std::make_unique<Entity>(); /* Initialize p_a */
	p_b = std::move(p_a); /* This moves ownership from p_a to p_b and assign p_a by nullptr */
	
	if (p_a != nullptr) { // this condition will not get satisfied
		std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // Will not work !
	}
}

void Two_2_Pass_By_sdt_Move() {
	std::unique_ptr<Entity> p_a = nullptr;
	std::unique_ptr<Entity> p_b = nullptr;
	
	p_a = std::make_unique<Entity>(); /* Initialize p_a */
	p_b = std::move(p_a); /* This moves ownership from p_a to p_b and assign p_a by nullptr */
	
	if (p_a != nullptr) { // this condition will not get satisfied
		std::cout << "p_a->GetName() : " << p_a->GetName() << std::endl; // Will not work !
	}
	
	/* By Raw Pointer */
	SetNameWrapper(p_b.get(), "Raw Pointer");
	std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl;
	
	/* By Copy Constructor */
	SetNameWrapper(*(p_b.get()), "Copy Constructor");
	std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl;
	
	/* By Unique Pointer */
	Entity* e = SetNameWrapper(std::move(p_b), "Unique Pointer");
	// std::cout << "p_b->GetName() : " << p_b->GetName() << std::endl; // This is not possible now.
	std::cout << "p_b->GetName() : " << e->GetName() << std::endl; // This is also not possible now.
}

// int main(int argc, char const *argv[])
// {
// 	One_1_OwnershipTransfer();
// 	Two_2_Pass_By_sdt_Move();
//     return 0;
// }


