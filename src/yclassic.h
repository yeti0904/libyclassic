#pragma once
#include "structures.h"
#include "components.h"
#include "packets.h"

// client
ServerConnection Client_Connect(char* ip, short port);
bool             Client_Auth(ServerConnection server, char* username, char* mppass);
bool             Client_SetBlock(ServerConnection server, Vec3 pos, bool place, uint8_t block);
bool             Client_Message(ServerConnection server, char* message);
bool             Client_PositionUpdate(ServerConnection server, Vec3 pos, Orientation orientation);

// server


// utils
char* Util_PadString(char* str);
char* Util_UnpadString(char str[64]);