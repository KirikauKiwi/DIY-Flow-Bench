/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "DIY-Flow-Bench_menu.h"

// Global variable declarations

LiquidCrystal lcd(2, 1, 0, 4, 5, 6, 7, ioFrom8574(0x20));
LiquidCrystalRenderer renderer(lcd, LCD_WIDTH, LCD_HEIGHT);

// Global Menu Item declarations

const PROGMEM AnyMenuInfo minfoSettingsCalFlow = { "Cal Flow", 16, 55, 0, setCalibrationOffset };
ActionMenuItem menuSettingsCalFlow(&minfoSettingsCalFlow, NULL);
const PROGMEM AnyMenuInfo minfoSettingsCalRefPress = { "Cal Ref Press", 15, 51, 0, setRefPressCalibrationValue };
ActionMenuItem menuSettingsCalRefPress(&minfoSettingsCalRefPress, &menuSettingsCalFlow);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsLeakTestChkRtCall, textItemRenderFn, "Leak Test Chk", 48, LeakTestCheck)
TextMenuItem menuSettingsLeakTestChk(fnSettingsLeakTestChkRtCall, 14, 3, &menuSettingsCalRefPress);
const PROGMEM AnyMenuInfo minfoSettingsLeakTestCal = { "Leak Test Cal", 8, 17, 0, setLeakCalibrationValue };
ActionMenuItem menuSettingsLeakTestCal(&minfoSettingsLeakTestCal, &menuSettingsLeakTestChk);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsBldRtCall, textItemRenderFn, "Bld", 30, NULL)
TextMenuItem menuSettingsBld(fnSettingsBldRtCall, 11, 9, &menuSettingsLeakTestCal);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsVerRtCall, textItemRenderFn, "Ver", 20, NULL)
TextMenuItem menuSettingsVer(fnSettingsVerRtCall, 10, 12, &menuSettingsBld);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", 10, NULL)
const PROGMEM SubMenuInfo minfoSettings = { "Settings", 5, 10, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(fnSettingsRtCall, &menuSettingsVer);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, NULL);
const PROGMEM AnalogMenuInfo minfoAFlow = { "AFlow", 13, 40, 255, NO_CALLBACK, 0, 1, "cfm" };
AnalogMenuItem menuAFlow(&minfoAFlow, 0, &menuSettings);
const PROGMEM AnalogMenuInfo minfoARef = { "ARef", 12, 38, 28, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuARef(&minfoARef, 0, &menuAFlow);
const PROGMEM AnalogMenuInfo minfoPitot = { "Pitot", 4, 8, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuPitot(&minfoPitot, 0, &menuARef);
const PROGMEM AnalogMenuInfo minfoTemp = { "Temp", 3, 6, 255, NO_CALLBACK, 0, 1, "DegC" };
AnalogMenuItem menuTemp(&minfoTemp, 0, &menuPitot);
const PROGMEM AnalogMenuInfo minfoPRef = { "PRef", 2, 4, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuPRef(&minfoPRef, 0, &menuTemp);
const PROGMEM AnalogMenuInfo minfoFlow = { "Flow", 1, 2, 255, NO_CALLBACK, 0, 1, "cfm" };
AnalogMenuItem menuFlow(&minfoFlow, 0, &menuPRef);
const PROGMEM ConnectorLocalInfo applicationInfo = { "DIY Flow Bench", "0fc9ae97-7781-4600-a281-4a3425ce8371" };

// Set up code

void setupMenu() {
    Wire.begin();
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    lcd.configureBacklightPin(3);
    lcd.backlight();
    switches.initialise(ioUsingArduino(), true);
    menuMgr.initForEncoder(&renderer, &menuFlow, ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_OK);

    // Read only and local only function calls
    menuFlow.setReadOnly(true);
    menuPRef.setReadOnly(true);
    menuTemp.setReadOnly(true);
    menuAFlow.setReadOnly(true);
    menuSettingsCalFlow.setReadOnly(true);
    menuSettingsBld.setReadOnly(true);
    menuSettingsLeakTestCal.setReadOnly(true);
    menuSettingsVer.setReadOnly(true);
    menuPitot.setReadOnly(true);
    menuSettingsLeakTestChk.setReadOnly(true);
    menuSettingsCalRefPress.setReadOnly(true);
}

