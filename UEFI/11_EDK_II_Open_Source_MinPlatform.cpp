EDK II Open Board Platform Design for Intel Architecture (IA)

1. LESSON OBJECTIVE
  Introduce Minimum Platform Architecture (MPA)
  Explain the EDK II Open board platforms infrastructure & focus areas
  Describe Intel(R) FSP with the EDK II open board platforms

  DESIRED USE CASES -- Open Source EDK II Platforms
    Developers need a way to turn on and off of a feature.
    Developers need a way to get platform configuration data.
    Developers need to do porting work from an existing board to a new board.

  Why can not the platform tree structures bear more similarity ?

  GOALS
  Minimum Platform Architecture (MPA)

  Structured: Enable developers to consistently navigate code, boot flow, and the functional results.

  Approachable: Enable developers to quickly produce a baseline that is extensible with minimal UEFI or EDK II knowledge.

  Portable: Minimize coupling between common, silicon, platform, board, and feature packages

  Reusable: Enable large granularity binary reuse (FV binaries)

  Testable: Enable validating the correctness of a port.

  Design open source EDK II Intel Architecture firmware.

  Why Move to Open Source?
  Goal:
    Enable improvements in quality and security for Intel products
    Enable vertically integrated open solutions

  Benefits:
    Allow improved customer engagements
    Builds transparency and trust
    Reduce overhead to transition from internal to external
    Deploy fixes across the ecosystem more rapidly

  Easier to access, understand, fix & optimize means improved product quality.

  What are Minimum Platform Stages?
  Stage I Minimal Debug
    External Debugger Support
    Serial Port
    Progress and Error reporting

  Stage II Memory Functional
    Basic HW Initialization
    Memory Lnitialized

  Stage III Boot to UEFI Shell
    Includes Serial Console I/O
    UEFI Shell command line interface

  Stage IV Boot to OS
    Basic ACPI Table Initialization
    SMM support
    OS kernal minimal functionality

  Stage V Security Enable
    Authenticated Boot
    Security Registers Locked

  Stage VI Advanced feature Selection
    Features Selected Based on System-Specific Usage
    BIOS Setup
    Capsule Update

  Stages reflect firmware development lifecycle and how a system bootstraps itself.

  Four Focus Areas
  Tree Structure

  Feature
    Staged Minimal Baseline
    Feature ON/OFF
     Debug
     I/O Devices
     User Interface
     ...

  Configuration
    Satged
    Defined PCD
    Policy Hob/PPI/Protocol

  Porting
    Staged
    GPIO
    SIO
    ACPI

  Minimum Platform Organization
    Common: No direct HW requirements
    Platform: Enable a specific platform's capabilities.
    Board: Board specific code
    Silicon: Hardware specific code
    Features: Advanced features of platform functionality that is non-essential for "basic OS boot"

  Package Organization Example
    MinPlatformPkg: Common-Boot flow, well defined interface
    BoardModulePkg: Board-Generic board functionality ( e.g. COMS access code ) - staging to EDk II
    XXXOpenBoardPkg: Platform Xxx* - Board - specific details: GPIOs, memory config, audio verb tables, etc.
    XxxSiliconPkg: Silicon - Hardware specific code for Xxx
    YyyFeaturePkg: Features - Advanced functional features.

  Feature Selection
  There are three phases of feature selection
  Minimum: Manage Stage I-V options
  Advanced Feature Selection: Add rich feature sets (Stage VI)
  Optimization: Remove undesired features(Stage VII)
  Select features through build, prune in binary

  Minimum Platform Feature Selection
  Minimum Platform
    Minimum feature selection should be exclusively implemented as Platform Configuration Database (PCD)
    Required PCD are identified in the MPA apecification
    PCDs:
      Declared with defaults in DEC files in defferent packages
      Modified in DSC file for the board, if defferent than the default value.

  Silicon -FSP Integration from <Generation> FspBinPkg
  documentation package
    All initial porting features selection should be done this way.

  Advanced Feature Selection
    Advanced features implement DSC and FDF files that you can include in your board DSC and FDF files in the correct spots.

    OpenBoardPkg.dsc File
    ...
    <End-of-File>
      !include YyyAdvancedPkg.dsc

    OpenBoardPkg.fdf File
      FV Advanced Pre-Mem
        !include YyyAdvancedPkgPreMem.fdf
      FV Advanced Post-Mem
        !include YyyAdvancedPkgPostMem.fdf
      FV Advanced Late
        !include YyyAdvancedPkgLate.fdf
      FV Advanced <- ( Pre-Mem + Post-mem + Late )

  Build Control Files
  DSC files: control what gets compiled and linked
  FDF files: control what gets put int the system FLASH image

  Configuration Options
  There might be many sources of platform configuration data.
  PI PCD                                    | Configuration Block           | COMS
  UEFI Variable                             | Global NVS                    | MACRO
  FSP UPD-Silicon Policy Hob/PPI/Protocol   | Platform signed data blob

  How to Map PCD to Configuration Data
  Using "Callback" mechanism to convert PCD to configuration data
  Platform driver should use PcdGet() to retrieve policy data, and PcdSet() to update policy data.

  PlatformInit                                               ConfigConvert
  PcdGet(                                                     PcdSet( ConfigurationX, Variable )
      ConfigurationX        --------->       PCD Data X       ------------>                      ------------>  Variable / Signed, Data blob / (Policy Ppi/Hob)
  )

  UEFI Fireware Volumes (FV) - Revies
  Platform Initialization - Firmware volume
    Basic storage repository for data and code is the Firmware Volume (FV)
    Each FV is organized into a file system, each with attributes
    One or more Firmware File Sections (FFS) files are combined into a FV
    Flash Device may contain one or more FVs.
    .FDF file controls the layout ->  .FD image(s)

    - Fireware Volume
     Modules organized by Firmware Volumes according to the different boot stages

     Standardize FV By Stages
     Pre-Memory: FvPreMemory - The PEIM dispatched before the memory initialization. Also included FSP - FV
     Post Memory: FvPostMemory - The PEIM dispatched after the memory intialization. Also include FSP - FV
     UEFI Boot: FvUefiBoot - The DXE driver supporting UEFI boot, such as boot to UEFI shell.
     OS Boot: FvOsBoot - The DXE driver supporting UEFI OS boot, such as UEFI Windows.
     Security: FvSecurity - The security related modules, such as UEFI Secure boot, TPM etc.
     Advanced: FvAdvanced - The advanced feature modules, such as UEFI network, IPMI etc.




















