#include <string.h>
#include <ctype.h>
#include "include/CSTL/bool.h"

char *bool_toString(const bool b, char *const __restrict ret) {
	if (ret == NULL) {
		return b ? "true" : "false";
	} else {
		return strcpy(ret, b ? "true" : "false");
	}
}

char *bool_fromString(const char *const __restrict string) {
	if (strlen(string) != 4) {
		return false;
	} else if (tolower(string[0]) == 't' && tolower(string[1]) == 'r' && tolower(string[2]) == 'u' && tolower(string[3]) == 'e') {
		return true;
	} else {
		return false;
	}
}
