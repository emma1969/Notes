#include <stdbool.h>
#include <string.h>

bool
validate (size_t len, char s[len])
{
  return !s
    || !strcmp (s, "/etc/ld.so.preload")
    || !strcmp (s, "/etc/ld.so.cache")
    || !strcmp (s, "/lib/x86_64-linux-gnu/glibc-hwcaps/x86-64-v3/libc.so.6")
    || (!strstr (s, "/../")
	&& *s != '/'
	&& strncmp (s, "../", strlen ("../"))
	&& (len < strlen ("/..")
	    || strncmp (s + len - strlen ("/.."),
			"/..",
			strlen ("/..")))
	&& strcmp (s, ".."));
}

int main()