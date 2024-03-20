#pragma once

#include "memory.h"
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <cstdint>

const DWORD pid = get_process_id(L"Metal.exe");
const address_t client = get_module_base(pid, L"GameAssembly.dll");

void get_offsets() {

    address_t base_addr = client;

    address_t player_addr = base_addr;
    player_addr = player_addr.Offset(0x320DFC8).Deref().Offset(0x320).Deref().Offset(0xC70).Deref();

    while (true) {

        if (!player_addr.Valid()) {
            std::cout << "player_addr is invalid\n";
            Sleep(1000);
            continue;
        }

        address_t attributes_addr = player_addr;
        attributes_addr = attributes_addr.Offset(0x48).Deref();

        address_t health_addr = attributes_addr;
        health_addr = health_addr.Offset(0x10);

        address_t m_isInvulnerable = player_addr;
        m_isInvulnerable = m_isInvulnerable.Offset(0x138);

        address_t m_invulnerableTimer = player_addr;
        m_invulnerableTimer = m_invulnerableTimer.Offset(0x13C);

        address_t m_fpController = player_addr;
        m_fpController = m_fpController.Offset(0x50).Deref();

        address_t jump_adr = controller_adr;

        std::cout << "player_addr: " << std::hex << player_addr.address << "\n";
        std::cout << "health_addr: " << std::hex << health_addr.address << "\n";
        std::cout << "invul_addr: " << std::hex << invul_addr.address << "\n";
        std::cout << "invul_timer_addr: " << std::hex << invul_timer_addr.address << "\n";
        
        Sleep(1000);

    }
}