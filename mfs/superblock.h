// Disk layout:
// [ boot block | super block | pages bitmap | inode bitmap | inode blocks | data blocks]
//
// mkfs computes the super block and builds an initial file system. The
// super block describes the disk layout:
struct superblock {
  unsigned int magic;        // Must be FSMAGIC
  unsigned int size;         // Size of file system image (blocks - 4Kb)
  unsigned int nblocks;      // Number of data blocks
  unsigned int ninodes;      // Number of inodes.
};

#define FSMAGIC 0x15253545

const int NUFS_SIZE  = 4096 * 256; // 1MB
