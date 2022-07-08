#pragma once

#include <Windows.h>
#include <iostream>

namespace offsets
{
    inline uintptr_t game_module_address = 0x00400000;
    inline uintptr_t game_module_offset = 0x0017E0A8;

    inline uintptr_t player_offset = 0x28;

    inline uintptr_t player_rot_x_offset = 0xC;
    inline uintptr_t player_rot_y_offset = 0x10;

    inline uintptr_t player_pos_x_offset = 0x0;
    inline uintptr_t player_pos_y_offset = 0x4;
    inline uintptr_t player_pos_z_offset = 0x8;

    inline uintptr_t player_grenades_offset = 0x11C;
    inline uintptr_t player_health_offset = 0xC4;
    inline uintptr_t player_shield_offset = 0xC8;
}
