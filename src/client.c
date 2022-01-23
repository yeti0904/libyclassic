#include "components.h"
#include "structures.h"
#include "yclassic.h"

// sending

ServerConnection Client_Connect(const char* ip, short port) {
	ServerConnection ret;
	ret.err  = false;
	ret.sock = socket(AF_INET, SOCK_STREAM, 0);
	if (ret.sock == -1) {
		ret.err = true;
		return ret;
	}

	ret.addr.sin_family = AF_INET;
	ret.addr.sin_port = htons(port);
	if (inet_pton(AF_INET, ip, &ret.addr.sin_addr) == 0) {
		ret.err = true;
		return ret;
	}

	if (connect(ret.sock, (struct sockaddr*)&ret.addr, sizeof(ret.addr)) == -1) {
		ret.err = true;
		return ret;
	}

	return ret;
}

bool Client_Auth(ServerConnection server, const char* username, const char* mppass) {
	char*   paddedUsername = Util_PadString(username);;
	char*   paddedMppass   = Util_PadString(mppass);
	uint8_t tmpByte        = PACKET_CLIENT_AUTH;

	if (send(server.sock, &tmpByte, 1, 0) != 1) { // packet ID
		server.err = true;
		return false;
	}

	tmpByte = 0x07;
	if (send(server.sock, &tmpByte, 1, 0) != 1) { // protocol version
		server.err = true;
		return false;
	}

	if (send(server.sock, paddedUsername, 64, 0) != 64) { // username
		free(paddedUsername);
		server.err = true;
		return false;
	}
	free(paddedUsername);

	if (send(server.sock, paddedMppass, 64, 0) != 64) { // mppass
		free(paddedMppass);
		server.err = true;
		return false;
	}
	free(paddedMppass);

	tmpByte = 0x00;
	if (send(server.sock, &tmpByte, 1, 0) != 1) { // unused
		server.err = true;
		return false;
	}
	return true;
}

bool Client_SetBlock(ServerConnection server, Vec3 pos, bool place, uint8_t block) {
	uint8_t tmpByte = PACKET_CLIENT_SETBLOCK;

	if (send(server.sock, &tmpByte, 1, 0) != 1) { // packet ID
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.x, 2, 0) != 2) { // x
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.y, 2, 0) != 2) { // y
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.z, 2, 0) != 2) { // z
		server.err = true;
		return false;
	}

	if (send(server.sock, &place, 1, 0) != 1) { // place
		server.err = true;
		return false;
	}

	if (send(server.sock, &block, 1, 0) != 1) { // block
		server.err = true;
		return false;
	}

	return true;
}

bool Client_PositionUpdate(ServerConnection server, Vec3 pos, Orientation orientation) {
	uint8_t tmpByte = PACKET_CLIENT_POSITION_ORIENTATION;
	
	if (send(server.sock, &tmpByte, 1, 0) != 1) { // packet ID
		server.err = true;
		return false;
	}

	tmpByte = 255;

	if (send(server.sock, &tmpByte, 1, 0) != 1) { // player id
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.x, 2, 0) != 2) { // x
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.y, 2, 0) != 2) { // y
		server.err = true;
		return false;
	}

	if (send(server.sock, &pos.z, 2, 0) != 2) { // z
		server.err = true;
		return false;
	}

	if (send(server.sock, &orientation.yaw, 1, 0) != 1) { // pitch
		server.err = true;
		return false;
	}

	if (send(server.sock, &orientation.pitch, 1, 0) != 1) { // yaw
		server.err = true;
		return false;
	}

	return true;
}

bool Client_Message(ServerConnection server, const char* message) {
	char* paddedMessage = Util_PadString(message);
	uint8_t tmpByte     = PACKET_CLIENT_MESSAGE;

	if (send(server.sock, &tmpByte, 1, 0) != 1) { // packet ID
		server.err = true;
		return false;
	}

	tmpByte = 0xFF;
	if (send(server.sock, &tmpByte, 1, 0) != 1) { // unused
		server.err = true;
		return false;
	}

	if (send(server.sock, paddedMessage, 64, 0) != 64) { // message
		free(paddedMessage);
		server.err = true;
		return false;
	}
	free(paddedMessage);
	return true;
}

// recieving
int8_t Client_GetPacket(ServerConnection server) {
	uint8_t id;
	if (recv(server.sock, &id, 1, MSG_WAITALL) != 1) {
		server.err = true;
		return -1;
	}
	return (int8_t) id;
}