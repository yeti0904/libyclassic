#pragma once

#define PACKET_CLIENT_AUTH                 0x00
#define PACKET_CLIENT_SETBLOCK             0x05
#define PACKET_CLIENT_POSITION_ORIENTATION 0x08
#define PACKET_CLIENT_MESSAGE              0x0D

#define PACKET_SERVER_INFO                 0x00
#define PACKET_SERVER_PING                 0x01
#define PACKET_SERVER_LEVEL_INIT           0x02
#define PACKET_SERVER_LEVEL_DATA           0x03
#define PACKET_SERVER_LEVEL_FINALIZE       0x04
#define PACKET_SERVER_BLOCK_UPDATE         0x06
#define PACKET_SERVER_SPAWN_PLAYER         0x07
#define PACKET_SERVER_POS_ORIENT_TP        0x08
#define PACKET_SERVER_POS_ORIENT_UPDATE    0x09
#define PACKET_SERVER_POSITION_UPDATE      0x0A
#define PACKET_SERVER_ORIENTATION_UPDATE   0x0B
#define PACKET_SERVER_DESPAWN_PLAYER       0x0C
#define PACKET_SERVER_MESSAGE              0x0D
#define PACKET_SERVER_DISCONNECT           0x0E
#define PACKET_SERVER_UPDATE_USER_TYPE     0x0F