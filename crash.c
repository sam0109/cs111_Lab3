#include <stdio.h>
#include <fcntl.h>
#include <error.h>
#include <ctype.h>
#include <stdlib.h>
#include <inttypes.h>
#include "ospfs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
	system("touch test/crash");
	int nwrites_to_crash = atoi(argv[1]);
	int fd = open("./test/crash", O_RDONLY);
	int status = ioctl(fd, OSPFSIOCRASH, nwrites_to_crash);
	close(fd);
	exit(status);
}
