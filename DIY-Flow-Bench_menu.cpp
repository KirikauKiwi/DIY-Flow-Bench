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

const PROGMEM AnyMenuInfo minfoSettingsMidFLowCal = { "Mid FLow Cal", 16, 51, 0, setMidFlowCalibrationValue };
ActionMenuItem menuSettingsMidFLowCal(&minfoSettingsMidFLowCal, NULL);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsLeakTestCheckRtCall, textItemRenderFn, "Leak Test Check", 48, NULL)
TextMenuItem menuSettingsLeakTestCheck(fnSettingsLeakTestCheckRtCall, 14, 3, &menuSettingsMidFLowCal);
const PROGMEM AnyMenuInfo minfoSettingsLeakTestCal = { "Leak Test Cal", 8, 17, 0, setLeakCalibrationValue };
ActionMenuItem menuSettingsLeakTestCal(&minfoSettingsLeakTestCal, &menuSettingsLeakTestCheck);
const PROGMEM AnyMenuInfo minfoSettingsRefPressCal = { "Ref Press Cal", 15, 51, 0, setRefPressCalibrationValue };
ActionMenuItem menuSettingsRefPressCal(&minfoSettingsRefPressCal, &menuSettingsLeakTestCal);
const PROGMEM AnyMenuInfo minfoSettingsHighFlowCal = { "High Flow Cal", 7, 14, 0, setHighFlowCalibrationValue };
ActionMenuItem menuSettingsHighFlowCal(&minfoSettingsHighFlowCal, &menuSettingsRefPressCal);
const PROGMEM AnyMenuInfo minfoSettingsLowFlowCal = { "Low Flow Cal", 6, 12, 0, setLowFlowCalibrationValue };
ActionMenuItem menuSettingsLowFlowCal(&minfoSettingsLowFlowCal, &menuSettingsHighFlowCal);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsBuildNumberRtCall, textItemRenderFn, "Build Number", 30, NULL)
TextMenuItem menuSettingsBuildNumber(fnSettingsBuildNumberRtCall, 11, 8, &menuSettingsLowFlowCal);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsCodeVersionRtCall, textItemRenderFn, "Code Version", 20, NULL)
TextMenuItem menuSettingsCodeVersion(fnSettingsCodeVersionRtCall, 10, 10, &menuSettingsBuildNumber);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", 10, NULL)
const PROGMEM SubMenuInfo minfoSettings = { "Settings", 5, 10, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(fnSettingsRtCall, &menuSettingsCodeVersion);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, NULL);
const PROGMEM AnalogMenuInfo minfoAdjustedFlow = { "Adjusted Flow", 13, 40, 255, NO_CALLBACK, 0, 1, "cfm" };
AnalogMenuItem menuAdjustedFlow(&minfoAdjustedFlow, 0, &menuSettings);
const PROGMEM AnalogMenuInfo minfoDesiredRef = { "Desired Ref", 12, 38, 28, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuDesiredRef(&minfoDesiredRef, 0, &menuAdjustedFlow);
const PROGMEM AnalogMenuInfo minfoPitot = { "Pitot", 4, 8, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuPitot(&minfoPitot, 0, &menuDesiredRef);
const PROGMEM AnalogMenuInfo minfoTemperature = { "Temperature", 3, 6, 255, NO_CALLBACK, 0, 1, "DegC" };
AnalogMenuItem menuTemperature(&minfoTemperature, 0, &menuPitot);
const PROGMEM AnalogMenuInfo minfoRefPressure = { "Ref Pressure", 2, 4, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuRefPressure(&minfoRefPressure, 0, &menuTemperature);
const PROGMEM AnalogMenuInfo minfoFlowRate = { "Flow Rate", 1, 2, 255, NO_CALLBACK, 0, 1, "cfm" };
AnalogMenuItem menuFlowRate(&minfoFlowRate, 0, &menuRefPressure);
const PROGMEM ConnectorLocalInfo applicationInfo = { "DIY Flow Bench", "0fc9ae97-7781-4600-a281-4a3425ce8371" };

// Set up code

void setupMenu() {
    Wire.begin();
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    lcd.configureBacklightPin(3);
    lcd.backlight();
    switches.initialise(ioUsingArduino(), true);
    menuMgr.initForEncoder(&renderer, &menuFlowRate, ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_OK);

    // Read only and local only function calls
    menuFlowRate.setReadOnly(true);
    menuRefPressure.setReadOnly(true);
    menuSettingsLeakTestCheck.setReadOnly(true);
    menuTemperature.setReadOnly(true);
    menuAdjustedFlow.setReadOnly(true);
    menuSettingsMidFLowCal.setReadOnly(true);
    menuSettingsCodeVersion.setReadOnly(true);
    menuSettingsRefPressCal.setReadOnly(true);
    menuSettingsLeakTestCal.setReadOnly(true);
    menuSettingsLowFlowCal.setReadOnly(true);
    menuPitot.setReadOnly(true);
    menuSettingsHighFlowCal.setReadOnly(true);
    menuSettingsBuildNumber.setReadOnly(true);
}

