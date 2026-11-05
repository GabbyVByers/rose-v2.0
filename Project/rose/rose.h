
/*
 *   Header [rose.h]
 */

#ifndef ROSE_ROSE_HEADER_GUARD
#define ROSE_ROSE_HEADER_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(NDEBUG)
#define ROSE_RELEASE
#else
#define ROSE_DEBUG
#endif

#if !defined(ROSE_PANIC)
#if defined(ROSE_RELEASE)
#define rose_panic_abort abort()
#else
#define rose_panic_abort __debugbreak()
#endif
#define ROSE_PANIC(...)                                     \
do {                                                        \
	const char *rose___file = strrchr(__FILE__, '\\');      \
	rose___file = rose___file ? rose___file + 1 : __FILE__; \
	fprintf(stderr, "> PANIC!!!\n");                        \
	fprintf(stderr, "> FILE: [%s]\n", rose___file);         \
	fprintf(stderr, "> LINE: [%d]\n", __LINE__);            \
	fprintf(stderr, "> ERROR: '");                          \
	fprintf(stderr, __VA_ARGS__);                           \
	fprintf(stderr, "'\n");                                 \
	rose_panic_abort;                                       \
} while (0)
#endif

typedef int8_t  Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;

typedef uint8_t  uInt8;
typedef uint16_t uInt16;
typedef uint32_t uInt32;
typedef uint64_t uInt64;

#define ROSE_COLOR_WHITE  ((ROSE_RGBA) { 255, 255, 255, 255 })
#define ROSE_COLOR_BLACK  ((ROSE_RGBA) {   0,   0,   0, 255 })
#define ROSE_COLOR_RED    ((ROSE_RGBA) { 255,   0,   0, 255 })
#define ROSE_COLOR_GREEN  ((ROSE_RGBA) {   0, 255,   0, 255 })
#define ROSE_COLOR_BLUE   ((ROSE_RGBA) {   0,   0, 255, 255 })
#define ROSE_COLOR_CYAN   ((ROSE_RGBA) {   0, 255, 255, 255 })
#define ROSE_COLOR_PURPLE ((ROSE_RGBA) { 255,   0, 255, 255 })
#define ROSE_COLOR_YELLOW ((ROSE_RGBA) { 255, 255,   0, 255 })
#define ROSE_COLOR_TRANS  ((ROSE_RGBA) { 255, 255, 255,   0 })

typedef struct ROSE_RGBA {
	uInt8 r;
	uInt8 g;
	uInt8 b;
	uInt8 a;
};

#define ROSE_IMAGE_INIT ((ROSE_Image) { 0u, 0u, NULL })

typedef struct ROSE_Image {
	uInt32 _width;
	uInt32 _height;
	uInt8* _pixels;
} ROSE_Image;

void ROSE_Init(const char* title, uInt32 width, uInt32 height);
void ROSE_Quit(void);

void ROSE_WindowVSync(bool vsync);
void ROSE_WindowPollEvents(void);
void ROSE_WindowBeginFrame(void);
void ROSE_WindowEndFrame(void);
void ROSE_Window(void);

#endif /* ROSE_ROSE_HEADER_GUARD */

