#ifndef LEGATO_FIXEDHEAP_H
#define LEGATO_FIXEDHEAP_H

#include "gfx/legato/common/legato_common.h"

#if LE_FIXEDHEAP_ENABLE == 1

#if LE_FIXEDHEAP_DEBUG == 1
#define LE_FIXEDHEAP_HEADER_SIZE   sizeof(leFixedHeapDebugHeader)
#define LE_FIXEDHEAP_FOOTER_SIZE   4
#define LE_FIXEDHEAP_CHECKSUM      (-1)

#define LE_FIXEDHEAP_BLOCK_FOOTER_PTR(size, blk)   ((uint8_t*)blk + size - LE_FIXEDHEAP_FOOTER_SIZE)

#else
#define LE_FIXEDHEAP_HEADER_SIZE        0
#define LE_FIXEDHEAP_FOOTER_SIZE        0
#endif

#define LE_FIXEDHEAP_BLOCK_SIZE(size) (LE_FIXEDHEAP_HEADER_SIZE + size + LE_FIXEDHEAP_FOOTER_SIZE)

#if LE_FIXEDHEAP_DEBUG == 1
typedef struct leFixedHeapDebugHeader
{
#if LE_USE_ALLOCATION_TRACKING == 1
    uint32_t lineNumber;
    const char* funcName;
    const char* fileName;
#endif

    leBool   free;
    uint32_t checksum;
} leFixedHeapDebugHeader;
#endif

typedef struct leFixedHeapBlock
{
#if LE_FIXEDHEAP_DEBUG == 1
    leFixedHeapDebugHeader debug;
#endif
    void* data;
} leFixedHeapBlock;

typedef struct leFixedHeap
{
    leBool initialized;
    uint32_t numElements;
    uint32_t logicalBlockSize;
    uint32_t physicalBlockSize;
    uint32_t capacity;
    uint32_t maxUsage;
    void* data;
    void* freeList;
} leFixedHeap;

leResult leFixedHeap_Init(leFixedHeap* heap,
                          uint32_t size,
                          uint32_t count,
                          uint8_t* data);

void leFixedHeap_Destroy(leFixedHeap* heap);

#if LE_USE_DEBUG_ALLOCATOR == 1
void* leFixedHeap_Alloc(leFixedHeap* heap,
                        uint32_t lineNum,
                        const char* funcName,
                        const char* fileName);
#else
void* leFixedHeap_Alloc(leFixedHeap* heap);
#endif

void leFixedHeap_Free(leFixedHeap* heap, void* ptr);

leBool leFixedHeap_Contains(leFixedHeap* heap, void* ptr);

leResult leFixedHeap_Validate(leFixedHeap* heap);

#ifdef _WIN32
void leFixedHeap_Dump(leFixedHeap* heap, leBool dumpRecords);
#endif

#endif

#endif /* LEGATO_FIXEDHEAP_H */
