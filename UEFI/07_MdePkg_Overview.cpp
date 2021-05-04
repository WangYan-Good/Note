MDEPKG  BASE APIS
1. AGENDA
  Public Definitions

  BaseLib/BaseMemoryLib

  DebugLib / ReportStatusCodeLib

  HobLib / MemoryAllocationLib

  PcdLib

  IoLib / PciLib

  PeiServicesTablesPointerLib /
  UefiBootServicesTableLib / DxeServicesTableLib /
  UefiRuntimeServicesTableLib / SmmServicesTableLib

  PeimEntryPoint / UefiDriverEnterPoint / UefiApplicationEntryPoint

2. PUBLIC DEFINITIONS
  PI: Common definitions in PI spec
  Uefi: Common definitions in UEFI spec
  Guid: Guid defined in PI / UEFI for Variable / Hob / EventGroup / SystemTable
  Ppi; PPI defined in PI spec
  Protocol: Protocol defined in PI / UEFI spec
  IndustryStandard
    Acpi
    Pci
    Tpm
    Sdram

  Register
    Intel: CPU related registers
    Amd: CPU related registers

3. CONT. MODULE TYPE HEADER FILE
  Base.h
  PiDxe.h
  PiMm.h
  PiPei.h
  PiSmm.h
  Uefi.h

4. BASELIB
  String APIs
  List APIs
  Math APIs
  BitField APIs
  CPU APIs
  Register Read / Write APIs

5. BASEMEMORYLIB
  CopyMem
  SetMem
  ZeroMem
  CompareMem
  ScanMem
  CopyGuid / ScanGuid / CompareGuid / IsZeroGuuid

6. DEBUGLIB
  gEfiMedPkgTokenSpaceGuid.PcdDebugPropertyMask
  ASSERT()
  DEBUG()
  ASSERT_EFI_ERROR()
  DEBUG_CODE_BEGIN() / DEBUG_CODE_END()
  DEBUG_CLEAR_MEMORY()

7. REPORTSTATUSCODELIB
  gEfiMedPkgkenSpaceGuid.PcdReportStatusCodePropertyMask
  REPORT_STATUS_CODE
  REPORT_STATUS_CODE_WITH_DEVICE_PATH
  REPORT_STATUS_CODE_WITH_EXTENDED_DATA
  REPORT_STATUS_CODE_EX

8. HOBLIB
  GetHobList
  GetFirstHob / GetNextHob
  GetFirstGuidHob / GetNextGuidHob
  GET_HOB_TYPE() / GET_HOOB_LENGTH() / GET_NEXT_HOB()
  GET_GUID_HOB_DATA() / GET_GUID_HOB_DATA_SIZE()
  BuildGuidHob / BuildGuidDataHob
  BuildFvHob
  BuildResourceDescriptorHob / BuildMemoryAllocationHob

9. MEMORYALLOCATIONLIB
  AllocatePages \ AllocateAlignedPages
  FreePages \ FreeAlignedPages
  AllocatePool
  AllocateZeroPool
  AllocateCopyPool
  ReallocatePool
  FreePool

10. PCDLIB
  PcdGetXX / PcdSetXX: Boolean, UINT8, UINT16, UINT32, UINT64, and VOID*
  FixedPcdGetXX
  PatchPcdGetXX
  PcdGetSize: VOID* PCD type only
  LibPcdGetSku / LibPcdSetSk: Dynamic PCD only
  LibPcdCallbackOnSet / LibPcdCancelCallback: Dynamic PCD only

11. IOLIB
  IO_LIB_ADDRESS
  IoReadCC / IoWriteXX
  IoOrXX / IoAndXX / IoAndThenOrXX
  IoBitFieldXX
  MmioReadXX / MmioWriteXX
  MmioOrXX / MmioAnd / MmioAndThenOrXX
  MmioBitFieldXX
  MmioReadBufferXX / MmioWriteBufferXX

12. PCILIB
  PCI_LIB_ADDRESS
  PciReadXX / PciWriteXX
  PciOrXX / PciAndXX / PciAndThenOrXX
  PciBitFieldXX
  PciReadBuffer / PciWriteBuffer

13. PEISERVICESTABLEPOINTERLIB /
       UEFIBOOTSERVICESTABLELIB / DXESERVICESTABLELIB /
       UEFIRUNTIMESERVICESTABLELIB / AMMSERVICESTABLELIB
  GetPeiServicesTablePointer() / SetPeiServicesTablePointer()
  gST
  gImageHandle
  gDS
  gRT
  gSmst
  InSmm()

14. PEIMENTRYPOINT /
       UEFIDRIVERENTRYPOINT / UEFIAPPLICATIONENTRYPOINT
  _ModuleEntryPoint
  ProcessLibraryConstructorList
  ProcessModuleEntryPointList

  _DriverUnloadHandler
  ProcessModuleUnloadList
  ProcessLibraryDestructorList
