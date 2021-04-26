FIRWARE STORGE AND VERIABLE
1.Firmware Storage
  Platform Initialization Firmware Volume
    Basic storage repository for fata and code is the FV
    Each FV is organized into a file system,each with attributes

  Fiemware File System format
    A firmware file system (FFS) describes the origanization of files and free space within the firmware volume.
    Each firmware file system has a unique GUID, which is used by the firmware to associate a driver with a newly exposed FV

  Firmware Files
    Code and data stored in firmware volumes
    Each of the files has the following attributes
      Name,Type,Alignment,Size

  FILE TYPE AND SECTION TYPE
  FFS File Type
    EFI_FV_FILETYPE_RAW
    EFI_FV_FILETYPE_FREEFORM
    EFI_FV_FILETYPE_PEIM
    EFI_FV_FILETYPE_DRIVER
    EFI_FV_FILETYPE_APPLICATION
    EFI_FV_FILETYPE_SMM
    EFI_FV_FILETYPE_FIRMWARE_VOLUME_IMAGE

  Section Type
    EFI_SECTION_PE32
    EFI_SECTION_DXE_DEPEX/EFI_SECTIN_PEI_DEPEX/EFI_SECTION_SMM_DEPEX
    EFI_SECTION_USER_INTERFACE
    EFI_SECTION_RAW
    EFI_SECTION_FIRMWARE_VOLUME_IMAGE

2.Access to Firmware Volume
  PEI ACCESS TO FIREWARE VOLUME
    Fireware Volume (FV) is assumed as the liner address
    region

    Implemented as layered FvPpi
      FvHob specifies FV image base address and length for DXE
      FvInfoPpi specifies FV image base address and length for PEI
      FvPpi abstracts the service to access the section data in FV

  DXE ACCESS TO FIRMWARE VOLUME
    The Firmware Volume is the basic firmware storge abstraction
      Read only until read/write DEX driver loads

    Implemented as layered protocols
      Firmware Volume protocol (abstracts for matting of firmware device)
      Firmware Volume Block protocol (abstracts firmware device hardware and partitioning)

    Firmware File System
      Space-optimized binary flat format

3.Code/Data Storage Modeles
  File System Support for EFI system partition
    File system header contains a GUID which describes the format of the firmware file system used to organize the firmware volume date.(i.e. FAT32)
    Pluggable file system abstraction

  Firmware volumes (FV)
    Location and media independence

  Code and data location need not be determined at build time
    Dispatcher and BDS can use FV, FIle or network to find required components
    Can change packaging based on platform needs.

4.EFI Image Format(PE/COFF)
  DOS Header
    Dos signature

  COFF Header
    Machine type:IA32 or X64 or ARM

  Optional Header
    Section alignment and file alignment
    Entry point relative address in PE image
    Subsystem:EFI driver/EFI runtime driver/EFI application
    Data Directory
      Debug directory to fine the debug PDB file path in .rdata section
      Relocation directory to fine the relocation data in .reloc section
  Section data
    .text:the binary instruction code
    .rdata:the read only data
    .data:the global data
    .rsrc:the resource section to iclude the additional data
    .reloc:info to reload PE image to the different address

  EFIOPTIONROM
    Option Rom is built int device
    Option Rom is auto loaded in UEFI boot
    EFI Option Rom includes EFI image as the device driver
    ROM header has 0x0EF1 ad signature
    PCI data structure includes DeviceId and VendorId
    The option rom image may iclude more than one images to support the different ARCHs.

5.Variable Storage
  FIRMWARE_IMAGE_HEADER
  VARIABLE_STORE_HEADER
  (4 byte align)VARIABLE_HEADER + NameData + VariableData
  (4 byte align)VARIABLE_HEADER + NameData + VariableData
  ...
  (4 byte align)VARIABLE_HEADER + NameData + VariableData

  VARIABLE_HEADER = VARIABLE Guid, Attribute, UnicodeNameString, VariableData

  VARIABLE SERVICE & ATTRIBUTE
    Read Variable
      PEI:ReadOnlyVariable2Ppi
      DXE:VariableArchProtocol

    SetVariable
      DXEVariableWriteArchProtocol is ready
      EFI_VARIABLE_NON_VOLATITE: Volatile variable doesn't require this attribute.
      EFI_VARIABLE_BOOTSERVICE_ACCESS:boot time only variable
      EFI_VARIABLE_RUNTIME_ACCESS:runtime acess variable in OS

    Variable Reclaim
