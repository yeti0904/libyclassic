#pragma once
#include "structures.h"
#include "components.h"
#include "packets.h"

// client
ServerConnection Client_Connect(const char* ip, short port);
bool             Client_Auth(ServerConnection server, const char* username, const char* mppass);
bool             Client_SetBlock(ServerConnection server, Vec3 pos, bool place, uint8_t block);
bool             Client_Message(ServerConnection server, const char* message);
bool             Client_PositionUpdate(ServerConnection server, Vec3 pos, Orientation orientation);

// server


// utils
char* Util_PadString(const char* str);
char* Util_UnpadString(const char str[64]);