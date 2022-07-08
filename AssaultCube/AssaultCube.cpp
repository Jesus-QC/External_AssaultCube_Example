#include "AssaultCube.h"

void input(HANDLE processHandle, uintptr_t player_address)
{
    while(true)
    {
        if (GetAsyncKeyState(VK_NUMPAD0)) // Easy example using the PositionZ offset to Lock the Z Axis.  (Flying)
        {
            float savedY;
            ReadProcessMemory(processHandle, (BYTE*)(player_address + offsets::player_pos_z_offset), &savedY, sizeof(float), nullptr);
            std::cout << "e";
            Sleep(500);
            while (true)
            {
                if(GetAsyncKeyState(VK_NUMPAD0))
                    break;
                
                WriteProcessMemory(processHandle, (BYTE*)(player_address + offsets::player_pos_z_offset), &savedY, sizeof(float), nullptr);
            }
            
            Sleep(100);
        }
        Sleep(10);
    }
}

int main()
{
    HWND game_window = FindWindowA(nullptr, "AssaultCube");

    if(game_window == nullptr)
    {
        std::cout << "Game Window not found!";
        Sleep(3000);
        return -1;
    }
    
    DWORD processId;
    GetWindowThreadProcessId(game_window, &processId);

    std::cout << "Found process id: " << processId << std::endl;

    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

    uintptr_t player_entry;
    ReadProcessMemory(processHandle, (BYTE*)(offsets::game_module_address + offsets::game_module_offset), &player_entry, sizeof(player_entry), nullptr);

    uintptr_t player_address = player_entry + offsets::player_offset;
    std::cout << "Player address found: 0x" << std::hex << player_address << std::endl;
    
    input(processHandle, player_address);
}
