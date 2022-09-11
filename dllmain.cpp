// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "hack.h"

DWORD WINAPI hackProgram(LPVOID IpParametr)
{
    /*AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT", "N", stdout);*/
    intptr_t moduleAddress = (intptr_t)GetModuleHandle(L"ac_client.exe");
    intptr_t playerObject = moduleAddress + 0x18AC00;

    bool recoil = false;
    bool firerate = false;
    bool reload = false;
    bool munition = false;

    while (true)
    {
        Sleep(1);
        if (GetAsyncKeyState(VK_LBUTTON) < 0)
        {
            
            hack::changeruningCode((void*)(moduleAddress + 0xC73EF), (void*)"\xFF\x00", 2);
        }
        if (GetAsyncKeyState(VK_RBUTTON) < 0)
        {
            intptr_t health = hack::createPointerTovariable(playerObject, { 0xEC });
            int* newhealth = (int*)health;
            *newhealth = 200;
        }
        
    }
    /*fclose(file);
    FreeConsole();*/

    FreeLibraryAndExitThread((HMODULE)IpParametr, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(NULL, 0, hackProgram, hModule, 0, NULL));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

