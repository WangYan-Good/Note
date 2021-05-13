How to Write a UEFI Driver

1. LESSON OBJECTIVE
  What is the UEFI Driver Model
  Details on Driver Binding Protocol
  Example of UEFI Driver

2. What are UEFI Drivers ?
  UEFI Drivers extend firmware
  Portable across platforms
  Enables rapid development
  Produce Protocols

  UEFI Driver is chained into a link list of Drivers Managing Devices

3. Defining a UEFI Driver
  UEFI Loadable Image
  May produce / consume protocols
  Supports complex bus hierarchies
  Driver Binding Protocol matches drivers to devices, adds version management
  Supports specific hardware, can be unloaded or override an existing driver.

4. What is a UEFI protocol ?
  Protocls
  Interface consisting of functions and data structures named by a GUID and stored in the Handle Database

  Handle Database
  Everything in the platform system gets a handle, drivers, devices, Images, etc

  GUIDs
  The UEFI Platform only knows items in the Handle Database by its GUID

5. UEFI Driver VS. Applications
    UEFI Loader    ------>       Entry Point    --------->     Driver Initialization ------->  Exit Driver  ---------->  UEFI Loader

6. Drivers Produce Protocols
  construction of a protocol

7. UEFI Driver Binding Protocol
  Supported()
  Determines if a driver supports a controller

  Start()
  Starts a driver on a controller & Installs Protocols

  Stop()
  Stops a driver from managing a controller.

8. Supported - PCI Controller Device Handle
  PCI Controller Device Handle
  EFI_DEVICE_PATH_PROTOCOL
  EFI_PCI_IO_PROTOCOL

  Tasks
  1) Opens PCI_IO Protocol
  2) Checks
  3) Closes PCI_IO Protocol
  4) Returns: Supported or Not Supported

  Input:
    "This"
    Controller to manage
    Remaining Device Path

  Supported():
    Checks to see if a driver supports a controller
    Check should not change hardware state of controller
    Minimize execution time, move complex I/O to Start ()
    May be called for controller that is already managed
    Child is optionally specified

9. Start - PCI Controller Device Handle
    PCI Controller Device Handle
    EFI_DEVICE_PATH_PROTOCOL
    EFI_PCI_IO_PROTOCOL

    Inputs:
      "This"
      Controller to manage,
      Remaining Device Path

      Start()
        Opens PCI I / O
        Starts a driver on a controller
        Can create ALL child handles or ONE child handle

10. Stop - PCI Controller Device Handle
  PCI Controller Device Handle
  EFI_DEVICE_PATH_PROTOCOL
  EFI_PCI_IO_PROTOCOL
  EFI_BLOCK_IO_PROTOCOL

  Inputs:
    "This"
    Controller to manage,
    Remaining Device Path

  Stop()
  Closes PCI I/O
  Stops a driver from managing a controller
  Destroys all specified child handles
  If no children specified, controller is stopped
  Stopping a bus controller requires 2 calls
    One call to stop the children. A second call to stop the bus controller itself

11. UEFI DRIVER EXAMPLE
  Examine details of the UEFI Driver - ScsiDiskDxe

  Example: UEFI Driver - ScsiDiskDxe
  edk2/MdeModulePkg/Bus/Scsi/ScsiDiskDxe
  SisiDiskDxe.inf
  ScsiDisk.c
  ScsiDisk.h
