EDK II Debugging through UEFI Boot Flow

1. LESSON OBJECTIVE
  Debugging commands similar to all debuggers
  Debugging UEFI Platform Initialization Boot Flow

2. DEBUGGING COMMANDS
  CpuBreakpoint() added to Source

  Source Level Debugging
  View call stack Go
  Insert CpuBreakpoint()
  View and edit local / global variables
  Set breakpoint Step into / over routines
  Go till View disassembled code
  View / edit general purpose register values

  CpuBreakpoint   VS.   CpuDeadLoop

  CpuBreakpoint
  when using a Software debugger:
    Visual Studio
    GDB (ovmf with qemu)
    Intel(R) UDK Debugger
    Windriver* Simics
    Debug agent-SourceLevelDebugPkg

  CpuDeadLoop
  when using a Hardware debugger:
    In-Target Probe(ITP)
    Intel(R) SVT DCI cable
    Intel(R) Closed Chassis Adapter (CCA)
    other 3rd Party Hardware (i.e. Lauterbach w/ JTAG)

  The functions CpuBreakpoint() and CpuDeadLoop() are part of the EDk II Base Libraries and can be compiled with any UEFI or PI Module at any phase of the boot flow (SEC, PEI, DXE, BDS, TSL)

  Special DCI Breakpoint with HW Debugger
  CpuIceBreakpoint
  The Intel Architecture has a special op-code for a breakpoint : int1 Better than a CpuDeadLoop() since it halts the processor. Better trace infomation
  Downside:
    Requires a Hardware Debugger with DCI capabilities to intercept the int1 op code
    There is no "C" equivalent - needs to be  assembly code.

3. DEBUGGING THRU BOOT FLOW
  Add Breakpoints to the Compiled BIOS / Firmware Source Code

  Debugging the Boot Phases

  Debugging the Boot Phases - SEC
  Debugging Sec Phase
  Hardware debugger capable only
    Break at the Reset Vector
    Check temporary memory - CAR NEM
    Enable the "C" code
    Trandfer control to PEI

  Debugging the Boot Phases - PEI
    Use debugger prior to PEI Main
    Check proper execution of PEI drivers
    Execute basic chipset & Memory init
    Check memory availability
    Complete flash accessibility
    Execute recovery driver
    Detect DXE IPL

  Debugging the Boot Phases - DXE
    Search for cyclic dependency check
    Trace ASSERTs caused during DXE execution
    Debug individual DXE drivers
    Check for architecrural protocol failure
    Ensure BDS entry call

  Debugging the Boot Phases - BDS
    Detect console devices (input and output)
    Check enumeration of all devices' preset
    Detect boot policy
    Ensure BIOS "front page" is loaded

  Debugging the Boot Phases - Pre-Boot
    "C" source debugging
    UEFI drivers
      Init
      Start
      Supported

    UEFI Shell Applications
      Entry point
      Local variable

    CpuBreakpoint()
