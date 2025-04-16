#include <string.h>
#include <stdint.h>
#include "pages.h"
#include "inode.h"
#include "bitmap.h"
#include "directory.h"
#include <stdlib.h>
int
main(int argc, char *argv[])
{
	// TODO : mkfs implementation...
	pages_init("data.nufs");
	size_t *p = (size_t*)get_root_start();
	*p = 2;
	dirent *root = (dirent*)get_root_start() + 1;
	dirent *dhello = root + 1;
	strcpy(root->name, "/");
	strcpy(dhello->name, "/hello.txt");
	void *blk = get_root_start();	// Root directory starts at the beginning of data segment...
	int t = alloc_inode();
	inode* ptr = get_inode(t);
	ptr->mode=644;
	ptr->ptrs[0] = (int)(uintptr_t)get_data_start();
	root->inum = t;
	root->type = DIRECTORY;
	root->active = true;
	t = alloc_inode();
	inode *hello = get_inode(t);
	//printf("%d\n", t);
	hello->mode=644;
	hello->ptrs[0] = (int)(uintptr_t)get_data_start();
	dhello->inum = t;
	dhello->type = DIRECTORY;
	dhello->active = true;
	dhello->next=NULL;
	root->next=dhello;
	pages_free();
}
