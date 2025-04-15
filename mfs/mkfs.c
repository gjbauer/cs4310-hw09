#include <string.h>
#include <stdint.h>
#include "pages.h"
#include "inode.h"
#include "bitmap.h"
#include "directory.h"
int
main(int argc, char *argv[])
{
	// TODO : mkfs implementation...
	pages_init("data.nufs");
	inode ind;
	dirent root;
	strcpy(root.name, "root");
	void *blk = get_data_start();	// Root directory starts at the beginning of data segment...
	memset(&ind, 0, sizeof(ind));
	ind.mode=644;
	ind.ptrs[0] = (int)(uintptr_t)blk;
	int t = alloc_inode();
	inode* ptr = get_inode(t);
	memcpy(ptr, &ind, sizeof(ind));
	root.inum = t;
	root.type = DIRECTORY;
	memcpy(blk, &root, sizeof(root));
	pages_free();
}
