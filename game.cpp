#include <game.hpp>

#include <cstring>
#include <string>

#include <command.hpp>
#include <utils.hpp>

#include <portal2.hpp>

std::vector<std::string> Game::mapNames;

const char* Game::Version() {
	return "Unknown";
}

Game* Game::CreateNew() {
	return new Portal2;
}

std::string Game::VersionToString(int version) {
	return "Portal 2";
}
