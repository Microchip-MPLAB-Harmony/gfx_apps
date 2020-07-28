/*******************************************************************************
  MPLAB Harmony Application Splash Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_FPSCMotion.c

  Summary:
    This file contains the source code for the demo FPS motion screen.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "gfx/legato/generated/screen/le_gen_screen_FPSImages.h"
#include "definitions.h"

#include <stdio.h>
#include <string.h>

#include "system/time/sys_time.h"

#define AVE_FPS_COUNT 10
#define FPS_UPDATE_TIMER_PERIOD_MS 1000
#define MAX_NUM_IMAGES 2
//#define ENABLE_FULL_SCREEN_IMAGE_TEST  1

static volatile leBool aveFPSValid = LE_FALSE;
static int aveCounter = 0;
static uint32_t prevDrawCountAve[AVE_FPS_COUNT] = {0};
static uint32_t prevDrawCount;
static uint32_t prevVsyncCount;

static SYS_TIME_HANDLE fpsUpdateTimer;

uint32_t imgSize;
uint32_t imgType;
uint32_t imgIndex;

static char charBuff[16] = {0};

static leDynamicString fpsBtnText;
static leDynamicString refreshRateText;

static leDynamicString imgSizeText;
static leTableString imageTypeStr;

typedef enum
{
    IMG_40x40,
    IMG_100x100,
    IMG_200x200,
#ifdef ENABLE_FULL_SCREEN_IMAGE_TEST            
    IMG_480x270,
#endif            
    IMG_MAX_SIZE,
} IMAGE_SIZE_T;

typedef enum
{
    //IMG_PNG_8888,
    //IMG_JPG_24,
    IMG_RAW_565,
    IMG_RAW_RLE_565,
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)            
    IMG_RAW_BLIT,
#endif            
    IMG_MAX_TYPE,
} IMAGE_TYPE_T;

typedef struct
{
    leImage * imgAsst[MAX_NUM_IMAGES];
} IMAGE_LIST_T;

char * imageSizeNames[IMG_MAX_SIZE] = 
{
    "40x40",
    "100x100",
    "200x200",
#ifdef ENABLE_FULL_SCREEN_IMAGE_TEST    
    "480x270",    
#endif    
};

unsigned int imageTypeNames[IMG_MAX_TYPE] = 
{
    stringID_Raw565,
    stringID_RawRLE565,
};

/*IMAGE_LIST_T imagesPNG[] =
{
    [IMG_40x40] = {
        {&PNG_GFX_mchp_40x40,
        &PNG_GFX_mplab_40x40},
    },
#ifdef PNG_100x100_NOT_SUPPORTED
    [IMG_100x100] = {
        {NULL,
        NULL},
    },    
#else
    [IMG_100x100] = {
        {&PNG_GFX_mchp_100x100,
        &PNG_GFX_mplab_100x100},
    },
#endif    
    [IMG_200x200] = {
        {NULL,
        NULL},
    },
 #ifdef ENABLE_FULL_SCREEN_IMAGE_TEST
    [IMG_480x270] = {
        {NULL,
        NULL},
    },
 #endif
};*/

/*IMAGE_LIST_T imagesJPG[] =
{
    [IMG_40x40] = {
        {&JPG_GFX_mchp_40x40,
        &JPG_GFX_mplab_40x40},
    },
    [IMG_100x100] = {
        {&JPG_GFX_mchp_100x100,
        &JPG_GFX_mplab_100x100},
    },
    [IMG_200x200] = {
        {&JPG_GFX_mchp_200x200,
        &JPG_GFX_mplab_200x200},
    },
 #ifdef ENABLE_FULL_SCREEN_IMAGE_TEST
    [IMG_480x270] = {
        {&JPG_GFX_mchp_480x270,
        &JPG_GFX_mplab_480x270},
    },
 #endif
};*/

IMAGE_LIST_T imagesRAW[] =
{
    { /* IMG_40x40 */
        {
            &RAW_GFX_mchp_40x40,
            &RAW_GFX_mplab_40x40
        },
    },
    { /* IMG_100x100 */
        {
            &RAW_GFX_mchp_100x100,
            &RAW_GFX_mplab_100x100
        },
    },
    { /* IMG_200x200 */
        {
            &RAW_GFX_mchp_200x200,
            &RAW_GFX_mplab_200x200
        },
    },
#ifdef ENABLE_FULL_SCREEN_IMAGE_TEST    
    { /* IMG_480x270 */
        {
            &RAW_GFX_mchp_480x270,
            &RAW_GFX_mplab_480x270
        },
    },
#endif
};

IMAGE_LIST_T imagesRAWRLE[] =
{
    { /* IMG_40x40 */
        {
            &RAWRLE_GFX_mchp_40x40,
            &RAWRLE_GFX_mplab_40x40
        },
    },
    { /* IMG_100x100 */
        {
            &RAWRLE_GFX_mchp_100x100,
            &RAWRLE_GFX_mplab_100x100
        },
    },
    { /* IMG_200x200 */
        {
            &RAWRLE_GFX_mchp_200x200,
            &RAWRLE_GFX_mplab_200x200
        },
    },
#ifdef ENABLE_FULL_SCREEN_IMAGE_TEST    
    { /* IMG_480x270 */
        {
            &RAWRLE_GFX_mchp_480x270,
            &RAWRLE_GFX_mplab_480x270
        },
    },
#endif    
};

#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)
IMAGE_LIST_T imagesRAWBLIT[] =
{
    [IMG_40x40] = {
        {&BLIT_GFX_mchp_40x40,
        &BLIT_GFX_mplab_40x40},
    },
    [IMG_100x100] = {
        {&BLIT_GFX_mchp_100x100,
        &BLIT_GFX_mplab_100x100},
    },
    [IMG_200x200] = {
        {&BLIT_GFX_mchp_200x200,
        &BLIT_GFX_mplab_200x200},
    },
#ifdef ENABLE_FULL_SCREEN_IMAGE_TEST    
    [IMG_480x270] = {
        {&BLIT_GFX_mchp_480x270,
        &BLIT_GFX_mplab_480x270},
    },
#endif    
};
#endif

static enum
{
    SCREEN_DO_NOTHING = 0,
    SCREEN_IMAGE_SIZE_UP,
    SCREEN_IMAGE_SIZE_DOWN,
    SCREEN_IMAGE_MODE_NEXT,
    SCREEN_IMAGE_MODE_PREV,
    SCREEN_NEXT,
    SCREEN_WAIT_FOR_NEXT,
    SCREEN_MOVE_TO_NEXT,
    SCREEN_DONE
} screenState;

static void resetFPS(void)
{
    aveFPSValid = LE_FALSE;
    aveCounter = 0;
    
    sprintf(charBuff, "---");
    
    fpsBtnText.fn->setFromCStr(&fpsBtnText, charBuff);
    Screen3_ImageUpdateValue->fn->setString(Screen3_ImageUpdateValue, (leString*)&fpsBtnText);
    
    prevDrawCount = 0;
    prevVsyncCount = 0;
}

static void fpsUpdateTimer_Callback()
{

    unsigned int rate;
    unsigned int i;
    
    if(Screen3_ImageUpdateValue == NULL)
        return;
    
    //Update the 10-pt rolling average
    prevDrawCountAve[aveCounter] = (leGetRenderState()->drawCount - prevDrawCount);
    
    //If not pressed, show current FPS
    if(Screen3_ImageUpdateValue->fn->getPressed(Screen3_ImageUpdateValue) == LE_FALSE)
    {
            //Update FPS
        rate = (leGetRenderState()->drawCount - prevDrawCount)/
               (FPS_UPDATE_TIMER_PERIOD_MS/1000);

        sprintf(charBuff, "%u curr", rate);
    }
    //If pressed, show average FPS
    else
    {
        for (i = 0, rate = 0; i < AVE_FPS_COUNT; i++)
        {
            rate += prevDrawCountAve[i];
        }

        if (aveFPSValid)
        {
            sprintf(charBuff, "%u avg", 
                   (rate / ((AVE_FPS_COUNT)*(FPS_UPDATE_TIMER_PERIOD_MS / 1000))));
        }
        else
        {
            sprintf(charBuff, "---");
        }
    }
    
    if (aveCounter < (AVE_FPS_COUNT - 1))
    {
        aveCounter++;
    }
    else
    {
        aveCounter = 0;
        aveFPSValid = LE_TRUE;
    }
    
    fpsBtnText.fn->setFromCStr(&fpsBtnText, charBuff);
    Screen3_ImageUpdateValue->fn->setString(Screen3_ImageUpdateValue, (leString*)&fpsBtnText);
    

    //Update Refresh Rate
    uint32_t vsyncCount = leGetRenderState()->dispDriver->getVSYNCCount();
    rate =  (vsyncCount - prevVsyncCount) / (FPS_UPDATE_TIMER_PERIOD_MS/1000);

    //If vsyncCount does not increase, assume fixed refresh rate using vsyncCount
    //value
    if (rate == 0)
        rate = vsyncCount;

    sprintf(charBuff, "%u", rate);
    
    refreshRateText.fn->setFromCStr(&refreshRateText, charBuff);
    Screen3_ImageRefreshValue->fn->setString(Screen3_ImageRefreshValue,
                                     (leString*)&refreshRateText);
    
    
    prevDrawCount = leGetRenderState()->drawCount;
    prevVsyncCount = vsyncCount;
    
//    DecrementCount(Counter1LabelWidget);
}

static void increaseImageSize()
{
    if(imgSize < IMG_MAX_SIZE - 1)
    {
        imgSize += 1;
    }
    else
    {
        return;
    }
                    
    // Special handling, PNG sizes are limited to 100x100 due 
    // to memory limitations
    /*if ((imgType == IMG_PNG_8888) && 
        (imgSize > IMG_100x100))
    {
        imgSize = IMG_100x100;
    }*/

    //Update image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    Screen3_ImageSizeValue->fn->setString(Screen3_ImageSizeValue, (leString*)&imgSizeText);

    resetFPS();
}

static void decreaseImageSize()
{
    if(imgSize > 0)
    {
        imgSize -= 1;
    }
    else
    {
        return;
    }
    
    //Update image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    Screen3_ImageSizeValue->fn->setString(Screen3_ImageSizeValue, (leString*)&imgSizeText);

    resetFPS();
}

static void nextImageType()
{
    if(imgType < IMG_MAX_TYPE - 1)
    {
        imgType += 1;
    }
    else
    {
        return;
    }
    
    //Update image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    Screen3_ImageTypeValue->fn->setString(Screen3_ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();
}

static void prevImageType()
{
    if(imgType > 0)
    {
        imgType -= 1;
    }
    else
    {
        return;
    }
                    
    //Update image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    Screen3_ImageTypeValue->fn->setString(Screen3_ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();
}

static void nextImage()
{
    if(imgIndex < MAX_NUM_IMAGES - 1)
    {
        imgIndex += 1;
    }
    else
    {
        imgIndex = 0;
    }
    
//    if (imgType == IMG_PNG_8888)
//    {
//        if (imagesPNG[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget, 
//                                   imagesPNG[imgSize].imgAsst[imgIndex]);
//        }
//        else
//        {
//            
//        }
//    }
//    else if (imgType == IMG_JPG_24)
//    {
//        if (imagesJPG[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget, 
//                                   imagesJPG[imgSize].imgAsst[imgIndex]);
//        }
//    }
    if (imgType == IMG_RAW_565)
    {
        if (imagesRAW[imgSize].imgAsst[imgIndex] != NULL)
        {
            Screen3_ImageRenderArea->fn->setImage(Screen3_ImageRenderArea, 
                                          imagesRAW[imgSize].imgAsst[imgIndex]);
        }
    }
    else if (imgType == IMG_RAW_RLE_565)
    {
        if (imagesRAWRLE[imgSize].imgAsst[imgIndex] != NULL)
        {
            Screen3_ImageRenderArea->fn->setImage(Screen3_ImageRenderArea, 
                                          imagesRAWRLE[imgSize].imgAsst[imgIndex]);
        }
    }
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)      
//    else if (imgType == IMG_RAW_BLIT)
//    {
//        if (imagesRAWBLIT[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget, 
//                                   imagesRAWBLIT[imgSize].imgAsst[imgIndex]);
//        }
//    }
#endif    
}

void Screen3_OnShow()
{
    leFont* font = NULL;
    
    font = leStringTable_GetStringFont(&stringTable, stringID_NumsLittle, 0);
    
    leDynamicString_Constructor(&fpsBtnText);
    fpsBtnText.fn->setFont(&fpsBtnText, font);
    
    leDynamicString_Constructor(&refreshRateText);
    refreshRateText.fn->setFont(&refreshRateText, font);
    
    font = leStringTable_GetStringFont(leGetState()->stringTable, stringID_NumsTiny, 0);
    
    leDynamicString_Constructor(&imgSizeText);
    imgSizeText.fn->setFont(&imgSizeText, font);
    
    leTableString_Constructor(&imageTypeStr, stringID_Raw565);

    imgSize = IMG_40x40;
    imgType = IMG_RAW_565;
    imgIndex = 0;
    
    // initialize image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    Screen3_ImageSizeValue->fn->setString(Screen3_ImageSizeValue, (leString*)&imgSizeText);

    // initialize image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    Screen3_ImageTypeValue->fn->setString(Screen3_ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();
                    
    memset(prevDrawCountAve, 0, sizeof(prevDrawCountAve));
                            
    fpsUpdateTimer = SYS_TIME_CallbackRegisterMS(fpsUpdateTimer_Callback, 
                                                 1,
                                                 FPS_UPDATE_TIMER_PERIOD_MS,
                                                 SYS_TIME_PERIODIC);
    
    screenState = SCREEN_DO_NOTHING;
}

void Screen3_OnHide()
{
    SYS_TIME_TimerDestroy(fpsUpdateTimer);
    
    fpsBtnText.fn->destructor(&fpsBtnText);
    refreshRateText.fn->destructor(&refreshRateText);
    imgSizeText.fn->destructor(&imgSizeText);
    imageTypeStr.fn->destructor(&imageTypeStr);
}

void Screen3_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_DO_NOTHING:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                nextImage();
            }
            
            break;
        }
        case SCREEN_IMAGE_SIZE_UP:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                increaseImageSize();

                screenState = SCREEN_DO_NOTHING;
            }

            break;
        }
        case SCREEN_IMAGE_SIZE_DOWN:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {            
                decreaseImageSize();

                screenState = SCREEN_DO_NOTHING;
            }

            break;                    
        }
        case SCREEN_IMAGE_MODE_NEXT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                nextImageType();

                screenState = SCREEN_DO_NOTHING;
            }

            break;
        }
        case SCREEN_IMAGE_MODE_PREV:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {            
                prevImageType();

                screenState = SCREEN_DO_NOTHING;
            }

            break;                    
        }
        case SCREEN_NEXT:
        {
            screenState = SCREEN_WAIT_FOR_NEXT;

            SYS_TIME_TimerStop(fpsUpdateTimer);

            aveFPSValid = LE_FALSE;

            break;                    
        }
        case SCREEN_WAIT_FOR_NEXT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                screenState = SCREEN_MOVE_TO_NEXT;
            }

            break;
        }
        case SCREEN_MOVE_TO_NEXT:
        {
            legato_showScreen(screenID_Screen1);

            screenState = SCREEN_DONE;

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }

    
}

// event handlers
void event_Screen3_ImageSizeDownButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_SIZE_DOWN;
    }
}

void event_Screen3_ImageSizeUpButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_SIZE_UP;
    }
}

void event_Screen3_ImageTypePrevButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_MODE_PREV;
    }
}

void event_Screen3_ImageTypeNextButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_MODE_NEXT;
    }
}

void event_Screen3_ImageNextButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_NEXT;
    }
}

/*******************************************************************************
 End of File
 */
