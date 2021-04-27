BOOT DEVICE SELECTION(BDS)

1.BDS ARCHITECTURE GOALS
  Centralize Polize and User Inter
    Lets you customize to different look adn feels
    1 board many customers

  Make a central repository for platform boot policy

  Allow for the ability to boot with minimal driver initialization and users interaction

  Allow for implementation of setup menu

  Aoolw for ability to store infomation using NVRAM variables

  Policy engine controls how the system will boot

  Takes control from DXE Foundation

  Attempts to pass control to boot target

  Arms watchdog to guard against boot failure

  Iterates list of possible boot targets
    Drivers and boot targets stored in architectural environment variable lists
    May need to return to DXE Foundation if more firmware volumes are encountered

  May present user interface and choices
    Setup, boot list, boot list maintenance, IHV adapter configuration, diagnostics,recovery
    OEM chooses what to expose and how to meet business requirements for the platform in given market.

  BDS STEPS
    1.Initialize language and string database.
    2.Get current boot mode. The boot mode will determine the different policy executed in step 3-7.
    3.Build device list.
    4.Connect devices.
    5.Detect console devices.
    6.Perform memory test.
    7.Process boot options.

  BOOT OPTION
    BDS will enumerate all possible boot devices in the system and create their boot option variables

    Current BDS will connect all devices and do this enumeration when user interrupts auto boot
      Boot Manager
      Device Manager
      Boot Maintenance Manager

    Current BDS has two steps to enumerate the boot option
      Legacy boot option for legacy boot
      EFI boot option for EFI boot

  SIMPLE BOOT MANAGER
    Functionally replaces legacy BIOS Boot Specification(BBS)
    Order of processing load options
      Driver order options
        Load any drivers specified in driver option list

      Check the Boot Next feature
        This feature is for operating systemsetup;so that, on the next boot, this option is selected once and then removed from the list.

      Boot option list
        Options that are stored in NVRAM with boot maintenance menu.

  BDS POLICY INPUT
    Globally Defined Variables

    ConIn   The device path of the default input device
    ConOut  The device path of the default output device
    ErrOut  The device path of the default error output device

    BDS will fill in the corresponding system table entries with the handle of the device that variables are pointing to.

    DriverOrder   A list of UINT16's that make up an ordered  list of the Driver#### variable.

    Driver####    A driver load option. BDS will attempt to load the driver specified. Contains an EFI_LOAD_OPTION. An example would be a PCI Root Bridge, or Serial I/O driver.

    BootOrder     A list of UINT16's that make up an ordered list of the Boot#### variable. The BootOrder is not an optional variable.

    BootNext      The Boot option for the next boot only. This option takes precedence over the Boot#### variable.

    Boot####      A boot load option. BDS will attempt to load the boot driver specified. An example would be an OS loader or Setup.

  BOOT MANAGER POLICY ENGINE

  DXE already put EFI driver images in memory
    Quiescent state: entry point operation doesn't touch hardware

  Boot devices described by EFI Device Path
    Path list of software visible hardware components supported with EFI drivers between host bus and device

  Initializes console devices
    Various output devices, key board adn mouse
    "connect" on EFI drivers specified by device path

  Initializes boot devices
    Mass storage or Network
    "connect" on required EFI drivers

  Proceeds to pass control to OS loader
    Iterating list of possibilities if required

Platform Configuration Database(PCD)
  BOOT MANAGER POLICY ENGINE
