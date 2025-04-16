#include <string.h>
#include <stdint.h>
#include "pages.h"
#include "inode.h"
#include "bitmap.h"
#include "directory.h"
#include <stdlib.h>

// Actually read data
int
mread(const char *path, char *buf, unsigned long size)
{
    int rv = 6;
    //strcpy(buf, "hello\n");
    int l = tree_lookup(path);
    inode* n = get_inode(l);
    void *data = (void*)(uintptr_t)n->ptrs[0];
    memcpy(buf, get_data_start(), size);
    printf("read(%s, %ld bytes)\n", path, size);
    return rv;
}

// Actually write data
int
mwrite(const char *path, const char *buf, size_t size)
{
    int rv = -1;
    int l = tree_lookup(path);
    if (l==-1) {
    	int l = alloc_inode();
    }
    inode* n = get_inode(l);
    //void *b = (void*)(uintptr_t)n->ptrs[0];
    memcpy(get_data_start(), buf, size);
    n->size += size;
    printf("write(%s, %ld bytes)\n", path, size);
    return rv;
}

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
	ptr->mode=040755;
	ptr->ptrs[0] = (int)(uintptr_t)get_data_start();
	root->inum = t;
	root->type = DIRECTORY;
	root->active = true;
	t = alloc_inode();
	inode *hello = get_inode(t);
	//printf("%d\n", t);
	hello->mode=0100644;
	hello->ptrs[0] = (int)(uintptr_t)get_data_start();
	dhello->inum = t;
	dhello->type = DIRECTORY;
	dhello->active = true;
	dhello->next=NULL;
	root->next=dhello;
	mwrite("/hello.txt", "hello\n", 6);
	pages_free();
}
