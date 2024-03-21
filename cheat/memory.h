#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <iostream>

inline HANDLE handle;
DWORD get_process_id(const wchar_t *process_name);
std::uintptr_t get_module_base(const DWORD pid, const wchar_t *module_name);


template <typename T>
bool read_memory(uintptr_t read_address, T* buffer)
{
    if (read_address == 0) {
        return false;
    }
    SIZE_T read;
    return ReadProcessMemory(handle, (LPCVOID)read_address, buffer, sizeof(T), &read);
}

template <typename T>
bool read_memory(uintptr_t read_address, T* buffer, size_t size)
{
    if (read_address == 0) {
        return false;
    }
    SIZE_T read;
    return ReadProcessMemory(handle, (LPCVOID)read_address, buffer, size, &read);
}

// wrapper to handle pointer arithmetic easily
struct address_t {
    address_t() : address(0) {}
    address_t(uintptr_t x) : address(x) {}
    address_t(void* ptr) : address(uintptr_t(ptr)) {}

    bool Valid() const {
        return address != 0 && address != ~0;
    }

    address_t& Offset(ptrdiff_t offset) {
        address += offset;
        //std::cout << "address : " << std::hex << address << "\n";
        return *this;
    }

    address_t& Deref(size_t n = 1) {
        uintptr_t value;
        for (size_t i = 0; i < n; i++) {
            if (!Valid() || !ReadProcessMemory(handle, (LPVOID)address, &value, sizeof(value), nullptr)) {
                address = ~0;
                break;
            }
            address = value;
            //std::cout << "address : " << std::hex << address << "\n";
        }
        return *this;
    }

    template <typename T>
    T Get(ptrdiff_t offset = 0x0) {
        T value{};
        if (!Valid())
            return value;

        ReadProcessMemory(handle, reinterpret_cast<void*>(address + offset), &value, sizeof(value), nullptr);
        return value;
    }
    template <typename T>
    void Set(T* value , ptrdiff_t offset = 0x0) {
        if (!Valid())
            return;

        WriteProcessMemory(handle, reinterpret_cast<void*>(address + offset), value, sizeof(T), nullptr);
        return;
    }

    uintptr_t address;
};