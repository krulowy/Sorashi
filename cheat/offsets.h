#pragma once

#include "types.h"
#include "memory.h"
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <cstdint>

#include <vector>

const DWORD pid = get_process_id(L"Metal.exe");
const address_t client = get_module_base(pid, L"GameAssembly.dll");

struct Enemy_t {
    char pad[0x60];
    void* puppet;
    void* attributeSystem;
    void* combatTarget;
    void* behaviour;
    void* enemyCtx;
};

inline void get_offsets() {

    address_t base_addr = client;

    while (true) {

        address_t m_Player = base_addr;
        m_Player = m_Player.Offset(0x320DFC8).Deref().Offset(0x320).Deref().Offset(0xC70).Deref();

        if (!m_Player.Valid()) {
            std::cout << "player_addr is invalid\n";
            Sleep(1000);
            continue;
        }


        // Local Player Attributes

        address_t m_attributeSystem = m_Player;
        m_attributeSystem.Offset(0x48).Deref();

        address_t m_health = m_attributeSystem;
        m_health.Offset(0x10);

        address_t m_isInvulnerable = m_Player;
        m_isInvulnerable.Offset(0x138);

        address_t m_invulnerableTimer = m_Player;
        m_invulnerableTimer.Offset(0x13C);

        // Movement

        address_t m_fpController = m_Player;
        m_fpController.Offset(0x50).Deref();

        address_t m_enemybehavior = m_fpController;
        m_enemybehavior.Offset(0x1F8).Deref();

        address_t m_activeEnemiesItems = m_enemybehavior;
        m_activeEnemiesItems.Offset(0x10).Deref().Offset(0x10).Deref();

        address_t m_activeEnemiesItemsCountAddr = m_activeEnemiesItems;
        m_activeEnemiesItemsCountAddr.Offset(0x18);

		address_t m_activeEnemiesItemsArrayAddr = m_activeEnemiesItemsCountAddr;
		m_activeEnemiesItemsArrayAddr.Offset(0x8);
        
        address_t m_jumpSettings = m_fpController;
        m_jumpSettings = m_jumpSettings.Offset(0x48).Deref();

        uint64_t enemyCount = m_activeEnemiesItemsCountAddr.Get<uint64_t>();

        std::cout << "player_addr: " << std::hex << m_Player.address << "\n";
        std::cout << "health_addr: " << m_health.address << "\n";
        std::cout << "invul_addr: " << m_isInvulnerable.address << "\n";
        std::cout << "invul_timer_addr: " << m_invulnerableTimer.address << "\n";
        std::cout << "m_activeEnemiesItems: " << m_activeEnemiesItemsCountAddr.address << "\n";
        std::cout << "m_activeEnemiesItems: " << std::dec << enemyCount << "\n";

        // size of the array in bytes will be : sizeof(uintptr_t) * enemyCount
        // uintptr_t enemyPtrs[enemyCount]; not allowed
        std::vector<Enemy_t*> enemyPtrs(enemyCount);
        if (enemyCount) {
            read_memory(m_activeEnemiesItemsArrayAddr.address, enemyPtrs.data(), enemyCount * sizeof(uintptr_t));

            for (int i = 0; i < enemyCount; i++) {
                if (enemyPtrs[i] != 0)
                    std::cout << "enemy " << std::dec << i << " : " << std::hex << enemyPtrs[i] << "\n";

                // READ TRANSFORM

                // enemyPtrs[i].puppet is wrong externally and won't yield results
                // you need to RPM it!
            }
        }

        jump_settings_t multistrafe = m_jumpSettings.Get<jump_settings_t>();
        multistrafe.ForwardVelocityMultiplier = 2.0f;
        multistrafe.CameraLookInfluence = 1.0f;
        multistrafe.InputMovementInfluence.x = 1000.0f;
        multistrafe.InputMovementInfluence.y = 1000.0f;
        multistrafe.InputMovementInfluence.z = 1000.0f;
        m_jumpSettings.Set<jump_settings_t>(&multistrafe);

        Sleep(1000);

    }
}