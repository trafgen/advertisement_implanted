#if !defined __FEATURES_H && !defined __need_uClibc_config_h
# error Never include <bits/uClibc_config.h> directly; use <features.h> instead
#endif

#define __UCLIBC_MAJOR__ 0
#define __UCLIBC_MINOR__ 9
#define __UCLIBC_SUBLEVEL__ 30
/* Automatically generated make config: don't edit */
/* Version: 0.9.30 */
/* Tue Jun 21 22:59:49 2011 */
#undef __TARGET_alpha__
#define __TARGET_arm__ 1
#undef __TARGET_avr32__
#undef __TARGET_bfin__
#undef __TARGET_cris__
#undef __TARGET_e1__
#undef __TARGET_frv__
#undef __TARGET_h8300__
#undef __TARGET_hppa__
#undef __TARGET_i386__
#undef __TARGET_i960__
#undef __TARGET_ia64__
#undef __TARGET_m68k__
#undef __TARGET_microblaze__
#undef __TARGET_mips__
#undef __TARGET_nios__
#undef __TARGET_nios2__
#undef __TARGET_powerpc__
#undef __TARGET_sh__
#undef __TARGET_sh64__
#undef __TARGET_sparc__
#undef __TARGET_v850__
#undef __TARGET_vax__
#undef __TARGET_x86_64__
#undef __TARGET_xtensa__

/* Target Architecture Features and Options */
#define __TARGET_ARCH__ "arm"
#define __FORCE_OPTIONS_FOR_ARCH__ 1
#undef __CONFIG_ARM_OABI__
#define __CONFIG_ARM_EABI__ 1
#define __CONFIG_GENERIC_ARM__ 1
#undef __CONFIG_ARM610__
#undef __CONFIG_ARM710__
#undef __CONFIG_ARM7TDMI__
#undef __CONFIG_ARM720T__
#undef __CONFIG_ARM920T__
#undef __CONFIG_ARM922T__
#undef __CONFIG_ARM926T__
#undef __CONFIG_ARM10T__
#undef __CONFIG_ARM1136JF_S__
#undef __CONFIG_ARM1176JZ_S__
#undef __CONFIG_ARM1176JZF_S__
#undef __CONFIG_ARM_CORTEX_M3__
#undef __CONFIG_ARM_CORTEX_M1__
#undef __CONFIG_ARM_SA110__
#undef __CONFIG_ARM_SA1100__
#undef __CONFIG_ARM_XSCALE__
#undef __CONFIG_ARM_IWMMXT__
#define __TARGET_SUBARCH__ ""

/* Using ELF file format */
#define __ARCH_ANY_ENDIAN__ 1
#define __ARCH_LITTLE_ENDIAN__ 1
#undef __ARCH_WANTS_BIG_ENDIAN__
#define __ARCH_WANTS_LITTLE_ENDIAN__ 1
#define __ARCH_HAS_MMU__ 1
#define __ARCH_USE_MMU__ 1
#define __UCLIBC_HAS_FLOATS__ 1
#undef __UCLIBC_HAS_FPU__
#define __UCLIBC_HAS_SOFT_FLOAT__ 1
#define __DO_C99_MATH__ 1
#define __UCLIBC_HAS_FENV__ 1
#define __KERNEL_HEADERS__ "/home/yinli/toolschain-make/V2.08.20_P2/autobuild/build/tcbuild/gcc4.1.2_uClibc0.9.30/install/arm_eabi_gcc4.1.2_uClibc0.9.30/arm-linux-uclibcgnueabi/include"
#define __HAVE_DOT_CONFIG__ 1

/* General Library Settings */
#undef __HAVE_NO_PIC__
#define __DOPIC__ 1
#undef __ARCH_HAS_NO_SHARED__
#undef __ARCH_HAS_NO_LDSO__
#define __HAVE_SHARED__ 1
#undef __FORCE_SHAREABLE_TEXT_SEGMENTS__
#define __LDSO_LDD_SUPPORT__ 1
#define __LDSO_CACHE_SUPPORT__ 1
#undef __LDSO_PRELOAD_FILE_SUPPORT__
#define __LDSO_BASE_FILENAME__ "ld.so"
#define __UCLIBC_STATIC_LDCONFIG__ 1
#define __LDSO_RUNPATH__ 1
#define __UCLIBC_CTOR_DTOR__ 1
#undef __LDSO_GNU_HASH_SUPPORT__
#undef __HAS_NO_THREADS__
#define __UCLIBC_HAS_THREADS__ 1
#undef __PTHREADS_DEBUG_SUPPORT__
#define __LINUXTHREADS_OLD__ 1
#define __UCLIBC_HAS_SYSLOG__ 1
#define __UCLIBC_HAS_LFS__ 1
#undef __MALLOC__
#undef __MALLOC_SIMPLE__
#define __MALLOC_STANDARD__ 1
#define __MALLOC_GLIBC_COMPAT__ 1
#define __UCLIBC_DYNAMIC_ATEXIT__ 1
#undef __COMPAT_ATEXIT__
#define __UCLIBC_SUSV3_LEGACY__ 1
#define __UCLIBC_SUSV3_LEGACY_MACROS__ 1
#undef __UCLIBC_HAS_STUBS__
#define __UCLIBC_HAS_SHADOW__ 1
#define __UCLIBC_HAS_PROGRAM_INVOCATION_NAME__ 1
#define __UCLIBC_HAS___PROGNAME__ 1
#define __UCLIBC_HAS_PTY__ 1
#undef __ASSUME_DEVPTS__
#undef __UNIX98PTY_ONLY__
#define __UCLIBC_HAS_GETPT__ 1
#define __UCLIBC_HAS_TM_EXTENSIONS__ 1
#define __UCLIBC_HAS_TZ_CACHING__ 1
#define __UCLIBC_HAS_TZ_FILE__ 1
#define __UCLIBC_HAS_TZ_FILE_READ_MANY__ 1
#define __UCLIBC_TZ_FILE_PATH__ "/etc/TZ"

/* Advanced Library Settings */
#define __UCLIBC_PWD_BUFFER_SIZE__ 256
#define __UCLIBC_GRP_BUFFER_SIZE__ 256

/* Support various families of functions */
#define __UCLIBC_LINUX_MODULE_24__ 1
#define __UCLIBC_LINUX_SPECIFIC__ 1
#define __UCLIBC_HAS_GNU_ERROR__ 1
#define __UCLIBC_BSD_SPECIFIC__ 1
#define __UCLIBC_HAS_BSD_ERR__ 1
#undef __UCLIBC_HAS_OBSOLETE_BSD_SIGNAL__
#undef __UCLIBC_HAS_OBSOLETE_SYSV_SIGNAL__
#undef __UCLIBC_NTP_LEGACY__
#undef __UCLIBC_SV4_DEPRECATED__
#define __UCLIBC_HAS_REALTIME__ 1
#define __UCLIBC_HAS_ADVANCED_REALTIME__ 1
#define __UCLIBC_HAS_EPOLL__ 1
#define __UCLIBC_HAS_XATTR__ 1
#define __UCLIBC_HAS_PROFILING__ 1
#define __UCLIBC_HAS_CRYPT_IMPL__ 1
#define __UCLIBC_HAS_CRYPT__ 1
#define __UCLIBC_HAS_NETWORK_SUPPORT__ 1
#define __UCLIBC_HAS_SOCKET__ 1
#define __UCLIBC_HAS_IPV4__ 1
#define __UCLIBC_HAS_IPV6__ 1
#define __UCLIBC_HAS_RPC__ 1
#define __UCLIBC_HAS_FULL_RPC__ 1
#define __UCLIBC_HAS_REENTRANT_RPC__ 1
#undef __UCLIBC_USE_NETLINK__
#undef __UCLIBC_HAS_BSD_RES_CLOSE__

/* String and Stdio Support */
#define __UCLIBC_HAS_STRING_GENERIC_OPT__ 1
#define __UCLIBC_HAS_STRING_ARCH_OPT__ 1
#define __UCLIBC_HAS_CTYPE_TABLES__ 1
#define __UCLIBC_HAS_CTYPE_SIGNED__ 1
#define __UCLIBC_HAS_CTYPE_UNSAFE__ 1
#undef __UCLIBC_HAS_CTYPE_CHECKED__
#undef __UCLIBC_HAS_CTYPE_ENFORCED__
#define __UCLIBC_HAS_WCHAR__ 1
#undef __UCLIBC_HAS_LOCALE__
#define __UCLIBC_HAS_HEXADECIMAL_FLOATS__ 1
#undef __UCLIBC_HAS_GLIBC_CUSTOM_PRINTF__
#define __UCLIBC_PRINTF_SCANF_POSITIONAL_ARGS__ 9
#undef __UCLIBC_HAS_SCANF_GLIBC_A_FLAG__
#undef __UCLIBC_HAS_STDIO_BUFSIZ_NONE__
#undef __UCLIBC_HAS_STDIO_BUFSIZ_256__
#undef __UCLIBC_HAS_STDIO_BUFSIZ_512__
#undef __UCLIBC_HAS_STDIO_BUFSIZ_1024__
#undef __UCLIBC_HAS_STDIO_BUFSIZ_2048__
#define __UCLIBC_HAS_STDIO_BUFSIZ_4096__ 1
#undef __UCLIBC_HAS_STDIO_BUFSIZ_8192__
#define __UCLIBC_HAS_STDIO_BUILTIN_BUFFER_NONE__ 1
#undef __UCLIBC_HAS_STDIO_BUILTIN_BUFFER_4__
#undef __UCLIBC_HAS_STDIO_BUILTIN_BUFFER_8__
#undef __UCLIBC_HAS_STDIO_SHUTDOWN_ON_ABORT__
#define __UCLIBC_HAS_STDIO_GETC_MACRO__ 1
#define __UCLIBC_HAS_STDIO_PUTC_MACRO__ 1
#define __UCLIBC_HAS_STDIO_AUTO_RW_TRANSITION__ 1
#undef __UCLIBC_HAS_FOPEN_LARGEFILE_MODE__
#undef __UCLIBC_HAS_FOPEN_EXCLUSIVE_MODE__
#undef __UCLIBC_HAS_GLIBC_CUSTOM_STREAMS__
#undef __UCLIBC_HAS_PRINTF_M_SPEC__
#define __UCLIBC_HAS_ERRNO_MESSAGES__ 1
#undef __UCLIBC_HAS_SYS_ERRLIST__
#define __UCLIBC_HAS_SIGNUM_MESSAGES__ 1
#undef __UCLIBC_HAS_SYS_SIGLIST__
#define __UCLIBC_HAS_GNU_GETOPT__ 1
#define __UCLIBC_HAS_GNU_GETSUBOPT__ 1

/* Big and Tall */
#define __UCLIBC_HAS_REGEX__ 1
#define __UCLIBC_HAS_REGEX_OLD__ 1
#define __UCLIBC_HAS_FNMATCH__ 1
#define __UCLIBC_HAS_FNMATCH_OLD__ 1
#undef __UCLIBC_HAS_WORDEXP__
#undef __UCLIBC_HAS_FTW__
#define __UCLIBC_HAS_GLOB__ 1
#undef __UCLIBC_HAS_GNU_GLOB__

/* Library Installation Options */
#define __SHARED_LIB_LOADER_PREFIX__ "/lib"
#define __RUNTIME_PREFIX__ "/"
#define __DEVEL_PREFIX__ "/arm-linux-uclibcgnueabi/"

/* Security options */
#undef __UCLIBC_BUILD_PIE__
#undef __UCLIBC_HAS_ARC4RANDOM__
#undef __HAVE_NO_SSP__
#undef __UCLIBC_HAS_SSP__
#define __UCLIBC_BUILD_RELRO__ 1
#undef __UCLIBC_BUILD_NOW__
#define __UCLIBC_BUILD_NOEXECSTACK__ 1

/* uClibc development/debugging options */
#define __CROSS_COMPILER_PREFIX__ "/home/yinli/toolschain-make/V2.08.20_P2/autobuild/build/tcbuild/gcc4.1.2_uClibc0.9.30/install/arm_eabi_gcc4.1.2_uClibc0.9.30/bin/arm-linux-uclibcgnueabi-"
#define __UCLIBC_EXTRA_CFLAGS__ ""
#undef __DODEBUG__
#undef __DODEBUG_PT__
#undef __DOSTRIP__
#undef __DOASSERTS__
#undef __SUPPORT_LD_DEBUG__
#undef __SUPPORT_LD_DEBUG_EARLY__
#undef __UCLIBC_MALLOC_DEBUGGING__
#define __WARNINGS__ "-Wall"
#undef __EXTRA_WARNINGS__
#undef __DOMULTI__
#undef __UCLIBC_MJN3_ONLY__
