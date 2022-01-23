#include "components.h"

char* Util_PadString(const char* str) {
	char* ret = (char*) malloc(64);
	size_t i = 0;
	for (i = 0; i < strlen(str); ++i) {
		ret[i] = str[i];
	}
	for (; i < 64; ++i) {
		ret[i] = ' ';
	}
	return ret;
}

char* Util_UnpadString(const char str[64]) {
	char* ret = (char*) malloc(64);
	size_t i = 0;
	for (i = 0; i < 64; ++i) {
		if (str[i] == ' ') {
			break;
		}
		ret[i] = str[i];
	}
	ret[i] = '\0';
	return ret;
}