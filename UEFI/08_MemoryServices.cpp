MEMORY SERVICES OVERVIEW
1. AGENDA
  Memory Services
  Memory Layout
  Shell command: memmap

2. MEMORY SERVICES
  PEI on CAR and System Memory
    CreateHob
    AllocatePool(limit: 64KB): Light version. Don't support memory type. No FreePool API. It bases on HOB
    AllocatePages / FreePages: Don't support memory allocate type

  DXE on System Memory
    AllocatePool / FreePool
    AllocatePages / FreePages

  SMM on SMRAM
    AllocatePool / FreePool: support runtime data / code only
    AllocatePages / FreePages: support runtime data / code only

3. HOB TYPE
  EFI_HOB_TYPE_HANDOFF
  EFI_HOB_TYPE_MEMORY_ALLOCATION
    Describe the allocated page memory base address, size and type
  EFI_HOB_TYPE_RESOURCE_DESCRIPTOR
    Describe the System resource snd attribute, include memory, IO and MMIO
  EFI_HOB_TYPE_GUID_EXTENSION
    Main usage is to share data between pre-memory and after-memory
  EFI_HOB_TYPE_FV
    FV reported to DXE phase
  EFI_HOB_TYPE_CPU
  EFI_HOB_TYPE_MEMORY_POOL

4. RESOURCE HOB
  Type:
    EFI_RESOURCE_SYSTEM_MEMORY
    EFI_RESOURCE_MEMORY_MAPPED_IO
    EFI_RESOURCE_IO
    EFI_RESOURCE_FIRMWARE_DEVICE
    EFI_RESOURCE_MEMORY_MAPPED_IO_PORT
    EFI_RESOURCE_MEMORY_RESERVED
    EFI_RESOURCE_IO_RESERVED

  Attributes:
    EFI_RESOURCE_ATTRIBUTE_PRESENT
    EFI_RESOURCE_ATTRIBUTE_INITALIZED
    EFI_RESOURCE_ATTRIBUTE_TESTED
    EFI_RESOURCE_ATTRIBUTE_PERSISTENT

5. MEMORY TYPE
  EfiConventionalMemory: Avaliable memory space
  EfiLoaderCode: UEFI Application code
  EfiLoaderData: UEFI Application data
  EfiBootServicesCode: UEFI / PEI / DXE driver
  EfiBootServicesData: UEFI / PEI / DXE driver allocated memory
  EfiPersistentMemory

  EfiRuntimeServicesCode: Runtime driver. It can't be used by OS.
  EfiRuntimeServicesData: Runtime data. It can't be used by OS.

  EfiReservedMemoryType: Reserved memory in BIOS. It can't be used by OS.
  EfiACPIReclaimMemory: Used by ACPI
  EfiACPIMemoryNVS: Used by ACPI. It can't be used by OS.

  EfiMemoryMappedIO
  EfiMemoryMappedIOPortSpace

6. DXE / SMM: PAGE ALLOCATION TYPE
  AllocateAnyPages: Allocate memory in the available memory space
  AllocateMaxAddress: Allocate memory based on the specified max address
  AllocateAddress: Allocate memory at the specified base address

7. PEI MEMORY LAYOUT

8. DXE MEMORY LAYOUT
  Top reserved memory ranges are specified by EFI_MEMORY_TYPE_INFORMATION
  Memoey Allocation is from top to bottom
  Memory allocation is from its reserved memory type range. If no enough, it will be allocated from the remaining memory.
  Pool and Page are in the same memory range.
  PEI Memory is reported in PEI phase.
