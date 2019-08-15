#include "gfx/legato/core/legato_stream.h"
#include "legato_stream.h"

#if LE_STREAMING_ENABLED == 1

void leStream_Init(leStream* stream,
                   leStreamDescriptor* desc,
                   uint32_t cacheSize,
                   uint8_t* cacheBuf,
                   void* userData)
{
    if(stream == NULL)
        return;

    stream->state = LE_STREAM_CLOSED;
    stream->desc = desc;
    stream->cache.ptr = cacheBuf;
    stream->cache.physicalSize = cacheSize;
    stream->userData = userData;
}

leResult leStream_Open(leStream* stream)
{
    if(stream == NULL ||
       stream->desc == NULL ||
       stream->state != LE_STREAM_CLOSED)
    {
        return LE_FAILURE;
    }

    if(stream->desc->location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        if(leApplication_MediaOpenRequest(stream) == LE_FAILURE)
            return LE_FAILURE;

        stream->state = LE_STREAM_READY;
    }

    return LE_SUCCESS;
}

leResult leStream_Read(leStream* stream,
                       uint32_t addr,
                       uint32_t size,
                       uint8_t* buf,
                       leStream_DataReadyCallback cb)
{
    uint32_t remaining;

    if(stream == NULL ||
        buf == NULL ||
        (stream->state != LE_STREAM_READY && stream->state != LE_STREAM_DATAREADY))
    {
        return LE_FAILURE;
    }

    if(stream->desc->location == LE_STREAM_LOCATION_ID_INTERNAL)
    {
        memcpy(buf, (void*)addr, size);

        if(cb != NULL)
        {
            cb(stream);
        }
    }
    else
    {
        // cache is enabled
        if(stream->cache.ptr != NULL)
        {
            // requested data is in the local cache
            if((uint32_t)addr >= stream->cache.baseAddress &&
               (uint32_t)addr - stream->cache.baseAddress + size < stream->cache.logicalSize)
            {
                memcpy(buf,
                       stream->cache.baseAddress + (uint8_t*)addr - stream->cache.baseAddress,
                       size);

                if(cb != NULL)
                {
                    cb(stream);
                }
            }
            // fill cache with new data
            else
            {
                remaining = stream->cache.physicalSize;

                if(stream->desc->size - ((uint32_t)addr - (uint32_t)stream->desc->address) < remaining)
                {
                    remaining = stream->desc->size - ((uint32_t)addr - (uint32_t)stream->desc->address);
                }

                stream->cache.baseAddress = (uint32_t)addr;
                stream->cache.logicalSize = remaining;

                stream->state = LE_STREAM_WAITING;

                stream->readRequest.size = size;
                stream->readRequest.buf = buf;
                stream->readRequest.dataReadyCB = cb;

                if(leApplication_MediaReadRequest(stream,
                                                  stream->cache.baseAddress,
                                                  stream->cache.logicalSize,
                                                  stream->cache.ptr) == LE_FAILURE)
                {
                    return LE_FAILURE;
                }
            }
        }
        // read from data source directly
        else
        {
            stream->state = LE_STREAM_WAITING;

            stream->readRequest.size = size;
            stream->readRequest.buf = buf;
            stream->readRequest.dataReadyCB = cb;

            if(leApplication_MediaReadRequest(stream, addr, size, buf) == LE_FAILURE)
            {
                return LE_FAILURE;
            }
        }
    }

    return LE_SUCCESS;
}

leBool leStream_IsDataReady(leStream* stream)
{
    return stream != NULL && stream->state == LE_STREAM_DATAREADY;
}

leResult leStream_DataReady(leStream* stream)
{
    if(stream == NULL || stream->state != LE_STREAM_WAITING)
        return LE_FAILURE;

    stream->state = LE_STREAM_DATAREADY;

    // this was a cache fill operation
    if(stream->cache.ptr != NULL)
    {
        // fill the read buffer from the cache
        memcpy(stream->readRequest.buf,
               stream->cache.ptr,
               stream->readRequest.size);
    }

    // call the callback
    if(stream->readRequest.dataReadyCB != NULL)
    {
        stream->readRequest.dataReadyCB(stream);
    }

    return LE_SUCCESS;
}

leResult leStream_Close(leStream* stream)
{
    if(stream == NULL || stream->state == LE_STREAM_CLOSED)
        return LE_FAILURE;

    if(stream->desc->location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        leApplication_MediaCloseRequest(stream);

        stream->state = LE_STREAM_CLOSED;
    }

    return LE_SUCCESS;
}

#endif /* LE_STREAMING_ENABLED */
