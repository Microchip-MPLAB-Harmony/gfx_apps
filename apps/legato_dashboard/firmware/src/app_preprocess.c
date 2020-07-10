/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "app.h"
#include "definitions.h"
#include <sys/kmem.h>

#define MAX_PREPROCESS_ASSETS 500
#define PRE_PROCESS_START_ADDRESS 0xA88CA000

void APP_AddImgAssetForPP(leImage * img)
{
    static uint32_t targetAddress = PRE_PROCESS_START_ADDRESS;
    
    leImage temp;
    leRect rect;
    leImage_Create(&temp,
                   img->buffer.size.width, 
                   img->buffer.size.height,
                   LE_COLOR_MODE_RGBA_8888,
                   (void *) targetAddress,
                   LE_STREAM_LOCATION_ID_INTERNAL);
    rect.x = 0;
    rect.y = 0;
    rect.height = img->buffer.size.height;
    rect.width = img->buffer.size.width;
    
    leImage_Render(img, &rect, 0, 0, LE_TRUE, LE_FALSE, &temp);
    memcpy(img, &temp, sizeof(leImage));
    
    targetAddress += temp.header.size;
}

void APP_PreprocessSplashImages(void)
{
    APP_AddImgAssetForPP(&MHGC_200x200_white);
    APP_AddImgAssetForPP(&mchpLogo_light);
}

void APP_PreprocessNeedleImages(void)
{
    //Priority Assets
    APP_AddImgAssetForPP(&n_02_84_240);
    APP_AddImgAssetForPP(&n_04_85_242);
    APP_AddImgAssetForPP(&n_06_84_244);
    APP_AddImgAssetForPP(&n_08_88_246);
    APP_AddImgAssetForPP(&n_10_89_248);
    APP_AddImgAssetForPP(&n_12_91_250);
    APP_AddImgAssetForPP(&n_14_90_251);
    APP_AddImgAssetForPP(&n_16_92_254);
    APP_AddImgAssetForPP(&n_18_93_256);
    APP_AddImgAssetForPP(&n_20_95_258);
    APP_AddImgAssetForPP(&n_22_98_259);
    APP_AddImgAssetForPP(&n_24_99_262);
    APP_AddImgAssetForPP(&n_26_97_255);
    APP_AddImgAssetForPP(&n_28_104_257);
    APP_AddImgAssetForPP(&n_30_106_259);
    APP_AddImgAssetForPP(&n_32_108_261);
    APP_AddImgAssetForPP(&n_34_110_264);
    APP_AddImgAssetForPP(&n_36_111_273);
    APP_AddImgAssetForPP(&n_38_117_275);
    APP_AddImgAssetForPP(&n_40_120_277);
    APP_AddImgAssetForPP(&n_42_121_280);
    APP_AddImgAssetForPP(&n_44_125_280);
    APP_AddImgAssetForPP(&n_46_127_280);
    APP_AddImgAssetForPP(&n_48_129_282);
    APP_AddImgAssetForPP(&n_50_136_285);
    APP_AddImgAssetForPP(&n_52_140_285);
    APP_AddImgAssetForPP(&n_54_140_286);
    APP_AddImgAssetForPP(&n_56_147_287);
    APP_AddImgAssetForPP(&n_58_150_289);
    APP_AddImgAssetForPP(&n_60_151_289);
    APP_AddImgAssetForPP(&n_62_159_292);
    APP_AddImgAssetForPP(&n_64_163_293);
    APP_AddImgAssetForPP(&n_66_167_294);
    APP_AddImgAssetForPP(&n_68_16_295);
    APP_AddImgAssetForPP(&n_70_175_295);
    APP_AddImgAssetForPP(&n_72_180_296);
    APP_AddImgAssetForPP(&n_74_184_296);
    APP_AddImgAssetForPP(&n_76_188_297);
    APP_AddImgAssetForPP(&n_78_193_297);
    APP_AddImgAssetForPP(&n_80_197_299);
    APP_AddImgAssetForPP(&n_82_200_300);
    APP_AddImgAssetForPP(&n_84_206_301);
    APP_AddImgAssetForPP(&n_86_211_301);
    APP_AddImgAssetForPP(&n_88_214_302);
    APP_AddImgAssetForPP(&n_90_217_301);
    APP_AddImgAssetForPP(&n000_88_238);
    APP_AddImgAssetForPP(&n002_88_233);
    APP_AddImgAssetForPP(&n004_89_228);
    APP_AddImgAssetForPP(&n006_88_223);
    APP_AddImgAssetForPP(&n008_89_219);
    APP_AddImgAssetForPP(&n010_89_214);
    APP_AddImgAssetForPP(&n012_90_210);
    APP_AddImgAssetForPP(&n014_91_209);
    APP_AddImgAssetForPP(&n016_89_205);
    APP_AddImgAssetForPP(&n018_91_200);
    APP_AddImgAssetForPP(&n020_92_196);
    APP_AddImgAssetForPP(&n022_94_191);
    APP_AddImgAssetForPP(&n024_96_187);
    APP_AddImgAssetForPP(&n026_97_183);
    APP_AddImgAssetForPP(&n028_100_177);
    APP_AddImgAssetForPP(&n030_102_173);
    APP_AddImgAssetForPP(&n032_104_170);
    APP_AddImgAssetForPP(&n034_107_167);
    APP_AddImgAssetForPP(&n036_110_163);
    APP_AddImgAssetForPP(&n038_112_159);
    APP_AddImgAssetForPP(&n040_115_155);
    APP_AddImgAssetForPP(&n042_118_152);
    APP_AddImgAssetForPP(&n044_121_149);
    APP_AddImgAssetForPP(&n046_125_145);
    APP_AddImgAssetForPP(&n048_128_142);
    APP_AddImgAssetForPP(&n050_132_139);
    APP_AddImgAssetForPP(&n052_135_136);
    APP_AddImgAssetForPP(&n054_138_154);
    APP_AddImgAssetForPP(&n056_142_131);
    APP_AddImgAssetForPP(&n058_146_128);
    APP_AddImgAssetForPP(&n060_149_126);
    APP_AddImgAssetForPP(&n062_153_123);
    APP_AddImgAssetForPP(&n064_157_121);
    APP_AddImgAssetForPP(&n066_161_118);
    APP_AddImgAssetForPP(&n068_165_116);
    APP_AddImgAssetForPP(&n070_170_115);
    APP_AddImgAssetForPP(&n072_174_113);
    APP_AddImgAssetForPP(&n074_177_110);
    APP_AddImgAssetForPP(&n076_182_110);
    APP_AddImgAssetForPP(&n078_187_109);
    APP_AddImgAssetForPP(&n080_191_108);
    APP_AddImgAssetForPP(&n082_196_107);
    APP_AddImgAssetForPP(&n084_200_106);
    APP_AddImgAssetForPP(&n086_205_106);
    APP_AddImgAssetForPP(&n088_207_105);
    APP_AddImgAssetForPP(&n090_210_106);
    APP_AddImgAssetForPP(&n000_627_238);
    APP_AddImgAssetForPP(&n002_626_235);
    APP_AddImgAssetForPP(&n004_626_232);
    APP_AddImgAssetForPP(&n006_626_227);
    APP_AddImgAssetForPP(&n008_625_223);
    APP_AddImgAssetForPP(&n010_624_218);
    APP_AddImgAssetForPP(&n012_624_213);
    APP_AddImgAssetForPP(&n014_623_209);
    APP_AddImgAssetForPP(&n016_625_205);
    APP_AddImgAssetForPP(&n018_625_200);
    APP_AddImgAssetForPP(&n020_624_196);
    APP_AddImgAssetForPP(&n022_623_191);
    APP_AddImgAssetForPP(&n024_622_186);
    APP_AddImgAssetForPP(&n026_621_183);
    APP_AddImgAssetForPP(&n028_620_177);
    APP_AddImgAssetForPP(&n030_618_174);
    APP_AddImgAssetForPP(&n032_617_170);
    APP_AddImgAssetForPP(&n034_616_166);
    APP_AddImgAssetForPP(&n036_615_163);
    APP_AddImgAssetForPP(&n038_613_159);
    APP_AddImgAssetForPP(&n040_612_155);
    APP_AddImgAssetForPP(&n042_610_152);
    APP_AddImgAssetForPP(&n044_608_149);
    APP_AddImgAssetForPP(&n046_607_145);
    APP_AddImgAssetForPP(&n048_605_142);
    APP_AddImgAssetForPP(&n050_603_139);
    APP_AddImgAssetForPP(&n052_602_136);
    APP_AddImgAssetForPP(&n054_601_134);
    APP_AddImgAssetForPP(&n056_599_131);
    APP_AddImgAssetForPP(&n058_597_128);
    APP_AddImgAssetForPP(&n060_596_125);
    APP_AddImgAssetForPP(&n062_594_123);
    APP_AddImgAssetForPP(&n064_592_121);
    APP_AddImgAssetForPP(&n066_590_118);
    APP_AddImgAssetForPP(&n068_588_116);
    APP_AddImgAssetForPP(&n070_586_115);
    APP_AddImgAssetForPP(&n072_584_113);
    APP_AddImgAssetForPP(&n074_583_111);
    APP_AddImgAssetForPP(&n076_581_110);
    APP_AddImgAssetForPP(&n078_577_109);
    APP_AddImgAssetForPP(&n080_576_108);
    APP_AddImgAssetForPP(&n082_576_107);
    APP_AddImgAssetForPP(&n084_571_106);
    APP_AddImgAssetForPP(&n086_570_106);
    APP_AddImgAssetForPP(&n088_569_105);
    APP_AddImgAssetForPP(&n090_567_105);
    APP_AddImgAssetForPP(&n270_559_301);
    APP_AddImgAssetForPP(&n272_562_302);
    APP_AddImgAssetForPP(&n274_564_301);
    APP_AddImgAssetForPP(&n276_566_301);
    APP_AddImgAssetForPP(&n278_569_300);
    APP_AddImgAssetForPP(&n280_570_299);
    APP_AddImgAssetForPP(&n282_572_298);
    APP_AddImgAssetForPP(&n284_574_297);
    APP_AddImgAssetForPP(&n286_576_297);
    APP_AddImgAssetForPP(&n288_578_296);
    APP_AddImgAssetForPP(&n290_580_295);
    APP_AddImgAssetForPP(&n292_582_295);
    APP_AddImgAssetForPP(&n294_583_294);
    APP_AddImgAssetForPP(&n296_585_293);
    APP_AddImgAssetForPP(&n298_587_292);
    APP_AddImgAssetForPP(&n300_587_290);
    APP_AddImgAssetForPP(&n302_591_290);
    APP_AddImgAssetForPP(&n304_592_288);
    APP_AddImgAssetForPP(&n306_595_287);
    APP_AddImgAssetForPP(&n308_597_285);
    APP_AddImgAssetForPP(&n310_599_285);
    APP_AddImgAssetForPP(&n312_597_282);
    APP_AddImgAssetForPP(&n314_602_282);
    APP_AddImgAssetForPP(&n316_604_280);
    APP_AddImgAssetForPP(&n318_606_280);
    APP_AddImgAssetForPP(&n320_607_277);
    APP_AddImgAssetForPP(&n322_608_275);
    APP_AddImgAssetForPP(&n324_611_274);
    APP_AddImgAssetForPP(&n326_613_271);
    APP_AddImgAssetForPP(&n328_611_271);
    APP_AddImgAssetForPP(&n330_613_269);
    APP_AddImgAssetForPP(&n332_615_266);
    APP_AddImgAssetForPP(&n334_620_264);
    APP_AddImgAssetForPP(&n336_617_262);
    APP_AddImgAssetForPP(&n338_618_259);
    APP_AddImgAssetForPP(&n340_621_259);
    APP_AddImgAssetForPP(&n342_622_256);
    APP_AddImgAssetForPP(&n344_623_254);
    APP_AddImgAssetForPP(&n346_619_251);
    APP_AddImgAssetForPP(&n348_624_250);
    APP_AddImgAssetForPP(&n350_625_248);
    APP_AddImgAssetForPP(&n352_625_246);
    APP_AddImgAssetForPP(&n354_629_244);
    APP_AddImgAssetForPP(&n356_629_242);
    APP_AddImgAssetForPP(&n358_629_240);
}

/* *****************************************************************************
 End of File
 */
