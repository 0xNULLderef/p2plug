#pragma once

#define MODULE_EXTENSION ".so"

#define __rescall __attribute__((__cdecl__))
#define __cdecl __attribute__((__cdecl__))
#define __stdcall __attribute__((__stdcall__))
#define __fastcall __attribute__((__fastcall__))
#define DLL_EXPORT extern "C" __attribute__((visibility("default")))
#define SEEK_DIR_CUR std::ios_base::seekdir::_S_cur

#define DECL_DETOUR(name, ...)                                     \
	using _##name = int(__rescall*)(void* thisptr, ##__VA_ARGS__); \
	static _##name name;                                           \
	static int __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)
#define DECL_DETOUR_T(type, name, ...)                              \
	using _##name = type(__rescall*)(void* thisptr, ##__VA_ARGS__); \
	static _##name name;                                            \
	static type __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)
#define DECL_DETOUR_B(name, ...)                                   \
	using _##name = int(__rescall*)(void* thisptr, ##__VA_ARGS__); \
	static _##name name;                                           \
	static _##name name##Base;                                     \
	static int __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)

#define DETOUR(name, ...) \
	int __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)
#define DETOUR_T(type, name, ...) \
	type __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)
#define DETOUR_B(name, ...) \
	int __rescall name##_Hook(void* thisptr, ##__VA_ARGS__)

#define DECL_DETOUR_STD(type, name, ...)             \
	using _##name = type(__stdcall*)(##__VA_ARGS__); \
	static _##name name;                             \
	static type __stdcall name##_Hook(##__VA_ARGS__)
#define DETOUR_STD(type, name, ...) type __stdcall name##_Hook(##__VA_ARGS__)