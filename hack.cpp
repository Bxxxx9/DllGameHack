#include "pch.h"
#include "hack.h"

intptr_t hack::createPointerTovariable(intptr_t pointer, std::list<int> offsetlist)
{
	intptr_t address = pointer;
	for (int offset : offsetlist)
	{
		address = *(intptr_t*)address;
		address += offset;
	}
	return address;
}


void hack::changeruningCode(void* dest, void* src, int size)
{
	DWORD oldprotect;
	VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memcpy(dest, src, size);
	VirtualProtect(dest, size, oldprotect, &oldprotect);
}