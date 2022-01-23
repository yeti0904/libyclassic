#include <stdio.h>
#include <yclassic/yclassic.h>

int main(void) {
	ServerConnection server;
	server = Client_Connect("127.0.0.1", 25565);
	if (Client_Auth(server, "user", "mppass-")) {
		printf("Authenticated\n");
	}
	if (Client_PositionUpdate(server, VEC3_FROM_BLOCK_COORDS(128, 128, 128), ORIENTATION(0, 0))) {
		printf("Position updated\n");
	}
	if (Client_SetBlock(server, VEC3(128, 128, 128), true, 1)) {
		printf("Placed block\n");
	}
	if (Client_Message(server, "hello from my minecraft classic library")) {
		printf("Sent a message\n");
	}
	return 0;
}
