/*
 * Copyright (C) 2000-2006 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */
/* Massivly hacked up for uClibc by Erik Andersen */

#include <_lfs_64.h>

#ifdef __UCLIBC_HAS_LFS__

#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <bits/uClibc_page.h>

libc_hidden_proto(mmap)

# if !defined __NR_mmap2 || !defined _syscall6

/*
 * This version is a stub that just chops off everything at the mmap 32 bit
 * mmap() address space...  You will probably need to add in an arch specific
 * implementation to override this as there is not a generic way for me to
 * implement this particular syscall if your arch lacks _syscall6...
 *
 */

__ptr_t mmap64(__ptr_t addr, size_t len, int prot, int flags, int fd, __off64_t offset)
{
	if (offset != (off_t) offset ||
	    (offset + len) != (off_t) (offset + len)) {
		__set_errno(EINVAL);
		return MAP_FAILED;
	}

	return mmap(addr, len, prot, flags, fd, (off_t) offset);
}

# else

#  define __NR___syscall_mmap2	    __NR_mmap2
static __inline__ _syscall6(__ptr_t, __syscall_mmap2, __ptr_t, addr,
			size_t, len, int, prot, int, flags, int, fd,
			off_t, offset)

/* Some architectures always use 12 as page shift for mmap2() eventhough the
 * real PAGE_SHIFT != 12.  Other architectures use the same value as
 * PAGE_SHIFT...
 */
#  ifndef MMAP2_PAGE_SHIFT
#   define MMAP2_PAGE_SHIFT 12
#  endif

__ptr_t mmap64(__ptr_t addr, size_t len, int prot, int flags, int fd, __off64_t offset)
{
	if (offset & ((1 << MMAP2_PAGE_SHIFT) - 1)) {
		__set_errno(EINVAL);
		return MAP_FAILED;
	}

#  ifdef __USE_FILE_OFFSET64
	return __syscall_mmap2(addr, len, prot, flags,
	                       fd, ((__u_quad_t) offset >> MMAP2_PAGE_SHIFT));
#  else
	return __syscall_mmap2(addr, len, prot, flags,
	                       fd, (__u_long) (offset >> MMAP2_PAGE_SHIFT));
#  endif
}

# endif
#endif /* __UCLIBC_HAS_LFS__ */
