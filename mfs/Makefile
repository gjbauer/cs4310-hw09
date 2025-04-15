SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
HDRS := $(wildcard *.h)

CFLAGS := -g `pkg-config fuse --cflags`
LDLIBS := `pkg-config fuse --libs`

mkfs: $(OBJS)
	gcc $(CLFAGS) -o mkfs mkfs.o pages.o bitmap.o inode.o $(LDLIBS)
	
read_root: $(OBJS)
	gcc $(CLFAGS) -o read_root read_root.o pages.o bitmap.o inode.o $(LDLIBS)
