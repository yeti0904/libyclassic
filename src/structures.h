#pragma once
#include "components.h"

typedef struct ServerConnection {
	int                sock;
	struct sockaddr_in addr;
	bool               err;
} ServerConnection;


typedef struct Vec3 {
	int16_t x, y, z;
} Vec3;

#define VEC3_FROM_BLOCK_COORDS(x, y, z) ((Vec3){x*32, y*32, z*32})
#define VEC3(x, y, z)                   ((Vec3){x, y, z})

typedef struct Orientation {
	int8_t pitch, yaw;
} Orientation;

#define ORIENTATION(p, y) ((Orientation){p, y})