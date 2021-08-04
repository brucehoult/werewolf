# Makefile for compiling the .c and .s files
# If you want to compile .dylan files, don't use this makefile.

CCFLAGS = -I. -I/usr/local/include -Os -fomit-frame-pointer -no-cpp-precomp -Wno-long-double
LIBTOOL = glibtool
GC_LIBS = -lgc -ldl -lpthread
# We only know the ultimate target when we've finished building the rest
# of this makefile.  So we use this fake target...
#
all : all-at-end-of-file

werewolf-exports.o : werewolf-exports.c
	gcc $(CCFLAGS) -c werewolf-exports.c -o werewolf-exports.o
werewolf.o : werewolf.c
	gcc $(CCFLAGS) -c werewolf.c -o werewolf.o
werewolf-init.o : werewolf-init.c
	gcc $(CCFLAGS) -c werewolf-init.c -o werewolf-init.o
werewolf-heap.o : werewolf-heap.c
	gcc $(CCFLAGS) -c werewolf-heap.c -o werewolf-heap.o
werewolf-global-heap.o : werewolf-global-heap.c
	gcc $(CCFLAGS) -c werewolf-global-heap.c -o werewolf-global-heap.o
werewolf-global-inits.o : werewolf-global-inits.c
	gcc $(CCFLAGS) -c werewolf-global-inits.c -o werewolf-global-inits.o

werewolf :  werewolf-exports.o werewolf.o werewolf-init.o werewolf-heap.o werewolf-global-heap.o werewolf-global-inits.o
	$(LIBTOOL) --mode=link gcc -o werewolf  werewolf-exports.o werewolf.o werewolf-init.o werewolf-heap.o werewolf-global-heap.o werewolf-global-inits.o  /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libio-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libformat-out-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libstandard-io-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libformat-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libprint-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libcommon-dylan-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/librandom-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libtranscendental-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libtable-extensions-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libthreads-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libstreams-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libmelange-support-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libdylan-dylan.a /usr/local/lib/dylan/2.4.1pre1/intel-darwin-gcc4/libruntime.a  $(GC_LIBS) -multiply_defined suppress

all-at-end-of-file : werewolf

clean :
	rm -f  werewolf-exports.o werewolf.o werewolf-init.o werewolf-heap.o werewolf-global-heap.o werewolf-global-inits.o werewolf

realclean :
	rm -f  cc-werewolf-files.mak werewolf-exports.o werewolf-exports.c werewolf.o werewolf.c werewolf-init.o werewolf-init.c werewolf-heap.o werewolf-heap.c werewolf-global-heap.o werewolf-global-heap.c werewolf-global-inits.o werewolf-global-inits.c werewolf
