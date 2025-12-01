#include "memory.h"
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include "offsets.h"

int main()
{
    std::atexit([]() {std::cin.get(); });
    if (pid == 0)
    {
        std::cout << "nigga Failed to find the process.\n";
        std::cin.get();
        return 1;
    }

    handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (handle == INVALID_HANDLE_VALUE) {
        std::cout << "bruh0";
        return 1;
    }

    if (!client.Valid())
    {
        std::cout << "bruh0";
        return 1;
    }

    std::cout << "we got da client " << std::hex << client.address << "\n";
    std::cout << "offsets : \n";
    get_offsets();

    while (true) {
        #if 0
        uintptr_t result;
        uintptr_t read_address = client + 0x320DFC8;
        uintptr_t health_address;
        uintptr_t attributes_addr;

        if (!read_memory(read_address, &result)) {
            Sleep(100);
            continue;
        }
        read_address = result + 0x320;

        if (!read_memory(read_address, &result)) {
            Sleep(100);
            continue;
        }
        read_address = result + 0xC70;

        if (!read_memory(read_address, &result)) {
            Sleep(100);
            continue;
        }
        std::cout << "address before 3 deref " << std::hex << read_address << "\n";
        std::cout << "player address = " << std::hex << result << "\n";
        attributes_addr = result + 0x48;
        if (!read_memory(attributes_addr, &health_address)) {
            Sleep(100);
            continue;
        }
        health_address = health_address + 0x10;
        std::cout << "health address = " << std::hex << health_address + 0x10 << "\n";

        float health;

        // float godmode = 100.0f;

        read_memory(health_address, &health);
        
        // WriteProcessMemory(handle, (LPVOID)health_address, &godmode, sizeof(godmode), NULL);

        std::cout << "health: " << health << "\n";
        #endif


        // the initial address we want to do our operations on
       

        
        if (health_addr.Valid()) {

            float inf_health = 100.0f;
            health_addr.Set<float>(&inf_health);

            float health = health_addr.Get<float>();
            bool invul = true;
            invul_addr.Set<bool>(&invul);

            float invul_timer = 100.0f;
            invul_timer_addr.Set<float>(&invul_timer);

            std::cout << "health: " << health << "\n";
            
        }
        else {
            // oh no..
        }*/

        Sleep(30);
    }
}
