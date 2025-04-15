#include <string.h>
#include <stdint.h>
#include "pages.h"
#include "inode.h"
#include "bitmap.h"
#include "directory.h"
int
main(int argc, char *argv[])
{
	pages_init("data.nufs");
	dirent root;
	void *blk = get_data_start();	// Root directory starts at the beginning of data segment...
	memcpy(&root, blk, sizeof(root));
	printf("%s\n", root.name);
	pages_free();
}
