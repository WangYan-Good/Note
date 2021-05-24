MINIMUM FILES FOR HII DRIVER
.C          .h        .uni        .vfr        .inf

1. EDK II HII
  HII DataBase    <--------------     HII Driver    <--------       BDS UI  <-----    System Reset
    Consistes of IFR / String / Font                                            |
    Which has been submitted by varying HII Drivers          |
                                                                                                      |
  Setup Brower         <---------------------------------------------------|
   | Provides User Interface Support
   | Callable by a Protocol Interface
   |
   |------------>   user changes -------------->  NVRAM  ------------>  HII Driver

2. HOW: UEFI HII PROTOCOLS
  Sections 29-31 the UEFI 2.x Specifiction

3. HII DATABASE OVERVIEW
  HII Data Store
    Data: Fonts, Strings, Image, Forms, GUID, Keyboard Layout, Device Paths

  HII Protocols
    Font Protocol
    String Protocol
    Image Protocol
    Database Protocol

  HII Browser Engine Protocols
    Configuration Routing Protocol
    Configuration Access Protocol
    Form Browser 2 Protocol

4. UEFI HII PROTOCOLS
  Font Protocol:
    String to Image, String ID to Image, Get Glyph, Get Font Info

  String Protocol:
    New - Get - Set -String;
    Get Language & 2nd Language

  Image Protocl:
    New - Get - Set Image;
    Draw Image, Draw Image ID

  Database Protocol:
    New - Remove - Update - List - Export Lists - Get Handle Package
    Register, Unregister Package Notify
    Find - Get - Set - Keyboard layout

5. UEFI DRIVER INITIALIZATION PROCESS
  1) Produce Config Access Protocols
  2) Install Device path protocol
  3) Install Config Access Protocol
  4) Create Package List

6. LAB FOR HII
  Use the Lab guide to follow the steps Adding HII to a UEFI Driver from the UEFI Driver Wizard Lab
    link to pdf Linux
    Link to pdf Windows
  Perquisite UEFI Driver Porting Lab


