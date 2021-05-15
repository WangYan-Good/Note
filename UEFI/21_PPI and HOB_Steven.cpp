PPI and HOB

1. Agenda
  PPI
  What is PPI
  Why need PPI
  How to use PPI
  HOB
  What is HOB
  Why need HOB
  HOW to use HOB

2. PPI Architecture
  PI Architecture Firmware Phase

3. PPI Concept
  PEIMs may invoke other PEIMs
  PEIMs communicate with each other using a structure called a PEIM-to-PEIM Interface (PPI)

4. PEIM Concept
  Pre-EFI Initialization Modules (PEIMs) are sepcialized drivers that personalize the PEI Foundation to the platform. thsy are analogous to DXE drivers and genarally correspond  to the components being initialized

  It is the responsibility of the PEI Foundation code to dispatch the PEIMs in a sequenced order and provide basic services. The PEIMs are intended to mirror the componets being intialized.

5. Why need PPI
  Conmunication between PEIMs is not easy in a "memory poor" environment
  PEIMs cannot be coded without some interaction between one another and, ecen if they could, it would be inefficient to do so.
  The PEI phase provides mechanisms for PEIMs to locate and incoke interfaces from other PEIMs.

  PPI Databse
    The PPI database is a data structure that PEIMs can use to discover what interfaces are available or to manage a specific interface. The actual layout of the PPI database ia opaque to a PEIM but its contents can be queried and manipulated using the following PEI Serviecs:
      InstallPpi()
      LocatePpi()
      ReinstallPpi()
      NotifyPpi()

6. HOB Concept
  Hand-Off Blocks (HOBs) are used to pass information to the next phase of the PI Architecture.

  HOB producer phase    (PEI phase)
  HOB consumer phase    (DXE phase)

  EFI_HOB_HANDOFF_INFO_TABLE
  EFI_HOB_RESOURCE_DESCRIPTOR
  EFI_HOB_FIRMWARE_WOLUME
  EFI_HOB_FIRMWARE_VOLUME2
  EFi_HOB_CPU
  EFI_HOB_GUID_TYPE
  EFI_HOB_MEMORY_POOL
  EFI_HOB_UEFI_CAPSULE
  EFI_HOB_TYPE_END_OF_HOB_LIST

  HOBlist structure and HOB transfer model

  PEI phase
  CreateHob
  (*PeiServices)->CreateHob( PeiServices, Type, Length, Hob );

  DXE pahse
  GetHob
  HOB related lib

