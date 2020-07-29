#include "gfx/legato/generated/le_gen_assets.h"

uint16_t leGlobalPalette_data[256] =
{
    0x0000,0x8000,0x0400,0x8400,0x0010,0x8010,0x0410,0xBDF7,0x8410,0xF800,0x07E0,0xFFE0,0x001F,0xF81F,0x07FF,0xFFFF,
    0x0841,0x1082,0x18E3,0x2925,0x3186,0x39C7,0x4228,0x4A69,0x5ACB,0x630C,0x630C,0x630C,0x73AE,0x8410,0x8C51,0x94B2,
    0x9CF3,0xA554,0xB596,0xBDD7,0xC638,0xCE79,0xDEDB,0xE71C,0x0801,0x0061,0x2000,0x1062,0x0043,0x20A1,0x3000,0x3060,
    0x2101,0x20C4,0x4860,0x1964,0x2924,0x0008,0x48A2,0x4903,0x2986,0x000A,0x4183,0x6061,0x39A6,0x6944,0x7903,0x4208,
    0x7165,0x69C6,0x88C2,0x80A5,0x524A,0xA0C3,0x91C8,0x5ACB,0xA964,0xA1A8,0x9A28,0xB104,0x8AE9,0x6B2D,0x2B8E,0xB1C7,
    0x3B8E,0x636E,0xC1A4,0x0017,0xB249,0x1BD0,0xAA8A,0x9ACB,0x736D,0x43CF,0xC1C8,0x2BD0,0xD146,0xD1A5,0xB26A,0x0C11,
    0xC20A,0xD1A8,0xCA26,0x4C10,0xE081,0xD944,0xB2CB,0xD1E9,0x4431,0xE0E4,0x3432,0xAB2D,0x7BEF,0xE146,0x2452,0xD9A8,
    0x5451,0xC2AB,0x0C72,0xE1C5,0xF102,0xDA09,0x4472,0xF0E6,0x3492,0xDA6A,0x6C72,0xF144,0x7471,0xE968,0xF800,0xF1A5,
    0xABAF,0xF8C3,0xDAE9,0x5492,0xD2CC,0x0494,0xC32D,0x14B4,0x24D3,0xF962,0xF946,0xF209,0x3CD3,0xF9E7,0xC38E,0x64D3,
    0x34F4,0xE2AB,0xDB2B,0xF26A,0x6CD3,0x24F5,0x9492,0x001F,0xB410,0x5514,0xE2ED,0xC3F0,0xDB6E,0xFA8B,0x84F3,0xD3D0,
    0xF2EC,0x4556,0xEB4E,0x6D35,0xDBCD,0x3556,0x9513,0xE3AF,0x7D55,0xBCB2,0xD451,0x4597,0xFB6E,0xF3CD,0xE411,0x5D97,
    0x7D96,0x9576,0xAD55,0xF44D,0x07E0,0xCCF3,0xFC10,0xDCB3,0xEC91,0x6DF8,0xFC6F,0xC535,0x5619,0x841F,0xA5B6,0xB596,
    0xD535,0xECB3,0x8DF8,0xFC92,0xDD14,0x6E39,0x5E5A,0x765A,0xFCF3,0xF81F,0xBDF7,0xED53,0x8E5A,0xAE38,0xE576,0x6E9B,
    0x965A,0xD5D6,0xFD56,0xCE38,0x7EDB,0xFDB5,0x8EBB,0xBE79,0xFDB7,0xAEBB,0xE618,0x96FB,0xEE37,0xBEDA,0xB61F,0xDE79,
    0x7F3D,0xD6BA,0xFE37,0x973D,0xFFE0,0xBF1C,0xAF3C,0xC71B,0xFE5A,0xF717,0xDEFB,0x07FF,0xF6BB,0xCF5C,0xBF5D,0xA77E,
    0x9FBF,0xFEF9,0xB79E,0x87FF,0x97FF,0xEF3B,0xAFDF,0xDF7D,0xFF79,0xD79E,0xBFDF,0xFF3C,0xF79C,0xDFFF,0xEFDE,0xFFFB,
};

const lePalette leGlobalPalette =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)leGlobalPalette_data, // data variable pointer
        512, // data size
    },
    256,
    LE_COLOR_MODE_RGB_565
};
