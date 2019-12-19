#include "uls.h"

char *get_login(uid_t st_uid) {
	char *user = (char *)malloc(256);
	struct passwd *pw = getpwuid(st_uid);

	if (pw == NULL)
		user = mx_itoa(st_uid);
	else
		mx_strcpy(user, pw->pw_name);
	return user;
}
