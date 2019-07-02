#ifndef LEGATO_VARIABLEHEAP_H
#define LEGATO_VARIABLEHEAP_H

#include "gfx/legato/common/legato_common.h"

typedef struct leVariableHeap
{
    leBool initialized;
    size_t size;
    size_t used;
    size_t maxUsage;

    void* data;

    void* allocList;
    void* freeList;

#if LE_VARIABLEHEAP_DEBUGLEVEL >= 1
    uint32_t allocBlockCount;
    uint32_t freeBlockCount;
#endif
} leVariableHeap;

leResult leVariableHeap_Init(leVariableHeap* heap,
                             void* data,
                             uint32_t size);

void leVariableHeap_Destroy(leVariableHeap* heap);

#if LE_USE_DEBUG_ALLOCATOR == 1
void* leVariableHeap_Alloc(leVariableHeap* heap,
                           uint32_t size,
                           uint32_t lineNum,
                           const char* funcName,
                           const char* fileName);
#else
void* leVariableHeap_Alloc(leVariableHeap* heap,
                           uint32_t size);
#endif

void leVariableHeap_Free(leVariableHeap* heap,
                         void* ptr);
                         
//size_t leVariableHeap_Used(leVariableHeap* heap);

leBool leVariableHeap_Contains(leVariableHeap* heap,
                               void* ptr);

leResult leVariableHeap_Validate(leVariableHeap* heap);

uint32_t leVariableHeap_SizeOf(leVariableHeap* heap,
                               void* ptr);

#ifdef _WIN32
void leVariableHeap_Dump(leVariableHeap* heap,
                         leBool dumpRecords);
#endif

#endif /* LEGATO_VARIABLEHEAP_H */
