EDK II Porting to a New Open Board Platform

1. LESSON OBJECTIOVE
  Define the porting task list for porting existing open platforms in EDK II
  Determine the necessary porting for each stage and boot phase of a new EDK II open platform project

2. APPROACH - PORTING EDK II
  Find Similar Open Board Projects
  Staged Approach by Features

3. Porting Task List
  1) Get the EDK II packages to a local workspace
  2) Select the Ref correct Intel(R) FSP Package
  3) Copy a reference OpenBoardPkg / BoardXxx
  4) Use feature stages to port all required project modules
  5) Validate each stage test point results defined with each stage

4. Analysis OpenBoard Reference Platform
  Step 1-3
    Find a similar OpenBoard EDK II Platform in Github edk2_platforms
    Get the reference OpenBoard Pkg EDK II Platform from Github
    Build the chosen reference OpenBoard Pkg EDK II Platform
    Study the reference Build directory, OpenBoard .FDF and .DSC files
    Copy a reference board directory to a new name ( i.e <Generation>OpenBoardPkg / NewBoardXxx where string "New" is meaningful to the project. )
    if it is a NEW Open Platform, Copy a reference <Generation>OpenBoardPkg / BoardXxx to a new name ( e.g NewOpenBoardPkg / NewBoardX )

5. Find Stage 1 Modules
  -Example SecCore.efi

  Producing Package - UefiCpuPkg
  Libraries Consumed - PlatformSecLib, SerialPortLib

  Library                 |  API definition         | Procuding Pkg            | Description
  PlatformSecLib  |  UefiCpuPkg            | MinPlatformPkg          | Reset vector and SEC initialization code
  SerialPortLib      |  MdeModulePkg      | Board<X>Pkg              | SIO vendor specific initializaton to enable serial port

6. How to search for Libraries in the Workspace
  1) Serch the workspace .DSC files for the string of the library
  2) Open the .DSC files associated with the open board platform project
  3) Determine which Library is used and that should have the  build path in the workspace
  4) DSC file will have similar to:
    SomeLib | Path_to_the_Library_used.inf
  5) Verify the instance used from the Build directory

7. Debug Configuration - Serial Port
  Serial port parameters come from the board and are used for debug features, serial input / output devices supporting local or remote consoles, and OS level debuggers

  Library - SerialPortLib find in workspace used by board .dsc
  Serial port configuration options consumed by SerialPortLib
  SerialPortLib is used by the StatusCodeHandlerPei.inf component to initialize and display messages to a serial port.

  Serial port configuration options are published via PCH_SERIAL_IO_ CONFIG used by PeiPchPolicyLib
    Silicon / Intel / KabylakeSiliconPkg / Pch / Library / PeiPchPolicyLib

 8. Prepare for Hand-off to DXE
 Hob Output : 2 Hob lists - FSP & FSP Wrpper
 MTRR Configuration:  2 locations - after permanent Memory & Prior to DXE IPL
 DXE IPL: Load and invoke DXE
