#ifndef COMPONENT_INTERACTABLE_HPP
#define COMPONENT_INTERACTABLE_HPP
#include "entityx/entityx.h"

struct Interactable : entityx::Component<Interactable>
{
	void(*Interact)(entityx::Entity entity);
};
#endif