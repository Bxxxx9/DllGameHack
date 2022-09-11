#pragma once
#include <list>
namespace hack
{
	intptr_t createPointerTovariable(intptr_t pointer, std::list<int> offsetlist);
	void changeruningCode(void* dest, void* src, int size);
}
