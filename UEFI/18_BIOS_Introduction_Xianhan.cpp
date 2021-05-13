BIOS Introduction

1. outline
  Introduction
  BIOS POSt & Boot Bolck
  BIOS ROM Structure
  BIOS Runtime

2. What is BIOS ?
  --Basic Imput, Output System
  --Provide services for accessing devices

  First Program executed by CPU
  Language used:
    --Assembly: Legacy BIOS
    --C: UEFI BIOS ( Unified Extensible Firmware Interface )

  BIOS main functions:
    --Memory Controller & DIMM Initialization
    --Devices Initialization & Resource Allocation
    --Prepare Environment for booting to OS
    --Power Management & ACPI

  What is BIOS ? ( Con't )
  BIOS stored in BIOS ROM ( Read-Only Memory )
  BIOS ROM is Flash
    --Read, Write, Erase, NOR Flash

  CPU fetches instructions in ROM after power-on
  ROM is always on top of CPU Memory Space
    --ex. 2MB ROM, FFE00000h~FFFFFFFFh
    --ex. 1MB ROM, FFF00000h~FFFFFFFFh

  After Power-On, CPU starts at the address FFFFFFF0h

3. Post - Power-On-Self-Test
  -Power-On System
  -CPU jumps to the 1st Instruction in BIOS ROM
    FFFFFFF0h in CPU Memory Space
  -Chipset Initialization
  -Memory Controller & DIMM Initialization
  -More Chipset Initialization
  -Device Initialization & Resource Allocation
  -BIOS Services Ready ( INT Services, UEFI Services )
  -Boot to OS

  BIOS POST divided into two phases:
    -- Boot block phase
    -- Main BIOS phase

  UEFI POST divided into 4 phases:
    -- SEC ( Security ) phase
    -- PEI ( Pre-EFI ) phase
    -- DXE ( Driver Execution ) phase
    -- BDS ( Boot Device Select ) phase

  Boot Block phase:
    -- Sec, PEI phase

  Main BIOS phase:
    -- DXE, BDS phase

  Why BIOS POST divided into two phases ?

  What is the division-point

    BIOS POST:
      - Power-On S ystem
      - CPU jumps to the 1st Instruction in BIOS ROM
      - Chipset Initialization
      - Memory Controller & DIMM Initialization
      - More Chipset Initialization
      - Device Initialization & Resource Allocation
      - BIOS Services Ready ( INT Services, UEFI Services )
      - Boot to OS

  Memory Init is the point deviding two phases

  Almost tasks in Boot Block run without Memory
    - Exception: CRISIS Recovery
    - CRISIS Recovery needs Memory to store new BIOS Image

  UEFI PEI phase also uses C Language
    - It means Memory ( Stack, Heap ) need

  How to overcome the problem ?
    - Using CPU Cache as RAM ( CAR )

  Almost Codes in Boot Block run in BIOS ROM

4. BIOS ROM Structure
  BIOS ROM divided into 4 parts or more: (UEFI):
    - EC Area
    - NVRAM
    - MAIN
    - Boot Block
    - ...

    EC Area
    EC F/W initializes some devices, monitors devices' status, controls devices
    Ex.
      - Thermal Sensor
      - FAN
      - Battery
      - Keyboard
      - PS2 Mouse ( Touchpad )
      - ...

    NVRAM Area
    BIOS Setting, Factory Configuration, ...
    In Legacy BIOS period, BIOS uses COMS SRAM in Chipset as NVRAM ( ~246 bytes )
    NVRAM Size: 64 KB~

    Main & Boot Block

    CPU fetches 1st Intr. in Boot Block ( FFFFFFF0h )

    Almost modules in BB aren't compressed

    All modules in MAIN are compressed

    UEFI 将BIOS ROM 看成是文件系统，FV 相当于Partition ( FV_BB, FV_MAIN )
    Partition中的文件名为GUID

    UEFI treats BIOS ROM as File System
    Firmware Volume ( FV ) similar to Partiton
    Each Module has GUID as file name
    Data in NVRAM use GUID as variable names
    GUID - Global Unique ID
      - GUID Size: 16 bytes

    typedef struct {
        UINT32 Data1;
        UINT16 Data2;
        UINT16 Data3;
        UINT8   Data4[8];
    } EFi_GUID;

5. BIOS Runtime
  In Runtime, OS & Drivers will call BIOS services ( by ACPI or INT Services in VM8086 mode )
    - BIOS is still alive in runtime

  OS should reserve memory occupied by BIOS
    - BIOS Runtime Codes & Data
    - Code & Data used only in POST are recycled by OS

  How OS konw which memery area used by BIOS ?

  How OS know which memory area is free ?
    - Legacy BIOS Interface:
      INT 15h E820 Service
    - UEFI Interface:
      Function "GetMemoryMap" in UEFI Boot Services Table

