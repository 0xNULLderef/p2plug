#pragma once
#include <module.hpp>

#include <interface.hpp>
#include <sdk.hpp>
#include <platform.hpp>

#define TIER1 "libvstdlib"

class Tier1 : public Module {
public:
	Interface* g_pCVar = nullptr;

	_RegisterConCommand RegisterConCommand = nullptr;
	_UnregisterConCommand UnregisterConCommand = nullptr;
	_FindCommandBase FindCommandBase = nullptr;
	_InstallGlobalChangeCallback InstallGlobalChangeCallback = nullptr;
	_RemoveGlobalChangeCallback RemoveGlobalChangeCallback = nullptr;

	ConCommandBase* m_pConCommandList = nullptr;

	void* ConCommand_VTable = nullptr;
	void* ConVar_VTable = nullptr;
	void* ConVar_VTable2 = nullptr;
	_AutoCompletionFunc AutoCompletionFunc = nullptr;

	using _Dtor = int(__rescall*)(ConVar* thisptr);
	using _Create = int(__rescall*)(ConVar* thisptr, const char* pName, const char* pDefaultValue, int flags, const char* pHelpString, bool bMin, float fMin, bool bMax, float fMax, FnChangeCallback_t callback);

	_Dtor Dtor = nullptr;
	_Create Create = nullptr;

public:
	bool Init() override;
	void Shutdown() override;
	const char* Name() override { return "libvstdlib.so"; }
};

extern Tier1* tier1;

struct CBaseAutoCompleteFileList {
	const char* m_pszCommandName;
	const char* m_pszSubDir;
	const char* m_pszExtension;

	CBaseAutoCompleteFileList(const char* cmdname, const char* subdir, const char* extension);
	int AutoCompletionFunc(char const* partial, char commands[COMMAND_COMPLETION_MAXITEMS][COMMAND_COMPLETION_ITEM_LENGTH]);
};