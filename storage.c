#include "storage.h"
#include "pages.h"

void storage_init(const char* path) {
	pages_init(path);
	void* bm = get_inode_bitmap();
}
