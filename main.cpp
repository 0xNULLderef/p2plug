#include <main.hpp>
#include <sdk.hpp>
#include <portal2.hpp>

#include <iostream>

Plug plug;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(Plug, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, plug);

Plug::Plug() : game(Game::CreateNew()) {
	// this->game = ;
}

bool Plug::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) {
	console = new Console();
	if(!console->Init())
		return false;
	
	console->PrintActive("Less foken goooooooooo! Successful plugin load!\n");

	return true;
}

void Plug::Unload() {}
void Plug::Pause() {}
void Plug::UnPause() {}
const char* Plug::GetPluginDescription() {
	return "Basic plugin";
}
void Plug::LevelInit(char const* pMapName) {}
void Plug::ServerActivate(void* pEdictList, int edictCount, int clientMax) {}
void Plug::GameFrame(bool simulating) {}
void Plug::LevelShutdown() {}
void Plug::ClientFullyConnect(void* pEdict) {}
void Plug::ClientActive(void* pEntity) {}
void Plug::ClientDisconnect(void* pEntity) {}
void Plug::ClientPutInServer(void* pEntity, char const* playername) {}
void Plug::SetCommandClient(int index) {}
void Plug::ClientSettingsChanged(void* pEdict) {}
int Plug::ClientConnect(bool* bAllowConnect, void* pEntity, const char* pszName, const char* pszAddress, char* reject, int maxrejectlen) { return 0; }
int Plug::ClientCommand(void* pEntity, const void*& args) { return 0; }
int Plug::NetworkIDValidated(const char* pszUserName, const char* pszNetworkID) { return 0; }
void Plug::OnQueryCvarValueFinished(int iCookie, void* pPlayerEntity, int eStatus, const char* pCvarName, const char* pCvarValue) {}
void Plug::OnEdictAllocated(void* edict) {}
void Plug::OnEdictFreed(const void* edict) {}