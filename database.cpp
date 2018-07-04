#include "database.h"
#include <QDebug>

#include "global.h"

/*
MP AND M'S PORT ARE CONVERSE
*/
Database::Database()
{
     _LOG << "Database constructor";
    // riom mvb ports
    this->riomPorts << new struct port(0x110, uFCode4, uSinkPort, 64) << new struct port(0x111, uFCode4, uSinkPort, 64) << new struct port(0x112, uFCode4, uSinkPort, 64)
                    << new struct port(0x120, uFCode4, uSinkPort, 64) << new struct port(0x121, uFCode4, uSinkPort, 64)
                    << new struct port(0x130, uFCode4, uSinkPort, 64) << new struct port(0x131, uFCode4, uSinkPort, 64)
                    << new struct port(0x140, uFCode4, uSinkPort, 64) << new struct port(0x141, uFCode4, uSinkPort, 64)
                    << new struct port(0x150, uFCode4, uSinkPort, 64) << new struct port(0x151, uFCode4, uSinkPort, 64)
                    << new struct port(0x160, uFCode4, uSinkPort, 64) << new struct port(0x161, uFCode4, uSinkPort, 64) << new struct port(0x162, uFCode4, uSinkPort, 64);

    // hmi ports
    this->hmiA1Ports << new struct port(0x310, uFCode4, uSourcePort, 256) << new struct port(0x311, uFCode4, uSourcePort, 256)
                     << new struct port(0x312, uFCode4, uSourcePort, 256) << new struct port(0x313, uFCode4, uSourcePort, 256)
                     << new struct port(0x320, uFCode4, uSinkPort, 256) << new struct port(0x321, uFCode4, uSinkPort, 256)
                     << new struct port(0x322, uFCode4, uSinkPort, 256) << new struct port(0x323, uFCode4, uSinkPort, 256);

    this->hmiA2Ports << new struct port(0x310, uFCode4, uSinkPort, 256) << new struct port(0x311, uFCode4, uSinkPort, 256)
                     << new struct port(0x312, uFCode4, uSinkPort, 256) << new struct port(0x313, uFCode4, uSinkPort, 256)
                     << new struct port(0x320, uFCode4, uSourcePort, 256) << new struct port(0x321, uFCode4, uSourcePort, 256)
                     << new struct port(0x322, uFCode4, uSourcePort, 256) << new struct port(0x323, uFCode4, uSourcePort, 256);

    // ccu ports
    this->ccuPortsA << new struct port(0x00f, uFCode3, uSinkPort, 256)
                    << new struct port(0x118, uFCode4, uSinkPort, 64) << new struct port(0x128, uFCode4, uSinkPort, 64)
                    << new struct port(0x138, uFCode4, uSinkPort, 64) << new struct port(0x148, uFCode4, uSinkPort, 64)
                    << new struct port(0x158, uFCode4, uSinkPort, 64) << new struct port(0x168, uFCode4, uSinkPort, 64)
                    << new struct port(0x218, uFCode4, uSinkPort, 256) << new struct port(0x219, uFCode4, uSinkPort, 256)
                    << new struct port(0x228, uFCode4, uSinkPort, 256) << new struct port(0x229, uFCode4, uSinkPort, 256)
                    << new struct port(0x308, uFCode4, uSinkPort, 256) << new struct port(0x309, uFCode4, uSinkPort, 256)
                    << new struct port(0x30A, uFCode4, uSinkPort, 256)
                    << new struct port(0x318, uFCode3, uSinkPort, 256) << new struct port(0x328, uFCode3, uSinkPort, 256)
                    << new struct port(0x418, uFCode4, uSinkPort, 32)
                    << new struct port(0x528, uFCode4, uSinkPort, 32) << new struct port(0x538, uFCode4, uSinkPort, 32)
                    << new struct port(0x548, uFCode4, uSinkPort, 32) << new struct port(0x558, uFCode4, uSinkPort, 32)
                    << new struct port(0x618, uFCode3, uSinkPort, 64) << new struct port(0x628, uFCode3, uSinkPort, 64)
                    << new struct port(0x708, uFCode1, uSinkPort, 128) << new struct port(0x709, uFCode1, uSinkPort, 1024)
                    << new struct port(0x70A, uFCode1, uSinkPort, 1024) << new struct port(0x70B, uFCode1, uSinkPort, 1024)
                    << new struct port(0x70C, uFCode1, uSinkPort, 1024) << new struct port(0x70D, uFCode1, uSinkPort, 1024)
                    << new struct port(0x70E, uFCode1, uSinkPort, 1024) << new struct port(0x808, uFCode4, uSinkPort, 256);
    this->ccuPortsB << new struct port(0x918, uFCode2, uSinkPort, 512) << new struct port(0x928, uFCode2, uSinkPort, 512)
                    << new struct port(0x938, uFCode2, uSinkPort, 512) << new struct port(0x948, uFCode2, uSinkPort, 512)
                    << new struct port(0x958, uFCode2, uSinkPort, 512) << new struct port(0x968, uFCode2, uSinkPort, 512)
                    << new struct port(0xA08, uFCode2, uSinkPort, 64)  << new struct port(0xC08, uFCode4, uSinkPort, 256)
                    << new struct port(0xC09, uFCode4, uSinkPort, 256) << new struct port(0xD18, uFCode2, uSinkPort, 256)
                    << new struct port(0xD28, uFCode2, uSinkPort, 256) << new struct port(0xF08, uFCode2, uSinkPort, 256);

    this->ermPorts << new struct port(0x210, uFCode4, uSinkPort, 256) << new struct port(0x211, uFCode4, uSinkPort, 512)
                   << new struct port(0x212, uFCode4, uSinkPort, 512) << new struct port(0x213, uFCode4, uSinkPort, 512)
                   << new struct port(0x220, uFCode4, uSinkPort, 256) << new struct port(0x221, uFCode4, uSinkPort, 512)
                   << new struct port(0x222, uFCode4, uSinkPort, 512) << new struct port(0x223, uFCode4, uSinkPort, 512);

    this->bcu1Ports << new struct port(0x410, uFCode4, uSinkPort, 32) << new struct port(0x411, uFCode4, uSinkPort, 64)
                    << new struct port(0x412, uFCode4, uSinkPort, 64) << new struct port(0x413, uFCode3, uSinkPort, 512)
                    << new struct port(0x414, uFCode4, uSinkPort, 64) << new struct port(0x415, uFCode4, uSinkPort, 64);

    this->bcu3Ports << new struct port(0x430, uFCode4, uSinkPort, 32) << new struct port(0x431, uFCode4, uSinkPort, 64)
                    << new struct port(0x432, uFCode4, uSinkPort, 64) << new struct port(0x433, uFCode3, uSinkPort, 512)
                    << new struct port(0x434, uFCode4, uSinkPort, 64) << new struct port(0x435, uFCode4, uSinkPort, 64);

    this->bcu4Ports << new struct port(0x440, uFCode4, uSinkPort, 32) << new struct port(0x441, uFCode4, uSinkPort, 64)
                    << new struct port(0x442, uFCode4, uSinkPort, 64) << new struct port(0x443, uFCode3, uSinkPort, 512)
                    << new struct port(0x444, uFCode4, uSinkPort, 64) << new struct port(0x445, uFCode4, uSinkPort, 64);

    this->bcu6Ports << new struct port(0x460, uFCode4, uSinkPort, 32) << new struct port(0x461, uFCode4, uSinkPort, 64)
                    << new struct port(0x462, uFCode4, uSinkPort, 64) << new struct port(0x463, uFCode3, uSinkPort, 512)
                    << new struct port(0x464, uFCode4, uSinkPort, 64) << new struct port(0x465, uFCode4, uSinkPort, 64);

    this->dcuPorts  << new struct port(0x520, uFCode4, uSinkPort, 64) << new struct port(0x521, uFCode4, uSinkPort, 64)
                    << new struct port(0x522, uFCode4, uSinkPort, 64) << new struct port(0x523, uFCode4, uSinkPort, 64)
                    << new struct port(0x530, uFCode4, uSinkPort, 64) << new struct port(0x531, uFCode4, uSinkPort, 64)
                    << new struct port(0x532, uFCode4, uSinkPort, 64) << new struct port(0x533, uFCode4, uSinkPort, 64)
                    << new struct port(0x540, uFCode4, uSinkPort, 64) << new struct port(0x541, uFCode4, uSinkPort, 64)
                    << new struct port(0x542, uFCode4, uSinkPort, 64) << new struct port(0x543, uFCode4, uSinkPort, 64)
                    << new struct port(0x550, uFCode4, uSinkPort, 64) << new struct port(0x551, uFCode4, uSinkPort, 64)
                    << new struct port(0x552, uFCode4, uSinkPort, 64) << new struct port(0x553, uFCode4, uSinkPort, 64);

    this->sivPorts  << new struct port(0x610, uFCode3, uSinkPort, 64) << new struct port(0x611, uFCode4, uSinkPort, 256)
                    << new struct port(0x620, uFCode3, uSinkPort, 64) << new struct port(0x621, uFCode4, uSinkPort, 256);

    this->pisPorts  << new struct port(0x810, uFCode4, uSinkPort, 256) << new struct port(0x811, uFCode4, uSinkPort, 256)
                    << new struct port(0x820, uFCode4, uSinkPort, 256) << new struct port(0x821, uFCode4, uSinkPort, 256);

    this->hvacPorts << new struct port(0x910, uFCode4, uSinkPort, 256) << new struct port(0x920, uFCode4, uSinkPort, 256)
                    << new struct port(0x930, uFCode4, uSinkPort, 256) << new struct port(0x940, uFCode4, uSinkPort, 256)
                    << new struct port(0x950, uFCode4, uSinkPort, 256) << new struct port(0x960, uFCode4, uSinkPort, 256);

    this->atcPorts  << new struct port(0xA10, uFCode4, uSinkPort, 64) << new struct port(0xA11, uFCode4, uSinkPort, 64)
                    << new struct port(0xA20, uFCode4, uSinkPort, 64) << new struct port(0xA21, uFCode4, uSinkPort, 64);

    this->pdsPorts << new struct port(0xC10, uFCode4, uSinkPort, 256) << new struct port(0xC20, uFCode4, uSinkPort, 256)
                   << new struct port(0xC11, uFCode2, uSinkPort, 512) << new struct port(0xC21, uFCode2, uSinkPort, 512);
    this->bcgPorts << new struct port(0xD10, uFCode4, uSinkPort, 256) << new struct port(0xD20, uFCode4, uSinkPort, 256);
    this->fauPorts << new struct port(0xF10, uFCode4, uSinkPort, 256) << new struct port(0xF11, uFCode4, uSinkPort, 256)
                   << new struct port(0xF20, uFCode4, uSinkPort, 256) << new struct port(0xF21, uFCode4, uSinkPort, 256);

    this->bmsPorts << new struct port(0xE10, uFCode4, uSinkPort, 1024) << new struct port(0xE11, uFCode3, uSinkPort, 512)
                   << new struct port(0xE20, uFCode4, uSinkPort, 1024) << new struct port(0xE21, uFCode3, uSinkPort, 512);

    this->edcu1Ports << new struct port(0x710, uFCode4, uSinkPort, 1024) << new struct port(0x711, uFCode4, uSinkPort, 512) << new struct port(0x712, uFCode4, uSinkPort, 1024)
                     << new struct port(0x720, uFCode4, uSinkPort, 1024) << new struct port(0x721, uFCode4, uSinkPort, 512) << new struct port(0x722, uFCode4, uSinkPort, 1024)
                     << new struct port(0x730, uFCode4, uSinkPort, 1024) << new struct port(0x731, uFCode4, uSinkPort, 512) << new struct port(0x732, uFCode4, uSinkPort, 1024)
                     << new struct port(0x740, uFCode4, uSinkPort, 1024) << new struct port(0x741, uFCode4, uSinkPort, 512) << new struct port(0x742, uFCode4, uSinkPort, 1024)
                     << new struct port(0x750, uFCode4, uSinkPort, 1024) << new struct port(0x751, uFCode4, uSinkPort, 512) << new struct port(0x752, uFCode4, uSinkPort, 1024)
                     << new struct port(0x760, uFCode4, uSinkPort, 1024) << new struct port(0x761, uFCode4, uSinkPort, 512) << new struct port(0x762, uFCode4, uSinkPort, 1024);

    this->edcu2Ports << new struct port(0x770, uFCode4, uSinkPort, 1024) << new struct port(0x771, uFCode4, uSinkPort, 512) << new struct port(0x772, uFCode4, uSinkPort, 1024)
                     << new struct port(0x780, uFCode4, uSinkPort, 1024) << new struct port(0x781, uFCode4, uSinkPort, 512) << new struct port(0x782, uFCode4, uSinkPort, 1024)
                     << new struct port(0x790, uFCode4, uSinkPort, 1024) << new struct port(0x791, uFCode4, uSinkPort, 512) << new struct port(0x792, uFCode4, uSinkPort, 1024)
                     << new struct port(0x7A0, uFCode4, uSinkPort, 1024) << new struct port(0x7A1, uFCode4, uSinkPort, 512) << new struct port(0x7A2, uFCode4, uSinkPort, 1024)
                     << new struct port(0x7B0, uFCode4, uSinkPort, 1024) << new struct port(0x7B1, uFCode4, uSinkPort, 512) << new struct port(0x7B2, uFCode4, uSinkPort, 1024)
                     << new struct port(0x7C0, uFCode4, uSinkPort, 1024) << new struct port(0x7C1, uFCode4, uSinkPort, 512) << new struct port(0x7C2, uFCode4, uSinkPort, 1024);

    this->userDefinePort << new struct port(0xF710, uFCode4, uUserDefinePort, 1024) << new struct port(0xF711, uFCode4, uUserDefinePort, 512) << new struct port(0xF712, uFCode4, uUserDefinePort, 1024)
                         << new struct port(0xF730, uFCode4, uUserDefinePort, 1024) << new struct port(0xF731, uFCode4, uUserDefinePort, 512) << new struct port(0xF732, uFCode4, uUserDefinePort, 1024)
                         << new struct port(0xF750, uFCode4, uUserDefinePort, 1024) << new struct port(0xF751, uFCode4, uUserDefinePort, 512) << new struct port(0xF752, uFCode4, uUserDefinePort, 1024)
                         << new struct port(0xF770, uFCode4, uUserDefinePort, 1024) << new struct port(0xF771, uFCode4, uUserDefinePort, 512) << new struct port(0xF772, uFCode4, uUserDefinePort, 1024)
                         << new struct port(0xF790, uFCode4, uUserDefinePort, 1024) << new struct port(0xF791, uFCode4, uUserDefinePort, 512) << new struct port(0xF792, uFCode4, uUserDefinePort, 1024)
                         << new struct port(0xF7B0, uFCode4, uUserDefinePort, 1024) << new struct port(0xF7B1, uFCode4, uUserDefinePort, 512) << new struct port(0xF7B2, uFCode4, uUserDefinePort, 1024);

    this->pisDefaultPort << new struct port(0xF810, uFCode4, uUserDefinePort, 256) << new struct port(0xF811, uFCode4, uUserDefinePort, 256);

    this->bcuDefaultPort << new struct port(0xF410, uFCode4, uUserDefinePort, 32) << new struct port(0xF411, uFCode4, uUserDefinePort, 64)
                         << new struct port(0xF412, uFCode4, uUserDefinePort, 64) << new struct port(0xF413, uFCode3, uUserDefinePort, 512)
                         << new struct port(0xF414, uFCode4, uUserDefinePort, 64) << new struct port(0xF415, uFCode4, uUserDefinePort, 64)
                         << new struct port(0xF440, uFCode4, uUserDefinePort, 32) << new struct port(0xF441, uFCode4, uUserDefinePort, 64)
                         << new struct port(0xF442, uFCode4, uUserDefinePort, 64) << new struct port(0xF443, uFCode3, uUserDefinePort, 512)
                         << new struct port(0xF444, uFCode4, uUserDefinePort, 64) << new struct port(0xF445, uFCode4, uUserDefinePort, 64);
    this->ermDefaultPort << new struct port(0xF210, uFCode4, uUserDefinePort, 256) << new struct port(0xF211, uFCode4, uUserDefinePort, 512)
                         << new struct port(0xF212, uFCode4, uUserDefinePort, 512) << new struct port(0xF213, uFCode4, uUserDefinePort, 512);

    this->initializeSignals();
    this->initializeERMSignals();
    this->initializeRIOMSignals();
    this->initializePisSignals();
    this->ifFire = false;

    QList<unsigned short int> temp;
    this->edcuDefaultList1.installDatabase(this);
    temp.clear();
    temp << 0xF710 << 0xF711 << 0xF712;
    this->edcuDefaultList1.setSinkPort(temp);
    temp.clear();
    temp << 0x710 << 0x711 << 0x712 << 0x720 << 0x721 << 0x722;
    this->edcuDefaultList1.setSourcePort(temp);

    this->edcuDefaultList2.installDatabase(this);
    temp.clear();
    temp << 0xF730 << 0xF731 << 0xF732;
    this->edcuDefaultList2.setSinkPort(temp);
    temp.clear();
    temp << 0x730 << 0x731 << 0x732 << 0x740 << 0x741 << 0x742;
    this->edcuDefaultList2.setSourcePort(temp);

    this->edcuDefaultList3.installDatabase(this);
    temp.clear();
    temp << 0xF750 << 0xF751 << 0xF752;
    this->edcuDefaultList3.setSinkPort(temp);
    temp.clear();
    temp << 0x750 << 0x751 << 0x752 << 0x760 << 0x761 << 0x762;
    this->edcuDefaultList3.setSourcePort(temp);

    this->edcuDefaultList4.installDatabase(this);
    temp.clear();
    temp << 0xF770 << 0xF771 << 0xF772;
    this->edcuDefaultList4.setSinkPort(temp);
    temp.clear();
    temp << 0x770 << 0x771 << 0x772 << 0x780 << 0x781 << 0x782;
    this->edcuDefaultList4.setSourcePort(temp);

    this->edcuDefaultList5.installDatabase(this);
    temp.clear();
    temp << 0xF790 << 0xF791 << 0xF792;
    this->edcuDefaultList5.setSinkPort(temp);
    temp.clear();
    temp << 0x790 << 0x791 << 0x792 << 0x7A0 << 0x7A1 << 0x7A2;
    this->edcuDefaultList5.setSourcePort(temp);

    this->edcuDefaultList6.installDatabase(this);
    temp.clear();
    temp << 0xF7B0 << 0xF7B1 << 0xF7B2;
    this->edcuDefaultList6.setSinkPort(temp);
    temp.clear();
    temp << 0x7B0 << 0x7B1 << 0x7B2 << 0x7C0 << 0x7C1 << 0x7C2;
    this->edcuDefaultList6.setSourcePort(temp);

    this->doorsOnLine1 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    this->doorsOnLine2 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    this->doorsOnLine3 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    this->doorsOnLine4 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    this->doorsOnLine5 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    this->doorsOnLine6 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;

    this->pisDefaultList.installDatabase(this);
    temp.clear();
    temp << 0xF810 << 0xF811;
    this->pisDefaultList.setSinkPort(temp);
    temp.clear();
    temp << 0x810 << 0x811 << 0x820 << 0x821;
    this->pisDefaultList.setSourcePort(temp);

    this->bcuDefaultList1.installDatabase(this);
    temp.clear();
    temp << 0xF410 << 0xF411 << 0xF412 << 0xF413;
    this->bcuDefaultList1.setSinkPort(temp);
    temp.clear();
    temp << 0x410 << 0x411 << 0x412 << 0x413
         << 0x430 << 0x431 << 0x432 << 0x433;
    this->bcuDefaultList1.setSourcePort(temp);

    this->bcuDefaultList2.installDatabase(this);
    temp.clear();
    temp << 0xF440 << 0xF441 << 0xF442 << 0xF443;
    this->bcuDefaultList2.setSinkPort(temp);
    temp.clear();
    temp << 0x440 << 0x441 << 0x442 << 0x443
         << 0x460 << 0x461 << 0x462 << 0x463;
    this->bcuDefaultList2.setSourcePort(temp);

    this->ermDefaultList.installDatabase(this);
    temp.clear();
    temp << 0xF210 << 0xF211 << 0xF212 << 0xF213;
    this->ermDefaultList.setSinkPort(temp);
    temp.clear();
    temp << 0x210 << 0x211 << 0x212 << 0x213
         << 0x220 << 0x221 << 0x222 << 0x223;
    this->ermDefaultList.setSourcePort(temp);

}

void Database::synchronize()
{
    this->synchronizeCcuSignals();
    this->synchronizeBcuSignals();
    this->synchronizeEDCUSignals();
    this->synchronizeERMSignals();
    this->synchronizePISSignals();
    this->synchronizeRIOMSignals();
    this->edcuDefaultList1.createList(this->CTHM_EDCU1On, this->CTHM_EDCU2On, this->doorsOnLine1);
    this->edcuDefaultList2.createList(this->CTHM_EDCU3On, this->CTHM_EDCU4On, this->doorsOnLine2);
    this->edcuDefaultList3.createList(this->CTHM_EDCU5On, this->CTHM_EDCU6On, this->doorsOnLine3);
    this->edcuDefaultList4.createList(this->CTHM_EDCU7On, this->CTHM_EDCU8On, this->doorsOnLine4);
    this->edcuDefaultList5.createList(this->CTHM_EDCU9On, this->CTHM_EDCU10On, this->doorsOnLine5);
    this->edcuDefaultList6.createList(this->CTHM_EDCU11On, this->CTHM_EDCU12On, this->doorsOnLine6);
    this->pisDefaultList.createList(this->CTHM_PIS1On, this->CTHM_PIS2On);
    this->bcuDefaultList1.createList(this->CTHM_Tc1BCUOn, this->CTHM_Mp1BCUOn);
    this->bcuDefaultList2.createList(this->CTHM_Mp2BCUOn, this->CTHM_Tc2BCUOn);
    this->ermDefaultList.createList();


    //port 0x308

    this->CTHM_CCU1On = getBool(0x308,0,0);
    this->CTHM_CCU2On = getBool(0x308,0,1);
    this->CTHM_ERM1On = getBool(0x308,0,2);
    this->CTHM_ERM2On = getBool(0x308,0,3);
    this->CTHM_HMI1On = getBool(0x308,0,4);
    this->CTHM_HMI2On = getBool(0x308,0,5);
    this->CTHM_TC1RIOMGWOn = getBool(0x308,1,0);
    this->CTHM_M1RIOMGWOn = getBool(0x308,1,1);
    this->CTHM_Mp1RIOMGWOn = getBool(0x308,1,2);
    this->CTHM_Mp2RIOMGWOn = getBool(0x308,1,3);
    this->CTHM_M2RIOMGWOn = getBool(0x308,1,4);
    this->CTHM_TC2RIOMGWOn = getBool(0x308,1,5);
    this->CTHM_TC1DI1On = getBool(0x308,2,0);
    this->CTHM_TC1DI2On = getBool(0x308,2,1);
    this->CTHM_TC1DI3On = getBool(0x308,2,2);
    this->CTHM_TC1DI4On = getBool(0x308,2,3);
    this->CTHM_TC1DO1On = getBool(0x308,2,4);
    this->CTHM_TC1AX1On = getBool(0x308,2,5);
    this->CTHM_MP1DI1On = getBool(0x308,3,0);
    this->CTHM_MP1DO1On = getBool(0x308,3,1);
    this->CTHM_M1DI1On = getBool(0x308,3,4);
    this->CTHM_M1DO1On = getBool(0x308,3,5);
    this->CTHM_M2DI1On = getBool(0x308,4,0);
    this->CTHM_M2DO1On = getBool(0x308,4,1);
    this->CTHM_MP2DI1On = getBool(0x308,4,4);
    this->CTHM_MP2DO1On = getBool(0x308,4,5);
    this->CTHM_TC2DI1On = getBool(0x308,5,0);
    this->CTHM_TC2DI2On = getBool(0x308,5,1);
    this->CTHM_TC2DI3On = getBool(0x308,5,2);
    this->CTHM_TC2DI4On = getBool(0x308,5,3);
    this->CTHM_TC2DO1On = getBool(0x308,5,4);
    this->CTHM_TC2AX1On = getBool(0x308,5,5);
    this->CTHM_Tc1BCUOn = getBool(0x308,5,6);
    this->CTHM_M1BCUOn = getBool(0x308,5,7);
    this->CTHM_Mp1BCUOn = getBool(0x308,6,0);
    this->CTHM_Mp2BCUOn = getBool(0x308,6,1);
    this->CTHM_M2BCUOn = getBool(0x308,6,2);
    this->CTHM_Tc2BCUOn = getBool(0x308,6,3);
    this->CTHM_M1DCUOn = getBool(0x308,6,4);
    this->CTHM_Mp1DCUOn = getBool(0x308,6,5);
    this->CTHM_Mp2DCUOn = getBool(0x308,6,6);
    this->CTHM_M2DCUOn = getBool(0x308,6,7);
    this->CTHM_SIV1On = getBool(0x308,7,0);
    this->CTHM_SIV2On = getBool(0x308,7,1);
    this->CTHM_EDCU1On = getBool(0x308,7,2);
    this->CTHM_EDCU2On = getBool(0x308,7,3);
    this->CTHM_EDCU3On = getBool(0x308,7,4);
    this->CTHM_EDCU4On = getBool(0x308,7,5);
    this->CTHM_EDCU5On = getBool(0x308,7,6);
    this->CTHM_EDCU6On = getBool(0x308,7,7);
    this->CTHM_EDCU7On = getBool(0x308,8,0);
    this->CTHM_EDCU8On = getBool(0x308,8,1);
    this->CTHM_EDCU9On = getBool(0x308,8,2);
    this->CTHM_EDCU10On = getBool(0x308,8,3);
    this->CTHM_EDCU11On = getBool(0x308,8,4);
    this->CTHM_EDCU12On = getBool(0x308,8,5);
    this->CTHM_BCG1On = getBool(0x308,8,6);
    this->CTHM_BCG2On = getBool(0x308,8,7);
    this->CTHM_PIS1On = getBool(0x308,9,0);
    this->CTHM_PIS2On = getBool(0x308,9,1);
    this->CTHM_Tc1HVACOn = getBool(0x308,9,2);
    this->CTHM_M1HVACOn = getBool(0x308,9,3);
    this->CTHM_Mp1HVACOn = getBool(0x308,9,4);
    this->CTHM_Mp2HVACOn = getBool(0x308,9,5);
    this->CTHM_M2HVACOn = getBool(0x308,9,6);
    this->CTHM_Tc2HVACOn = getBool(0x308,9,7);
    this->CTHM_ATC1On = getBool(0x308,10,0);
    this->CTHM_ATC2On = getBool(0x308,10,1);
    this->CTHM_FAU1On = getBool(0x308,10,2);
    this->CTHM_FAU2On = getBool(0x308,10,3);
    this->CTHM_BMS1On = getBool(0x308,10,4);
    this->CTHM_BMS2On = getBool(0x308,10,5);
    this->CTHM_PDS1On = getBool(0x308,10,6);
    this->CTHM_PDS2On = getBool(0x308,10,7);

    this->CTHM_StationCancelByte1 = getUnsignedChar(0x308,11);
    this->CTHM_StationCancelByte2 = getUnsignedChar(0x308,12);
    this->CTHM_StationCancelByte3 = getUnsignedChar(0x308,13);
    this->CTHM_StationCancelByte4 = getUnsignedChar(0x308,14);
    this->CTHM_ATC1Active = getBool(0x308,16,6);
    this->CTHM_ATC2Active = getBool(0x308,16,7);
    this->CTHM_PIS1Active = getBool(0x308,17,0);
    this->CTHM_PIS2Active = getBool(0x308,17,1);
    this->CTHM_CCU1Active = getBool(0x308,17,4);
    this->CTHM_CCU2Active = getBool(0x308,17,5);
    this->CTHM_TC1Active = getBool(0x308,17,6);
    this->CTHM_TC2Active = getBool(0x308,17,7);
    this->CTHM_Traction = getBool(0x308,18,0);
    this->CTHM_Brake = getBool(0x308,18,1);
    this->CTHM_FastBrake = getBool(0x308,18,2);
    this->CTHM_EmgyBrake = getBool(0x308,18,3);
    this->CTHM_Backward = getBool(0x308,18,4);
    this->CTHM_Forward = getBool(0x308,18,5);
    this->CTHM_Testing = getBool(0x308,19,2);
    this->CTHM_TestFinish = getBool(0x308,19,3);
    this->CTHM_CCU1VerOK = getBool(0x308,19,4);
    this->CTHM_CCU2VerOK = getBool(0x308,19,5);
    this->CTHM_ClaarVVVFECEnable = getBool(0x308,19,6);
    this->CTHM_ClearSIVECEnable = getBool(0x308,19,7);
    this->CTHM_TestDistance = getUnsignedInt(0x308,20);
    this->CTHM_TestTime = getUnsignedInt(0x308,22);
    this->CTHM_Grade = getUnsignedChar(0x308,24);
    this->CTHM_CurrentStation = getUnsignedChar(0x308,25);
    this->CTHM_TrainSpeed = getUnsignedInt(0x308,26);
    this->CTHM_CatenaryVoltage = getUnsignedInt(0x308,28);
    this->CTHM_CatenaryCurrent = getUnsignedInt(0x308,30);

    // 0x309

    this->lineNo.sprintf("%d", this->getUnsignedChar(0x309, 21));
    this->vehicleNo.sprintf("%02d", this->getUnsignedChar(0x309, 22));
    if(this->CTHM_CCU1On)
    {
        this->ccu1OsVersion.sprintf("%3d.%-3d", getUnsignedChar(0x309, 0), getUnsignedChar(0x30A, 0));
        this->ccu1MvbVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 1), getUnsignedChar(0x30A, 1));
        this->ccu1SdbVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 2), getUnsignedChar(0x30A, 2));
        this->ccu1VxWorksVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 3), getUnsignedChar(0x30A, 3));
    }
    else
    {
        this->ccu1OsVersion = QString("0");
        this->ccu1MvbVersion = QString("0");
        this->ccu1SdbVersion = QString("0");
        this->ccu1VxWorksVersion = QString("0");
    }

    if(this->CTHM_CCU2On)
    {
        this->ccu2OsVersion.sprintf("%3d.%-3d", getUnsignedChar(0x309, 23), getUnsignedChar(0x30A, 4));
        this->ccu2MvbVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 24), getUnsignedChar(0x30A, 5));
        this->ccu2SdbVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 25), getUnsignedChar(0x30A, 6));
        this->ccu2VxWorksVersion.sprintf("%2d.%-2d", getUnsignedChar(0x309, 26), getUnsignedChar(0x30A, 7));
    }
    else
    {
        this->ccu2OsVersion = QString("0");
        this->ccu2MvbVersion = QString("0");
        this->ccu2SdbVersion = QString("0");
        this->ccu2VxWorksVersion = QString("0");
    }

    this->CTHM_WheelDigTc1FedBk = getUnsignedChar(0x309,4) + 700;
    this->CTHM_WheelDigM1FedBk = getUnsignedChar(0x309,5) + 700;
    this->CTHM_WheelDigMp1FedBk = getUnsignedChar(0x309,6) + 700;
    this->CTHM_WheelDigMp2FedBk = getUnsignedChar(0x309,7) + 700;
    this->CTHM_WheelDigM2FedBk = getUnsignedChar(0x309,8) + 700;
    this->CTHM_WheelDigTc2FedBk = getUnsignedChar(0x309,9) + 700;
    this->CTHM_PBReleaseTc1 = getBool(0x309,10,0);
    this->CTHM_PBReleaseM1 = getBool(0x309,10,1);
    this->CTHM_PBReleaseMp1 = getBool(0x309,10,2);
    this->CTHM_PBReleaseMp2 = getBool(0x309,10,3);
    this->CTHM_PBReleaseM2 = getBool(0x309,10,4);
    this->CTHM_PBReleaseTc2 = getBool(0x309,10,5);
    this->CTHM_BCUSTOverTime = getBool(0x309,10,7);
    this->CTHM_LineNum = getUnsignedChar(0x309,12);
    this->CTHM_TrainNum = getUnsignedChar(0x309,13);
    this->CTHM_FirstStationID = getUnsignedChar(0x309,14);
    this->CTHM_LastStationID = getUnsignedChar(0x309,15);

    this->CTHM_Tc1HVACColdHibt = getBool(0x309,27,0);
    this->CTHM_M1HVACColdHibt = getBool(0x309,27,1);
    this->CTHM_Mp1HVACColdHibt = getBool(0x309,27,2);
    this->CTHM_Mp2HVACColdHibt = getBool(0x309,27,3);
    this->CTHM_M2HVACColdHibt = getBool(0x309,27,4);
    this->CTHM_Tc2HVACColdHibt = getBool(0x309,27,5);
    this->CTHM_AutoWarmHibt = getBool(0x309,27,6);
    this->CTHM_ColdHibt = getBool(0x309,27,7);
    this->CTHM_SAVEWheelDigTc1FedBk = getBool(0x309,28,0);
    this->CTHM_SAVEWheelDigM1FedBk = getBool(0x309,28,1);
    this->CTHM_SAVEWheelDigMp1FedBk = getBool(0x309,28,2);
    this->CTHM_SAVEWheelDigMp2FedBk = getBool(0x309,28,3);
    this->CTHM_SAVEWheelDigM2FedBk = getBool(0x309,28,4);
    this->CTHM_SAVEWheelDigTc2FedBk = getBool(0x309,28,5);
    this->CTHM_SAVEHVACModeTc1FedBk = getBool(0x309,29,0);
    this->CTHM_SAVEHVACModeM1FedBk = getBool(0x309,29,1);
    this->CTHM_SAVEHVACModeMp1FedBk = getBool(0x309,29,2);
    this->CTHM_SAVEHVACModeMp2FedBk = getBool(0x309,29,3);
    this->CTHM_SAVEHVACModeM2FedBk = getBool(0x309,29,4);
    this->CTHM_SAVEHVACModeTc2FedBk = getBool(0x309,29,5);
    this->CTHM_SAVEHVACTempTc1FedBk = getBool(0x309,30,0);
    this->CTHM_SAVEHVACTempM1FedBk = getBool(0x309,30,1);
    this->CTHM_SAVEHVACTempMp1FedBk = getBool(0x309,30,2);
    this->CTHM_SAVEHVACTempMp2FedBk = getBool(0x309,30,3);
    this->CTHM_SAVEHVACTempM2FedBk = getBool(0x309,30,4);
    this->CTHM_SAVEHVACTempTc2FedBk = getBool(0x309,30,5);
    this->CTHM_SAVETimeFedBk = getBool(0x309,31,0);
    this->CTHM_SAVETrainNumFedBk = getBool(0x309,31,1);
    this->CTHM_SAVELineNumFedBk = getBool(0x309,31,2);
    this->CTHM_SAVEFirstStationFedBk = getBool(0x309,31,3);
    this->CTHM_SAVELastStationFedBk = getBool(0x309,31,4);
    this->CTHM_SAVEStationCancelFedBk = getBool(0x309,31,7);

    this->CTDO_Tc1CCULifeSign = getUnsignedInt(0x118,0);
    this->CTDO_Tc2CCULifeSign = getUnsignedInt(0x168,0);

    //0x310
    this->HM1CT_LifeSignal_A1 = getUnsignedInt(0x310,0);
    this->HM1CT_HMISWVerH_A1 = getUnsignedChar(0x310,2);
    this->HM1CT_HMISWVerL_A1 = getUnsignedChar(0x310,3);
    this->HM1CT_SetFlagChecker_A1 = getUnsignedChar(0x310,31);

    //0x311
    this->HM1CT_Year_A1 = getUnsignedChar(0x311,0);
    this->HM1CT_Month_A1 = getUnsignedChar(0x311,1);
    this->HM1CT_Day_A1 = getUnsignedChar(0x311,2);
    this->HM1CT_Hour_A1 = getUnsignedChar(0x311,3);
    this->HM1CT_Minute_A1 = getUnsignedChar(0x311,4);
    this->HM1CT_Second_A1 = getUnsignedChar(0x311,5);
    this->HM1CT_TrainNum_A1 = getUnsignedChar(0x311,6);
    this->HM1CT_LineNum_A1 = getUnsignedChar(0x311,7);
    this->HM1CT_StationIDFirst_A1 = getUnsignedChar(0x311,8);
    this->HM1CT_StationIDLast_A1 = getUnsignedChar(0x311,9);
    this->HM1CT_SAVETime_A1 = getBool(0x311,10,0);
    this->HM1CT_SAVETrainNum_A1 = getBool(0x311,10,1);
    this->HM1CT_SAVELineNum_A1 = getBool(0x311,10,2);
    this->HM1CT_SAVEFirstStation_A1 = getBool(0x311,10,3);
    this->HM1CT_SAVELastStation_A1 = getBool(0x311,10,4);
    this->HM1CT_HVACModeTc1_A1 = getUnsignedChar(0x311,11);
    this->HM1CT_HVACModeM1_A1 = getUnsignedChar(0x311,12);
    this->HM1CT_HVACModeMp1_A1 = getUnsignedChar(0x311,13);
    this->HM1CT_HVACModeMp2_A1 = getUnsignedChar(0x311,14);
    this->HM1CT_HVACModeM2_A1 = getUnsignedChar(0x311,15);
    this->HM1CT_HVACModeTc2_A1 = getUnsignedChar(0x311,16);
    this->HM1CT_SetTempTc1_A1 = getUnsignedChar(0x311,19);
    this->HM1CT_SetTempM1_A1 = getUnsignedChar(0x311,20);
    this->HM1CT_SetTempMp1_A1 = getUnsignedChar(0x311,21);
    this->HM1CT_SetTempMp2_A1 = getUnsignedChar(0x311,22);
    this->HM1CT_SetTempM2_A1 = getUnsignedChar(0x311,23);
    this->HM1CT_SetTempTc2_A1 = getUnsignedChar(0x311,24);
    this->HM1CT_SAVEHVACModeTc1_A1 = getBool(0x311,27,0);
    this->HM1CT_SAVEHVACModeM1_A1 = getBool(0x311,27,1);
    this->HM1CT_SAVEHVACModeMp1_A1 = getBool(0x311,27,2);
    this->HM1CT_SAVEHVACModeMp2_A1 = getBool(0x311,27,3);
    this->HM1CT_SAVEHVACModeM2_A1 = getBool(0x311,27,4);
    this->HM1CT_SAVEHVACModeTc2_A1 = getBool(0x311,27,5);
    this->HM1CT_SAVEHVACTempTc1_A1 = getBool(0x311,28,0);
    this->HM1CT_SAVEHVACTempM1_A1 = getBool(0x311,28,1);
    this->HM1CT_SAVEHVACTempMp1_A1 = getBool(0x311,28,2);
    this->HM1CT_SAVEHVACTempMp2_A1 = getBool(0x311,28,3);
    this->HM1CT_SAVEHVACTempM2_A1 = getBool(0x311,28,4);
    this->HM1CT_SAVEHVACTempTc2_A1 = getBool(0x311,28,5);

    //0x312
    this->HM1CT_WheelDiaTc1_A1 = getUnsignedChar(0x312,0);
    this->HM1CT_WheelDiaM1_A1 = getUnsignedChar(0x312,1);
    this->HM1CT_WheelDiaMp1_A1 = getUnsignedChar(0x312,2);
    this->HM1CT_WheelDiaMp2_A1 = getUnsignedChar(0x312,3);
    this->HM1CT_WheelDiaM2_A1 = getUnsignedChar(0x312,4);
    this->HM1CT_WheelDiaTc2_A1 = getUnsignedChar(0x312,5);
    this->HM1CT_BCUTestCode_A1 = getUnsignedChar(0x312,7);
    this->HM1CT_SAVEWheelDigTc1_A1 = getBool(0x312,8,0);
    this->HM1CT_SAVEWheelDigM1_A1 = getBool(0x312,8,1);
    this->HM1CT_SAVEWheelDigMp1_A1 = getBool(0x312,8,2);
    this->HM1CT_SAVEWheelDigMp2_A1 = getBool(0x312,8,3);
    this->HM1CT_SAVEWheelDigM2_A1 = getBool(0x312,8,4);
    this->HM1CT_SAVEWheelDigTc2_A1 = getBool(0x312,8,5);
    this->HM1CT_StationIDCurrent_A1 = getUnsignedChar(0x312,9);
    this->HM1CT_StationIDNext_A1 = getUnsignedChar(0x312,10);
    this->HM1CT_EmgyBroadcastID_A1 = getUnsignedChar(0x312,11);
    this->HM1CT_BackMode_A1 = getBool(0x312,14,6);
    this->HM1CT_WashMode_A1 = getBool(0x312,14,7);
    this->HM1CT_CutBCG1_A1 = getBool(0x312,15,0);
    this->HM1CT_CutBCG2_A1 = getBool(0x312,15,1);
    this->HM1CT_ResetBCG1_A1 = getBool(0x312,15,2);
    this->HM1CT_ResetBCG2_A1 = getBool(0x312,15,3);
    this->HM1CT_ResetSIV1Fult_A1 = getBool(0x312,15,4);
    this->HM1CT_ResetSIV2Fult_A1 = getBool(0x312,15,5);
    this->HM1CT_CutSIV1Fult_A1 = getBool(0x312,15,6);
    this->HM1CT_CutSIV2Fult_A1 = getBool(0x312,15,7);
    this->HM1CT_MuteFAU_A1 = getBool(0x312,16,0);
    this->HM1CT_ResetFAU_A1 = getBool(0x312,16,1);
    this->HM1CT_ResetSIV1Energy_A1 = getBool(0x312,16,2);
    this->HM1CT_ResetSIV2Energy_A1 = getBool(0x312,16,3);
    this->HM1CT_ResetDCUEnergy1_A1 = getBool(0x312,16,4);
    this->HM1CT_ResetDCUEnergy2_A1 = getBool(0x312,16,5);
    this->HM1CT_ResetDCUEnergy3_A1 = getBool(0x312,16,6);
    this->HM1CT_ResetDCUEnergy4_A1 = getBool(0x312,16,7);
    this->HM1CT_AdjustStation_A1 = getBool(0x312,17,0);
    this->HM1CT_EmgyBroadcastCommd_A1 = getBool(0x312,17,1);
    this->HM1CT_EmgyBroadcastStop_A1 = getBool(0x312,17,2);

    //0x313
    this->HM1CT_ClearERMAP1Time_A1 = getBool(0x313,0,0);
    this->HM1CT_ClearERMAP2Time_A1 = getBool(0x313,0,1);
    this->HM1CT_ClearTractionCost_A1 = getBool(0x313,0,2);
    this->HM1CT_ClearServiceDistance_A1 = getBool(0x313,0,3);
    this->HM1CT_ClearAuxCost_A1 = getBool(0x313,0,4);
    this->HM1CT_StationCancelByte1_A1 = getUnsignedChar(0x313,6);
    this->HM1CT_StationCancelByte2_A1 = getUnsignedChar(0x313,7);
    this->HM1CT_StationCancelByte3_A1 = getUnsignedChar(0x313,8);
    this->HM1CT_StationCancelByte4_A1 = getUnsignedChar(0x313,9);
    this->HM1CT_StationCancelSet_A1 = getUnsignedChar(0x313,10);
    this->HM1CT_TCMSStationCtrl_A1 = getUnsignedChar(0x313,16);
    this->HM1CT_SetServiceKilometers_A1 = getUnsignedInt32(0x313,22);
    this->HM1CT_SetTagServiceKilometers_A1 = getUnsignedChar(0x313,26);
    this->HM1CT_SetRunningKilometers_A1 = getUnsignedInt32(0x313,27);
    this->HM1CT_SetTagRunningKilometers_A1 = getUnsignedChar(0x313,31);

    //0x320
    this->HM2CT_LifeSignal_A2 = getUnsignedInt(0x320,0);
    this->HM2CT_HMISWVerH_A2 = getUnsignedChar(0x320,2);
    this->HM2CT_HMISWVerL_A2 = getUnsignedChar(0x320,3);
    this->HM2CT_SetFlagChecker_A2 = getUnsignedChar(0x320,31);

    //0x321
    this->HM2CT_Year_A2 = getUnsignedChar(0x321,0);
    this->HM2CT_Month_A2 = getUnsignedChar(0x321,1);
    this->HM2CT_Day_A2 = getUnsignedChar(0x321,2);
    this->HM2CT_Hour_A2 = getUnsignedChar(0x321,3);
    this->HM2CT_Minute_A2 = getUnsignedChar(0x321,4);
    this->HM2CT_Second_A2 = getUnsignedChar(0x321,5);
    this->HM2CT_TrainNum_A2 = getUnsignedChar(0x321,6);
    this->HM2CT_LineNum_A2 = getUnsignedChar(0x321,7);
    this->HM2CT_StationIDFirst_A2 = getUnsignedChar(0x321,8);
    this->HM2CT_StationIDLast_A2 = getUnsignedChar(0x321,9);
    this->HM2CT_SAVETime_A2 = getBool(0x321,10,0);
    this->HM2CT_SAVETrainNum_A2 = getBool(0x321,10,1);
    this->HM2CT_SAVELineNum_A2 = getBool(0x321,10,2);
    this->HM2CT_SAVEFirstStation_A2 = getBool(0x321,10,3);
    this->HM2CT_SAVELastStation_A2 = getBool(0x321,10,4);
    this->HM2CT_HVACModeTc1_A2 = getUnsignedChar(0x321,11);
    this->HM2CT_HVACModeM1_A2 = getUnsignedChar(0x321,12);
    this->HM2CT_HVACModeMp1_A2 = getUnsignedChar(0x321,13);
    this->HM2CT_HVACModeMp2_A2 = getUnsignedChar(0x321,14);
    this->HM2CT_HVACModeM2_A2 = getUnsignedChar(0x321,15);
    this->HM2CT_HVACModeTc2_A2 = getUnsignedChar(0x321,16);
    this->HM2CT_SetTempTc1_A2 = getUnsignedChar(0x321,19);
    this->HM2CT_SetTempM1_A2 = getUnsignedChar(0x321,20);
    this->HM2CT_SetTempMp1_A2 = getUnsignedChar(0x321,21);
    this->HM2CT_SetTempMp2_A2 = getUnsignedChar(0x321,22);
    this->HM2CT_SetTempM2_A2 = getUnsignedChar(0x321,23);
    this->HM2CT_SetTempTc2_A2 = getUnsignedChar(0x321,24);
    this->HM2CT_SAVEHVACModeTc1_A2 = getBool(0x321,27,0);
    this->HM2CT_SAVEHVACModeM1_A2 = getBool(0x321,27,1);
    this->HM2CT_SAVEHVACModeMp1_A2 = getBool(0x321,27,2);
    this->HM2CT_SAVEHVACModeMp2_A2 = getBool(0x321,27,3);
    this->HM2CT_SAVEHVACModeM2_A2 = getBool(0x321,27,4);
    this->HM2CT_SAVEHVACModeTc2_A2 = getBool(0x321,27,5);
    this->HM2CT_SAVEHVACTempTc1_A2 = getBool(0x321,28,0);
    this->HM2CT_SAVEHVACTempM1_A2 = getBool(0x321,28,1);
    this->HM2CT_SAVEHVACTempMp1_A2 = getBool(0x321,28,2);
    this->HM2CT_SAVEHVACTempMp2_A2 = getBool(0x321,28,3);
    this->HM2CT_SAVEHVACTempM2_A2 = getBool(0x321,28,4);
    this->HM2CT_SAVEHVACTempTc2_A2 = getBool(0x321,28,5);

    //0x322
    this->HM2CT_WheelDiaTc1_A2 = getUnsignedChar(0x322,0);
    this->HM2CT_WheelDiaM1_A2 = getUnsignedChar(0x322,1);
    this->HM2CT_WheelDiaMp1_A2 = getUnsignedChar(0x322,2);
    this->HM2CT_WheelDiaMp2_A2 = getUnsignedChar(0x322,3);
    this->HM2CT_WheelDiaM2_A2 = getUnsignedChar(0x322,4);
    this->HM2CT_WheelDiaTc2_A2 = getUnsignedChar(0x322,5);
    this->HM2CT_BCUTestCode_A2 = getUnsignedChar(0x322,7);
    this->HM2CT_SAVEWheelDigTc1_A2 = getBool(0x322,8,0);
    this->HM2CT_SAVEWheelDigM1_A2 = getBool(0x322,8,1);
    this->HM2CT_SAVEWheelDigMp1_A2 = getBool(0x322,8,2);
    this->HM2CT_SAVEWheelDigMp2_A2 = getBool(0x322,8,3);
    this->HM2CT_SAVEWheelDigM2_A2 = getBool(0x322,8,4);
    this->HM2CT_SAVEWheelDigTc2_A2 = getBool(0x322,8,5);
    this->HM2CT_StationIDCurrent_A2 = getUnsignedChar(0x322,9);
    this->HM2CT_StationIDNext_A2 = getUnsignedChar(0x322,10);
    this->HM2CT_EmgyBroadcastID_A2 = getUnsignedChar(0x322,11);
    this->HM2CT_BackMode_A2 = getBool(0x322,14,6);
    this->HM2CT_WashMode_A2 = getBool(0x322,14,7);
    this->HM2CT_CutBCG1_A2 = getBool(0x322,15,0);
    this->HM2CT_CutBCG2_A2 = getBool(0x322,15,1);
    this->HM2CT_ResetBCG1_A2 = getBool(0x322,15,2);
    this->HM2CT_ResetBCG2_A2 = getBool(0x322,15,3);
    this->HM2CT_ResetSIV1Fult_A2 = getBool(0x322,15,4);
    this->HM2CT_ResetSIV2Fult_A2 = getBool(0x322,15,5);
    this->HM2CT_CutSIV1Fult_A2 = getBool(0x322,15,6);
    this->HM2CT_CutSIV2Fult_A2 = getBool(0x322,15,7);
    this->HM2CT_MuteFAU_A2 = getBool(0x322,16,0);
    this->HM2CT_ResetFAU_A2 = getBool(0x322,16,1);
    this->HM2CT_ResetSIV1Energy_A2 = getBool(0x322,16,2);
    this->HM2CT_ResetSIV2Energy_A2 = getBool(0x322,16,3);
    this->HM2CT_ResetDCUEnergy1_A2 = getBool(0x322,16,4);
    this->HM2CT_ResetDCUEnergy2_A2 = getBool(0x322,16,5);
    this->HM2CT_ResetDCUEnergy3_A2 = getBool(0x322,16,6);
    this->HM2CT_ResetDCUEnergy4_A2 = getBool(0x322,16,7);
    this->HM2CT_AdjustStation_A2 = getBool(0x322,17,0);
    this->HM2CT_EmgyBroadcastCommd_A2 = getBool(0x322,17,1);
    this->HM2CT_EmgyBroadcastStop_A2 = getBool(0x322,17,2);

    //0x323
    this->HM2CT_ClearERMAP1Time_A2 = getBool(0x323,0,0);
    this->HM2CT_ClearERMAP2Time_A2 = getBool(0x323,0,1);
    this->HM2CT_ClearTractionCost_A2 = getBool(0x323,0,2);
    this->HM2CT_ClearServiceDistance_A2 = getBool(0x323,0,3);
    this->HM2CT_ClearAuxCost_A2 = getBool(0x323,0,4);
    this->HM2CT_StationCancelByte1_A2 = getUnsignedChar(0x323,6);
    this->HM2CT_StationCancelByte2_A2 = getUnsignedChar(0x323,7);
    this->HM2CT_StationCancelByte3_A2 = getUnsignedChar(0x323,8);
    this->HM2CT_StationCancelByte4_A2 = getUnsignedChar(0x323,9);
    this->HM2CT_StationCancelSet_A2 = getUnsignedChar(0x323,10);
    this->HM2CT_TCMSStationCtrl_A2 = getUnsignedChar(0x323,16);
    this->HM2CT_SetServiceKilometers_A2 = getUnsignedInt32(0x323,22);
    this->HM2CT_SetTagServiceKilometers_A2 = getUnsignedChar(0x323,26);
    this->HM2CT_SetRunningKilometers_A2 = getUnsignedInt32(0x323,27);
    this->HM2CT_SetTagRunningKilometers_A2 = getUnsignedChar(0x323,31);

    //0x00f
    this->PUBPORT_TMSLifeSignal = getUnsignedInt(0x00f,0);
    this->PUBPORT_SysTimeMonth = getUnsignedChar(0x00F,2);
    this->PUBPORT_SysTimeYear = getUnsignedChar(0x00F,3);
    this->PUBPORT_SysTimeHour = getUnsignedChar(0x00F,4);
    this->PUBPORT_SysTimeDay = getUnsignedChar(0x00F,5);
    this->PUBPORT_SysTimeSecond = getUnsignedChar(0x00F,6);
    this->PUBPORT_SysTimeMinute = getUnsignedChar(0x00F,7);
    this->PUBPORT_TrainNumber = getUnsignedInt(0x00F,8);
    this->PUBPORT_SettingTimeEnable = getBool(0x00F,10,0);

    // ccu online state
    this->hmiCcuOnlineState = this->checkCcuOnline(this->PUBPORT_TMSLifeSignal);


    //0x118
    this->CTDO_Tc1BHBMaintain = getBool(0x118, 20, 7);
    this->CTDO_Tc1BHBAction = getBool(0x118, 20, 6);
    this->CTDO_Tc1CmpStart = getBool(0x118, 20, 5);

    //0x168
    this->CTDO_Tc2BHBMaintain = getBool(0x168, 20, 7);
    this->CTDO_Tc2BHBAction = getBool(0x168, 20, 6);
    this->CTDO_Tc2CmpStart = getBool(0x168, 20, 5);

    //0x138
    this->CTDO_M3ExPowerCmd = getBool(0x138,20,7);

    //0x148
    this->CTDO_M4ExPowerCmd = getBool(0x148,20,7);

    //0x210
    this->DT1CT_ERMLfSginal_A1 = getUnsignedInt(0x210,0);
    this->DT1CT_ERMTimeYear_A1 = getUnsignedChar(0x210,2);
    this->DT1CT_ERMTimeMonth_A1 = getUnsignedChar(0x210,3);
    this->DT1CT_ERMTimeDay_A1 = getUnsignedChar(0x210,4);
    this->DT1CT_ERMTimeHour_A1 = getUnsignedChar(0x210,5);
    this->DT1CT_ERMTimeMinute_A1 = getUnsignedChar(0x210,6);
    this->DT1CT_ERMTimeSecond_A1 = getUnsignedChar(0x210,7);

    if(this->CTHM_ERM1On)
        this->erm1OsVersion.sprintf("%3d.%-3d", getUnsignedInt(0x210,8)/256, getUnsignedInt(0x210,8)%256);
    else
        this->erm1OsVersion.sprintf("0");
    this->DT1CT_ERMVxWorksVer_A1 = getUnsignedChar(0x210,9);
    //this->DT1CT_ERMMVBSWVer_A1 = getUnsignedChar(0x210,10);
    //this->DT1CT_ERMSDBVer_A1 = getUnsignedChar(0x210,11);
    this->DT1CT_TCMSRunTime_A1 = getUnsignedInt(0x210,12);

    //0x211
    this->DT1CT_RunningKilometers_A1 = getUnsignedInt32(0x211,0);
    this->DT1CT_VVVFEngyConsumption_A1 = getUnsignedInt32(0x211,4);
    this->DT1CT_SIVEngyConsumption_A1 = getUnsignedInt32(0x211,8);
    this->DT1CT_ReEngy_A1 = getUnsignedInt32(0x211,12);
    this->DT1CT_ServiceDistance_A1 = getUnsignedInt32(0x211,16);
    this->DT1CT_AP1RunningTime_A1 = getUnsignedInt32(0x211,20);
    this->DT1CT_AP2RunningTime_A1 = getUnsignedInt32(0x211,24);
    this->DT1CT_TCMSTotalTime_A1 = getUnsignedInt32(0x211,28);

    //0x212
    this->DT1CT_TotalDistanceYear_A1 = getUnsignedChar(0x212,0);
    this->DT1CT_TotalDistanceMonth_A1 = getUnsignedChar(0x212,1);
    this->DT1CT_TotalDistanceDay_A1 = getUnsignedChar(0x212,2);
    this->DT1CT_VVVFECYear_A1 = getUnsignedChar(0x212,3);
    this->DT1CT_VVVFECMonth_A1 = getUnsignedChar(0x212,4);
    this->DT1CT_VVVFECDay_A1 = getUnsignedChar(0x212,5);
    this->DT1CT_SIVECYear_A1 = getUnsignedChar(0x212,6);
    this->DT1CT_SIVECMonth_A1 = getUnsignedChar(0x212,7);
    this->DT1CT_SIVECDay_A1 = getUnsignedChar(0x212,8);
    this->DT1CT_ReEngyYear_A1 = getUnsignedChar(0x212,9);
    this->DT1CT_ReEngyMonth_A1 = getUnsignedChar(0x212,10);
    this->DT1CT_ReEngyDay_A1 = getUnsignedChar(0x212,11);
    this->DT1CT_ServiceDistanceYear_A1 = getUnsignedChar(0x212,12);
    this->DT1CT_ServiceDistanceMonth_A1 = getUnsignedChar(0x212,13);
    this->DT1CT_ServiceDistanceDay_A1 = getUnsignedChar(0x212,14);
    this->DT1CT_AP1ECYear_A1 = getUnsignedChar(0x212,15);
    this->DT1CT_AP1ECMonth_A1 = getUnsignedChar(0x212,16);
    this->DT1CT_AP1ECDay_A1 = getUnsignedChar(0x212,17);
    this->DT1CT_AP2ECYear_A1 = getUnsignedChar(0x212,18);
    this->DT1CT_AP2ECMonth_A1 = getUnsignedChar(0x212,19);
    this->DT1CT_AP2ECDay_A1 = getUnsignedChar(0x212,20);
    this->DT1CT_TCMSTotalTimeYear_A1 = getUnsignedChar(0x212,21);
    this->DT1CT_TCMSTotalTimeMonth_A1 = getUnsignedChar(0x212,22);
    this->DT1CT_TCMSTotalTimeDay_A1 = getUnsignedChar(0x212,23);


    //0x220
    this->DT6CT_ERMLfSginal_A2 = getUnsignedInt(0x220,0);
    this->DT6CT_ERMTimeYear_A2 = getUnsignedChar(0x220,2);
    this->DT6CT_ERMTimeMonth_A2 = getUnsignedChar(0x220,3);
    this->DT6CT_ERMTimeDay_A2 = getUnsignedChar(0x220,4);
    this->DT6CT_ERMTimeHour_A2 = getUnsignedChar(0x220,5);
    this->DT6CT_ERMTimeMinute_A2 = getUnsignedChar(0x220,6);
    this->DT6CT_ERMTimeSecond_A2 = getUnsignedChar(0x220,7);
    if(this->CTHM_ERM2On)
        this->erm2OsVersion.sprintf("%3d.%-3d", getUnsignedInt(0x220,8)/256, getUnsignedInt(0x220,8)%256);
    else
        this->erm2OsVersion = QString("0");
    this->DT6CT_ERMVxWorksVer_A2 = getUnsignedChar(0x220,9);
    //this->DT6CT_ERMMVBSWVer_A2 = getUnsignedChar(0x220,10);
    //this->DT6CT_ERMSDBVer_A2 = getUnsignedChar(0x220,11);
    this->DT6CT_TCMSRunTime_A2 = getUnsignedInt(0x220,12);

    //0x221
    this->DT6CT_RunningKilometers_A2 = getUnsignedInt32(0x221,0);
    this->DT6CT_VVVFEngyConsumption_A2 = getUnsignedInt32(0x221,4);
    this->DT6CT_SIVEngyConsumption_A2 = getUnsignedInt32(0x221,8);
    this->DT6CT_ReEngy_A2 = getUnsignedInt32(0x221,12);
    this->DT6CT_ServiceDistance_A2 = getUnsignedInt32(0x221,16);
    this->DT6CT_AP1RunningTime_A2 = getUnsignedInt32(0x221,20);
    this->DT6CT_AP2RunningTime_A2 = getUnsignedInt32(0x221,24);
    this->DT6CT_TCMSTotalTime_A2 = getUnsignedInt32(0x221,28);


    //0x222
    this->DT6CT_TotalDistanceYear_A2 = getUnsignedChar(0x222,0);
    this->DT6CT_TotalDistanceMonth_A2 = getUnsignedChar(0x222,1);
    this->DT6CT_TotalDistanceDay_A2 = getUnsignedChar(0x222,2);
    this->DT6CT_VVVFECYear_A2 = getUnsignedChar(0x222,3);
    this->DT6CT_VVVFECMonth_A2 = getUnsignedChar(0x222,4);
    this->DT6CT_VVVFECDay_A2 = getUnsignedChar(0x222,5);
    this->DT6CT_SIVECYear_A2 = getUnsignedChar(0x222,6);
    this->DT6CT_SIVECMonth_A2 = getUnsignedChar(0x222,7);
    this->DT6CT_SIVECDay_A2 = getUnsignedChar(0x222,8);
    this->DT6CT_ReEngyYear_A2 = getUnsignedChar(0x222,9);
    this->DT6CT_ReEngyMonth_A2 = getUnsignedChar(0x222,10);
    this->DT6CT_ReEngyDay_A2 = getUnsignedChar(0x222,11);
    this->DT6CT_ServiceDistanceYear_A2 = getUnsignedChar(0x222,12);
    this->DT6CT_ServiceDistanceMonth_A2 = getUnsignedChar(0x222,13);
    this->DT6CT_ServiceDistanceDay_A2 = getUnsignedChar(0x222,14);
    this->DT6CT_AP1ECYear_A2 = getUnsignedChar(0x222,15);
    this->DT6CT_AP1ECMonth_A2 = getUnsignedChar(0x222,16);
    this->DT6CT_AP1ECDay_A2 = getUnsignedChar(0x222,17);
    this->DT6CT_AP2ECYear_A2 = getUnsignedChar(0x222,18);
    this->DT6CT_AP2ECMonth_A2 = getUnsignedChar(0x222,19);
    this->DT6CT_AP2ECDay_A2 = getUnsignedChar(0x222,20);
    this->DT6CT_TCMSTotalTimeYear_A2 = getUnsignedChar(0x222,21);
    this->DT6CT_TCMSTotalTimeMonth_A2 = getUnsignedChar(0x222,22);
    this->DT6CT_TCMSTotalTimeDay_A2 = getUnsignedChar(0x222,23);

    //0x218
    this->CTDT1_RidingRateTc1_A1 = getUnsignedChar(0x218,0);
    this->CTDT1_RidingRateM1_A1 = getUnsignedChar(0x218,1);
    this->CTDT1_RidingRateMp1_A1 = getUnsignedChar(0x218,2);
    this->CTDT1_RidingRateMp2_A1 = getUnsignedChar(0x218,3);
    this->CTDT1_RidingRateM2_A1 = getUnsignedChar(0x218,4);
    this->CTDT1_RidingRateTc2_A1 = getUnsignedChar(0x218,5);
    this->CTDT1_RidingRate_A1 = getUnsignedChar(0x218,6);
    this->CTDT1_Accerate_A1 = getUnsignedInt(0x218,10);
    this->CTDT1_BrakeDistance_A1 = getUnsignedInt(0x218,12);
    this->CTDT1_RunClass_A1 = getUnsignedChar(0x218,14);
    this->CTDT1_Level_A1 = getUnsignedChar(0x218,15);
    this->CTDT1_BrakeStartSpeed_A1 = getUnsignedChar(0x218,16);
    this->CTDT1_Regeneration_A1 = getBool(0x218,17,0);
    this->CTDT1_TestDataValid = getBool(0x218, 17, 1);
    this->CTDT1_DrivingTL_A1 = getBool(0x218,18,0);
    this->CTDT1_BkeTL_A1 = getBool(0x218,18,1);
    this->CTDT1_EmBkeCircleTL_A1 = getBool(0x218,18,2);
    this->CTDT1_TCDI1Off_A1 = getBool(0x218,18,3);
    this->CTDT1_TCDO1Off_A1 = getBool(0x218,18,4);
    this->CTDT1_KeyTowardError1_A1 = getBool(0x218,18,5);
    this->CTDT1_ForwardReverseError1_A1 = getBool(0x218,18,6);
    this->CTDT1_PBError1_A1 = getBool(0x218,18,7);
    this->CTDT1_DirPBError1_A1 = getBool(0x218,19,0);
    this->CTDT1_KeyActiveError_A1 = getBool(0x218,19,1);
    this->CTDT1_KeyTowardError2_A1 = getBool(0x218,19,2);
    this->CTDT1_ForwardReverseError2_A1 = getBool(0x218,19,3);
    this->CTDT1_PBError2_A1 = getBool(0x218,19,4);
    this->CTDT1_DirPBError2_A1 = getBool(0x218,19,5);
    this->CTDT1_QuickBrkTL_A1 = getBool(0x218,19,6);
    this->CTDT1_ForwardRedu1_A1 = getBool(0x218,19,7);
    this->CTDT1_ForwardRedu2_A1 = getBool(0x218,20,0);
    this->CTDT1_BackwardRedu1_A1 = getBool(0x218,20,1);
    this->CTDT1_BackwardRedu2_A1 = getBool(0x218,20,2);
    this->CTDT1_TrcRedu1_A1 = getBool(0x218,20,3);
    this->CTDT1_TrcRedu2_A1 = getBool(0x218,20,4);
    this->CTDT1_BrkRedu1_A1 = getBool(0x218,20,5);
    this->CTDT1_BrkRedu2_A1 = getBool(0x218,20,6);
    this->CTDT1_QBrkRedu1_A1 = getBool(0x218,20,7);
    this->CTDT1_QBrkRedu2_A1 = getBool(0x218,21,0);
    this->CTDT1_EMCRedu1_A1 = getBool(0x218,21,1);
    this->CTDT1_EMCRedu2_A1 = getBool(0x218,21,2);

    //0x228
    this->CTDT6_RidingRateTc1_A2 = getUnsignedChar(0x228,0);
    this->CTDT6_RidingRateM1_A2 = getUnsignedChar(0x228,1);
    this->CTDT6_RidingRateMp1_A2 = getUnsignedChar(0x228,2);
    this->CTDT6_RidingRateMp2_A2 = getUnsignedChar(0x228,3);
    this->CTDT6_RidingRateM2_A2 = getUnsignedChar(0x228,4);
    this->CTDT6_RidingRateTc2_A2 = getUnsignedChar(0x228,5);
    this->CTDT6_RidingRate_A2 = getUnsignedChar(0x228,6);
    this->CTDT6_Accerate_A2 = getUnsignedInt(0x228,10);
    this->CTDT6_BrakeDistance_A2 = getUnsignedInt(0x228,12);
    this->CTDT6_RunClass_A2 = getUnsignedChar(0x228,14);
    this->CTDT6_Level_A2 = getUnsignedChar(0x228,15);
    this->CTDT6_BrakeStartSpeed_A2 = getUnsignedChar(0x228,16);
    this->CTDT6_Regeneration_A2 = getBool(0x228,17,0);
    this->CTDT6_TestDataValid = getBool(0x228, 17, 1);
    this->CTDT6_DrivingTL_A2 = getBool(0x228,18,0);
    this->CTDT6_BkeTL_A2 = getBool(0x228,18,1);
    this->CTDT6_EmBkeCircleTL_A2 = getBool(0x228,18,2);
    this->CTDT6_TCDI1Off_A2 = getBool(0x228,18,3);
    this->CTDT6_TCDO1Off_A2 = getBool(0x228,18,4);
    this->CTDT6_KeyTowardError1_A2 = getBool(0x228,18,5);
    this->CTDT6_ForwardReverseError1_A2 = getBool(0x228,18,6);
    this->CTDT6_PBError1_A2 = getBool(0x228,18,7);
    this->CTDT6_DirPBError1_A2 = getBool(0x228,19,0);
    this->CTDT6_KeyActiveError_A2 = getBool(0x228,19,1);
    this->CTDT6_KeyTowardError2_A2 = getBool(0x228,19,2);
    this->CTDT6_ForwardReverseError2_A2 = getBool(0x228,19,3);
    this->CTDT6_PBError2_A2 = getBool(0x228,19,4);
    this->CTDT6_DirPBError2_A2 = getBool(0x228,19,5);
    this->CTDT6_QuickBrkTL_A2 = getBool(0x228,19,6);
    this->CTDT6_ForwardRedu1_A2 = getBool(0x228,19,7);
    this->CTDT6_ForwardRedu2_A2 = getBool(0x228,20,0);
    this->CTDT6_BackwardRedu1_A2 = getBool(0x228,20,1);
    this->CTDT6_BackwardRedu2_A2 = getBool(0x228,20,2);
    this->CTDT6_TrcRedu1_A2 = getBool(0x228,20,3);
    this->CTDT6_TrcRedu2_A2 = getBool(0x228,20,4);
    this->CTDT6_BrkRedu1_A2 = getBool(0x228,20,5);
    this->CTDT6_BrkRedu2_A2 = getBool(0x228,20,6);
    this->CTDT6_QBrkRedu1_A2 = getBool(0x228,20,7);
    this->CTDT6_QBrkRedu2_A2 = getBool(0x228,21,0);
    this->CTDT6_EMCRedu1_A2 = getBool(0x228,21,1);
    this->CTDT6_EMCRedu2_A2 = getBool(0x228,21,2);



    //0x418
    this->CTBR_AchEDFrcMP1 = getSignedInt(0x418,2);
    this->CTBR_AchEDFrcMP2 = getSignedInt(0x418,4);
    this->CTBR_CutHoldBrk = getBool(0x418,6,0);
    this->CTBR_PerBrFrc = getSignedInt(0x418,12);
    this->CTBR_Driving = getBool(0x418,14,0);
    this->CTBR_Braking = getBool(0x418,14,1);
    this->CTBR_EBLpOpen = getBool(0x418,14,2);
    this->CTBR_ATOMode = getBool(0x418,14,3);
    this->CTBR_ATOHBApply = getBool(0x418,14,5);
    this->CTBR_HBRls = getBool(0x418,14,6);
    this->CTBR_EDFdOt = getBool(0x418,14,7);
    this->CTBR_EDOKMP1 = getBool(0x418,15,0);
    this->CTBR_EDSldMP1 = getBool(0x418,15,1);
    this->CTBR_AchEDFrcVldMP1 = getBool(0x418,15,2);
    this->CTBR_EDFrcAblyVldMP1 = getBool(0x418,15,3);
    this->CTBR_EDOKMP2 = getBool(0x418,15,4);
    this->CTBR_EDSldMP2 = getBool(0x418,15,5);
    this->CTBR_AchEDFrcVldMP2 = getBool(0x418,15,6);
    this->CTBR_EDFrcAblyVldMP2 = getBool(0x418,15,7);
    this->CTBR_AllDrsClsd = getBool(0x418,16,0);
    this->CTBR_PerBrFrcVld = getBool(0x418,16,1);
    this->CTBR_StartST = getBool(0x418,16,2);
    this->CTBR_RunST = getBool(0x418,16,3);
    this->CTBR_DiamReqTC1 = getBool(0x418,16,4);
    this->CTBR_DiamReqMP1 = getBool(0x418,16,5);
    this->CTBR_DiamReqMP2 = getBool(0x418,16,6);
    this->CTBR_DiamReqTC2 = getBool(0x418,16,7);
    this->CTBR_WhDiamTC1 = getSignedChar(0x418,17);
    this->CTBR_WhDiamMP1 = getSignedChar(0x418,18);
    this->CTBR_WhDiamMP2 = getSignedChar(0x418,19);
    this->CTBR_WhDiamTC2 = getSignedChar(0x418,20);
    this->CTBR_CodeST = getSignedChar(0x418,21);
    this->CTBR_EDFrcAblyMP1 = getSignedInt(0x418,22);
    this->CTBR_EDFrcAblyMP2 = getSignedInt(0x418,24);

    //0x520/0x521/0x522/0x523
    this->TR2CT_T1LifeSignalVCU = getUnsignedInt(0x520,0);
    this->TR2CT_M1MainConState = getBool(0x520,2,0);
    this->TR2CT_M1CharConState = getBool(0x520,2,1);
    this->TR2CT_HSCBState = getBool(0x520,2,2);
    this->TR2CT_HSCBDemand = getBool(0x520,2,3);
    this->TR2CT_T1CutOff = getBool(0x520,2,4);
    this->TR2CT_A1Slide = getBool(0x520,2,5);
    this->TR2CT_A1EBAvailable = getBool(0x520,3,0);
    this->TR2CT_A1EBSlide = getBool(0x520,3,1);
    this->TR2CT_A1EBDecrease = getBool(0x520,3,2);
    this->TR2CT_A1EBCutOff = getBool(0x520,3,3);
    this->TR2CT_A1EBOK = getBool(0x520,3,4);
    this->TR2CT_BrkReleaseReq1 = getBool(0x520,3,5);
    this->TR2CT_AllBrkReleased1 = getBool(0x520,3,6);
    this->TR2CT_T1SafetyBrk = getBool(0x520,4,0);
    this->TR2CT_T1PM1ReBrkPulse = getBool(0x520,5,6);
    this->TR2CT_T1PM1TrtPulse = getBool(0x520,5,7);
    this->TR2CT_T1RadOverTemp = getBool(0x520,6,0);
    this->TR2CT_T1HSCBNotClosed = getBool(0x520,6,1);
    this->TR2CT_T1LB1NotClosed = getBool(0x520,6,2);
    this->TR2CT_T1LB2NotClosed = getBool(0x520,6,3);
    this->TR2CT_T1OverCurrent = getBool(0x520,6,4);
    this->TR2CT_T1OverSpeed = getBool(0x520,6,5);
    this->TR2CT_T1TMCSFault = getBool(0x520,6,6);
    this->TR2CT_T1LineOverVolt = getBool(0x520,6,7);
    this->TR2CT_T1InverterOverCur = getBool(0x520,7,0);
    this->TR2CT_T1NetOverCur = getBool(0x520,7,1);
    this->TR2CT_T1NetOverVolt = getBool(0x520,7,2);
    this->TR2CT_T1OverTime = getBool(0x520,7,3);
    this->TR2CT_T1ChargeFault = getBool(0x520,7,4);
    this->TR2CT_T1DriverFlt = getBool(0x520,7,5);
    this->TR2CT_T1MotorOverTem = getBool(0x520,7,6);
    this->TR2CT_T1DirectionFlt = getBool(0x520,7,7);
    this->TR2CT_T1InstructionFlt = getBool(0x520,8,0);
    this->TR2CT_T1OverCurU = getBool(0x520,8,1);
    this->TR2CT_T1OverCurV = getBool(0x520,8,2);
    this->TR2CT_T1SpeedSensorFlt = getBool(0x520,8,3);
    this->TR2CT_T1BrkNotRealesed = getBool(0x520,8,4);
    this->TR2CT_T1LineOverVoltSet = getBool(0x520,8,5);
    this->TR2CT_T1LineOverCur = getBool(0x520,8,6);
    this->TR2CT_T1DriverFltU = getBool(0x520,8,7);
    this->TR2CT_T1DriverFltV = getBool(0x520,9,0);
    this->TR2CT_T1DriverFltW = getBool(0x520,9,1);
    this->TR2CT_T1PhaseLess = getBool(0x520,9,2);
    this->TR2CT_T1NetUnderVolt = getBool(0x520,9,3);
    this->TR2CT_T1TractionEffort = getUnsignedInt(0x520,10);
    this->TR2CT_T1ActualEBEffort = getUnsignedInt(0x520,12);
    this->TR2CT_M1LineCur = getUnsignedInt(0x520,14);
    this->TR2CT_NetVoltage = getUnsignedInt(0x520,16);
    this->TR2CT_T1InverterCurrent = getUnsignedInt(0x520,18);
    this->TR2CT_A1MotorSpeed = getUnsignedInt(0x520,20);
    this->TR2CT_A1MotorTemp = getUnsignedInt(0x520,22);
    this->TR2CT_T1SwVersion = getUnsignedInt(0x520,24);
    this->TR2CT_T1LifeSignal = getUnsignedInt(0x520,26);
    this->TR2CT_T2LifeSignalVCU = getUnsignedInt(0x521,0);
    this->TR2CT_T2CutOff = getBool(0x521,2,4);
    this->TR2CT_A2Slide = getBool(0x521,2,5);
    this->TR2CT_A2EBAvailable = getBool(0x521,3,0);
    this->TR2CT_A2EBSlide = getBool(0x521,3,1);
    this->TR2CT_A2EBDecrease = getBool(0x521,3,2);
    this->TR2CT_A2EBCutOff = getBool(0x521,3,3);
    this->TR2CT_A2EBOK = getBool(0x521,3,4);
    this->TR2CT_BrkReleaseReq2 = getBool(0x521,3,5);
    this->TR2CT_AllBrkReleased2 = getBool(0x521,3,6);
    this->TR2CT_T2SafetyBrk = getBool(0x521,4,0);
    this->TR2CT_T2RadOverTemp = getBool(0x521,6,0);
    this->TR2CT_T2HSCBNotClosed = getBool(0x521,6,1);
    this->TR2CT_T2LB1NotClosed = getBool(0x521,6,2);
    this->TR2CT_T2LB2NotClosed = getBool(0x521,6,3);
    this->TR2CT_T2OverCurrent = getBool(0x521,6,4);
    this->TR2CT_T2OverSpeed = getBool(0x521,6,5);
    this->TR2CT_T2TMCSFault = getBool(0x521,6,6);
    this->TR2CT_T2LineOverVolt = getBool(0x521,6,7);
    this->TR2CT_T2InverterOverCur = getBool(0x521,7,0);
    this->TR2CT_T2NetOverCur = getBool(0x521,7,1);
    this->TR2CT_T2NetOverVolt = getBool(0x521,7,2);
    this->TR2CT_T2OverTime = getBool(0x521,7,3);
    this->TR2CT_T2ChargeFault = getBool(0x521,7,4);
    this->TR2CT_T2DriverFlt = getBool(0x521,7,5);
    this->TR2CT_T2MotorOverTem = getBool(0x521,7,6);
    this->TR2CT_T2DirectionFlt = getBool(0x521,7,7);
    this->TR2CT_T2InstructionFlt = getBool(0x521,8,0);
    this->TR2CT_T2OverCurU = getBool(0x521,8,1);
    this->TR2CT_T2OverCurV = getBool(0x521,8,2);
    this->TR2CT_T2SpeedSensorFlt = getBool(0x521,8,3);
    this->TR2CT_T2BrkNotRealesed = getBool(0x521,8,4);
    this->TR2CT_T2LineOverVoltSet = getBool(0x521,8,5);
    this->TR2CT_T2LineOverCur = getBool(0x521,8,6);
    this->TR2CT_T2DriverFltU = getBool(0x521,8,7);
    this->TR2CT_T2DriverFltV = getBool(0x521,9,0);
    this->TR2CT_T2DriverFltW = getBool(0x521,9,1);
    this->TR2CT_T2PhaseLess = getBool(0x521,9,2);
    this->TR2CT_T2NetUnderVolt = getBool(0x521,9,3);
    this->TR2CT_T2TractionEffort = getUnsignedInt(0x521,10);
    this->TR2CT_T2ActualEBEffort = getUnsignedInt(0x521,12);
    this->TR2CT_T2InverterCurrent = getUnsignedInt(0x521,18);
    this->TR2CT_A2MotorSpeed = getUnsignedInt(0x521,20);
    this->TR2CT_A2MotorTemp = getUnsignedInt(0x521,22);
    this->TR2CT_T2SwVersion = getUnsignedInt(0x521,24);
    this->TR2CT_T2LifeSignal = getUnsignedInt(0x521,26);
    this->TR2CT_M1LineVol = getUnsignedInt(0x521,28);
    this->TR2CT_T3LifeSignalVCU = getUnsignedInt(0x522,0);
    this->TR2CT_M2MainConState = getBool(0x522,2,0);
    this->TR2CT_M2CharConState = getBool(0x522,2,1);
    this->TR2CT_T3CutOff = getBool(0x522,2,4);
    this->TR2CT_A3Slide = getBool(0x522,2,5);
    this->TR2CT_A3EBAvailable = getBool(0x522,3,0);
    this->TR2CT_A3EBSlide = getBool(0x522,3,1);
    this->TR2CT_A3EBDecrease = getBool(0x522,3,2);
    this->TR2CT_A3EBCutOff = getBool(0x522,3,3);
    this->TR2CT_A3EBOK = getBool(0x522,3,4);
    this->TR2CT_BrkReleaseReq3 = getBool(0x522,3,5);
    this->TR2CT_AllBrkReleased3 = getBool(0x522,3,6);
    this->TR2CT_T3SafetyBrk = getBool(0x522,4,0);
    this->TR2CT_PM2ReBrkPulse = getBool(0x522,5,6);
    this->TR2CT_PM2TrtPulse = getBool(0x522,5,7);
    this->TR2CT_T3RadOverTemp = getBool(0x522,6,0);
    this->TR2CT_T3HSCBNotClosed = getBool(0x522,6,1);
    this->TR2CT_T3LB1NotClosed = getBool(0x522,6,2);
    this->TR2CT_T3LB2NotClosed = getBool(0x522,6,3);
    this->TR2CT_T3OverCurrent = getBool(0x522,6,4);
    this->TR2CT_T3OverSpeed = getBool(0x522,6,5);
    this->TR2CT_T3TMCSFault = getBool(0x522,6,6);
    this->TR2CT_T3LineOverVolt = getBool(0x522,6,7);
    this->TR2CT_T3InverterOverCur = getBool(0x522,7,0);
    this->TR2CT_T3NetOverCur = getBool(0x522,7,1);
    this->TR2CT_T3NetOverVolt = getBool(0x522,7,2);
    this->TR2CT_T3OverTime = getBool(0x522,7,3);
    this->TR2CT_T3ChargeFault = getBool(0x522,7,4);
    this->TR2CT_T3DriverFlt = getBool(0x522,7,5);
    this->TR2CT_T3MotorOverTem = getBool(0x522,7,6);
    this->TR2CT_T3DirectionFlt = getBool(0x522,7,7);
    this->TR2CT_T3InstructionFlt = getBool(0x522,8,0);
    this->TR2CT_T3OverCurU = getBool(0x522,8,1);
    this->TR2CT_T3OverCurV = getBool(0x522,8,2);
    this->TR2CT_T3SpeedSensorFlt = getBool(0x522,8,3);
    this->TR2CT_T3BrkNotRealesed = getBool(0x522,8,4);
    this->TR2CT_T3LineOverVoltSet = getBool(0x522,8,5);
    this->TR2CT_T3LineOverCur = getBool(0x522,8,6);
    this->TR2CT_T3DriverFltU = getBool(0x522,8,7);
    this->TR2CT_T3DriverFltV = getBool(0x522,9,0);
    this->TR2CT_T3DriverFltW = getBool(0x522,9,1);
    this->TR2CT_T3PhaseLess = getBool(0x522,9,2);
    this->TR2CT_T3NetUnderVolt = getBool(0x522,9,3);
    this->TR2CT_T3TractionEffort = getUnsignedInt(0x522,10);
    this->TR2CT_T3ActualEBEffort = getUnsignedInt(0x522,12);
    this->TR2CT_M2LineCur = getUnsignedInt(0x522,14);
    this->TR2CT_T3InverterCurrent = getUnsignedInt(0x522,18);
    this->TR2CT_A3MotorSpeed = getUnsignedInt(0x522,20);
    this->TR2CT_A3MotorTemp = getUnsignedInt(0x522,22);
    this->TR2CT_T3SwVersion = getUnsignedInt(0x522,24);
    this->TR2CT_T3LifeSignal = getUnsignedInt(0x522,26);
    this->TR2CT_GWLifeSignal = getUnsignedChar(0x522,31);
    this->TR2CT_T4LifeSignalVCU = getUnsignedInt(0x523,0);
    this->TR2CT_T4CutOff = getBool(0x523,2,4);
    this->TR2CT_A4Slide = getBool(0x523,2,5);
    this->TR2CT_A4EBAvailable = getBool(0x523,3,0);
    this->TR2CT_A4EBSlide = getBool(0x523,3,1);
    this->TR2CT_A4EBDecrease = getBool(0x523,3,2);
    this->TR2CT_A4EBCutOff = getBool(0x523,3,3);
    this->TR2CT_A4EBOK = getBool(0x523,3,4);
    this->TR2CT_BrkReleaseReq4 = getBool(0x523,3,5);
    this->TR2CT_AllBrkReleased4 = getBool(0x523,3,6);
    this->TR2CT_T4SafetyBrk = getBool(0x523,4,0);
    this->TR2CT_T4RadOverTemp = getBool(0x523,6,0);
    this->TR2CT_T4HSCBNotClosed = getBool(0x523,6,1);
    this->TR2CT_T4LB1NotClosed = getBool(0x523,6,2);
    this->TR2CT_T4LB2NotClosed = getBool(0x523,6,3);
    this->TR2CT_T4OverCurrent = getBool(0x523,6,4);
    this->TR2CT_T4OverSpeed = getBool(0x523,6,5);
    this->TR2CT_T4TMCSFault = getBool(0x523,6,6);
    this->TR2CT_T4LineOverVolt = getBool(0x523,6,7);
    this->TR2CT_T4InverterOverCur = getBool(0x523,7,0);
    this->TR2CT_T4NetOverCur = getBool(0x523,7,1);
    this->TR2CT_T4NetOverVolt = getBool(0x523,7,2);
    this->TR2CT_T4OverTime = getBool(0x523,7,3);
    this->TR2CT_T4ChargeFault = getBool(0x523,7,4);
    this->TR2CT_T4DriverFlt = getBool(0x523,7,5);
    this->TR2CT_T4MotorOverTem = getBool(0x523,7,6);
    this->TR2CT_T4DirectionFlt = getBool(0x523,7,7);
    this->TR2CT_T4InstructionFlt = getBool(0x523,8,0);
    this->TR2CT_T4OverCurU = getBool(0x523,8,1);
    this->TR2CT_T4OverCurV = getBool(0x523,8,2);
    this->TR2CT_T4SpeedSensorFlt = getBool(0x523,8,3);
    this->TR2CT_T4BrkNotRealesed = getBool(0x523,8,4);
    this->TR2CT_T4LineOverVoltSet = getBool(0x523,8,5);
    this->TR2CT_T4LineOverCur = getBool(0x523,8,6);
    this->TR2CT_T4DriverFltU = getBool(0x523,8,7);
    this->TR2CT_T4DriverFltV = getBool(0x523,9,0);
    this->TR2CT_T4DriverFltW = getBool(0x523,9,1);
    this->TR2CT_T4PhaseLess = getBool(0x523,9,2);
    this->TR2CT_T4NetUnderVolt = getBool(0x523,9,3);
    this->TR2CT_T4TractionEffort = getUnsignedInt(0x523,10);
    this->TR2CT_T4ActualEBEffort = getUnsignedInt(0x523,12);
    this->TR2CT_T4InverterCurrent = getUnsignedInt(0x523,18);
    this->TR2CT_A4MotorSpeed = getUnsignedInt(0x523,20);
    this->TR2CT_A4MotorTemp = getUnsignedInt(0x523,22);
    this->TR2CT_T4SwVersion = getUnsignedInt(0x523,24);
    this->TR2CT_T4LifeSignal = getUnsignedInt(0x523,26);
    this->TR2CT_M2LineVol = getUnsignedInt(0x523,28);
    this->TR2CT_GWVersion = getUnsignedChar(0x523,31);

    //0x530/0x531/0x532/0x533
    this->TR3CT_T1LifeSignalVCU = getUnsignedInt(0x530,0);
    this->TR3CT_M1MainConState = getBool(0x530,2,0);
    this->TR3CT_M1CharConState = getBool(0x530,2,1);
    this->TR3CT_HSCBState = getBool(0x530,2,2);
    this->TR3CT_HSCBDemand = getBool(0x530,2,3);
    this->TR3CT_T1CutOff = getBool(0x530,2,4);
    this->TR3CT_A1Slide = getBool(0x530,2,5);
    this->TR3CT_A1EBAvailable = getBool(0x530,3,0);
    this->TR3CT_A1EBSlide = getBool(0x530,3,1);
    this->TR3CT_A1EBDecrease = getBool(0x530,3,2);
    this->TR3CT_A1EBCutOff = getBool(0x530,3,3);
    this->TR3CT_A1EBOK = getBool(0x530,3,4);
    this->TR3CT_BrkReleaseReq1 = getBool(0x530,3,5);
    this->TR3CT_AllBrkReleased1 = getBool(0x530,3,6);
    this->TR3CT_T1SafetyBrk = getBool(0x530,4,0);
    this->TR3CT_T1PM1ReBrkPulse = getBool(0x530,5,6);
    this->TR3CT_T1PM1TrtPulse = getBool(0x530,5,7);
    this->TR3CT_T1RadOverTemp = getBool(0x530,6,0);
    this->TR3CT_T1HSCBNotClosed = getBool(0x530,6,1);
    this->TR3CT_T1LB1NotClosed = getBool(0x530,6,2);
    this->TR3CT_T1LB2NotClosed = getBool(0x530,6,3);
    this->TR3CT_T1OverCurrent = getBool(0x530,6,4);
    this->TR3CT_T1OverSpeed = getBool(0x530,6,5);
    this->TR3CT_T1TMCSFault = getBool(0x530,6,6);
    this->TR3CT_T1LineOverVolt = getBool(0x530,6,7);
    this->TR3CT_T1InverterOverCur = getBool(0x530,7,0);
    this->TR3CT_T1NetOverCur = getBool(0x530,7,1);
    this->TR3CT_T1NetOverVolt = getBool(0x530,7,2);
    this->TR3CT_T1OverTime = getBool(0x530,7,3);
    this->TR3CT_T1ChargeFault = getBool(0x530,7,4);
    this->TR3CT_T1DriverFlt = getBool(0x530,7,5);
    this->TR3CT_T1MotorOverTem = getBool(0x530,7,6);
    this->TR3CT_T1DirectionFlt = getBool(0x530,7,7);
    this->TR3CT_T1InstructionFlt = getBool(0x530,8,0);
    this->TR3CT_T1OverCurU = getBool(0x530,8,1);
    this->TR3CT_T1OverCurV = getBool(0x530,8,2);
    this->TR3CT_T1SpeedSensorFlt = getBool(0x530,8,3);
    this->TR3CT_T1BrkNotRealesed = getBool(0x530,8,4);
    this->TR3CT_T1LineOverVoltSet = getBool(0x530,8,5);
    this->TR3CT_T1LineOverCur = getBool(0x530,8,6);
    this->TR3CT_T1DriverFltU = getBool(0x530,8,7);
    this->TR3CT_T1DriverFltV = getBool(0x530,9,0);
    this->TR3CT_T1DriverFltW = getBool(0x530,9,1);
    this->TR3CT_T1PhaseLess = getBool(0x530,9,2);
    this->TR3CT_T1NetUnderVolt = getBool(0x530,9,3);
    this->TR3CT_T1TractionEffort = getUnsignedInt(0x530,10);
    this->TR3CT_T1ActualEBEffort = getUnsignedInt(0x530,12);
    this->TR3CT_M1LineCur = getUnsignedInt(0x530,14);
    this->TR3CT_NetVoltage = getUnsignedInt(0x530,16);
    this->TR3CT_T1InverterCurrent = getUnsignedInt(0x530,18);
    this->TR3CT_A1MotorSpeed = getUnsignedInt(0x530,20);
    this->TR3CT_A1MotorTemp = getUnsignedInt(0x530,22);
    this->TR3CT_T1SwVersion = getUnsignedInt(0x530,24);
    if(this->CTHM_Mp1DCUOn)
    {
        this->dcu1VersionMp1.sprintf("%3d.%-3d", getUnsignedInt(0x530, 24)/256 , getUnsignedInt(0x530, 24) % 256);
        this->dcu2VersionMp1.sprintf("%3d.%-3d", getUnsignedInt(0x531, 24)/256 , getUnsignedInt(0x531, 24) % 256);
        this->dcu3VersionMp1.sprintf("%3d.%-3d", getUnsignedInt(0x532, 24)/256 , getUnsignedInt(0x532, 24) % 256);
        this->dcu4VersionMp1.sprintf("%3d.%-3d", getUnsignedInt(0x533, 24)/256 , getUnsignedInt(0x533, 24) % 256);
        this->dcuGwVersionMp1.sprintf("%2d.%-2d", getUnsignedChar(0x533, 31)/10 , getUnsignedChar(0x533, 31) % 10);
    }
    else
    {
        this->dcu1VersionMp1 = QString("0");
        this->dcu2VersionMp1 = QString("0");
        this->dcu3VersionMp1 = QString("0");
        this->dcu4VersionMp1 = QString("0");
        this->dcuGwVersionMp1 = QString("0");
    }
    this->TR3CT_T1LifeSignal = getUnsignedInt(0x530,26);
    this->TR3CT_T2LifeSignalVCU = getUnsignedInt(0x531,0);
    this->TR3CT_T2CutOff = getBool(0x531,2,4);
    this->TR3CT_A2Slide = getBool(0x531,2,5);
    this->TR3CT_A2EBAvailable = getBool(0x531,3,0);
    this->TR3CT_A2EBSlide = getBool(0x531,3,1);
    this->TR3CT_A2EBDecrease = getBool(0x531,3,2);
    this->TR3CT_A2EBCutOff = getBool(0x531,3,3);
    this->TR3CT_A2EBOK = getBool(0x531,3,4);
    this->TR3CT_BrkReleaseReq2 = getBool(0x531,3,5);
    this->TR3CT_AllBrkReleased2 = getBool(0x531,3,6);
    this->TR3CT_T2SafetyBrk = getBool(0x531,4,0);
    this->TR3CT_T2RadOverTemp = getBool(0x531,6,0);
    this->TR3CT_T2HSCBNotClosed = getBool(0x531,6,1);
    this->TR3CT_T2LB1NotClosed = getBool(0x531,6,2);
    this->TR3CT_T2LB2NotClosed = getBool(0x531,6,3);
    this->TR3CT_T2OverCurrent = getBool(0x531,6,4);
    this->TR3CT_T2OverSpeed = getBool(0x531,6,5);
    this->TR3CT_T2TMCSFault = getBool(0x531,6,6);
    this->TR3CT_T2LineOverVolt = getBool(0x531,6,7);
    this->TR3CT_T2InverterOverCur = getBool(0x531,7,0);
    this->TR3CT_T2NetOverCur = getBool(0x531,7,1);
    this->TR3CT_T2NetOverVolt = getBool(0x531,7,2);
    this->TR3CT_T2OverTime = getBool(0x531,7,3);
    this->TR3CT_T2ChargeFault = getBool(0x531,7,4);
    this->TR3CT_T2DriverFlt = getBool(0x531,7,5);
    this->TR3CT_T2MotorOverTem = getBool(0x531,7,6);
    this->TR3CT_T2DirectionFlt = getBool(0x531,7,7);
    this->TR3CT_T2InstructionFlt = getBool(0x531,8,0);
    this->TR3CT_T2OverCurU = getBool(0x531,8,1);
    this->TR3CT_T2OverCurV = getBool(0x531,8,2);
    this->TR3CT_T2SpeedSensorFlt = getBool(0x531,8,3);
    this->TR3CT_T2BrkNotRealesed = getBool(0x531,8,4);
    this->TR3CT_T2LineOverVoltSet = getBool(0x531,8,5);
    this->TR3CT_T2LineOverCur = getBool(0x531,8,6);
    this->TR3CT_T2DriverFltU = getBool(0x531,8,7);
    this->TR3CT_T2DriverFltV = getBool(0x531,9,0);
    this->TR3CT_T2DriverFltW = getBool(0x531,9,1);
    this->TR3CT_T2PhaseLess = getBool(0x531,9,2);
    this->TR3CT_T2NetUnderVolt = getBool(0x531,9,3);
    this->TR3CT_T2TractionEffort = getUnsignedInt(0x531,10);
    this->TR3CT_T2ActualEBEffort = getUnsignedInt(0x531,12);
    this->TR3CT_T2InverterCurrent = getUnsignedInt(0x531,18);
    this->TR3CT_A2MotorSpeed = getUnsignedInt(0x531,20);
    this->TR3CT_A2MotorTemp = getUnsignedInt(0x531,22);
    this->TR3CT_T2SwVersion = getUnsignedInt(0x531,24);
    this->TR3CT_T2LifeSignal = getUnsignedInt(0x531,26);
    this->TR3CT_M1LineVol = getUnsignedInt(0x531,28);
    this->TR3CT_T3LifeSignalVCU = getUnsignedInt(0x532,0);
    this->TR3CT_M2MainConState = getBool(0x532,2,0);
    this->TR3CT_M2CharConState = getBool(0x532,2,1);
    this->TR3CT_T3CutOff = getBool(0x532,2,4);
    this->TR3CT_A3Slide = getBool(0x532,2,5);
    this->TR3CT_A3EBAvailable = getBool(0x532,3,0);
    this->TR3CT_A3EBSlide = getBool(0x532,3,1);
    this->TR3CT_A3EBDecrease = getBool(0x532,3,2);
    this->TR3CT_A3EBCutOff = getBool(0x532,3,3);
    this->TR3CT_A3EBOK = getBool(0x532,3,4);
    this->TR3CT_BrkReleaseReq3 = getBool(0x532,3,5);
    this->TR3CT_AllBrkReleased3 = getBool(0x532,3,6);
    this->TR3CT_T3SafetyBrk = getBool(0x532,4,0);
    this->TR3CT_PM2ReBrkPulse = getBool(0x532,5,6);
    this->TR3CT_PM2TrtPulse = getBool(0x532,5,7);
    this->TR3CT_T3RadOverTemp = getBool(0x532,6,0);
    this->TR3CT_T3HSCBNotClosed = getBool(0x532,6,1);
    this->TR3CT_T3LB1NotClosed = getBool(0x532,6,2);
    this->TR3CT_T3LB2NotClosed = getBool(0x532,6,3);
    this->TR3CT_T3OverCurrent = getBool(0x532,6,4);
    this->TR3CT_T3OverSpeed = getBool(0x532,6,5);
    this->TR3CT_T3TMCSFault = getBool(0x532,6,6);
    this->TR3CT_T3LineOverVolt = getBool(0x532,6,7);
    this->TR3CT_T3InverterOverCur = getBool(0x532,7,0);
    this->TR3CT_T3NetOverCur = getBool(0x532,7,1);
    this->TR3CT_T3NetOverVolt = getBool(0x532,7,2);
    this->TR3CT_T3OverTime = getBool(0x532,7,3);
    this->TR3CT_T3ChargeFault = getBool(0x532,7,4);
    this->TR3CT_T3DriverFlt = getBool(0x532,7,5);
    this->TR3CT_T3MotorOverTem = getBool(0x532,7,6);
    this->TR3CT_T3DirectionFlt = getBool(0x532,7,7);
    this->TR3CT_T3InstructionFlt = getBool(0x532,8,0);
    this->TR3CT_T3OverCurU = getBool(0x532,8,1);
    this->TR3CT_T3OverCurV = getBool(0x532,8,2);
    this->TR3CT_T3SpeedSensorFlt = getBool(0x532,8,3);
    this->TR3CT_T3BrkNotRealesed = getBool(0x532,8,4);
    this->TR3CT_T3LineOverVoltSet = getBool(0x532,8,5);
    this->TR3CT_T3LineOverCur = getBool(0x532,8,6);
    this->TR3CT_T3DriverFltU = getBool(0x532,8,7);
    this->TR3CT_T3DriverFltV = getBool(0x532,9,0);
    this->TR3CT_T3DriverFltW = getBool(0x532,9,1);
    this->TR3CT_T3PhaseLess = getBool(0x532,9,2);
    this->TR3CT_T3NetUnderVolt = getBool(0x532,9,3);
    this->TR3CT_T3TractionEffort = getUnsignedInt(0x532,10);
    this->TR3CT_T3ActualEBEffort = getUnsignedInt(0x532,12);
    this->TR3CT_M2LineCur = getUnsignedInt(0x532,14);
    this->TR3CT_T3InverterCurrent = getUnsignedInt(0x532,18);
    this->TR3CT_A3MotorSpeed = getUnsignedInt(0x532,20);
    this->TR3CT_A3MotorTemp = getUnsignedInt(0x532,22);
    this->TR3CT_T3SwVersion = getUnsignedInt(0x532,24);

    this->TR3CT_T3LifeSignal = getUnsignedInt(0x532,26);
    this->TR3CT_GWLifeSignal = getUnsignedChar(0x532,31);
    this->TR3CT_T4LifeSignalVCU = getUnsignedInt(0x533,0);
    this->TR3CT_T4CutOff = getBool(0x533,2,4);
    this->TR3CT_A4Slide = getBool(0x533,2,5);
    this->TR3CT_A4EBAvailable = getBool(0x533,3,0);
    this->TR3CT_A4EBSlide = getBool(0x533,3,1);
    this->TR3CT_A4EBDecrease = getBool(0x533,3,2);
    this->TR3CT_A4EBCutOff = getBool(0x533,3,3);
    this->TR3CT_A4EBOK = getBool(0x533,3,4);
    this->TR3CT_BrkReleaseReq4 = getBool(0x533,3,5);
    this->TR3CT_AllBrkReleased4 = getBool(0x533,3,6);
    this->TR3CT_T4SafetyBrk = getBool(0x533,4,0);
    this->TR3CT_T4RadOverTemp = getBool(0x533,6,0);
    this->TR3CT_T4HSCBNotClosed = getBool(0x533,6,1);
    this->TR3CT_T4LB1NotClosed = getBool(0x533,6,2);
    this->TR3CT_T4LB2NotClosed = getBool(0x533,6,3);
    this->TR3CT_T4OverCurrent = getBool(0x533,6,4);
    this->TR3CT_T4OverSpeed = getBool(0x533,6,5);
    this->TR3CT_T4TMCSFault = getBool(0x533,6,6);
    this->TR3CT_T4LineOverVolt = getBool(0x533,6,7);
    this->TR3CT_T4InverterOverCur = getBool(0x533,7,0);
    this->TR3CT_T4NetOverCur = getBool(0x533,7,1);
    this->TR3CT_T4NetOverVolt = getBool(0x533,7,2);
    this->TR3CT_T4OverTime = getBool(0x533,7,3);
    this->TR3CT_T4ChargeFault = getBool(0x533,7,4);
    this->TR3CT_T4DriverFlt = getBool(0x533,7,5);
    this->TR3CT_T4MotorOverTem = getBool(0x533,7,6);
    this->TR3CT_T4DirectionFlt = getBool(0x533,7,7);
    this->TR3CT_T4InstructionFlt = getBool(0x533,8,0);
    this->TR3CT_T4OverCurU = getBool(0x533,8,1);
    this->TR3CT_T4OverCurV = getBool(0x533,8,2);
    this->TR3CT_T4SpeedSensorFlt = getBool(0x533,8,3);
    this->TR3CT_T4BrkNotRealesed = getBool(0x533,8,4);
    this->TR3CT_T4LineOverVoltSet = getBool(0x533,8,5);
    this->TR3CT_T4LineOverCur = getBool(0x533,8,6);
    this->TR3CT_T4DriverFltU = getBool(0x533,8,7);
    this->TR3CT_T4DriverFltV = getBool(0x533,9,0);
    this->TR3CT_T4DriverFltW = getBool(0x533,9,1);
    this->TR3CT_T4PhaseLess = getBool(0x533,9,2);
    this->TR3CT_T4NetUnderVolt = getBool(0x533,9,3);
    this->TR3CT_T4TractionEffort = getUnsignedInt(0x533,10);
    this->TR3CT_T4ActualEBEffort = getUnsignedInt(0x533,12);
    this->TR3CT_T4InverterCurrent = getUnsignedInt(0x533,18);
    this->TR3CT_A4MotorSpeed = getUnsignedInt(0x533,20);
    this->TR3CT_A4MotorTemp = getUnsignedInt(0x533,22);
    this->TR3CT_T4SwVersion = getUnsignedInt(0x533,24);
    this->TR3CT_T4LifeSignal = getUnsignedInt(0x533,26);
    this->TR3CT_M2LineVol = getUnsignedInt(0x533,28);
    this->TR3CT_GWVersion = getUnsignedChar(0x533,31);

    //0x540/0x541/0x542/0x543
    this->TR4CT_T1LifeSignalVCU = getUnsignedInt(0x540,0);
    this->TR4CT_M1MainConState = getBool(0x540,2,0);
    this->TR4CT_M1CharConState = getBool(0x540,2,1);
    this->TR4CT_HSCBState = getBool(0x540,2,2);
    this->TR4CT_HSCBDemand = getBool(0x540,2,3);
    this->TR4CT_T1CutOff = getBool(0x540,2,4);
    this->TR4CT_A1Slide = getBool(0x540,2,5);
    this->TR4CT_A1EBAvailable = getBool(0x540,3,0);
    this->TR4CT_A1EBSlide = getBool(0x540,3,1);
    this->TR4CT_A1EBDecrease = getBool(0x540,3,2);
    this->TR4CT_A1EBCutOff = getBool(0x540,3,3);
    this->TR4CT_A1EBOK = getBool(0x540,3,4);
    this->TR4CT_BrkReleaseReq1 = getBool(0x540,3,5);
    this->TR4CT_AllBrkReleased1 = getBool(0x540,3,6);
    this->TR4CT_T1SafetyBrk = getBool(0x540,4,0);
    this->TR4CT_T1PM1ReBrkPulse = getBool(0x540,5,6);
    this->TR4CT_T1PM1TrtPulse = getBool(0x540,5,7);
    this->TR4CT_T1RadOverTemp = getBool(0x540,6,0);
    this->TR4CT_T1HSCBNotClosed = getBool(0x540,6,1);
    this->TR4CT_T1LB1NotClosed = getBool(0x540,6,2);
    this->TR4CT_T1LB2NotClosed = getBool(0x540,6,3);
    this->TR4CT_T1OverCurrent = getBool(0x540,6,4);
    this->TR4CT_T1OverSpeed = getBool(0x540,6,5);
    this->TR4CT_T1TMCSFault = getBool(0x540,6,6);
    this->TR4CT_T1LineOverVolt = getBool(0x540,6,7);
    this->TR4CT_T1InverterOverCur = getBool(0x540,7,0);
    this->TR4CT_T1NetOverCur = getBool(0x540,7,1);
    this->TR4CT_T1NetOverVolt = getBool(0x540,7,2);
    this->TR4CT_T1OverTime = getBool(0x540,7,3);
    this->TR4CT_T1ChargeFault = getBool(0x540,7,4);
    this->TR4CT_T1DriverFlt = getBool(0x540,7,5);
    this->TR4CT_T1MotorOverTem = getBool(0x540,7,6);
    this->TR4CT_T1DirectionFlt = getBool(0x540,7,7);
    this->TR4CT_T1InstructionFlt = getBool(0x540,8,0);
    this->TR4CT_T1OverCurU = getBool(0x540,8,1);
    this->TR4CT_T1OverCurV = getBool(0x540,8,2);
    this->TR4CT_T1SpeedSensorFlt = getBool(0x540,8,3);
    this->TR4CT_T1BrkNotRealesed = getBool(0x540,8,4);
    this->TR4CT_T1LineOverVoltSet = getBool(0x540,8,5);
    this->TR4CT_T1LineOverCur = getBool(0x540,8,6);
    this->TR4CT_T1DriverFltU = getBool(0x540,8,7);
    this->TR4CT_T1DriverFltV = getBool(0x540,9,0);
    this->TR4CT_T1DriverFltW = getBool(0x540,9,1);
    this->TR4CT_T1PhaseLess = getBool(0x540,9,2);
    this->TR4CT_T1NetUnderVolt = getBool(0x540,9,3);
    this->TR4CT_T1TractionEffort = getUnsignedInt(0x540,10);
    this->TR4CT_T1ActualEBEffort = getUnsignedInt(0x540,12);
    this->TR4CT_M1LineCur = getUnsignedInt(0x540,14);
    this->TR4CT_NetVoltage = getUnsignedInt(0x540,16);
    this->TR4CT_T1InverterCurrent = getUnsignedInt(0x540,18);
    this->TR4CT_A1MotorSpeed = getUnsignedInt(0x540,20);
    this->TR4CT_A1MotorTemp = getUnsignedInt(0x540,22);
    this->TR4CT_T1SwVersion = getUnsignedInt(0x540,24);
    if(this->CTHM_Mp2DCUOn)
    {
        this->dcu1VersionMp2.sprintf("%3d.%-3d", getUnsignedInt(0x540, 24) / 256, getUnsignedInt(0x540, 24) % 256);
        this->dcu2VersionMp2.sprintf("%3d.%-3d", getUnsignedInt(0x541, 24) / 256, getUnsignedInt(0x541, 24) % 256);
        this->dcu3VersionMp2.sprintf("%3d.%-3d", getUnsignedInt(0x542, 24) / 256, getUnsignedInt(0x542, 24) % 256);
        this->dcu4VersionMp2.sprintf("%3d.%-3d", getUnsignedInt(0x543, 24) / 256, getUnsignedInt(0x543, 24) % 256);
        this->dcuGwVersionMp2.sprintf("%3d.%-3d", getUnsignedChar(0x543, 31) / 10, getUnsignedChar(0x543, 31) % 10);
    }
    else
    {
        this->dcu1VersionMp2 = QString("0");
        this->dcu2VersionMp2 = QString("0");
        this->dcu3VersionMp2 = QString("0");
        this->dcu4VersionMp2 = QString("0");
        this->dcuGwVersionMp2 = QString("0");
    }
    this->TR4CT_T1LifeSignal = getUnsignedInt(0x540,26);
    this->TR4CT_T2LifeSignalVCU = getUnsignedInt(0x541,0);
    this->TR4CT_T2CutOff = getBool(0x541,2,4);
    this->TR4CT_A2Slide = getBool(0x541,2,5);
    this->TR4CT_A2EBAvailable = getBool(0x541,3,0);
    this->TR4CT_A2EBSlide = getBool(0x541,3,1);
    this->TR4CT_A2EBDecrease = getBool(0x541,3,2);
    this->TR4CT_A2EBCutOff = getBool(0x541,3,3);
    this->TR4CT_A2EBOK = getBool(0x541,3,4);
    this->TR4CT_BrkReleaseReq2 = getBool(0x541,3,5);
    this->TR4CT_AllBrkReleased2 = getBool(0x541,3,6);
    this->TR4CT_T2SafetyBrk = getBool(0x541,4,0);
    this->TR4CT_T2RadOverTemp = getBool(0x541,6,0);
    this->TR4CT_T2HSCBNotClosed = getBool(0x541,6,1);
    this->TR4CT_T2LB1NotClosed = getBool(0x541,6,2);
    this->TR4CT_T2LB2NotClosed = getBool(0x541,6,3);
    this->TR4CT_T2OverCurrent = getBool(0x541,6,4);
    this->TR4CT_T2OverSpeed = getBool(0x541,6,5);
    this->TR4CT_T2TMCSFault = getBool(0x541,6,6);
    this->TR4CT_T2LineOverVolt = getBool(0x541,6,7);
    this->TR4CT_T2InverterOverCur = getBool(0x541,7,0);
    this->TR4CT_T2NetOverCur = getBool(0x541,7,1);
    this->TR4CT_T2NetOverVolt = getBool(0x541,7,2);
    this->TR4CT_T2OverTime = getBool(0x541,7,3);
    this->TR4CT_T2ChargeFault = getBool(0x541,7,4);
    this->TR4CT_T2DriverFlt = getBool(0x541,7,5);
    this->TR4CT_T2MotorOverTem = getBool(0x541,7,6);
    this->TR4CT_T2DirectionFlt = getBool(0x541,7,7);
    this->TR4CT_T2InstructionFlt = getBool(0x541,8,0);
    this->TR4CT_T2OverCurU = getBool(0x541,8,1);
    this->TR4CT_T2OverCurV = getBool(0x541,8,2);
    this->TR4CT_T2SpeedSensorFlt = getBool(0x541,8,3);
    this->TR4CT_T2BrkNotRealesed = getBool(0x541,8,4);
    this->TR4CT_T2LineOverVoltSet = getBool(0x541,8,5);
    this->TR4CT_T2LineOverCur = getBool(0x541,8,6);
    this->TR4CT_T2DriverFltU = getBool(0x541,8,7);
    this->TR4CT_T2DriverFltV = getBool(0x541,9,0);
    this->TR4CT_T2DriverFltW = getBool(0x541,9,1);
    this->TR4CT_T2PhaseLess = getBool(0x541,9,2);
    this->TR4CT_T2NetUnderVolt = getBool(0x541,9,3);
    this->TR4CT_T2TractionEffort = getUnsignedInt(0x541,10);
    this->TR4CT_T2ActualEBEffort = getUnsignedInt(0x541,12);
    this->TR4CT_T2InverterCurrent = getUnsignedInt(0x541,18);
    this->TR4CT_A2MotorSpeed = getUnsignedInt(0x541,20);
    this->TR4CT_A2MotorTemp = getUnsignedInt(0x541,22);
    this->TR4CT_T2SwVersion = getUnsignedInt(0x541,24);
    this->TR4CT_T2LifeSignal = getUnsignedInt(0x541,26);
    this->TR4CT_M1LineVol = getUnsignedInt(0x541,28);
    this->TR4CT_T3LifeSignalVCU = getUnsignedInt(0x542,0);
    this->TR4CT_M2MainConState = getBool(0x542,2,0);
    this->TR4CT_M2CharConState = getBool(0x542,2,1);
    this->TR4CT_T3CutOff = getBool(0x542,2,4);
    this->TR4CT_A3Slide = getBool(0x542,2,5);
    this->TR4CT_A3EBAvailable = getBool(0x542,3,0);
    this->TR4CT_A3EBSlide = getBool(0x542,3,1);
    this->TR4CT_A3EBDecrease = getBool(0x542,3,2);
    this->TR4CT_A3EBCutOff = getBool(0x542,3,3);
    this->TR4CT_A3EBOK = getBool(0x542,3,4);
    this->TR4CT_BrkReleaseReq3 = getBool(0x542,3,5);
    this->TR4CT_AllBrkReleased3 = getBool(0x542,3,6);
    this->TR4CT_T3SafetyBrk = getBool(0x542,4,0);
    this->TR4CT_PM2ReBrkPulse = getBool(0x542,5,6);
    this->TR4CT_PM2TrtPulse = getBool(0x542,5,7);
    this->TR4CT_T3RadOverTemp = getBool(0x542,6,0);
    this->TR4CT_T3HSCBNotClosed = getBool(0x542,6,1);
    this->TR4CT_T3LB1NotClosed = getBool(0x542,6,2);
    this->TR4CT_T3LB2NotClosed = getBool(0x542,6,3);
    this->TR4CT_T3OverCurrent = getBool(0x542,6,4);
    this->TR4CT_T3OverSpeed = getBool(0x542,6,5);
    this->TR4CT_T3TMCSFault = getBool(0x542,6,6);
    this->TR4CT_T3LineOverVolt = getBool(0x542,6,7);
    this->TR4CT_T3InverterOverCur = getBool(0x542,7,0);
    this->TR4CT_T3NetOverCur = getBool(0x542,7,1);
    this->TR4CT_T3NetOverVolt = getBool(0x542,7,2);
    this->TR4CT_T3OverTime = getBool(0x542,7,3);
    this->TR4CT_T3ChargeFault = getBool(0x542,7,4);
    this->TR4CT_T3DriverFlt = getBool(0x542,7,5);
    this->TR4CT_T3MotorOverTem = getBool(0x542,7,6);
    this->TR4CT_T3DirectionFlt = getBool(0x542,7,7);
    this->TR4CT_T3InstructionFlt = getBool(0x542,8,0);
    this->TR4CT_T3OverCurU = getBool(0x542,8,1);
    this->TR4CT_T3OverCurV = getBool(0x542,8,2);
    this->TR4CT_T3SpeedSensorFlt = getBool(0x542,8,3);
    this->TR4CT_T3BrkNotRealesed = getBool(0x542,8,4);
    this->TR4CT_T3LineOverVoltSet = getBool(0x542,8,5);
    this->TR4CT_T3LineOverCur = getBool(0x542,8,6);
    this->TR4CT_T3DriverFltU = getBool(0x542,8,7);
    this->TR4CT_T3DriverFltV = getBool(0x542,9,0);
    this->TR4CT_T3DriverFltW = getBool(0x542,9,1);
    this->TR4CT_T3PhaseLess = getBool(0x542,9,2);
    this->TR4CT_T3NetUnderVolt = getBool(0x542,9,3);
    this->TR4CT_T3TractionEffort = getUnsignedInt(0x542,10);
    this->TR4CT_T3ActualEBEffort = getUnsignedInt(0x542,12);
    this->TR4CT_M2LineCur = getUnsignedInt(0x542,14);
    this->TR4CT_T3InverterCurrent = getUnsignedInt(0x542,18);
    this->TR4CT_A3MotorSpeed = getUnsignedInt(0x542,20);
    this->TR4CT_A3MotorTemp = getUnsignedInt(0x542,22);
    this->TR4CT_T3SwVersion = getUnsignedInt(0x542,24);
    this->TR4CT_T3LifeSignal = getUnsignedInt(0x542,26);
    this->TR4CT_GWLifeSignal = getUnsignedChar(0x542,31);
    this->TR4CT_T4LifeSignalVCU = getUnsignedInt(0x543,0);
    this->TR4CT_T4CutOff = getBool(0x543,2,4);
    this->TR4CT_A4Slide = getBool(0x543,2,5);
    this->TR4CT_A4EBAvailable = getBool(0x543,3,0);
    this->TR4CT_A4EBSlide = getBool(0x543,3,1);
    this->TR4CT_A4EBDecrease = getBool(0x543,3,2);
    this->TR4CT_A4EBCutOff = getBool(0x543,3,3);
    this->TR4CT_A4EBOK = getBool(0x543,3,4);
    this->TR4CT_BrkReleaseReq4 = getBool(0x543,3,5);
    this->TR4CT_AllBrkReleased4 = getBool(0x543,3,6);
    this->TR4CT_T4SafetyBrk = getBool(0x543,4,0);
    this->TR4CT_T4RadOverTemp = getBool(0x543,6,0);
    this->TR4CT_T4HSCBNotClosed = getBool(0x543,6,1);
    this->TR4CT_T4LB1NotClosed = getBool(0x543,6,2);
    this->TR4CT_T4LB2NotClosed = getBool(0x543,6,3);
    this->TR4CT_T4OverCurrent = getBool(0x543,6,4);
    this->TR4CT_T4OverSpeed = getBool(0x543,6,5);
    this->TR4CT_T4TMCSFault = getBool(0x543,6,6);
    this->TR4CT_T4LineOverVolt = getBool(0x543,6,7);
    this->TR4CT_T4InverterOverCur = getBool(0x543,7,0);
    this->TR4CT_T4NetOverCur = getBool(0x543,7,1);
    this->TR4CT_T4NetOverVolt = getBool(0x543,7,2);
    this->TR4CT_T4OverTime = getBool(0x543,7,3);
    this->TR4CT_T4ChargeFault = getBool(0x543,7,4);
    this->TR4CT_T4DriverFlt = getBool(0x543,7,5);
    this->TR4CT_T4MotorOverTem = getBool(0x543,7,6);
    this->TR4CT_T4DirectionFlt = getBool(0x543,7,7);
    this->TR4CT_T4InstructionFlt = getBool(0x543,8,0);
    this->TR4CT_T4OverCurU = getBool(0x543,8,1);
    this->TR4CT_T4OverCurV = getBool(0x543,8,2);
    this->TR4CT_T4SpeedSensorFlt = getBool(0x543,8,3);
    this->TR4CT_T4BrkNotRealesed = getBool(0x543,8,4);
    this->TR4CT_T4LineOverVoltSet = getBool(0x543,8,5);
    this->TR4CT_T4LineOverCur = getBool(0x543,8,6);
    this->TR4CT_T4DriverFltU = getBool(0x543,8,7);
    this->TR4CT_T4DriverFltV = getBool(0x543,9,0);
    this->TR4CT_T4DriverFltW = getBool(0x543,9,1);
    this->TR4CT_T4PhaseLess = getBool(0x543,9,2);
    this->TR4CT_T4NetUnderVolt = getBool(0x543,9,3);
    this->TR4CT_T4TractionEffort = getUnsignedInt(0x543,10);
    this->TR4CT_T4ActualEBEffort = getUnsignedInt(0x543,12);
    this->TR4CT_T4InverterCurrent = getUnsignedInt(0x543,18);
    this->TR4CT_A4MotorSpeed = getUnsignedInt(0x543,20);
    this->TR4CT_A4MotorTemp = getUnsignedInt(0x543,22);
    this->TR4CT_T4SwVersion = getUnsignedInt(0x543,24);
    this->TR4CT_T4LifeSignal = getUnsignedInt(0x543,26);
    this->TR4CT_M2LineVol = getUnsignedInt(0x543,28);
    this->TR4CT_GWVersion = getUnsignedChar(0x543,31);

    //0x550/0x551/0x552/0x553
    this->TR5CT_T1LifeSignalVCU = getUnsignedInt(0x550,0);
    this->TR5CT_M1MainConState = getBool(0x550,2,0);
    this->TR5CT_M1CharConState = getBool(0x550,2,1);
    this->TR5CT_HSCBState = getBool(0x550,2,2);
    this->TR5CT_HSCBDemand = getBool(0x550,2,3);
    this->TR5CT_T1CutOff = getBool(0x550,2,4);
    this->TR5CT_A1Slide = getBool(0x550,2,5);
    this->TR5CT_A1EBAvailable = getBool(0x550,3,0);
    this->TR5CT_A1EBSlide = getBool(0x550,3,1);
    this->TR5CT_A1EBDecrease = getBool(0x550,3,2);
    this->TR5CT_A1EBCutOff = getBool(0x550,3,3);
    this->TR5CT_A1EBOK = getBool(0x550,3,4);
    this->TR5CT_BrkReleaseReq1 = getBool(0x550,3,5);
    this->TR5CT_AllBrkReleased1 = getBool(0x550,3,6);
    this->TR5CT_T1SafetyBrk = getBool(0x550,4,0);
    this->TR5CT_T1PM1ReBrkPulse = getBool(0x550,5,6);
    this->TR5CT_T1PM1TrtPulse = getBool(0x550,5,7);
    this->TR5CT_T1RadOverTemp = getBool(0x550,6,0);
    this->TR5CT_T1HSCBNotClosed = getBool(0x550,6,1);
    this->TR5CT_T1LB1NotClosed = getBool(0x550,6,2);
    this->TR5CT_T1LB2NotClosed = getBool(0x550,6,3);
    this->TR5CT_T1OverCurrent = getBool(0x550,6,4);
    this->TR5CT_T1OverSpeed = getBool(0x550,6,5);
    this->TR5CT_T1TMCSFault = getBool(0x550,6,6);
    this->TR5CT_T1LineOverVolt = getBool(0x550,6,7);
    this->TR5CT_T1InverterOverCur = getBool(0x550,7,0);
    this->TR5CT_T1NetOverCur = getBool(0x550,7,1);
    this->TR5CT_T1NetOverVolt = getBool(0x550,7,2);
    this->TR5CT_T1OverTime = getBool(0x550,7,3);
    this->TR5CT_T1ChargeFault = getBool(0x550,7,4);
    this->TR5CT_T1DriverFlt = getBool(0x550,7,5);
    this->TR5CT_T1MotorOverTem = getBool(0x550,7,6);
    this->TR5CT_T1DirectionFlt = getBool(0x550,7,7);
    this->TR5CT_T1InstructionFlt = getBool(0x550,8,0);
    this->TR5CT_T1OverCurU = getBool(0x550,8,1);
    this->TR5CT_T1OverCurV = getBool(0x550,8,2);
    this->TR5CT_T1SpeedSensorFlt = getBool(0x550,8,3);
    this->TR5CT_T1BrkNotRealesed = getBool(0x550,8,4);
    this->TR5CT_T1LineOverVoltSet = getBool(0x550,8,5);
    this->TR5CT_T1LineOverCur = getBool(0x550,8,6);
    this->TR5CT_T1DriverFltU = getBool(0x550,8,7);
    this->TR5CT_T1DriverFltV = getBool(0x550,9,0);
    this->TR5CT_T1DriverFltW = getBool(0x550,9,1);
    this->TR5CT_T1PhaseLess = getBool(0x550,9,2);
    this->TR5CT_T1NetUnderVolt = getBool(0x550,9,3);
    this->TR5CT_T1TractionEffort = getUnsignedInt(0x550,10);
    this->TR5CT_T1ActualEBEffort = getUnsignedInt(0x550,12);
    this->TR5CT_M1LineCur = getUnsignedInt(0x550,14);
    this->TR5CT_NetVoltage = getUnsignedInt(0x550,16);
    this->TR5CT_T1InverterCurrent = getUnsignedInt(0x550,18);
    this->TR5CT_A1MotorSpeed = getUnsignedInt(0x550,20);
    this->TR5CT_A1MotorTemp = getUnsignedInt(0x550,22);
    this->TR5CT_T1SwVersion = getUnsignedInt(0x550,24);
    this->TR5CT_T1LifeSignal = getUnsignedInt(0x550,26);
    this->TR5CT_T2LifeSignalVCU = getUnsignedInt(0x551,0);
    this->TR5CT_T2CutOff = getBool(0x551,2,4);
    this->TR5CT_A2Slide = getBool(0x551,2,5);
    this->TR5CT_A2EBAvailable = getBool(0x551,3,0);
    this->TR5CT_A2EBSlide = getBool(0x551,3,1);
    this->TR5CT_A2EBDecrease = getBool(0x551,3,2);
    this->TR5CT_A2EBCutOff = getBool(0x551,3,3);
    this->TR5CT_A2EBOK = getBool(0x551,3,4);
    this->TR5CT_BrkReleaseReq2 = getBool(0x551,3,5);
    this->TR5CT_AllBrkReleased2 = getBool(0x551,3,6);
    this->TR5CT_T2SafetyBrk = getBool(0x551,4,0);
    this->TR5CT_T2RadOverTemp = getBool(0x551,6,0);
    this->TR5CT_T2HSCBNotClosed = getBool(0x551,6,1);
    this->TR5CT_T2LB1NotClosed = getBool(0x551,6,2);
    this->TR5CT_T2LB2NotClosed = getBool(0x551,6,3);
    this->TR5CT_T2OverCurrent = getBool(0x551,6,4);
    this->TR5CT_T2OverSpeed = getBool(0x551,6,5);
    this->TR5CT_T2TMCSFault = getBool(0x551,6,6);
    this->TR5CT_T2LineOverVolt = getBool(0x551,6,7);
    this->TR5CT_T2InverterOverCur = getBool(0x551,7,0);
    this->TR5CT_T2NetOverCur = getBool(0x551,7,1);
    this->TR5CT_T2NetOverVolt = getBool(0x551,7,2);
    this->TR5CT_T2OverTime = getBool(0x551,7,3);
    this->TR5CT_T2ChargeFault = getBool(0x551,7,4);
    this->TR5CT_T2DriverFlt = getBool(0x551,7,5);
    this->TR5CT_T2MotorOverTem = getBool(0x551,7,6);
    this->TR5CT_T2DirectionFlt = getBool(0x551,7,7);
    this->TR5CT_T2InstructionFlt = getBool(0x551,8,0);
    this->TR5CT_T2OverCurU = getBool(0x551,8,1);
    this->TR5CT_T2OverCurV = getBool(0x551,8,2);
    this->TR5CT_T2SpeedSensorFlt = getBool(0x551,8,3);
    this->TR5CT_T2BrkNotRealesed = getBool(0x551,8,4);
    this->TR5CT_T2LineOverVoltSet = getBool(0x551,8,5);
    this->TR5CT_T2LineOverCur = getBool(0x551,8,6);
    this->TR5CT_T2DriverFltU = getBool(0x551,8,7);
    this->TR5CT_T2DriverFltV = getBool(0x551,9,0);
    this->TR5CT_T2DriverFltW = getBool(0x551,9,1);
    this->TR5CT_T2PhaseLess = getBool(0x551,9,2);
    this->TR5CT_T2NetUnderVolt = getBool(0x551,9,3);
    this->TR5CT_T2TractionEffort = getUnsignedInt(0x551,10);
    this->TR5CT_T2ActualEBEffort = getUnsignedInt(0x551,12);
    this->TR5CT_T2InverterCurrent = getUnsignedInt(0x551,18);
    this->TR5CT_A2MotorSpeed = getUnsignedInt(0x551,20);
    this->TR5CT_A2MotorTemp = getUnsignedInt(0x551,22);
    this->TR5CT_T2SwVersion = getUnsignedInt(0x551,24);
    this->TR5CT_T2LifeSignal = getUnsignedInt(0x551,26);
    this->TR5CT_M1LineVol = getUnsignedInt(0x551,28);
    this->TR5CT_T3LifeSignalVCU = getUnsignedInt(0x552,0);
    this->TR5CT_M2MainConState = getBool(0x552,2,0);
    this->TR5CT_M2CharConState = getBool(0x552,2,1);
    this->TR5CT_T3CutOff = getBool(0x552,2,4);
    this->TR5CT_A3Slide = getBool(0x552,2,5);
    this->TR5CT_A3EBAvailable = getBool(0x552,3,0);
    this->TR5CT_A3EBSlide = getBool(0x552,3,1);
    this->TR5CT_A3EBDecrease = getBool(0x552,3,2);
    this->TR5CT_A3EBCutOff = getBool(0x552,3,3);
    this->TR5CT_A3EBOK = getBool(0x552,3,4);
    this->TR5CT_BrkReleaseReq3 = getBool(0x552,3,5);
    this->TR5CT_AllBrkReleased3 = getBool(0x552,3,6);
    this->TR5CT_T3SafetyBrk = getBool(0x552,4,0);
    this->TR5CT_PM2ReBrkPulse = getBool(0x552,5,6);
    this->TR5CT_PM2TrtPulse = getBool(0x552,5,7);
    this->TR5CT_T3RadOverTemp = getBool(0x552,6,0);
    this->TR5CT_T3HSCBNotClosed = getBool(0x552,6,1);
    this->TR5CT_T3LB1NotClosed = getBool(0x552,6,2);
    this->TR5CT_T3LB2NotClosed = getBool(0x552,6,3);
    this->TR5CT_T3OverCurrent = getBool(0x552,6,4);
    this->TR5CT_T3OverSpeed = getBool(0x552,6,5);
    this->TR5CT_T3TMCSFault = getBool(0x552,6,6);
    this->TR5CT_T3LineOverVolt = getBool(0x552,6,7);
    this->TR5CT_T3InverterOverCur = getBool(0x552,7,0);
    this->TR5CT_T3NetOverCur = getBool(0x552,7,1);
    this->TR5CT_T3NetOverVolt = getBool(0x552,7,2);
    this->TR5CT_T3OverTime = getBool(0x552,7,3);
    this->TR5CT_T3ChargeFault = getBool(0x552,7,4);
    this->TR5CT_T3DriverFlt = getBool(0x552,7,5);
    this->TR5CT_T3MotorOverTem = getBool(0x552,7,6);
    this->TR5CT_T3DirectionFlt = getBool(0x552,7,7);
    this->TR5CT_T3InstructionFlt = getBool(0x552,8,0);
    this->TR5CT_T3OverCurU = getBool(0x552,8,1);
    this->TR5CT_T3OverCurV = getBool(0x552,8,2);
    this->TR5CT_T3SpeedSensorFlt = getBool(0x552,8,3);
    this->TR5CT_T3BrkNotRealesed = getBool(0x552,8,4);
    this->TR5CT_T3LineOverVoltSet = getBool(0x552,8,5);
    this->TR5CT_T3LineOverCur = getBool(0x552,8,6);
    this->TR5CT_T3DriverFltU = getBool(0x552,8,7);
    this->TR5CT_T3DriverFltV = getBool(0x552,9,0);
    this->TR5CT_T3DriverFltW = getBool(0x552,9,1);
    this->TR5CT_T3PhaseLess = getBool(0x552,9,2);
    this->TR5CT_T3NetUnderVolt = getBool(0x552,9,3);
    this->TR5CT_T3TractionEffort = getUnsignedInt(0x552,10);
    this->TR5CT_T3ActualEBEffort = getUnsignedInt(0x552,12);
    this->TR5CT_M2LineCur = getUnsignedInt(0x552,14);
    this->TR5CT_T3InverterCurrent = getUnsignedInt(0x552,18);
    this->TR5CT_A3MotorSpeed = getUnsignedInt(0x552,20);
    this->TR5CT_A3MotorTemp = getUnsignedInt(0x552,22);
    this->TR5CT_T3SwVersion = getUnsignedInt(0x552,24);
    this->TR5CT_T3LifeSignal = getUnsignedInt(0x552,26);
    this->TR5CT_GWLifeSignal = getUnsignedChar(0x552,31);
    this->TR5CT_T4LifeSignalVCU = getUnsignedInt(0x553,0);
    this->TR5CT_T4CutOff = getBool(0x553,2,4);
    this->TR5CT_A4Slide = getBool(0x553,2,5);
    this->TR5CT_A4EBAvailable = getBool(0x553,3,0);
    this->TR5CT_A4EBSlide = getBool(0x553,3,1);
    this->TR5CT_A4EBDecrease = getBool(0x553,3,2);
    this->TR5CT_A4EBCutOff = getBool(0x553,3,3);
    this->TR5CT_A4EBOK = getBool(0x553,3,4);
    this->TR5CT_BrkReleaseReq4 = getBool(0x553,3,5);
    this->TR5CT_AllBrkReleased4 = getBool(0x553,3,6);
    this->TR5CT_T4SafetyBrk = getBool(0x553,4,0);
    this->TR5CT_T4RadOverTemp = getBool(0x553,6,0);
    this->TR5CT_T4HSCBNotClosed = getBool(0x553,6,1);
    this->TR5CT_T4LB1NotClosed = getBool(0x553,6,2);
    this->TR5CT_T4LB2NotClosed = getBool(0x553,6,3);
    this->TR5CT_T4OverCurrent = getBool(0x553,6,4);
    this->TR5CT_T4OverSpeed = getBool(0x553,6,5);
    this->TR5CT_T4TMCSFault = getBool(0x553,6,6);
    this->TR5CT_T4LineOverVolt = getBool(0x553,6,7);
    this->TR5CT_T4InverterOverCur = getBool(0x553,7,0);
    this->TR5CT_T4NetOverCur = getBool(0x553,7,1);
    this->TR5CT_T4NetOverVolt = getBool(0x553,7,2);
    this->TR5CT_T4OverTime = getBool(0x553,7,3);
    this->TR5CT_T4ChargeFault = getBool(0x553,7,4);
    this->TR5CT_T4DriverFlt = getBool(0x553,7,5);
    this->TR5CT_T4MotorOverTem = getBool(0x553,7,6);
    this->TR5CT_T4DirectionFlt = getBool(0x553,7,7);
    this->TR5CT_T4InstructionFlt = getBool(0x553,8,0);
    this->TR5CT_T4OverCurU = getBool(0x553,8,1);
    this->TR5CT_T4OverCurV = getBool(0x553,8,2);
    this->TR5CT_T4SpeedSensorFlt = getBool(0x553,8,3);
    this->TR5CT_T4BrkNotRealesed = getBool(0x553,8,4);
    this->TR5CT_T4LineOverVoltSet = getBool(0x553,8,5);
    this->TR5CT_T4LineOverCur = getBool(0x553,8,6);
    this->TR5CT_T4DriverFltU = getBool(0x553,8,7);
    this->TR5CT_T4DriverFltV = getBool(0x553,9,0);
    this->TR5CT_T4DriverFltW = getBool(0x553,9,1);
    this->TR5CT_T4PhaseLess = getBool(0x553,9,2);
    this->TR5CT_T4NetUnderVolt = getBool(0x553,9,3);
    this->TR5CT_T4TractionEffort = getUnsignedInt(0x553,10);
    this->TR5CT_T4ActualEBEffort = getUnsignedInt(0x553,12);
    this->TR5CT_T4InverterCurrent = getUnsignedInt(0x553,18);
    this->TR5CT_A4MotorSpeed = getUnsignedInt(0x553,20);
    this->TR5CT_A4MotorTemp = getUnsignedInt(0x553,22);
    this->TR5CT_T4SwVersion = getUnsignedInt(0x553,24);
    this->TR5CT_T4LifeSignal = getUnsignedInt(0x553,26);
    this->TR5CT_M2LineVol = getUnsignedInt(0x553,28);
    this->TR5CT_GWVersion = getUnsignedChar(0x553,31);


    //0x528
    this->CTTR2_EBRelease = getBool(0x528,0,0);
    this->CTTR2_EBFade = getBool(0x528,0,1);
    this->CTTR2_EmBrake = getBool(0x528,2,0);
    this->CTTR2_Brake = getBool(0x528,2,1);
    this->CTTR2_Traction = getBool(0x528,2,2);
    this->CTTR2_Backward = getBool(0x528,2,3);
    this->CTTR2_Forward = getBool(0x528,2,4);
    this->CTTR2_PantUp = getBool(0x528,2,5);
    this->CTTR2_EBCutOff = getBool(0x528,2,6);
    this->CTTR2_WashingMode = getBool(0x528,2,7);
    this->CTTR2_Reverse = getBool(0x528,3,0);
    this->CTTR2_TractionAllowed = getBool(0x528,3,1);
    this->CTTR2_SpdLimitValid = getBool(0x528,3,2);
    this->CTTR2_TCU1CutOff = getBool(0x528,3,3);
    this->CTTR2_TCU2CutOff = getBool(0x528,3,4);
    this->CTTR2_TCU3CutOff = getBool(0x528,3,5);
    this->CTTR2_TCU4CutOff = getBool(0x528,3,6);
    this->CTTRi_SpdLimit = getUnsignedChar(0x528,4);
    this->CTTR2_MasterControler = getUnsignedInt(0x528,6);
    this->CTTR2_EBReqValue = getUnsignedInt(0x528,8);
    this->CTTR2_TrailerSpeed = getUnsignedInt(0x528,10);
    this->CTTR2_Diameter = getUnsignedInt(0x528,12);
    this->CTTR2_Load = getUnsignedInt(0x528,14);
    this->CTTR2_TrailerLoad = getUnsignedInt(0x528,16);
    this->CTTR2_VechileNumber = getUnsignedInt(0x528,18);

    //0x538
    this->CTTR3_EBRelease = getBool(0x538,0,0);
    this->CTTR3_EBFade = getBool(0x538,0,1);
    this->CTTR3_EmBrake = getBool(0x538,2,0);
    this->CTTR3_Brake = getBool(0x538,2,1);
    this->CTTR3_Traction = getBool(0x538,2,2);
    this->CTTR3_Backward = getBool(0x538,2,3);
    this->CTTR3_Forward = getBool(0x538,2,4);
    this->CTTR3_PantUp = getBool(0x538,2,5);
    this->CTTR3_EBCutOff = getBool(0x538,2,6);
    this->CTTR3_WashingMode = getBool(0x538,2,7);
    this->CTTR3_Reverse = getBool(0x538,3,0);
    this->CTTR3_TractionAllowed = getBool(0x538,3,1);
    this->CTTR3_SpdLimitValid = getBool(0x538,3,2);
    this->CTTR3_TCU1CutOff = getBool(0x538,3,3);
    this->CTTR3_TCU2CutOff = getBool(0x538,3,4);
    this->CTTR3_TCU3CutOff = getBool(0x538,3,5);
    this->CTTR3_TCU4CutOff = getBool(0x538,3,6);
    this->CTTR3_SpdLimit = getUnsignedChar(0x538,4);
    this->CTTR3_MasterControler = getUnsignedInt(0x538,6);
    this->CTTR3_EBReqValue = getUnsignedInt(0x538,8);
    this->CTTR3_TrailerSpeed = getUnsignedInt(0x538,10);
    this->CTTR3_Diameter = getUnsignedInt(0x538,12);
    this->CTTR3_Load = getUnsignedInt(0x538,14);
    this->CTTR3_TrailerLoad = getUnsignedInt(0x538,16);
    this->CTTR3_VechileNumber = getUnsignedInt(0x538,18);

    //0x548
    this->CTTR4_EBRelease = getBool(0x548,0,0);
    this->CTTR4_EBFade = getBool(0x548,0,1);
    this->CTTR4_EmBrake = getBool(0x548,2,0);
    this->CTTR4_Brake = getBool(0x548,2,1);
    this->CTTR4_Traction = getBool(0x548,2,2);
    this->CTTR4_Backward = getBool(0x548,2,3);
    this->CTTR4_Forward = getBool(0x548,2,4);
    this->CTTR4_PantUp = getBool(0x548,2,5);
    this->CTTR4_EBCutOff = getBool(0x548,2,6);
    this->CTTR4_WashingMode = getBool(0x548,2,7);
    this->CTTR4_Reverse = getBool(0x548,3,0);
    this->CTTR4_TractionAllowed = getBool(0x548,3,1);
    this->CTTR4_SpdLimitValid = getBool(0x548,3,2);
    this->CTTR4_TCU1CutOff = getBool(0x548,3,3);
    this->CTTR4_TCU2CutOff = getBool(0x548,3,4);
    this->CTTR4_TCU3CutOff = getBool(0x548,3,5);
    this->CTTR4_TCU4CutOff = getBool(0x548,3,6);
    this->CTTR4_SpdLimit = getUnsignedChar(0x548,4);
    this->CTTR4_MasterControler = getUnsignedInt(0x548,6);
    this->CTTR4_EBReqValue = getUnsignedInt(0x548,8);
    this->CTTR4_TrailerSpeed = getUnsignedInt(0x548,10);
    this->CTTR4_Diameter = getUnsignedInt(0x548,12);
    this->CTTR4_Load = getUnsignedInt(0x548,14);
    this->CTTR4_TrailerLoad = getUnsignedInt(0x548,16);
    this->CTTR4_VechileNumber = getUnsignedInt(0x548,18);

    //0x558
    this->CTTR5_EBRelease = getBool(0x558,0,0);
    this->CTTR5_EBFade = getBool(0x558,0,1);
    this->CTTR5_EmBrake = getBool(0x558,2,0);
    this->CTTR5_Brake = getBool(0x558,2,1);
    this->CTTR5_Traction = getBool(0x558,2,2);
    this->CTTR5_Backward = getBool(0x558,2,3);
    this->CTTR5_Forward = getBool(0x558,2,4);
    this->CTTR5_PantUp = getBool(0x558,2,5);
    this->CTTR5_EBCutOff = getBool(0x558,2,6);
    this->CTTR5_WashingMode = getBool(0x558,2,7);
    this->CTTR5_Reverse = getBool(0x558,3,0);
    this->CTTR5_TractionAllowed = getBool(0x558,3,1);
    this->CTTR5_SpdLimitValid = getBool(0x558,3,2);
    this->CTTR5_TCU1CutOff = getBool(0x558,3,3);
    this->CTTR5_TCU2CutOff = getBool(0x558,3,4);
    this->CTTR5_TCU3CutOff = getBool(0x558,3,5);
    this->CTTR5_TCU4CutOff = getBool(0x558,3,6);
    this->CTTR5_SpdLimit = getUnsignedChar(0x558,4);
    this->CTTR5_MasterControler = getUnsignedInt(0x558,6);
    this->CTTR5_EBReqValue = getUnsignedInt(0x558,8);
    this->CTTR5_TrailerSpeed = getUnsignedInt(0x558,10);
    this->CTTR5_Diameter = getUnsignedInt(0x558,12);
    this->CTTR5_Load = getUnsignedInt(0x558,14);
    this->CTTR5_TrailerLoad = getUnsignedInt(0x558,16);
    this->CTTR5_VechileNumber = getUnsignedInt(0x558,18);

    //0x610
    if(this->CTHM_SIV1On)
    {
        this->siv1Version.sprintf("%2d.%-2d", getUnsignedChar(0x610, 0)/16, getUnsignedChar(0x610, 0) % 16);
        this->sivGW1Version.sprintf("%3d", getUnsignedChar(0x611, 15));
    }
    else
    {
        this->siv1Version = QString("0");
        this->sivGW1Version = QString("0");
    }
    //this->AX1CT_SIVSwVersion = getUnsignedChar(0x610,0);
    this->AX1CT_Fault = getBool(0x610,1,0);
    this->AX1CT_Running = getBool(0x610,1,1);
    this->AX1CT_Stop = getBool(0x610,1,2);
    this->AX1CT_ExtendEnable = getBool(0x610,1,3);
    this->AX1CT_DropPantStop = getBool(0x610,1,4);
    this->AX1CT_PowerValid = getBool(0x610,3,0);
    this->AX1CT_UVOverVol = getBool(0x610,8,0);
    this->AX1CT_VWOverVol = getBool(0x610,8,1);
    this->AX1CT_WUOverVol = getBool(0x610,8,2);
    this->AX1CT_UOverCur = getBool(0x610,8,3);
    this->AX1CT_VOverCur = getBool(0x610,8,4);
    this->AX1CT_WOverCur = getBool(0x610,8,5);
    this->AX1CT_LineHWOverVol = getBool(0x610,8,6);
    this->AX1CT_NetHWOverVol = getBool(0x610,8,7);
    this->AX1CT_PDPProtection = getBool(0x610,9,0);
    this->AX1CT_CtrlLowVoltage = getBool(0x610,9,1);
    this->AX1CT_UIGBTOverCur = getBool(0x610,9,2);
    this->AX1CT_VIGBTOverCur = getBool(0x610,9,3);
    this->AX1CT_WIGBTOverCur = getBool(0x610,9,4);
    this->AX1CT_UIGBTFlt = getBool(0x610,9,5);
    this->AX1CT_VIGBTFlt = getBool(0x610,9,6);
    this->AX1CT_WIGBTFlt = getBool(0x610,9,7);
    this->AX1CT_NetOverVol = getBool(0x610,10,0);
    this->AX1CT_LineOverVol = getBool(0x610,10,1);
    this->AX1CT_LineLowVol = getBool(0x610,10,2);
    this->AX1CT_UOutEffOverVol = getBool(0x610,10,3);
    this->AX1CT_VOutEffOverVol = getBool(0x610,10,4);
    this->AX1CT_WOutEffOverVol = getBool(0x610,10,5);
    this->AX1CT_UOutEffLowVol = getBool(0x610,10,6);
    this->AX1CT_VOutEffLowVol = getBool(0x610,10,7);
    this->AX1CT_WOutEffLowVol = getBool(0x610,11,0);
    this->AX1CT_UOutIEffOverCur = getBool(0x610,11,1);
    this->AX1CT_VOutIEffOverCur = getBool(0x610,11,2);
    this->AX1CT_WOutIEffOverCur = getBool(0x610,11,3);
    this->AX1CT_UOutIInsOverCur = getBool(0x610,11,4);
    this->AX1CT_VOutIInsOverCur = getBool(0x610,11,5);
    this->AX1CT_WOutIInsOverCur = getBool(0x610,11,6);
    this->AX1CT_NetLowerVol = getBool(0x610,11,7);
    this->AX1CT_UIGBTIEffOverCur = getBool(0x610,12,0);
    this->AX1CT_VIGBTIEffOverCur = getBool(0x610,12,1);
    this->AX1CT_WIGBTIEffOverCur = getBool(0x610,12,2);
    this->AX1CT_UIGBTIInsOverCur = getBool(0x610,12,3);
    this->AX1CT_VIGBTIInsOverCur = getBool(0x610,12,4);
    this->AX1CT_WIGBTIInsOverCur = getBool(0x610,12,5);
    this->AX1CT_UOutUIInsOverCur = getBool(0x610,12,6);
    this->AX1CT_VOutUIInsOverCur = getBool(0x610,12,7);
    this->AX1CT_WOutUIInsOverCur = getBool(0x610,13,0);
    this->AX1CT_OutputFreFlt = getBool(0x610,13,1);
    this->AX1CT_LackPhase = getBool(0x610,13,2);
    this->AX1CT_IGBTOverRHeat = getBool(0x610,13,3);
    this->AX1CT_Con15OverLoad = getBool(0x610,13,4);
    this->AX1CT_Ins2OverLoad = getBool(0x610,13,5);
    this->AX1CT_LineCShortFlt = getBool(0x610,13,6);
    this->AX1CT_IGBTOverSHeat = getBool(0x610,13,7);
    this->AX1CT_PreChargerLose = getBool(0x610,14,0);
    this->AX1CT_SoftStartLose = getBool(0x610,14,1);
    this->AX1CT_FastDischargerFlt = getBool(0x610,14,2);
    this->AX1CT_PreChargerKMFlt = getBool(0x610,14,3);
    this->AX1CT_MainKMFlt = getBool(0x610,14,4);
    this->AX1CT_OutputKMFlt = getBool(0x610,14,5);
    this->AX1CT_SelfcheckErr = getBool(0x610,14,6);
    this->AX1CT_FlashErr = getBool(0x610,14,7);
    this->AX1CT_AdcCheckErr = getBool(0x610,15,0);
    this->AX1CT_FuseFlt = getBool(0x610,15,1);
    this->AX1CT_CANFlt = getBool(0x610,15,2);
    this->AX1CT_THDOverHigh = getBool(0x610,15,3);
    this->AX1CT_ConSoftOverVol = getBool(0x610,15,4);
    this->AX1CT_ConSoftLowerVol = getBool(0x610,15,5);
    this->AX1CT_NetVolChangeBigger = getBool(0x610,15,6);

    //0x611
    this->AX1CT_LifeSignal = getUnsignedChar(0x611,0);
    this->AX1CT_InputCurrent = getUnsignedChar(0x611,1);
    this->AX1CT_Power = getUnsignedInt(0x611,2);
    this->AX1CT_InputVoltage = getUnsignedInt(0x611,4);
    this->AX1CT_OutputACFrenq = getUnsignedInt(0x611,6);
    this->AX1CT_LineVoltageDC = getUnsignedInt(0x611,8);
    this->AX1CT_OutputVoltAC = getUnsignedInt(0x611,10);
    this->AX1CT_OutputCurAC = getUnsignedInt(0x611,12);
    this->AX1CT_GWLifeSig = getUnsignedChar(0x611,14);
    this->AX1CT_GWVersion = getUnsignedChar(0x611,15);

    //0x620
    if(this->CTHM_SIV2On)      
    {
        this->siv2Version.sprintf("%2d.%-2d", getUnsignedChar(0x620, 0)/16, getUnsignedChar(0x620, 0) % 16);
        this->sivGW2version.sprintf("%3d", getUnsignedChar(0x621, 15));
    }
    else
    {
        this->siv2Version = QString("0");
        this->sivGW2version = QString("0");
    }
    //this->AX2CT_SIVSwVersion = getUnsignedChar(0x620,0);
    this->AX2CT_Fault = getBool(0x620,1,0);
    this->AX2CT_Running = getBool(0x620,1,1);
    this->AX2CT_Stop = getBool(0x620,1,2);
    this->AX2CT_ExtendEnable = getBool(0x620,1,3);
    this->AX2CT_DropPantStop = getBool(0x620,1,4);
    this->AX2CT_PowerValid = getBool(0x620,3,0);
    this->AX2CT_UVOverVol = getBool(0x620,8,0);
    this->AX2CT_VWOverVol = getBool(0x620,8,1);
    this->AX2CT_WUOverVol = getBool(0x620,8,2);
    this->AX2CT_UOverCur = getBool(0x620,8,3);
    this->AX2CT_VOverCur = getBool(0x620,8,4);
    this->AX2CT_WOverCur = getBool(0x620,8,5);
    this->AX2CT_LineHWOverVol = getBool(0x620,8,6);
    this->AX2CT_NetHWOverVol = getBool(0x620,8,7);
    this->AX2CT_PDPProtection = getBool(0x620,9,0);
    this->AX2CT_CtrlLowVoltage = getBool(0x620,9,1);
    this->AX2CT_UIGBTOverCur = getBool(0x620,9,2);
    this->AX2CT_VIGBTOverCur = getBool(0x620,9,3);
    this->AX2CT_WIGBTOverCur = getBool(0x620,9,4);
    this->AX2CT_UIGBTFlt = getBool(0x620,9,5);
    this->AX2CT_VIGBTFlt = getBool(0x620,9,6);
    this->AX2CT_WIGBTFlt = getBool(0x620,9,7);
    this->AX2CT_NetOverVol = getBool(0x620,10,0);
    this->AX2CT_LineOverVol = getBool(0x620,10,1);
    this->AX2CT_LineLowVol = getBool(0x620,10,2);
    this->AX2CT_UOutEffOverVol = getBool(0x620,10,3);
    this->AX2CT_VOutEffOverVol = getBool(0x620,10,4);
    this->AX2CT_WOutEffOverVol = getBool(0x620,10,5);
    this->AX2CT_UOutEffLowVol = getBool(0x620,10,6);
    this->AX2CT_VOutEffLowVol = getBool(0x620,10,7);
    this->AX2CT_WOutEffLowVol = getBool(0x620,11,0);
    this->AX2CT_UOutIEffOverCur = getBool(0x620,11,1);
    this->AX2CT_VOutIEffOverCur = getBool(0x620,11,2);
    this->AX2CT_WOutIEffOverCur = getBool(0x620,11,3);
    this->AX2CT_UOutIInsOverCur = getBool(0x620,11,4);
    this->AX2CT_VOutIInsOverCur = getBool(0x620,11,5);
    this->AX2CT_WOutIInsOverCur = getBool(0x620,11,6);
    this->AX2CT_NetLowerVol = getBool(0x620,11,7);
    this->AX2CT_UIGBTIEffOverCur = getBool(0x620,12,0);
    this->AX2CT_VIGBTIEffOverCur = getBool(0x620,12,1);
    this->AX2CT_WIGBTIEffOverCur = getBool(0x620,12,2);
    this->AX2CT_UIGBTIInsOverCur = getBool(0x620,12,3);
    this->AX2CT_VIGBTIInsOverCur = getBool(0x620,12,4);
    this->AX2CT_WIGBTIInsOverCur = getBool(0x620,12,5);
    this->AX2CT_UOutUIInsOverCur = getBool(0x620,12,6);
    this->AX2CT_VOutUIInsOverCur = getBool(0x620,12,7);
    this->AX2CT_WOutUIInsOverCur = getBool(0x620,13,0);
    this->AX2CT_OutputFreFlt = getBool(0x620,13,1);
    this->AX2CT_LackPhase = getBool(0x620,13,2);
    this->AX2CT_IGBTOverRHeat = getBool(0x620,13,3);
    this->AX2CT_Con15OverLoad = getBool(0x620,13,4);
    this->AX2CT_Ins2OverLoad = getBool(0x620,13,5);
    this->AX2CT_LineCShortFlt = getBool(0x620,13,6);
    this->AX2CT_IGBTOverSHeat = getBool(0x620,13,7);
    this->AX2CT_PreChargerLose = getBool(0x620,14,0);
    this->AX2CT_SoftStartLose = getBool(0x620,14,1);
    this->AX2CT_FastDischargerFlt = getBool(0x620,14,2);
    this->AX2CT_PreChargerKMFlt = getBool(0x620,14,3);
    this->AX2CT_MainKMFlt = getBool(0x620,14,4);
    this->AX2CT_OutputKMFlt = getBool(0x620,14,5);
    this->AX2CT_SelfcheckErr = getBool(0x620,14,6);
    this->AX2CT_FlashErr = getBool(0x620,14,7);
    this->AX2CT_AdcCheckErr = getBool(0x620,15,0);
    this->AX2CT_FuseFlt = getBool(0x620,15,1);
    this->AX2CT_CANFlt = getBool(0x620,15,2);
    this->AX2CT_THDOverHigh = getBool(0x620,15,3);
    this->AX2CT_ConSoftOverVol = getBool(0x620,15,4);
    this->AX2CT_ConSoftLowerVol = getBool(0x620,15,5);
    this->AX2CT_NetVolChangeBigger = getBool(0x620,15,6);

    //0x621
    this->AX2CT_LifeSignal = getUnsignedChar(0x621,0);
    this->AX2CT_InputCurrent = getUnsignedChar(0x621,1);
    this->AX2CT_Power = getUnsignedInt(0x621,2);
    this->AX2CT_InputVoltage = getUnsignedInt(0x621,4);
    this->AX2CT_OutputACFrenq = getUnsignedInt(0x621,6);
    this->AX2CT_LineVoltageDC = getUnsignedInt(0x621,8);
    this->AX2CT_OutputVoltAC = getUnsignedInt(0x621,10);
    this->AX2CT_OutputCurAC = getUnsignedInt(0x621,12);
    this->AX2CT_GWLifeSig = getUnsignedChar(0x621,14);
    this->AX2CT_GWVersion = getUnsignedChar(0x621,15);

    //0x618
    this->CTAX1_TrainSpeed = getUnsignedInt(0x618,0);
    this->CTAX1_TestValid = getBool(0x618,2,3);
    this->CTAX1_ExtendPowerValid = getBool(0x618,2,4);
    this->CTAX1_Reset = getBool(0x618,2,5);
    this->CTAX1_Cutoff = getBool(0x618,2,6);
    this->CTAX1_PowerRec = getBool(0x618,2,7);
    this->CTAX1_GWCode = getUnsignedChar(0x618,15);


    //0x628
    this->CTAX2_TrainSpeed = getUnsignedInt(0x628,0);
    this->CTAX2_TestValid = getBool(0x628,2,3);
    this->CTAX2_ExtendPowerValid = getBool(0x628,2,4);
    this->CTAX2_Reset = getBool(0x628,2,5);
    this->CTAX2_Cutoff = getBool(0x628,2,6);
    this->CTAX2_PowerRec = getBool(0x628,2,7);
    this->CTAX2_GWCode = getUnsignedChar(0x628,15);   

    //0x808
    this->CTPA_TrainSpeed = getUnsignedInt(0x808,0);
    this->CTPA_EmBroadcastID = getUnsignedChar(0x808,2);
    this->CTPA_ATCLifeSignal = getUnsignedChar(0x808,6);
    this->CTPA_StreamDirection = getBool(0x808,7,0);
    this->CTPA_SkipStation = getBool(0x808,7,1);
    this->CTPA_SkipNextStation = getBool(0x808,7,2);
    this->CTPA_RightDoorOpen = getBool(0x808,7,4);
    this->CTPA_LeftDoorOpen = getBool(0x808,7,5);
    this->CTPA_StartStationID = getUnsignedInt(0x808,8);
    this->CTPA_DestinationID = getUnsignedInt(0x808,10);
    this->CTPA_NextStationID = getUnsignedInt(0x808,12);
    this->CTPA_TrainID = getUnsignedInt(0x808,14);
    this->CTPA_DisToNextStation = getUnsignedInt(0x808,16);
    this->CTPA_TC1Master = getBool(0x808,20,0);
    this->CTPA_TC2Master = getBool(0x808,20,1);
    this->CTPA_CloseRightDoor = getBool(0x808,20,2);
    this->CTPA_OpenRightDoor = getBool(0x808,20,3);
    this->CTPA_CloseLeftDoor = getBool(0x808,20,4);
    this->CTPA_OpenLeftDoor = getBool(0x808,20,5);
    this->CTPA_AllDoorClosed = getBool(0x808,20,6);
    this->CTPA_ATOMode = getBool(0x808,20,7);
    this->CTPA_Cab1VideoShow = getBool(0x808,21,0);
    this->CTPA_Tc1Video1Show = getBool(0x808,21,1);
    this->CTPA_Tc1Video2Show = getBool(0x808,21,2);
    this->CTPA_Mp1Video1Show = getBool(0x808,21,3);
    this->CTPA_Mp1Video2Show = getBool(0x808,21,4);
    this->CTPA_Mp2Video1Show = getBool(0x808,22,1);
    this->CTPA_Mp2Video2Show = getBool(0x808,22,2);
    this->CTPA_Tc2Video1Show = getBool(0x808,22,3);
    this->CTPA_Tc2Video2Show = getBool(0x808,22,4);
    this->CTPA_Cab2VideoShow = getBool(0x808,22,5);
    this->CTPA_TracClash = getBool(0x808,23,0);
    this->CTPA_BrkClash = getBool(0x808,23,1);
    this->CTPA_EBClash = getBool(0x808,23,2);
    this->CTPA_SBClash = getBool(0x808,23,3);
    this->CTPA_ForwardClash = getBool(0x808,23,4);
    this->CTPA_BackwardClash = getBool(0x808,23,5);
    this->CTPA_CabActiveClash = getBool(0x808,23,6);
    this->CTPA_ForBackClash = getBool(0x808,23,7);
    this->CTPA_TrBrkClash = getBool(0x808,24,0);
    this->CTPA_LROpenClash = getBool(0x808,24,1);

    //0x910
    this->AC1CT_Lifesignal = getUnsignedInt(0x910,0);
    this->AC1CT_SWVersion1 = getUnsignedChar(0x910,2);
    this->AC1CT_SWVersion2 = getUnsignedChar(0x910,3);
    if(this->CTHM_Tc1HVACOn)
        this->hvacVersionTc1.sprintf("%3d.%-3d", getUnsignedChar(0x910, 2), getUnsignedChar(0x910, 3));
    else
        this->hvacVersionTc1 = QString("0");
    this->AC1CT_Mode = getUnsignedChar(0x910,4);
    this->AC1CT_TempInside = getUnsignedChar(0x910,5);
    this->AC1CT_TempOutside = getUnsignedChar(0x910,6);
    this->AC1CT_TargetTemp = getUnsignedChar(0x910,7);
    this->AC1CT_WorkingStste = getBool(0x910,8,0);
    this->AC1CT_LoadDecState = getBool(0x910,8,1);
    this->AC1CT_HeaterCenCon = getBool(0x910,8,2);
    this->AC1CT_Vent11State = getBool(0x910,10,0);
    this->AC1CT_Vent12State = getBool(0x910,10,1);
    this->AC1CT_Vent21State = getBool(0x910,10,2);
    this->AC1CT_Vent22State = getBool(0x910,10,3);
    this->AC1CT_Compressor11State = getBool(0x910,10,4);
    this->AC1CT_Compressor12State = getBool(0x910,10,5);
    this->AC1CT_Compressor21State = getBool(0x910,10,6);
    this->AC1CT_Compressor22State = getBool(0x910,10,7);
    this->AC1CT_Conden11State = getBool(0x910,11,0);
    this->AC1CT_Conden12State = getBool(0x910,11,1);
    this->AC1CT_Conden21State = getBool(0x910,11,2);
    this->AC1CT_Conden22State = getBool(0x910,11,3);
    this->AC1CT_PreHeater11State = getBool(0x910,11,4);
    this->AC1CT_PreHeater12State = getBool(0x910,11,5);
    this->AC1CT_PreHeater21State = getBool(0x910,11,6);
    this->AC1CT_PreHeater22State = getBool(0x910,11,7);
    this->AC1CT_Vent11Fault = getBool(0x910,12,0);
    this->AC1CT_Vent12Fault = getBool(0x910,12,1);
    this->AC1CT_Vent21Fault = getBool(0x910,12,2);
    this->AC1CT_Vent22Fault = getBool(0x910,12,3);
    this->AC1CT_Compressor11Fault = getBool(0x910,12,4);
    this->AC1CT_Compressor12Fault = getBool(0x910,12,5);
    this->AC1CT_Compressor21Fault = getBool(0x910,12,6);
    this->AC1CT_Compressor22Fault = getBool(0x910,12,7);
    this->AC1CT_Conden11Fault = getBool(0x910,13,0);
    this->AC1CT_Conden12Fault = getBool(0x910,13,1);
    this->AC1CT_Conden21Fault = getBool(0x910,13,2);
    this->AC1CT_Conden22Fault = getBool(0x910,13,3);
    this->AC1CT_PreHeater11Fault = getBool(0x910,13,4);
    this->AC1CT_PreHeater12Fault = getBool(0x910,13,5);
    this->AC1CT_PreHeater21Fault = getBool(0x910,13,6);
    this->AC1CT_PreHeater22Fault = getBool(0x910,13,7);
    this->AC1CT_FreshAir11Fault = getBool(0x910,14,0);
    this->AC1CT_FreshAir12Fault = getBool(0x910,14,1);
    this->AC1CT_ReAir11Fault = getBool(0x910,14,2);
    this->AC1CT_FreshAir21Fault = getBool(0x910,14,3);
    this->AC1CT_FreshAir22Fault = getBool(0x910,14,4);
    this->AC1CT_ReAir21Fault = getBool(0x910,14,5);
    this->AC1CT_Cleaner11Fault = getBool(0x910,14,6);
    this->AC1CT_Cleaner21Fault = getBool(0x910,14,7);
    this->AC1CT_EleHeating11Fault = getBool(0x910,15,0);
    this->AC1CT_EleHeating12Fault = getBool(0x910,15,1);
    this->AC1CT_EmcVent1Sta = getBool(0x910,15,3);
    this->AC1CT_EmcVent2Sta = getBool(0x910,15,4);
    this->AC1CT_EmcVentInvFault = getBool(0x910,15,5);
    this->AC1CT_EmcVent1Fault = getBool(0x910,15,6);
    this->AC1CT_EmcVent2Fault = getBool(0x910,15,7);

    //0x920
    this->AC2CT_Lifesignal = getUnsignedInt(0x920,0);
    this->AC2CT_SWVersion1 = getUnsignedChar(0x920,2);
    this->AC2CT_SWVersion2 = getUnsignedChar(0x920,3);
    this->AC2CT_Mode = getUnsignedChar(0x920,4);
    this->AC2CT_TempInside = getUnsignedChar(0x920,5);
    this->AC2CT_TempOutside = getUnsignedChar(0x920,6);
    this->AC2CT_TargetTemp = getUnsignedChar(0x920,7);
    this->AC2CT_WorkingStste = getBool(0x920,8,0);
    this->AC2CT_LoadDecState = getBool(0x920,8,1);
    this->AC2CT_HeaterCenCon = getBool(0x920,8,2);
    this->AC2CT_Vent11State = getBool(0x920,10,0);
    this->AC2CT_Vent12State = getBool(0x920,10,1);
    this->AC2CT_Vent21State = getBool(0x920,10,2);
    this->AC2CT_Vent22State = getBool(0x920,10,3);
    this->AC2CT_Compressor11State = getBool(0x920,10,4);
    this->AC2CT_Compressor12State = getBool(0x920,10,5);
    this->AC2CT_Compressor21State = getBool(0x920,10,6);
    this->AC2CT_Compressor22State = getBool(0x920,10,7);
    this->AC2CT_Conden11State = getBool(0x920,11,0);
    this->AC2CT_Conden12State = getBool(0x920,11,1);
    this->AC2CT_Conden21State = getBool(0x920,11,2);
    this->AC2CT_Conden22State = getBool(0x920,11,3);
    this->AC2CT_PreHeater11State = getBool(0x920,11,4);
    this->AC2CT_PreHeater12State = getBool(0x920,11,5);
    this->AC2CT_PreHeater21State = getBool(0x920,11,6);
    this->AC2CT_PreHeater22State = getBool(0x920,11,7);
    this->AC2CT_Vent11Fault = getBool(0x920,12,0);
    this->AC2CT_Vent12Fault = getBool(0x920,12,1);
    this->AC2CT_Vent21Fault = getBool(0x920,12,2);
    this->AC2CT_Vent22Fault = getBool(0x920,12,3);
    this->AC2CT_Compressor11Fault = getBool(0x920,12,4);
    this->AC2CT_Compressor12Fault = getBool(0x920,12,5);
    this->AC2CT_Compressor21Fault = getBool(0x920,12,6);
    this->AC2CT_Compressor22Fault = getBool(0x920,12,7);
    this->AC2CT_Conden11Fault = getBool(0x920,13,0);
    this->AC2CT_Conden12Fault = getBool(0x920,13,1);
    this->AC2CT_Conden21Fault = getBool(0x920,13,2);
    this->AC2CT_Conden22Fault = getBool(0x920,13,3);
    this->AC2CT_PreHeater11Fault = getBool(0x920,13,4);
    this->AC2CT_PreHeater12Fault = getBool(0x920,13,5);
    this->AC2CT_PreHeater21Fault = getBool(0x920,13,6);
    this->AC2CT_PreHeater22Fault = getBool(0x920,13,7);
    this->AC2CT_FreshAir11Fault = getBool(0x920,14,0);
    this->AC2CT_FreshAir12Fault = getBool(0x920,14,1);
    this->AC2CT_ReAir11Fault = getBool(0x920,14,2);
    this->AC2CT_FreshAir21Fault = getBool(0x920,14,3);
    this->AC2CT_FreshAir22Fault = getBool(0x920,14,4);
    this->AC2CT_ReAir21Fault = getBool(0x920,14,5);
    this->AC2CT_Cleaner11Fault = getBool(0x920,14,6);
    this->AC2CT_Cleaner21Fault = getBool(0x920,14,7);
    this->AC2CT_EleHeating11Fault = getBool(0x920,15,0);
    this->AC2CT_EleHeating12Fault = getBool(0x920,15,1);
    this->AC2CT_EmcVent1Sta = getBool(0x920,15,3);
    this->AC2CT_EmcVent2Sta = getBool(0x920,15,4);
    this->AC2CT_EmcVentInvFault = getBool(0x920,15,5);
    this->AC2CT_EmcVent1Fault = getBool(0x920,15,6);
    this->AC2CT_EmcVent2Fault = getBool(0x920,15,7);

    //0x930
    this->AC3CT_Lifesignal = getUnsignedInt(0x930,0);
    this->AC3CT_SWVersion1 = getUnsignedChar(0x930,2);
    this->AC3CT_SWVersion2 = getUnsignedChar(0x930,3);
    if(this->CTHM_Mp1HVACOn)
        this->hvacVersionMp1.sprintf("%3d.%-3d", getUnsignedChar(0x930, 2), getUnsignedChar(0x930, 3));
    else
        this->hvacVersionMp1 = QString("0");
    this->AC3CT_Mode = getUnsignedChar(0x930,4);
    this->AC3CT_TempInside = getUnsignedChar(0x930,5);
    this->AC3CT_TempOutside = getUnsignedChar(0x930,6);
    this->AC3CT_TargetTemp = getUnsignedChar(0x930,7);
    this->AC3CT_WorkingStste = getBool(0x930,8,0);
    this->AC3CT_LoadDecState = getBool(0x930,8,1);
    this->AC3CT_HeaterCenCon = getBool(0x930,8,2);
    this->AC3CT_Vent11State = getBool(0x930,10,0);
    this->AC3CT_Vent12State = getBool(0x930,10,1);
    this->AC3CT_Vent21State = getBool(0x930,10,2);
    this->AC3CT_Vent22State = getBool(0x930,10,3);
    this->AC3CT_Compressor11State = getBool(0x930,10,4);
    this->AC3CT_Compressor12State = getBool(0x930,10,5);
    this->AC3CT_Compressor21State = getBool(0x930,10,6);
    this->AC3CT_Compressor22State = getBool(0x930,10,7);
    this->AC3CT_Conden11State = getBool(0x930,11,0);
    this->AC3CT_Conden12State = getBool(0x930,11,1);
    this->AC3CT_Conden21State = getBool(0x930,11,2);
    this->AC3CT_Conden22State = getBool(0x930,11,3);
    this->AC3CT_PreHeater11State = getBool(0x930,11,4);
    this->AC3CT_PreHeater12State = getBool(0x930,11,5);
    this->AC3CT_PreHeater21State = getBool(0x930,11,6);
    this->AC3CT_PreHeater22State = getBool(0x930,11,7);
    this->AC3CT_Vent11Fault = getBool(0x930,12,0);
    this->AC3CT_Vent12Fault = getBool(0x930,12,1);
    this->AC3CT_Vent21Fault = getBool(0x930,12,2);
    this->AC3CT_Vent22Fault = getBool(0x930,12,3);
    this->AC3CT_Compressor11Fault = getBool(0x930,12,4);
    this->AC3CT_Compressor12Fault = getBool(0x930,12,5);
    this->AC3CT_Compressor21Fault = getBool(0x930,12,6);
    this->AC3CT_Compressor22Fault = getBool(0x930,12,7);
    this->AC3CT_Conden11Fault = getBool(0x930,13,0);
    this->AC3CT_Conden12Fault = getBool(0x930,13,1);
    this->AC3CT_Conden21Fault = getBool(0x930,13,2);
    this->AC3CT_Conden22Fault = getBool(0x930,13,3);
    this->AC3CT_PreHeater11Fault = getBool(0x930,13,4);
    this->AC3CT_PreHeater12Fault = getBool(0x930,13,5);
    this->AC3CT_PreHeater21Fault = getBool(0x930,13,6);
    this->AC3CT_PreHeater22Fault = getBool(0x930,13,7);
    this->AC3CT_FreshAir11Fault = getBool(0x930,14,0);
    this->AC3CT_FreshAir12Fault = getBool(0x930,14,1);
    this->AC3CT_ReAir11Fault = getBool(0x930,14,2);
    this->AC3CT_FreshAir21Fault = getBool(0x930,14,3);
    this->AC3CT_FreshAir22Fault = getBool(0x930,14,4);
    this->AC3CT_ReAir21Fault = getBool(0x930,14,5);
    this->AC3CT_Cleaner11Fault = getBool(0x930,14,6);
    this->AC3CT_Cleaner21Fault = getBool(0x930,14,7);
    this->AC3CT_EleHeating11Fault = getBool(0x930,15,0);
    this->AC3CT_EleHeating12Fault = getBool(0x930,15,1);
    this->AC3CT_EmcVent1Sta = getBool(0x930,15,3);
    this->AC3CT_EmcVent2Sta = getBool(0x930,15,4);
    this->AC3CT_EmcVentInvFault = getBool(0x930,15,5);
    this->AC3CT_EmcVent1Fault = getBool(0x930,15,6);
    this->AC3CT_EmcVent2Fault = getBool(0x930,15,7);

    //0x940
    this->AC4CT_Lifesignal = getUnsignedInt(0x940,0);
    this->AC4CT_SWVersion1 = getUnsignedChar(0x940,2);
    this->AC4CT_SWVersion2 = getUnsignedChar(0x940,3);
    if(this->CTHM_Mp2HVACOn)
        this->hvacVersionMp2.sprintf("%3d.%-3d", getUnsignedChar(0x940, 2), getUnsignedChar(0x940, 3));
    else
        this->hvacVersionMp2 = QString("0");
    this->AC4CT_Mode = getUnsignedChar(0x940,4);
    this->AC4CT_TempInside = getUnsignedChar(0x940,5);
    this->AC4CT_TempOutside = getUnsignedChar(0x940,6);
    this->AC4CT_TargetTemp = getUnsignedChar(0x940,7);
    this->AC4CT_WorkingStste = getBool(0x940,8,0);
    this->AC4CT_LoadDecState = getBool(0x940,8,1);
    this->AC4CT_HeaterCenCon = getBool(0x940,8,2);
    this->AC4CT_Vent11State = getBool(0x940,10,0);
    this->AC4CT_Vent12State = getBool(0x940,10,1);
    this->AC4CT_Vent21State = getBool(0x940,10,2);
    this->AC4CT_Vent22State = getBool(0x940,10,3);
    this->AC4CT_Compressor11State = getBool(0x940,10,4);
    this->AC4CT_Compressor12State = getBool(0x940,10,5);
    this->AC4CT_Compressor21State = getBool(0x940,10,6);
    this->AC4CT_Compressor22State = getBool(0x940,10,7);
    this->AC4CT_Conden11State = getBool(0x940,11,0);
    this->AC4CT_Conden12State = getBool(0x940,11,1);
    this->AC4CT_Conden21State = getBool(0x940,11,2);
    this->AC4CT_Conden22State = getBool(0x940,11,3);
    this->AC4CT_PreHeater11State = getBool(0x940,11,4);
    this->AC4CT_PreHeater12State = getBool(0x940,11,5);
    this->AC4CT_PreHeater21State = getBool(0x940,11,6);
    this->AC4CT_PreHeater22State = getBool(0x940,11,7);
    this->AC4CT_Vent11Fault = getBool(0x940,12,0);
    this->AC4CT_Vent12Fault = getBool(0x940,12,1);
    this->AC4CT_Vent21Fault = getBool(0x940,12,2);
    this->AC4CT_Vent22Fault = getBool(0x940,12,3);
    this->AC4CT_Compressor11Fault = getBool(0x940,12,4);
    this->AC4CT_Compressor12Fault = getBool(0x940,12,5);
    this->AC4CT_Compressor21Fault = getBool(0x940,12,6);
    this->AC4CT_Compressor22Fault = getBool(0x940,12,7);
    this->AC4CT_Conden11Fault = getBool(0x940,13,0);
    this->AC4CT_Conden12Fault = getBool(0x940,13,1);
    this->AC4CT_Conden21Fault = getBool(0x940,13,2);
    this->AC4CT_Conden22Fault = getBool(0x940,13,3);
    this->AC4CT_PreHeater11Fault = getBool(0x940,13,4);
    this->AC4CT_PreHeater12Fault = getBool(0x940,13,5);
    this->AC4CT_PreHeater21Fault = getBool(0x940,13,6);
    this->AC4CT_PreHeater22Fault = getBool(0x940,13,7);
    this->AC4CT_FreshAir11Fault = getBool(0x940,14,0);
    this->AC4CT_FreshAir12Fault = getBool(0x940,14,1);
    this->AC4CT_ReAir11Fault = getBool(0x940,14,2);
    this->AC4CT_FreshAir21Fault = getBool(0x940,14,3);
    this->AC4CT_FreshAir22Fault = getBool(0x940,14,4);
    this->AC4CT_ReAir21Fault = getBool(0x940,14,5);
    this->AC4CT_Cleaner11Fault = getBool(0x940,14,6);
    this->AC4CT_Cleaner21Fault = getBool(0x940,14,7);
    this->AC4CT_EleHeating11Fault = getBool(0x940,15,0);
    this->AC4CT_EleHeating12Fault = getBool(0x940,15,1);
    this->AC4CT_EmcVent1Sta = getBool(0x940,15,3);
    this->AC4CT_EmcVent2Sta = getBool(0x940,15,4);
    this->AC4CT_EmcVentInvFault = getBool(0x940,15,5);
    this->AC4CT_EmcVent1Fault = getBool(0x940,15,6);
    this->AC4CT_EmcVent2Fault = getBool(0x940,15,7);

    //0x950
    this->AC5CT_Lifesignal = getUnsignedInt(0x950,0);
    this->AC5CT_SWVersion1 = getUnsignedChar(0x950,2);
    this->AC5CT_SWVersion2 = getUnsignedChar(0x950,3);
    this->AC5CT_Mode = getUnsignedChar(0x950,4);
    this->AC5CT_TempInside = getUnsignedChar(0x950,5);
    this->AC5CT_TempOutside = getUnsignedChar(0x950,6);
    this->AC5CT_TargetTemp = getUnsignedChar(0x950,7);
    this->AC5CT_WorkingStste = getBool(0x950,8,0);
    this->AC5CT_LoadDecState = getBool(0x950,8,1);
    this->AC5CT_HeaterCenCon = getBool(0x950,8,2);
    this->AC5CT_Vent11State = getBool(0x950,10,0);
    this->AC5CT_Vent12State = getBool(0x950,10,1);
    this->AC5CT_Vent21State = getBool(0x950,10,2);
    this->AC5CT_Vent22State = getBool(0x950,10,3);
    this->AC5CT_Compressor11State = getBool(0x950,10,4);
    this->AC5CT_Compressor12State = getBool(0x950,10,5);
    this->AC5CT_Compressor21State = getBool(0x950,10,6);
    this->AC5CT_Compressor22State = getBool(0x950,10,7);
    this->AC5CT_Conden11State = getBool(0x950,11,0);
    this->AC5CT_Conden12State = getBool(0x950,11,1);
    this->AC5CT_Conden21State = getBool(0x950,11,2);
    this->AC5CT_Conden22State = getBool(0x950,11,3);
    this->AC5CT_PreHeater11State = getBool(0x950,11,4);
    this->AC5CT_PreHeater12State = getBool(0x950,11,5);
    this->AC5CT_PreHeater21State = getBool(0x950,11,6);
    this->AC5CT_PreHeater22State = getBool(0x950,11,7);
    this->AC5CT_Vent11Fault = getBool(0x950,12,0);
    this->AC5CT_Vent12Fault = getBool(0x950,12,1);
    this->AC5CT_Vent21Fault = getBool(0x950,12,2);
    this->AC5CT_Vent22Fault = getBool(0x950,12,3);
    this->AC5CT_Compressor11Fault = getBool(0x950,12,4);
    this->AC5CT_Compressor12Fault = getBool(0x950,12,5);
    this->AC5CT_Compressor21Fault = getBool(0x950,12,6);
    this->AC5CT_Compressor22Fault = getBool(0x950,12,7);
    this->AC5CT_Conden11Fault = getBool(0x950,13,0);
    this->AC5CT_Conden12Fault = getBool(0x950,13,1);
    this->AC5CT_Conden21Fault = getBool(0x950,13,2);
    this->AC5CT_Conden22Fault = getBool(0x950,13,3);
    this->AC5CT_PreHeater11Fault = getBool(0x950,13,4);
    this->AC5CT_PreHeater12Fault = getBool(0x950,13,5);
    this->AC5CT_PreHeater21Fault = getBool(0x950,13,6);
    this->AC5CT_PreHeater22Fault = getBool(0x950,13,7);
    this->AC5CT_FreshAir11Fault = getBool(0x950,14,0);
    this->AC5CT_FreshAir12Fault = getBool(0x950,14,1);
    this->AC5CT_ReAir11Fault = getBool(0x950,14,2);
    this->AC5CT_FreshAir21Fault = getBool(0x950,14,3);
    this->AC5CT_FreshAir22Fault = getBool(0x950,14,4);
    this->AC5CT_ReAir21Fault = getBool(0x950,14,5);
    this->AC5CT_Cleaner11Fault = getBool(0x950,14,6);
    this->AC5CT_Cleaner21Fault = getBool(0x950,14,7);
    this->AC5CT_EleHeating11Fault = getBool(0x950,15,0);
    this->AC5CT_EleHeating12Fault = getBool(0x950,15,1);
    this->AC5CT_EmcVent1Sta = getBool(0x950,15,3);
    this->AC5CT_EmcVent2Sta = getBool(0x950,15,4);
    this->AC5CT_EmcVentInvFault = getBool(0x950,15,5);
    this->AC5CT_EmcVent1Fault = getBool(0x950,15,6);
    this->AC5CT_EmcVent2Fault = getBool(0x950,15,7);

    //0x960
    this->AC6CT_Lifesignal = getUnsignedInt(0x960,0);
    this->AC6CT_SWVersion1 = getUnsignedChar(0x960,2);
    this->AC6CT_SWVersion2 = getUnsignedChar(0x960,3);
    if(this->CTHM_Tc2HVACOn)
        this->hvacVersionTc2.sprintf("%3d.%-3d", getUnsignedChar(0x960, 2), getUnsignedChar(0x960, 3));
    else
        this->hvacVersionTc2 = QString("0");
    this->AC6CT_Mode = getUnsignedChar(0x960,4);
    this->AC6CT_TempInside = getUnsignedChar(0x960,5);
    this->AC6CT_TempOutside = getUnsignedChar(0x960,6);
    this->AC6CT_TargetTemp = getUnsignedChar(0x960,7);
    this->AC6CT_WorkingStste = getBool(0x960,8,0);
    this->AC6CT_LoadDecState = getBool(0x960,8,1);
    this->AC6CT_HeaterCenCon = getBool(0x960,8,2);
    this->AC6CT_Vent11State = getBool(0x960,10,0);
    this->AC6CT_Vent12State = getBool(0x960,10,1);
    this->AC6CT_Vent21State = getBool(0x960,10,2);
    this->AC6CT_Vent22State = getBool(0x960,10,3);
    this->AC6CT_Compressor11State = getBool(0x960,10,4);
    this->AC6CT_Compressor12State = getBool(0x960,10,5);
    this->AC6CT_Compressor21State = getBool(0x960,10,6);
    this->AC6CT_Compressor22State = getBool(0x960,10,7);
    this->AC6CT_Conden11State = getBool(0x960,11,0);
    this->AC6CT_Conden12State = getBool(0x960,11,1);
    this->AC6CT_Conden21State = getBool(0x960,11,2);
    this->AC6CT_Conden22State = getBool(0x960,11,3);
    this->AC6CT_PreHeater11State = getBool(0x960,11,4);
    this->AC6CT_PreHeater12State = getBool(0x960,11,5);
    this->AC6CT_PreHeater21State = getBool(0x960,11,6);
    this->AC6CT_PreHeater22State = getBool(0x960,11,7);
    this->AC6CT_Vent11Fault = getBool(0x960,12,0);
    this->AC6CT_Vent12Fault = getBool(0x960,12,1);
    this->AC6CT_Vent21Fault = getBool(0x960,12,2);
    this->AC6CT_Vent22Fault = getBool(0x960,12,3);
    this->AC6CT_Compressor11Fault = getBool(0x960,12,4);
    this->AC6CT_Compressor12Fault = getBool(0x960,12,5);
    this->AC6CT_Compressor21Fault = getBool(0x960,12,6);
    this->AC6CT_Compressor22Fault = getBool(0x960,12,7);
    this->AC6CT_Conden11Fault = getBool(0x960,13,0);
    this->AC6CT_Conden12Fault = getBool(0x960,13,1);
    this->AC6CT_Conden21Fault = getBool(0x960,13,2);
    this->AC6CT_Conden22Fault = getBool(0x960,13,3);
    this->AC6CT_PreHeater11Fault = getBool(0x960,13,4);
    this->AC6CT_PreHeater12Fault = getBool(0x960,13,5);
    this->AC6CT_PreHeater21Fault = getBool(0x960,13,6);
    this->AC6CT_PreHeater22Fault = getBool(0x960,13,7);
    this->AC6CT_FreshAir11Fault = getBool(0x960,14,0);
    this->AC6CT_FreshAir12Fault = getBool(0x960,14,1);
    this->AC6CT_ReAir11Fault = getBool(0x960,14,2);
    this->AC6CT_FreshAir21Fault = getBool(0x960,14,3);
    this->AC6CT_FreshAir22Fault = getBool(0x960,14,4);
    this->AC6CT_ReAir21Fault = getBool(0x960,14,5);
    this->AC6CT_Cleaner11Fault = getBool(0x960,14,6);
    this->AC6CT_Cleaner21Fault = getBool(0x960,14,7);
    this->AC6CT_EleHeating11Fault = getBool(0x960,15,0);
    this->AC6CT_EleHeating12Fault = getBool(0x960,15,1);
    this->AC6CT_EmcVent1Sta = getBool(0x960,15,3);
    this->AC6CT_EmcVent2Sta = getBool(0x960,15,4);
    this->AC6CT_EmcVentInvFault = getBool(0x960,15,5);
    this->AC6CT_EmcVent1Fault = getBool(0x960,15,6);
    this->AC6CT_EmcVent2Fault = getBool(0x960,15,7);

    //0x918
    this->CTAC1_Mode = getUnsignedChar(0x918,0);
    this->CTAC1_TargetTemp = getUnsignedChar(0x918,1);
    this->CTAC1_StartAllowance = getBool(0x918,2,0);
    this->CTAC1_LoadDec = getBool(0x918,2,1);
    this->CTAC1_HeaterCenCont = getBool(0x918,2,2);
    this->CTAC1_SpdMode = getBool(0x918,2,3);
    this->CTAC1_PassengerLoad = getUnsignedChar(0x918,3);
    this->CTAC1_NewWindMode = getUnsignedChar(0x918,4);

    //0x928
    this->CTAC2_Mode = getUnsignedChar(0x928,0);
    this->CTAC2_TargetTemp = getUnsignedChar(0x928,1);
    this->CTAC2_StartAllowance = getBool(0x928,2,0);
    this->CTAC2_LoadDec = getBool(0x928,2,1);
    this->CTAC2_HeaterCenCont = getBool(0x928,2,2);
    this->CTAC2_SpdMode = getBool(0x928,2,3);
    this->CTAC2_PassengerLoad = getUnsignedChar(0x928,3);
    this->CTAC2_NewWindMode = getUnsignedChar(0x928,4);

    //0x938
    this->CTAC3_Mode = getUnsignedChar(0x938,0);
    this->CTAC3_TargetTemp = getUnsignedChar(0x938,1);
    this->CTAC3_StartAllowance = getBool(0x938,2,0);
    this->CTAC3_LoadDec = getBool(0x938,2,1);
    this->CTAC3_HeaterCenCont = getBool(0x938,2,2);
    this->CTAC3_SpdMode = getBool(0x938,2,3);
    this->CTAC3_PassengerLoad = getUnsignedChar(0x938,3);
    this->CTAC3_NewWindMode = getUnsignedChar(0x938,4);

    //0x948
    this->CTAC4_Mode = getUnsignedChar(0x948,0);
    this->CTAC4_TargetTemp = getUnsignedChar(0x948,1);
    this->CTAC4_StartAllowance = getBool(0x948,2,0);
    this->CTAC4_LoadDec = getBool(0x948,2,1);
    this->CTAC4_HeaterCenCont = getBool(0x948,2,2);
    this->CTAC4_SpdMode = getBool(0x948,2,3);
    this->CTAC4_PassengerLoad = getUnsignedChar(0x948,3);
    this->CTAC4_NewWindMode = getUnsignedChar(0x948,4);

    //0x958
    this->CTAC5_Mode = getUnsignedChar(0x958,0);
    this->CTAC5_TargetTemp = getUnsignedChar(0x958,1);
    this->CTAC5_StartAllowance = getBool(0x958,2,0);
    this->CTAC5_LoadDec = getBool(0x958,2,1);
    this->CTAC5_HeaterCenCont = getBool(0x958,2,2);
    this->CTAC5_SpdMode = getBool(0x958,2,3);
    this->CTAC5_PassengerLoad = getUnsignedChar(0x958,3);
    this->CTAC5_NewWindMode = getUnsignedChar(0x958,4);

    //0x968
    this->CTAC6_Mode = getUnsignedChar(0x968,0);
    this->CTAC6_TargetTemp = getUnsignedChar(0x968,1);
    this->CTAC6_StartAllowance = getBool(0x968,2,0);
    this->CTAC6_LoadDec = getBool(0x968,2,1);
    this->CTAC6_HeaterCenCont = getBool(0x968,2,2);
    this->CTAC6_SpdMode = getBool(0x968,2,3);
    this->CTAC6_PassengerLoad = getUnsignedChar(0x968,3);
    this->CTAC6_NewWindMode = getUnsignedChar(0x968,4);


    //0xA10,0xA20,0xA08,0xC10,0xC20,0xC08
    this->AT1CT_LfSign = getUnsignedInt(0xA10,0);
    this->AT2CT_LfSign = getUnsignedInt(0xA20,0);
    this->AT1CT_Test = getUnsignedChar(0xA08,0);
    this->PDS1CT_LfSign = getUnsignedInt(0XC10,0);
    this->PDS2CT_LfSign = getUnsignedInt(0XC20,0);
    this->CTPDS_Function = getUnsignedChar(0xC08,0);

    //0xD10
    this->BC1CT_SwVersion = getUnsignedChar(0xD10,0);
    if(this->CTHM_BCG1On)
    {
        this->bcgVersion1.sprintf("%2d.%-1d", getUnsignedChar(0xD10, 0) / 10, getUnsignedChar(0xD10, 0) % 10);
        //this->bcgVersion1.sprintf("%02d",getUnsignedChar(0xD10, 0));
    }
    else
        this->bcgVersion1 = QString("0");
    this->BC1CT_BatteryTemp = getUnsignedChar(0xD10,1);
    this->BC1CT_BatteryTempFlt = getBool(0xD10,2,0);
    this->BC1CT_DC24VOutputFlt = getBool(0xD10,2,1);
    this->BC1CT_DC110VOutputOverFlt = getBool(0xD10,2,2);
    this->BC1CT_DC110VOutputShortFlt = getBool(0xD10,2,3);
    this->BC1CT_RecOverLoadFlt = getBool(0xD10,2,4);
    this->BC1CT_InputOverCurFlt = getBool(0xD10,2,5);
    this->BC1CT_InputOverVolFlt = getBool(0xD10,2,6);
    this->BC1CT_InputLowVolFlt = getBool(0xD10,2,7);
    this->BC1CT_RadOverTempFlt = getBool(0xD10,3,0);
    this->BC1CT_DC24VInputFuseFlt = getBool(0xD10,3,1);
    this->BC1CT_DC24VModuleFlt = getBool(0xD10,3,2);
    this->BC1CT_DC24VOutputRunSig = getBool(0xD10,3,3);
    this->BC1CT_DC110VOutputFuseFlt = getBool(0xD10,3,6);
    this->BC1CT_WholeInputFuseFlt = getBool(0xD10,3,7);
    this->BC1CT_BatteryVoltage = getUnsignedInt(0xD10,4);
    this->BC1CT_BatteryCurrent = getUnsignedInt(0xD10,6);
    this->BC1CT_NetVoltage = getUnsignedInt(0xD10,8);
    this->BC1CT_CapacityVoltage = getUnsignedInt(0xD10,10);
    this->BC1CT_NetCurrent = getUnsignedInt(0xD10,12);
    this->BC1CT_LifeSignal = getUnsignedInt(0xD10,14);

    //0xD20
    this->BC2CT_SwVersion = getUnsignedChar(0xD20,0);
    if(this->CTHM_BCG2On)
        this->bcgVersion2.sprintf("%2d.%-1d", getUnsignedChar(0xD20, 0) / 10, getUnsignedChar(0xD20, 0) % 10);
    else
        this->bcgVersion2 = QString("0");
    this->BC2CT_BatteryTemp = getUnsignedChar(0xD20,1);
    this->BC2CT_BatteryTempFlt = getBool(0xD20,2,0);
    this->BC2CT_DC24VOutputFlt = getBool(0xD20,2,1);
    this->BC2CT_DC110VOutputOverFlt = getBool(0xD20,2,2);
    this->BC2CT_DC110VOutputShortFlt = getBool(0xD20,2,3);
    this->BC2CT_RecOverLoadFlt = getBool(0xD20,2,4);
    this->BC2CT_InputOverCurFlt = getBool(0xD20,2,5);
    this->BC2CT_InputOverVolFlt = getBool(0xD20,2,6);
    this->BC2CT_InputLowVolFlt = getBool(0xD20,2,7);
    this->BC2CT_RadOverTempFlt = getBool(0xD20,3,0);
    this->BC2CT_DC24VInputFuseFlt = getBool(0xD20,3,1);
    this->BC2CT_DC24VModuleFlt = getBool(0xD20,3,2);
    this->BC2CT_DC24VOutputRunSig = getBool(0xD20,3,3);
    this->BC2CT_DC110VOutputFuseFlt = getBool(0xD20,3,6);
    this->BC2CT_WholeInputFuseFlt = getBool(0xD20,3,7);
    this->BC2CT_BatteryVoltage = getUnsignedInt(0xD20,4);
    this->BC2CT_BatteryCurrent = getUnsignedInt(0xD20,6);
    this->BC2CT_NetVoltage = getUnsignedInt(0xD20,8);
    this->BC2CT_CapacityVoltage = getUnsignedInt(0xD20,10);
    this->BC2CT_NetCurrent = getUnsignedInt(0xD20,12);
    this->BC2CT_LifeSignal = getUnsignedInt(0xD20,14);

    //0xF10
    this->FA1CT_Lifesignal = getUnsignedChar(0xF10,0);
    this->FA1CT_FAComFault = getBool(0xF10,1,0);
    this->FA1CT_TrainExtended = getBool(0xF10,1,1);
    this->FA1CT_SWHighByte = getUnsignedChar(0xF10,2);
    this->FA1CT_SWLowByte = getUnsignedChar(0xF10,3);
    if(this->CTHM_FAU1On)
    {
        this->fauVersion1.sprintf("%3d.%-3d", getUnsignedChar(0xF10, 2), getUnsignedChar(0xF10, 3));
    }
    else
    {
        this->fauVersion1 = QString("0");
    }
    this->FA1CT_Det11FireAlert = getBool(0xF10,4,0);
    this->FA1CT_Det11ComFault = getBool(0xF10,4,1);
    this->FA1CT_Det11FanFault = getBool(0xF10,4,2);
    this->FA1CT_Det11Polluted = getBool(0xF10,4,3);
    this->FA1CT_Det12FireAlert = getBool(0xF10,4,4);
    this->FA1CT_Det12ComFault = getBool(0xF10,4,5);
    this->FA1CT_Det12FanFault = getBool(0xF10,4,6);
    this->FA1CT_Det12Polluted = getBool(0xF10,4,7);
    this->FA1CT_Det13FireAlert = getBool(0xF10,5,0);
    this->FA1CT_Det13ComFault = getBool(0xF10,5,1);
    this->FA1CT_Det13FanFault = getBool(0xF10,5,2);
    this->FA1CT_Det13Polluted = getBool(0xF10,5,3);
    this->FA1CT_Det14FireAlert = getBool(0xF10,5,4);
    this->FA1CT_Det14ComFault = getBool(0xF10,5,5);
    this->FA1CT_Det14FanFault = getBool(0xF10,5,6);
    this->FA1CT_Det14Polluted = getBool(0xF10,5,7);
    this->FA1CT_Det15FireAlert = getBool(0xF10,6,0);
    this->FA1CT_Det15ComFault = getBool(0xF10,6,1);
    this->FA1CT_Det15FanFault = getBool(0xF10,6,2);
    this->FA1CT_Det15Polluted = getBool(0xF10,6,3);
    this->FA1CT_Det16FireAlert = getBool(0xF10,6,4);
    this->FA1CT_Det16ComFault = getBool(0xF10,6,5);
    this->FA1CT_Det16FanFault = getBool(0xF10,6,6);
    this->FA1CT_Det16Polluted = getBool(0xF10,6,7);
    this->FA1CT_Det17FireAlert = getBool(0xF10,7,0);
    this->FA1CT_Det17ComFault = getBool(0xF10,7,1);
    this->FA1CT_Det17FanFault = getBool(0xF10,7,2);
    this->FA1CT_Det17Polluted = getBool(0xF10,7,3);
    this->FA1CT_Det21FireAlert = getBool(0xF10,7,4);
    this->FA1CT_Det21ComFault = getBool(0xF10,7,5);
    this->FA1CT_Det21FanFault = getBool(0xF10,7,6);
    this->FA1CT_Det21Polluted = getBool(0xF10,7,7);
    this->FA1CT_Det22FireAlert = getBool(0xF10,8,0);
    this->FA1CT_Det22ComFault = getBool(0xF10,8,1);
    this->FA1CT_Det22FanFault = getBool(0xF10,8,2);
    this->FA1CT_Det22Polluted = getBool(0xF10,8,3);
    this->FA1CT_Det23FireAlert = getBool(0xF10,8,4);
    this->FA1CT_Det23ComFault = getBool(0xF10,8,5);
    this->FA1CT_Det23FanFault = getBool(0xF10,8,6);
    this->FA1CT_Det23Polluted = getBool(0xF10,8,7);
    this->FA1CT_Det24FireAlert = getBool(0xF10,9,0);
    this->FA1CT_Det24ComFault = getBool(0xF10,9,1);
    this->FA1CT_Det24FanFault = getBool(0xF10,9,2);
    this->FA1CT_Det24Polluted = getBool(0xF10,9,3);
    this->FA1CT_Det31FireAlert = getBool(0xF10,9,4);
    this->FA1CT_Det31ComFault = getBool(0xF10,9,5);
    this->FA1CT_Det31FanFault = getBool(0xF10,9,6);
    this->FA1CT_Det31Polluted = getBool(0xF10,9,7);
    this->FA1CT_Det32FireAlert = getBool(0xF10,10,0);
    this->FA1CT_Det32ComFault = getBool(0xF10,10,1);
    this->FA1CT_Det32FanFault = getBool(0xF10,10,2);
    this->FA1CT_Det32Polluted = getBool(0xF10,10,3);
    this->FA1CT_Det33FireAlert = getBool(0xF10,10,4);
    this->FA1CT_Det33ComFault = getBool(0xF10,10,5);
    this->FA1CT_Det33FanFault = getBool(0xF10,10,6);
    this->FA1CT_Det33Polluted = getBool(0xF10,10,7);
    this->FA1CT_Det34FireAlert = getBool(0xF10,11,0);
    this->FA1CT_Det34ComFault = getBool(0xF10,11,1);
    this->FA1CT_Det34FanFault = getBool(0xF10,11,2);
    this->FA1CT_Det34Polluted = getBool(0xF10,11,3);
    this->FA1CT_Det41FireAlert = getBool(0xF10,11,4);
    this->FA1CT_Det41ComFault = getBool(0xF10,11,5);
    this->FA1CT_Det41FanFault = getBool(0xF10,11,6);
    this->FA1CT_Det41Polluted = getBool(0xF10,11,7);
    this->FA1CT_Det42FireAlert = getBool(0xF10,12,0);
    this->FA1CT_Det42ComFault = getBool(0xF10,12,1);
    this->FA1CT_Det42FanFault = getBool(0xF10,12,2);
    this->FA1CT_Det42Polluted = getBool(0xF10,12,3);
    this->FA1CT_Det43FireAlert = getBool(0xF10,12,4);
    this->FA1CT_Det43ComFault = getBool(0xF10,12,5);
    this->FA1CT_Det43FanFault = getBool(0xF10,12,6);
    this->FA1CT_Det43Polluted = getBool(0xF10,12,7);
    this->FA1CT_Det44FireAlert = getBool(0xF10,13,0);
    this->FA1CT_Det44ComFault = getBool(0xF10,13,1);
    this->FA1CT_Det44FanFault = getBool(0xF10,13,2);
    this->FA1CT_Det44Polluted = getBool(0xF10,13,3);
    this->FA1CT_Det51FireAlert = getBool(0xF10,13,4);
    this->FA1CT_Det51ComFault = getBool(0xF10,13,5);
    this->FA1CT_Det51FanFault = getBool(0xF10,13,6);
    this->FA1CT_Det51Polluted = getBool(0xF10,13,7);
    this->FA1CT_Det52FireAlert = getBool(0xF10,14,0);
    this->FA1CT_Det52ComFault = getBool(0xF10,14,1);
    this->FA1CT_Det52FanFault = getBool(0xF10,14,2);
    this->FA1CT_Det52Polluted = getBool(0xF10,14,3);
    this->FA1CT_Det53FireAlert = getBool(0xF10,14,4);
    this->FA1CT_Det53ComFault = getBool(0xF10,14,5);
    this->FA1CT_Det53FanFault = getBool(0xF10,14,6);
    this->FA1CT_Det53Polluted = getBool(0xF10,14,7);
    this->FA1CT_Det54FireAlert = getBool(0xF10,15,0);
    this->FA1CT_Det54ComFault = getBool(0xF10,15,1);
    this->FA1CT_Det54FanFault = getBool(0xF10,15,2);
    this->FA1CT_Det54Polluted = getBool(0xF10,15,3);
    this->FA1CT_Det61FireAlert = getBool(0xF10,15,4);
    this->FA1CT_Det61ComFault = getBool(0xF10,15,5);
    this->FA1CT_Det61FanFault = getBool(0xF10,15,6);
    this->FA1CT_Det61Polluted = getBool(0xF10,15,7);
    this->FA1CT_Det62FireAlert = getBool(0xF10,16,0);
    this->FA1CT_Det62ComFault = getBool(0xF10,16,1);
    this->FA1CT_Det62FanFault = getBool(0xF10,16,2);
    this->FA1CT_Det62Polluted = getBool(0xF10,16,3);
    this->FA1CT_Det63FireAlert = getBool(0xF10,16,4);
    this->FA1CT_Det63ComFault = getBool(0xF10,16,5);
    this->FA1CT_Det63FanFault = getBool(0xF10,16,6);
    this->FA1CT_Det63Polluted = getBool(0xF10,16,7);
    this->FA1CT_Det64FireAlert = getBool(0xF10,17,0);
    this->FA1CT_Det64ComFault = getBool(0xF10,17,1);
    this->FA1CT_Det64FanFault = getBool(0xF10,17,2);
    this->FA1CT_Det64Polluted = getBool(0xF10,17,3);
    this->FA1CT_Det65FireAlert = getBool(0xF10,17,4);
    this->FA1CT_Det65ComFault = getBool(0xF10,17,5);
    this->FA1CT_Det65FanFault = getBool(0xF10,17,6);
    this->FA1CT_Det65Polluted = getBool(0xF10,17,7);
    this->FA1CT_Det66FireAlert = getBool(0xF10,18,0);
    this->FA1CT_Det66ComFault = getBool(0xF10,18,1);
    this->FA1CT_Det66FanFault = getBool(0xF10,18,2);
    this->FA1CT_Det66Polluted = getBool(0xF10,18,3);
    this->FA1CT_Det67FireAlert = getBool(0xF10,18,4);
    this->FA1CT_Det67ComFault = getBool(0xF10,18,5);
    this->FA1CT_Det67FanFault = getBool(0xF10,18,6);
    this->FA1CT_Det67Polluted = getBool(0xF10,18,7);

    //0xF20
    this->FA2CT_Lifesignal = getUnsignedChar(0xF20,0);
    this->FA2CT_FAComFault = getBool(0xF20,1,0);
    this->FA2CT_TrainExtended = getBool(0xF20,1,1);
    this->FA2CT_SWHighByte = getUnsignedChar(0xF20,2);
    this->FA2CT_SWLowByte = getUnsignedChar(0xF20,3);
    if(this->CTHM_FAU2On)
    {
        this->fauVersion2.sprintf("%3d.%-3d", getUnsignedChar(0xF20,2), getUnsignedChar(0xF20,3));
    }
    else
    {
        this->fauVersion2 = QString("0");
    }
    this->FA2CT_Det11FireAlert = getBool(0xF20,4,0);
    this->FA2CT_Det11ComFault = getBool(0xF20,4,1);
    this->FA2CT_Det11FanFault = getBool(0xF20,4,2);
    this->FA2CT_Det11Polluted = getBool(0xF20,4,3);
    this->FA2CT_Det12FireAlert = getBool(0xF20,4,4);
    this->FA2CT_Det12ComFault = getBool(0xF20,4,5);
    this->FA2CT_Det12FanFault = getBool(0xF20,4,6);
    this->FA2CT_Det12Polluted = getBool(0xF20,4,7);
    this->FA2CT_Det13FireAlert = getBool(0xF20,5,0);
    this->FA2CT_Det13ComFault = getBool(0xF20,5,1);
    this->FA2CT_Det13FanFault = getBool(0xF20,5,2);
    this->FA2CT_Det13Polluted = getBool(0xF20,5,3);
    this->FA2CT_Det14FireAlert = getBool(0xF20,5,4);
    this->FA2CT_Det14ComFault = getBool(0xF20,5,5);
    this->FA2CT_Det14FanFault = getBool(0xF20,5,6);
    this->FA2CT_Det14Polluted = getBool(0xF20,5,7);
    this->FA2CT_Det15FireAlert = getBool(0xF20,6,0);
    this->FA2CT_Det15ComFault = getBool(0xF20,6,1);
    this->FA2CT_Det15FanFault = getBool(0xF20,6,2);
    this->FA2CT_Det15Polluted = getBool(0xF20,6,3);
    this->FA2CT_Det16FireAlert = getBool(0xF20,6,4);
    this->FA2CT_Det16ComFault = getBool(0xF20,6,5);
    this->FA2CT_Det16FanFault = getBool(0xF20,6,6);
    this->FA2CT_Det16Polluted = getBool(0xF20,6,7);
    this->FA2CT_Det17FireAlert = getBool(0xF20,7,0);
    this->FA2CT_Det17ComFault = getBool(0xF20,7,1);
    this->FA2CT_Det17FanFault = getBool(0xF20,7,2);
    this->FA2CT_Det17Polluted = getBool(0xF20,7,3);
    this->FA2CT_Det21FireAlert = getBool(0xF20,7,4);
    this->FA2CT_Det21ComFault = getBool(0xF20,7,5);
    this->FA2CT_Det21FanFault = getBool(0xF20,7,6);
    this->FA2CT_Det21Polluted = getBool(0xF20,7,7);
    this->FA2CT_Det22FireAlert = getBool(0xF20,8,0);
    this->FA2CT_Det22ComFault = getBool(0xF20,8,1);
    this->FA2CT_Det22FanFault = getBool(0xF20,8,2);
    this->FA2CT_Det22Polluted = getBool(0xF20,8,3);
    this->FA2CT_Det23FireAlert = getBool(0xF20,8,4);
    this->FA2CT_Det23ComFault = getBool(0xF20,8,5);
    this->FA2CT_Det23FanFault = getBool(0xF20,8,6);
    this->FA2CT_Det23Polluted = getBool(0xF20,8,7);
    this->FA2CT_Det24FireAlert = getBool(0xF20,9,0);
    this->FA2CT_Det24ComFault = getBool(0xF20,9,1);
    this->FA2CT_Det24FanFault = getBool(0xF20,9,2);
    this->FA2CT_Det24Polluted = getBool(0xF20,9,3);
    this->FA2CT_Det31FireAlert = getBool(0xF20,9,4);
    this->FA2CT_Det31ComFault = getBool(0xF20,9,5);
    this->FA2CT_Det31FanFault = getBool(0xF20,9,6);
    this->FA2CT_Det31Polluted = getBool(0xF20,9,7);
    this->FA2CT_Det32FireAlert = getBool(0xF20,10,0);
    this->FA2CT_Det32ComFault = getBool(0xF20,10,1);
    this->FA2CT_Det32FanFault = getBool(0xF20,10,2);
    this->FA2CT_Det32Polluted = getBool(0xF20,10,3);
    this->FA2CT_Det33FireAlert = getBool(0xF20,10,4);
    this->FA2CT_Det33ComFault = getBool(0xF20,10,5);
    this->FA2CT_Det33FanFault = getBool(0xF20,10,6);
    this->FA2CT_Det33Polluted = getBool(0xF20,10,7);
    this->FA2CT_Det34FireAlert = getBool(0xF20,11,0);
    this->FA2CT_Det34ComFault = getBool(0xF20,11,1);
    this->FA2CT_Det34FanFault = getBool(0xF20,11,2);
    this->FA2CT_Det34Polluted = getBool(0xF20,11,3);
    this->FA2CT_Det41FireAlert = getBool(0xF20,11,4);
    this->FA2CT_Det41ComFault = getBool(0xF20,11,5);
    this->FA2CT_Det41FanFault = getBool(0xF20,11,6);
    this->FA2CT_Det41Polluted = getBool(0xF20,11,7);
    this->FA2CT_Det42FireAlert = getBool(0xF20,12,0);
    this->FA2CT_Det42ComFault = getBool(0xF20,12,1);
    this->FA2CT_Det42FanFault = getBool(0xF20,12,2);
    this->FA2CT_Det42Polluted = getBool(0xF20,12,3);
    this->FA2CT_Det43FireAlert = getBool(0xF20,12,4);
    this->FA2CT_Det43ComFault = getBool(0xF20,12,5);
    this->FA2CT_Det43FanFault = getBool(0xF20,12,6);
    this->FA2CT_Det43Polluted = getBool(0xF20,12,7);
    this->FA2CT_Det44FireAlert = getBool(0xF20,13,0);
    this->FA2CT_Det44ComFault = getBool(0xF20,13,1);
    this->FA2CT_Det44FanFault = getBool(0xF20,13,2);
    this->FA2CT_Det44Polluted = getBool(0xF20,13,3);
    this->FA2CT_Det51FireAlert = getBool(0xF20,13,4);
    this->FA2CT_Det51ComFault = getBool(0xF20,13,5);
    this->FA2CT_Det51FanFault = getBool(0xF20,13,6);
    this->FA2CT_Det51Polluted = getBool(0xF20,13,7);
    this->FA2CT_Det52FireAlert = getBool(0xF20,14,0);
    this->FA2CT_Det52ComFault = getBool(0xF20,14,1);
    this->FA2CT_Det52FanFault = getBool(0xF20,14,2);
    this->FA2CT_Det52Polluted = getBool(0xF20,14,3);
    this->FA2CT_Det53FireAlert = getBool(0xF20,14,4);
    this->FA2CT_Det53ComFault = getBool(0xF20,14,5);
    this->FA2CT_Det53FanFault = getBool(0xF20,14,6);
    this->FA2CT_Det53Polluted = getBool(0xF20,14,7);
    this->FA2CT_Det54FireAlert = getBool(0xF20,15,0);
    this->FA2CT_Det54ComFault = getBool(0xF20,15,1);
    this->FA2CT_Det54FanFault = getBool(0xF20,15,2);
    this->FA2CT_Det54Polluted = getBool(0xF20,15,3);
    this->FA2CT_Det61FireAlert = getBool(0xF20,15,4);
    this->FA2CT_Det61ComFault = getBool(0xF20,15,5);
    this->FA2CT_Det61FanFault = getBool(0xF20,15,6);
    this->FA2CT_Det61Polluted = getBool(0xF20,15,7);
    this->FA2CT_Det62FireAlert = getBool(0xF20,16,0);
    this->FA2CT_Det62ComFault = getBool(0xF20,16,1);
    this->FA2CT_Det62FanFault = getBool(0xF20,16,2);
    this->FA2CT_Det62Polluted = getBool(0xF20,16,3);
    this->FA2CT_Det63FireAlert = getBool(0xF20,16,4);
    this->FA2CT_Det63ComFault = getBool(0xF20,16,5);
    this->FA2CT_Det63FanFault = getBool(0xF20,16,6);
    this->FA2CT_Det63Polluted = getBool(0xF20,16,7);
    this->FA2CT_Det64FireAlert = getBool(0xF20,17,0);
    this->FA2CT_Det64ComFault = getBool(0xF20,17,1);
    this->FA2CT_Det64FanFault = getBool(0xF20,17,2);
    this->FA2CT_Det64Polluted = getBool(0xF20,17,3);
    this->FA2CT_Det65FireAlert = getBool(0xF20,17,4);
    this->FA2CT_Det65ComFault = getBool(0xF20,17,5);
    this->FA2CT_Det65FanFault = getBool(0xF20,17,6);
    this->FA2CT_Det65Polluted = getBool(0xF20,17,7);
    this->FA2CT_Det66FireAlert = getBool(0xF20,18,0);
    this->FA2CT_Det66ComFault = getBool(0xF20,18,1);
    this->FA2CT_Det66FanFault = getBool(0xF20,18,2);
    this->FA2CT_Det66Polluted = getBool(0xF20,18,3);
    this->FA2CT_Det67FireAlert = getBool(0xF20,18,4);
    this->FA2CT_Det67ComFault = getBool(0xF20,18,5);
    this->FA2CT_Det67FanFault = getBool(0xF20,18,6);
    this->FA2CT_Det67Polluted = getBool(0xF20,18,7);

    //0xF08
    this->CTFA_Silence = getBool(0xF08,0,6);
    this->CTFA_Reset = getBool(0xF08,0,7);

    //0xE10
    this->BM1CT_OverVolBattNum = getUnsignedChar(0xE10,0);
    this->BM1CT_LowVolBattNum = getUnsignedChar(0xE10,1);
    this->BM1CT_OverTempBattNum = getUnsignedChar(0xE10,2);
    this->BM1CT_OverResBattNum = getUnsignedChar(0xE10,3);
    this->BM1CT_OverVolAlarmBatt1 = getUnsignedChar(0xE10,4);
    this->BM1CT_OverVolAlarmBatt2 = getUnsignedChar(0xE10,5);
    this->BM1CT_OverVolAlarmBatt1Val = getUnsignedInt(0xE10,6);
    this->BM1CT_OverVolAlarmBatt2Val = getUnsignedInt(0xE10,8);
    this->BM1CT_LowVolAlarmBatt1 = getUnsignedChar(0xE10,10);
    this->BM1CT_LowVolAlarmBatt2 = getUnsignedChar(0xE10,11);
    this->BM1CT_LowVolAlarmBatt1Val = getUnsignedInt(0xE10,12);
    this->BM1CT_LowVolAlarmBatt2Val = getUnsignedInt(0xE10,14);
    this->BM1CT_OverTempAlarmBatt1 = getUnsignedChar(0xE10,16);
    this->BM1CT_OverTempAlarmBatt2 = getUnsignedChar(0xE10,17);
    this->BM1CT_OverTempAlarmBatt1Val = getUnsignedInt(0xE10,18);
    this->BM1CT_OverTempAlarmBatt2Val = getUnsignedInt(0xE10,20);
    this->BM1CT_OverResAlarmBatt1 = getUnsignedChar(0xE10,22);
    this->BM1CT_OverResAlarmBatt2 = getUnsignedChar(0xE10,23);
    this->BM1CT_OverResAlarmBatt1Val = getUnsignedInt(0xE10,24);
    this->BM1CT_OverResAlarmBatt2Val = getUnsignedInt(0xE10,26);
    this->BM1CT_OnlyOverVolAlarm = getBool(0xE10,28,0);
    this->BM1CT_OnlyLowVolAlarm = getBool(0xE10,28,1);
    this->BM1CT_TempAlarm = getBool(0xE10,28,2);
    this->BM1CT_ResAlarm = getBool(0xE10,28,3);
    this->BM1CT_WholeLowVolAlarm = getBool(0xE10,28,4);
    this->BM1CT_InsetOverTempAlarm = getBool(0xE10,28,5);
    this->BM1CT_OverChargeCurAlarm = getBool(0xE10,28,6);
    this->BM1CT_SoftVersion = getUnsignedInt(0xE10,30);

    if(this->CTHM_BMS1On)
        this->bmsVersion1.sprintf("%3d.%-3d", getUnsignedInt(0xE10, 30) / 256, getUnsignedInt(0xE10, 30) % 256);
    else
        this->bmsVersion1 = QString("0");

    //0xE11
    this->BM1CT_LifeSignal = getUnsignedChar(0xE11,0);
    this->BM1CT_AlarmLampSta = getUnsignedChar(0xE11,1);
    this->BM1CT_ChargeVolVal = getUnsignedInt(0xE11,2);
    this->BM1CT_DischargeVolVal = getUnsignedInt(0xE11,4);
    this->BM1CT_InsetTempVal = getUnsignedInt(0xE11,6);
    this->BM1CT_ChargeCurVal = getUnsignedInt(0xE11,8);
    this->BM1CT_DischargeCurVal = getUnsignedInt(0xE11,10);

    //0xE20
    this->BM2CT_OverVolBattNum = getUnsignedChar(0xE20,0);
    this->BM2CT_LowVolBattNum = getUnsignedChar(0xE20,1);
    this->BM2CT_OverTempBattNum = getUnsignedChar(0xE20,2);
    this->BM2CT_OverResBattNum = getUnsignedChar(0xE20,3);
    this->BM2CT_OverVolAlarmBatt1 = getUnsignedChar(0xE20,4);
    this->BM2CT_OverVolAlarmBatt2 = getUnsignedChar(0xE20,5);
    this->BM2CT_OverVolAlarmBatt1Val = getUnsignedInt(0xE20,6);
    this->BM2CT_OverVolAlarmBatt2Val = getUnsignedInt(0xE20,8);
    this->BM2CT_LowVolAlarmBatt1 = getUnsignedChar(0xE20,10);
    this->BM2CT_LowVolAlarmBatt2 = getUnsignedChar(0xE20,11);
    this->BM2CT_LowVolAlarmBatt1Val = getUnsignedInt(0xE20,12);
    this->BM2CT_LowVolAlarmBatt2Val = getUnsignedInt(0xE20,14);
    this->BM2CT_OverTempAlarmBatt1 = getUnsignedChar(0xE20,16);
    this->BM2CT_OverTempAlarmBatt2 = getUnsignedChar(0xE20,17);
    this->BM2CT_OverTempAlarmBatt1Val = getUnsignedInt(0xE20,18);
    this->BM2CT_OverTempAlarmBatt2Val = getUnsignedInt(0xE20,20);
    this->BM2CT_OverResAlarmBatt1 = getUnsignedChar(0xE20,22);
    this->BM2CT_OverResAlarmBatt2 = getUnsignedChar(0xE20,23);
    this->BM2CT_OverResAlarmBatt1Val = getUnsignedInt(0xE20,24);
    this->BM2CT_OverResAlarmBatt2Val = getUnsignedInt(0xE20,26);
    this->BM2CT_OnlyOverVolAlarm = getBool(0xE20,28,0);
    this->BM2CT_OnlyLowVolAlarm = getBool(0xE20,28,1);
    this->BM2CT_TempAlarm = getBool(0xE20,28,2);
    this->BM2CT_ResAlarm = getBool(0xE20,28,3);
    this->BM2CT_WholeLowVolAlarm = getBool(0xE20,28,4);
    this->BM2CT_InsetOverTempAlarm = getBool(0xE20,28,5);
    this->BM2CT_OverChargeCurAlarm = getBool(0xE20,28,6);
    this->BM2CT_SoftVersion = getUnsignedInt(0xE20,30);

    //0xE21
    this->BM2CT_LifeSignal = getUnsignedChar(0xE21,0);
    this->BM2CT_AlarmLampSta = getUnsignedChar(0xE21,1);
    this->BM2CT_ChargeVolVal = getUnsignedInt(0xE21,2);
    this->BM2CT_DischargeVolVal = getUnsignedInt(0xE21,4);
    this->BM2CT_InsetTempVal = getUnsignedInt(0xE21,6);
    this->BM2CT_ChargeCurVal = getUnsignedInt(0xE21,8);
    this->BM2CT_DischargeCurVal = getUnsignedInt(0xE21,10);
    if(this->CTHM_BMS2On)
        this->bmsVersion2.sprintf("%3d.%-3d", getUnsignedInt(0xE20, 30) / 256, getUnsignedInt(0xE20, 30) % 256);
    else
        this->bmsVersion2 = QString("0");
    //Reservation
//    //DI

//    this->RIOM3_DIM1Ch10 = getBool(0x131,21,6);
//    this->RIOM3_DIM1Ch11 = getBool(0x131,21,5);
//    this->RIOM3_DIM1Ch12 = getBool(0x131,21,4);
//    this->RIOM3_DIM1Ch18 = getBool(0x131,20,6);
//    this->RIOM3_DIM1Ch19 = getBool(0x131,20,5);
//    this->RIOM3_DIM1Ch22 = getBool(0x131,20,2);
//    this->RIOM3_DIM1Ch23 = getBool(0x131,20,1);
//    this->RIOM3_DIM1Ch24 = getBool(0x131,20,0);

//    this->RIOM4_DIM1Ch10 = getBool(0x141,21,6);
//    this->RIOM4_DIM1Ch11 = getBool(0x141,21,5);
//    this->RIOM4_DIM1Ch12 = getBool(0x141,21,4);
//    this->RIOM4_DIM1Ch18 = getBool(0x141,20,6);
//    this->RIOM4_DIM1Ch19 = getBool(0x141,20,5);
//    this->RIOM4_DIM1Ch22 = getBool(0x141,20,2);
//    this->RIOM4_DIM1Ch23 = getBool(0x141,20,1);
//    this->RIOM4_DIM1Ch24 = getBool(0x141,20,0);


//    this->RIOM2_DIM1Ch10 = getBool(0x121,21,6);
//    this->RIOM2_DIM1Ch11 = getBool(0x121,21,5);
//    this->RIOM2_DIM1Ch12 = getBool(0x121,21,4);
//    this->RIOM2_DIM1Ch19 = getBool(0x121,20,5);
//    this->RIOM2_DIM1Ch22 = getBool(0x121,20,2);
//    this->RIOM2_DIM1Ch23 = getBool(0x121,20,1);
//    this->RIOM2_DIM1Ch24 = getBool(0x121,20,0);

//    this->RIOM5_DIM1Ch10 = getBool(0x151,21,6);
//    this->RIOM5_DIM1Ch11 = getBool(0x151,21,5);
//    this->RIOM5_DIM1Ch12 = getBool(0x151,21,4);
//    this->RIOM5_DIM1Ch19 = getBool(0x151,20,5);
//    this->RIOM5_DIM1Ch22 = getBool(0x151,20,2);
//    this->RIOM5_DIM1Ch23 = getBool(0x151,20,1);
//    this->RIOM5_DIM1Ch24 = getBool(0x151,20,0);

//    this->RIOM1_DOMIC4 = getBool(0x118,20,4);
//    this->RIOM1_DOMIC5 = getBool(0x118,20,3);
//    this->RIOM1_DOMIC6 = getBool(0x118,20,2);
//    this->RIOM1_DOMIC7 = getBool(0x118,20,1);
//    this->RIOM1_DOMIC8 = getBool(0x118,20,0);
//    this->RIOM1_DOMIC9 = getBool(0x118,19,7);

//    this->RIOM1_DOMIC10 = getBool(0x118,19,6);
//    this->RIOM1_DOMIC11 = getBool(0x118,19,5);
//    this->RIOM1_DOMIC12 = getBool(0x118,19,4);
//    this->RIOM1_DOMIC13 = getBool(0x118,19,3);
//    this->RIOM1_DOMIC14 = getBool(0x118,19,2);
//    this->RIOM1_DOMIC15 = getBool(0x118,19,1);
//    this->RIOM1_DOMIC16 = getBool(0x118,19,0);

//    this->RIOM6_DOMIC4 = getBool(0x168,20,4);
//    this->RIOM6_DOMIC5 = getBool(0x168,20,3);
//    this->RIOM6_DOMIC6 = getBool(0x168,20,2);
//    this->RIOM6_DOMIC7 = getBool(0x168,20,1);
//    this->RIOM6_DOMIC8 = getBool(0x168,20,0);
//    this->RIOM6_DOMIC9 = getBool(0x168,19,7);

//    this->RIOM6_DOMIC10 = getBool(0x168,19,6);
//    this->RIOM6_DOMIC11 = getBool(0x168,19,5);
//    this->RIOM6_DOMIC12 = getBool(0x168,19,4);
//    this->RIOM6_DOMIC13 = getBool(0x168,19,3);
//    this->RIOM6_DOMIC14 = getBool(0x168,19,2);
//    this->RIOM6_DOMIC15 = getBool(0x168,19,1);
//    this->RIOM6_DOMIC16 = getBool(0x168,19,0);

//    this->RIOM2_DOMIC1 = getBool(0x128,20,7);
//    this->RIOM2_DOMIC2 = getBool(0x128,20,6);
//    this->RIOM2_DOMIC3 = getBool(0x128,20,5);
//    this->RIOM2_DOMIC4 = getBool(0x128,20,4);
//    this->RIOM2_DOMIC5 = getBool(0x128,20,3);
//    this->RIOM2_DOMIC6 = getBool(0x128,20,2);
//    this->RIOM2_DOMIC7 = getBool(0x128,20,1);
//    this->RIOM2_DOMIC8 = getBool(0x128,20,0);
//    this->RIOM2_DOMIC9 = getBool(0x128,19,7);

//    this->RIOM2_DOMIC10 = getBool(0x128,19,6);
//    this->RIOM2_DOMIC11 = getBool(0x128,19,5);
//    this->RIOM2_DOMIC12 = getBool(0x128,19,4);
//    this->RIOM2_DOMIC13 = getBool(0x128,19,3);
//    this->RIOM2_DOMIC14 = getBool(0x128,19,2);
//    this->RIOM2_DOMIC15 = getBool(0x128,19,1);
//    this->RIOM2_DOMIC16 = getBool(0x128,19,0);

//    this->RIOM5_DOMIC1 = getBool(0x158,20,7);
//    this->RIOM5_DOMIC2 = getBool(0x158,20,6);
//    this->RIOM5_DOMIC3 = getBool(0x158,20,5);
//    this->RIOM5_DOMIC4 = getBool(0x158,20,4);
//    this->RIOM5_DOMIC5 = getBool(0x158,20,3);
//    this->RIOM5_DOMIC6 = getBool(0x158,20,2);
//    this->RIOM5_DOMIC7 = getBool(0x158,20,1);
//    this->RIOM5_DOMIC8 = getBool(0x158,20,0);
//    this->RIOM5_DOMIC9 = getBool(0x158,19,7);

//    this->RIOM5_DOMIC10 = getBool(0x158,19,6);
//    this->RIOM5_DOMIC11 = getBool(0x158,19,5);
//    this->RIOM5_DOMIC12 = getBool(0x158,19,4);
//    this->RIOM5_DOMIC13 = getBool(0x158,19,3);
//    this->RIOM5_DOMIC14 = getBool(0x158,19,2);
//    this->RIOM5_DOMIC15 = getBool(0x158,19,1);
//    this->RIOM5_DOMIC16 = getBool(0x158,19,0);

//    this->RIOM3_DOMIC3 = getBool(0x138,20,5);
//    this->RIOM3_DOMIC4 = getBool(0x138,20,4);
//    this->RIOM3_DOMIC5 = getBool(0x138,20,3);
//    this->RIOM3_DOMIC6 = getBool(0x138,20,2);
//    this->RIOM3_DOMIC7 = getBool(0x138,20,1);
//    this->RIOM3_DOMIC8 = getBool(0x138,20,0);
//    this->RIOM3_DOMIC9 = getBool(0x138,19,7);
//    this->RIOM3_DOMIC10 = getBool(0x138,19,6);
//    this->RIOM3_DOMIC11 = getBool(0x138,19,5);
//    this->RIOM3_DOMIC12 = getBool(0x138,19,4);
//    this->RIOM3_DOMIC13 = getBool(0x138,19,3);
//    this->RIOM3_DOMIC14 = getBool(0x138,19,2);
//    this->RIOM3_DOMIC15 = getBool(0x138,19,1);
//    this->RIOM3_DOMIC16 = getBool(0x138,19,0);

//    this->RIOM4_DOMIC3 = getBool(0x148,20,5);
//    this->RIOM4_DOMIC4 = getBool(0x148,20,4);
//    this->RIOM4_DOMIC5 = getBool(0x148,20,3);
//    this->RIOM4_DOMIC6 = getBool(0x148,20,2);
//    this->RIOM4_DOMIC7 = getBool(0x148,20,1);
//    this->RIOM4_DOMIC8 = getBool(0x148,20,0);
//    this->RIOM4_DOMIC9 = getBool(0x148,19,7);
//    this->RIOM4_DOMIC10 = getBool(0x148,19,6);
//    this->RIOM4_DOMIC11 = getBool(0x148,19,5);
//    this->RIOM4_DOMIC12 = getBool(0x148,19,4);
//    this->RIOM4_DOMIC13 = getBool(0x148,19,3);
//    this->RIOM4_DOMIC14 = getBool(0x148,19,2);
//    this->RIOM4_DOMIC15 = getBool(0x148,19,1);
//    this->RIOM4_DOMIC16 = getBool(0x148,19,0);

//    this->RIOM1_AXC3 = getBool(0x111,4,0);
//    this->RIOM1_AXC4 = getBool(0x111,6,0);
//    this->RIOM6_AXC3 = getBool(0x161,4,0);
//    this->RIOM6_AXC4 = getBool(0x161,6,0);

    this->bcuCB01Version1.sprintf("%2d.%-2d", this->getSignedChar(0xF413, 11) / 16, this->getSignedChar(0xF413, 11) % 16);
    this->bcuMVBVersion1.sprintf("%2d.%-2d", this->getSignedChar(0xF413, 12) / 16, this->getSignedChar(0xF413, 12) % 16);
    this->bcuEB01Version1.sprintf("%2d.%-2d", this->getSignedChar(0xF413, 13) / 16, this->getSignedChar(0xF413, 13) % 16);

    this->bcuCB01Version2.sprintf("%2d.%-2d", this->getSignedChar(0xF443, 11) / 16, this->getSignedChar(0xF443, 11) % 16);
    this->bcuMVBVersion2.sprintf("%2d.%-2d", this->getSignedChar(0xF443, 12) / 16, this->getSignedChar(0xF443, 12) % 16);
    this->bcuEB01Version2.sprintf("%2d.%-2d", this->getSignedChar(0xF443, 13) / 16, this->getSignedChar(0xF443, 13) % 16);
}
// collect all ports to list
void Database::insertPort(const QList<struct port *> ports)
{
    foreach (struct port *pointer, ports)
    {

        bool flag = false;

        foreach (struct port *temp, this->allPorts)
        {
            if (temp->address == pointer->address)
            {
                flag = true;
                break;
            }
        }

        if(true == flag)
        {
            _LOG << "mvb port of" << pointer->address << "has already been in the port list";
        }
        else
        {
            this->allPorts.append(pointer);
        }
    }
}


//insert by different ports
void Database::installPorts()
{
    // create
    this->insertPort(this->riomPorts);
    this->insertPort(this->ccuPortsA);
    this->insertPort(this->ccuPortsB);
    this->insertPort(this->ermPorts);
    this->insertPort(this->bcu1Ports);
    this->insertPort(this->bcu3Ports);
    this->insertPort(this->bcu4Ports);
    this->insertPort(this->bcu6Ports);
    this->insertPort(this->dcuPorts);
    this->insertPort(this->sivPorts);
    this->insertPort(this->pisPorts);
    this->insertPort(this->hvacPorts);
    this->insertPort(this->atcPorts);
    this->insertPort(this->pdsPorts);
    this->insertPort(this->bcgPorts);
    this->insertPort(this->fauPorts);
    this->insertPort(this->bmsPorts);
    this->insertPort(this->edcu1Ports);
    this->insertPort(this->edcu2Ports);
    this->insertPort(this->userDefinePort);
    this->insertPort(this->pisDefaultPort);
    this->insertPort(this->bcuDefaultPort);
    this->insertPort(this->ermDefaultPort);

    if (1 == this->hmiPosition)
    {
        this->insertPort(this->hmiA1Ports);
    }
    else if (2 == this->hmiPosition)
    {
        this->insertPort(this->hmiA2Ports);
    }
    _LOG << "there are" << this->allPorts.length() << "mvb ports in the list";

    // insert ports into the map
    foreach (struct port *pointer, allPorts)
    {
        if (ports.contains(pointer->address) == false)
        {
            struct port_data *temp = new struct port_data();
            ports.insert(pointer->address, temp);
        }
    }

    // clear refresh time if the port type is source
    if (1 == this->hmiPosition)
    {
        this->ports[0x310]->time = 65535 - 256;
        this->ports[0x311]->time = 65535 - 256;
        this->ports[0x312]->time = 65535 - 256;
        this->ports[0x313]->time = 65535 - 256;
    }
    else if (2 == this->hmiPosition)
    {
        this->ports[0x320]->time = 65535 - 256;
        this->ports[0x321]->time = 65535 - 256;
        this->ports[0x322]->time = 65535 - 256;
        this->ports[0x323]->time = 65535 - 256;
    }
}


bool Database::getBool(unsigned short int port, unsigned short byteOffset, unsigned short bitOffset)
{
    unsigned char *pointer = NULL, value = 0;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if(byteOffset % 2 == 1)
        {
             pointer = (unsigned char *)(this->ports[port]->data);
             value = *(pointer + byteOffset - 1);
        }

        else
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            value = *(pointer + byteOffset + 1);
        }
    }
    else
    {
        _LOG << "the bit offset is too long" << port;
        return false;
    }


    if (bitOffset < 8)
    {
        value = value & (0x80 >> bitOffset);
    }

    else
    {
        _LOG << "the bit offset is too long" << port;

        return false;
    }
    if (value == 0)
       return false;

    else
       return true;
}


unsigned char Database::getUnsignedChar(unsigned short int port, unsigned short byteOffset)
{
    unsigned char *pointer = NULL, value = 0;

    if (this ->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            value = *(pointer + byteOffset - 1);
        }
        else
        {
             pointer = (unsigned char *)(this->ports[port]->data);
             value = *(pointer + byteOffset + 1);
        }

        return value;
    }
    else
    {
        _LOG << "there no port in the database or byte offset is too long" << port;

        return 0;
    }
}


unsigned short int Database::getUnsignedInt(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL;
    unsigned short int value = 0;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        pointer = (unsigned char *)(this->ports[port]->data);
        value = *(unsigned short int *)(pointer + byteOffset);

        return value;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

signed char Database::getSignedChar(unsigned short int port, unsigned short int byteOffset)
{
    signed char *pointer = NULL, value = 0;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (signed char *)(this->ports[port]->data);
            value = *(pointer + byteOffset - 1);
        }
        else
        {
            pointer = (signed char *)(this->ports[port]->data);
            value = *(pointer + byteOffset + 1);
        }

        return value;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}
signed short int Database::getSignedInt(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL;
    signed short int value = 0;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        pointer = (unsigned char *)(this->ports[port]->data);
        value = *(signed short int *)(pointer + byteOffset);

        return value;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

quint32 Database::getUnsignedInt32(unsigned short int port, unsigned short int byteOffset)
{
    if (this->ports.contains(port) && byteOffset < 32)
    {
        unsigned short int temp[2] = {0};

        temp[0] = this->getUnsignedInt(port, byteOffset + 2);
        temp[1] = this->getUnsignedInt(port, byteOffset);

        return *(quint32 *)temp;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

void Database::setUnsignedInt32(unsigned short int port, unsigned short int byteOffset, quint32 signal)
{
    if (this->ports.contains(port) && byteOffset < 29)
    {
        this->setUnsignedInt(port, byteOffset, *((unsigned short int *)(&signal) + 1));
        this->setUnsignedInt(port, byteOffset + 2, *(unsigned short int *)(&signal));
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;
    }
}


void Database::setBool(unsigned short int port, unsigned short byteOffset, unsigned short bitOffset, bool signal)
{
    unsigned char *pointer = NULL;

    if (this ->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            pointer = pointer + byteOffset - 1;
        }
        else
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            pointer = pointer + byteOffset + 1;
        }
    }
    else
        _LOG << "there no port in the database or byte offset is too long" << port;

    if (bitOffset > 8)
    {
        _LOG << "the bit offset is too long" << port;
        return ;
    }

    if (true == signal)
    {
        *pointer = *pointer | (0x80 >> bitOffset);
    }

    else
    {
        *pointer = *pointer & ~(0x80 >> bitOffset);
    }
}

void Database::setUnsignedChar(unsigned short int port, unsigned short int byteOffset, unsigned char signal)
{
    unsigned char *pointer = NULL;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            *(pointer + byteOffset - 1) = signal;
        }
        else
        {
            pointer = (unsigned char *)(this->ports[port]->data);
            *(pointer + byteOffset + 1) = signal;
        }
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;
    }
}

void Database::setSignedChar(unsigned short int port, unsigned short int byteOffset, signed char signal)
{
    signed char *pointer = NULL;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (signed char *)(this->ports[port]->data);
            *(pointer + byteOffset - 1) = signal;
        }
        else
        {
            pointer = (signed char *)(this->ports[port]->data);
            *(pointer + byteOffset + 1) = signal;
        }
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;
    }
}

void Database::setUnsignedInt(unsigned short int port, unsigned short int byteOffset, unsigned short int signal)
{
    unsigned char *pointer = NULL;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        pointer = (unsigned char *)(this->ports[port]->data);
        *(unsigned short int *)(pointer + byteOffset) = signal;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;
    }
}

void Database::setSignedInt(unsigned short int port, unsigned short int byteOffset, signed short int signal)
{
    unsigned char *pointer = NULL;

    if (this->ports.contains(port) && byteOffset < 32)
    {
        pointer = (unsigned char *)(this->ports[port]->data);
        *(signed short int *)(pointer + byteOffset) = signal;
    }
    else
    {
        _LOG << "there no port in the databse or byte offset is too long" << port;
    }
}

bool Database::checkCcuOnline(unsigned short int lifeSignal)
{
    static unsigned short int oldLifeSignal = 0, counter = 0;

    if (oldLifeSignal == lifeSignal)
    {
        counter ++;
    }
    else
    {
        counter = 0;
    }

    oldLifeSignal = lifeSignal;

    if (counter > 1000)
    {
        counter = 100;
    }

    if (counter > 10)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Database::checkCcuSwitch(unsigned short lifeSignal)
{
    static unsigned short int oldLifeSignal = 0, counter = 0, temp = 0;

    if (oldLifeSignal == lifeSignal)
    {
        temp = 1;
    }
    else if(temp == 1)
    {
        temp = 0;
        counter ++;
    }

    oldLifeSignal = lifeSignal;

    if (counter > 1000)
    {
        counter = 100;
    }
    return counter;
}

void Database::setFireButtonState(bool state)
{
    this->ifFire = state;
}

bool Database::getFireButtonState()
{
    return this->ifFire;
}

unsigned short int Database::getMvbCycleByPort(unsigned short int portNumber)
{
    foreach (struct port *pointer, this->allPorts)
    {
        if (pointer->address == portNumber)
        {
            return pointer->cycle;
        }
    }
    return 0;
}


