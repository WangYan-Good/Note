Platform Configuration Database(PCD)

1.Define Platform Configuration Database(PCD) and explain the syntax
  PCD OVERVIEW

   Purpose
   Established platform common definitions
   Build-time/Run-time aspects
   Binary Editing Capabilities

   Goals
   Simplify porting
   Easy to associate with a module or platform

   PEI
   PCD PEIM produces PCD database
   Two PCD PPIs: PCD_PPI and EFI_PEI_PCD_PPI

   DXE
   DXE Driver Manages PCDs
   Two PCD Protocols: PCD_PROTOCOL and EFI_PCD_PROTOCOL

2.Differentiate types of PCDs
   PCD LIBRARY
   Providesinterface for PCDs
   PCD PPI_PEI
   PCD Protocol-DXE
   Allows access to data

   PCD SYNTAX
   PCDs can be located anywhere within the Workshpace even though a different package will use those PCDs for a given project
   .DEC: Define PCD  Package
   .INF: Reference PCD Module
   .DSC: Modify PCD Plarform

   What about a Dynamic PCDs?
   Only can be Set and changed during Boot time.
   PCD can be set with the library Set: LibPcdSet...
   PCD can be retieved with the library Get: LibPcdGet...

   Example: Use the variable PcdPlatfromBootTimeOut defined for the platform time in seconds before booting, modified for a value of 03 seconds.

3.Explain how changing a PCD value affectsoutput

4.Evaluate the results of a PCD value modification

5.Special PCDs
  Multi-Structure PCD: C data structure and assign the value to each sub-field firectly

  Multi-Sku PCD: Multiple configuration generated at build time & set @ run time, (PI Spec Vol 3 chap. 8)

  DefaultStores PCD: Support the default stores  concept in UEFI specificition, (UEFI, HII, Chap.32 )
