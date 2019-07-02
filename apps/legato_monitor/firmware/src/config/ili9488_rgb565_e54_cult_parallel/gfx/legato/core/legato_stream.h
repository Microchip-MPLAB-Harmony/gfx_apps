#ifndef LE_STREAM_H
#define LE_STREAM_H

#include "gfx/legato/common/legato_common.h"

// *****************************************************************************
/* Structure:
    leStreamDescriptor

  Summary:
    Defines a common header for all stream operations.

  Description:
    dataLocation - indicates the location of the data.  0 is always
                   internal flash.  any other number must be understood
                   by the application

    dataAddress  - the address at which the data resides.  may be a local pointer
                   or a location in some external storage location not in the
                   local memory map.

    dataSize     - the size of the data in bytes
*/
typedef struct leStreamDescriptor
{
    uint32_t location;
    void* address;
    uint32_t size;
} leStreamDescriptor;

#define LE_STREAM_LOCATION_ID_INTERNAL 0

#if LE_STREAMING_ENABLED == 1

// *****************************************************************************
/* enum:
    leStreamState

  Summary:
    Enumerates stream state machine states.

    LE_STREAM_CLOSED    - stream isn't currently open
    LE_STREAM_READY     - stream is ready to fetch data
    LE_STREAM_WAITING   - stream is waiting for a memory operation to complete
    LE_STREAM_DATAREADY - stream has data ready for use
    LE_STREAM_ERROR     - stream encountered an unrecoverable error
*/
typedef enum leStreamState
{
    LE_STREAM_CLOSED     = 1 << 0,
    LE_STREAM_READY      = 1 << 1,
    LE_STREAM_WAITING    = 1 << 2,
    LE_STREAM_DATAREADY  = 1 << 3,
    LE_STREAM_ERROR      = 1 << 4,
} leStreamState;

struct leStream;

typedef void (*leStream_DataReadyCallback)(struct leStream* strm);

// *****************************************************************************
/* Structure:
    struct leStream

  Summary:
    Defines the base description of an stream reader.  Specific reader
    implementations will build on this foundation for each decoder type.

  Description:
    data - the data being streamed

    status - the overall status of the stream state machine

    dataReady - signals that the requested data is ready.  if NULL then the stream
                is a blocking-type stream and cannot preempt itself

    userData - any kind of user or application data attached to this reader

*/
typedef struct leStream
{
    leStreamDescriptor* desc;

    enum leStreamState state;

    int32_t result;

    struct
    {
        uint32_t size;
        uint8_t* buf;
        leStream_DataReadyCallback dataReadyCB;
    } readRequest;

    struct
    {
        uint32_t physicalSize;
        uint32_t baseAddress;
        uint32_t logicalSize;
        uint8_t* ptr;
    } cache;

    void* userData;
} leStream;

void leStream_Init(leStream* stream,
                   leStreamDescriptor* desc,
                   uint32_t cacheSize,
                   uint8_t* cacheBuf,
                   void* userData);

leResult leStream_Open(leStream* stream);

leResult leStream_Read(leStream* stream,
                       uint32_t addr,
                       uint32_t size,
                       uint8_t* buf,
                       leStream_DataReadyCallback cb);

leBool leStream_IsDataReady(leStream* stream);

leResult leStream_DataReady(leStream* stream);

leResult leStream_Close(leStream* stream);

typedef struct leStreamManager
{
    leResult (*exec)(struct leStreamManager* mgr);
    leBool (*isDone)(struct leStreamManager* mgr);
    void (*abort)(struct leStreamManager* mgr);

    void (*onDone)(struct leStreamManager* mgr);
    void* userData;
} leStreamManager;

// *****************************************************************************
/* typedef:
    leApplication_MediaOpenRequest

  Summary:
    A callback that indicates that a stream wishes to read from an external
    source and that the application should prepare that source.

    If the result is false then the stream will abort.

    reader - the reader that is requesting to stream data
*/
leResult leApplication_MediaOpenRequest(leStream* stream);

// *****************************************************************************
/* typedef:
    leMemoryReadRequest_FnPtr

  Summary:
    A memory read request function is a request that is issued by anything that
    needs external support to access data that is stored in some external
    location.  For instance, an image may be stored in an SPI memory chip.
    A JPEG decoder has no knowledge of what SPI is.  This read request is issued
    to the application so that the application can then assume responsibility for
    communication with the peripherial to retrieve the data.  If the reader pointer
    or the callback pointer are null then the read request must be serviced
    immediately.  In other words, the requesting decoder does not support
    non-blocking streaming.

    From the reader the handler can determine which asset is being decoded and
    which media it resides in.

    stream - the stream requesting the media data
    address - the requested source address
    size - the requested data size
    buf - the destination data address
*/
leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address,  // address
                                        uint32_t size,  // dest size
                                        uint8_t* buf);  // dest buffer);

// *****************************************************************************
/* typedef:
    leMediaCloseRequest_FnPtr

  Summary:
    A callback that indicates that a stream is finished with a given
    media location and that the application can close if it.

    reader - the reader that was streaming data.
*/
void leApplication_MediaCloseRequest(leStream* stream);


#endif /* LE_STREAMING_ENABLED */

#endif /* LE_STREAM_H */
