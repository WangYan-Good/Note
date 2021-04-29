EDK II Modules: Libraried, Drivers & Applications

1.What is a EDK II Module

  MODULES: Building blocks of EDK II
  Smallest separate object complied in EDK II

  Most Used Module Types
  PEI_CORE      UEFI_APPLICATION              DXE_CORE
  BASE               DXE_RUNTIME_DRIVER
  PEIM                 UEFI_DRIVER                         DXE_DRIVER

  EDK II LIBRARY MODULES

  "NULL" Library Class
  Special Cases

  Locating Library Classes
  Library based upon
    1. Industry specs (UEFI, etc.)
          MdePkg / MdeModulePkg
    2. Features
          NetworkPkg / SecurityPkg

  Use the  package help files (.CHM) to find a library or function
  Example: MdePkg.chm

  Serch WorkSpace (.INF) "LIBRARY_CLASS"

  Library Instance Hierarchy
  Form: a hierarchy similar to UEFI drivers
  Link:   your moudle to another

  Commonly Used Base Library Classes
  BaseLib   DebugLib      UefiDriverEntryPoint    ...

  EDK II UEFI APPLICATION

  Defining a UEFI Application
  Characteristics of a UEFI Loadable Image
    1. Loaded by UEFI load, just like drivers
    2. Does not register protocols
    3. Consumes protocols
    4. Typically exits when completed ( user driven )
    5. Same set of interfaces as drivers available

  UEFI Loadable Image Usages
    1. Platform Diagnostics
    2. Factory Diagnostics
    3. Utilities
    4. Driver Prototyping
    5. "Platform" Applications
    6. Portable Across Platforms ( IA32, X64, ARM, Itanium, etc. )

  Execution Application


2.Use EDK II libraries to write UEFI application / drivers
    Application Files Placement
      1. Application source files can be located anywhere in the EDK II workspace including PACKAGES_PATH
      2. All code and include files go under a signle directory containing the driver INF
      3. EDK II Sample Applications can be found here: edk2 / MdemdulePkg / Applicaiton
      4. Typically, modules reside within a package:
          MyWorkSpace /
              edk2 /
                  MyPkg /
                      Application /
                          MyApp / MyApp.c, MyApp.inf

  Changes for a UEFI Driver Module

  Application can be converted to a driver
  But ... It remains in memory after it runs

  UEFI Driver Module requirements:
    1. Driver Buing Protocol
    2. Component Name2 Protocol ( recommended )

  DXE / PEIM / other Driver requirements

3.How to Define a UEFI application

4.Differences between UEFI Application / Drivers INF file
