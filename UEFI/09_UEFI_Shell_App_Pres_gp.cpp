UEFI SHELL APPLICATION
1. LESSON OBJECTIVE
  Explain UEFI, the shell, and how they work together
  Define the shell components
  Use the shell API in a UEFI application
  UEFI Shell command Library
  UEFI Shell scripts

2. UEFI SHELL OVERVIEW
     Components of the UEFI shell

     what is a UEFI shell ?
     it's an Extensive & Standarized Pre-OS UEFI Application

     UEFI SHELL ELEMENTS
     Small Size Profiles
     Shell commands
     New Shell API
     Enhanced Scriptiong

     SHELL SIZE PROFILES
     Level / Profile                                Commands
     Level 0                                            Shell API Only
     Level 1                                            Basic scripting support
     Level 2                                            File support, cmds(cd, cp, mv)
     Level 3                                            Adds interactive CLI + Profiles
     UEFI Debug Profile                       bcfg, comp, dblk, dmem, dmpstore, echo, edit
     UEFI Network Profile                   ipconfig, ping
     UEFI Driver Profile                       drvdiag, openinfo, reconnect, load, upload

     Shell Command
     help -b
     attrib
     cd
     cp
     load
     map
     mkdir
     mv
     parse
     reset
     set
     ls
     rm
     vol
     date
     time
     timezone
     stall
     for
      goto
      if
      shift
      ......

      New Shell API
      EFI_SHELL_PROTOCOL
      Group                                                                         Functions
      File Manipulation                                                       OpenFileByName(), WriteFile(), etc...
      Mapping, Alias & Environmental Variables          GetMapFromDevicePath(), GetFilePathFromDevicePath, etc...
      Launch Application or Script                                  Execute(), BatchIsActive(), IsRootShell(), etc...
      Miscellaneous                                                             GetPageBreak(), EnablePageBreak(), etc...

3. ShellPkg Main Libraries
  ShellLib
  HandleParsingLib
  ShellCommandLib

  EDKII ShellPkg
  Supports bianry portability
  Shell Protocols

  Shell parameters
  #Include <Library/ShellLib.h>
  gEfiShellParametersProtocol
  gEfiShellProtocol

  Shell call Example

  Enhanced Scripting
  Contains .nsh extension
  "Startup.nsh" Runs first
  Supports:
    Command-line arguments
    Standard script commands
    Input & output redirection & pipes

    Shell Scripts(Benefits)
    Perform basic flow control
    Allows branching / looping
    Users can control input, output and script nesting

    Documentation for EDK II ShellPkg
    wiki Shell Package

    UEFI Shell 2.2 Vs  EFI Shell 1.0
    UEFI Shell 2.x        -EFI_SHELL_PARAMETERS_PROTOCOL
    EFI Shell 1.0           -EFI_SHELL_INTERFACE

    LEGACY VS. UEFI

    SHELL USAGE
    Execute preboot programs
    Move files between devices
    Load a preboot UEFIdriver (.efi)

    ACCESSING THE SHELL
    /EFI/boot/BOOTx64.efi
      FAT paratition
          /EFI
              /BOOT
                  BOOTx64.efi

    BOOTx64.efi = OS loader, UEFI application, or UEFI Shell

    COMMON SHELL COMMANDS FOR DEBUGGING
    "-b" is the command line parameter for breaking after each page.

    UEFI SHELL SCRIPT
    The UEFI Shell can executecommands from a file, which is called a batch seript file(.nsh).

    Benefits: These files allow users to simplifyroutine or repetive tasks.
      Perform basic flow control.
      Allow branching and looping in a acript.
      Allow users to control input and output and call other batch programs(knows as script nesting).

      Writing UEFI SHELL SCRIPTS
      echo
