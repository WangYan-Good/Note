UEFI Capsule Update

1. LESSON OBJECTIVE
  What is Capsule Update
  Why is Capsule Update needde
  How to enable Capsule Update in Edk II platforms


2. Why is Capsule Update Needed?
  Establish a Root-of-Trust at the low-level platform initialization

  National Institute of Standards and Technology ( NIST ) provides guidelines on BIOS update
    BIOS Update Authentication
    Secure Local Update Method
    Integrity Protection
    Non-Bypassability

  3. What is Capsule Update ?
    A more secure way to update firmware
    OS Agnostic

    Solving Firmware Update
    Reliable update story
      Fault tolerant
      Scalable & repeatable

    How can UEFI Help ?
      Capsule model for hinary delivery
      Bus / Device Enumeration
      Managing updates via
        EFI System Resource Table
        Firmware Management Protocol
        Capsule Signing

4. How dose the Capsule Update work?
  UEFI Spec defines Capsule Services to meet NIST Requirement
    EFI_FIRMWARE_MANAGEMET_PROTOCOL, (FMP) capsule format
    EFI System Resource Table (ESRT) to support system firmware and device firmware update
    An OS agent may call the UEFI serivice UpdateCapsule() to pass the capsule image from the OS to the firmware. Based upon the capsule flags, the firmware may pjrocess the capsule image immediately, or the firmware may reset the system and process  the capsule image on the next boot.

5. UEFI Capsule Update - Firmware Management Protocol ( FMP )
  FMP capsule image format
  Update FMP drivers

  FMP payloads
    -binary update image and optional vendor code
    The platform may consume a FMP protocol to update the firmware image

6. UEFI Firmware Secure "Capsule" Update
  Capsule update is a runtime service used to update UEFI FW
  1) Update is initiated by update application / OS run-time
  2) Update application stores update "capsule" in DRAM or HDD on ESP (e.g \EFI\CapsuleUpdate)
  3) Upon reboot or S3 resume, FW finds and parses update capsule
  4) After FW verifies digital signature of the capsule, FW writes new BIOS FV(s) to SPI flash memory.

7. Firmware Update Rollback Protection

8. HOW TO ENABLE?
  How to Enable Capsule Update on a EDK II Platform?

  UEFI Capsule Implementation in EDK II
  SignedCapsulePkg Uses OpenSSL to sign and authenticate firmware update capsules and firmware recovery images

  KEYS
    Test signing key
      Used for firmware development and debug

    Production signing key
      Used by OEM to create and manage their own
        OpenSLL utilities can be used to create key

9. Enable Capsule Based System Firmware Update
  The following wiki pages provide details on how to add the system firmware update using Signed UEFI Capsules
    Implement Platform Components for UEFI Capsule
    Add CAPSULE_ENABLE feature to Platform DSC / FDF Files
    Verify CAPSULE_ENABLE Feature using Test Signing Keys
    Change System Firmware Update Version
    Change ESRT System Firmware Update GUID
    How to Generate Signing Keys using OpenSSL  Command Line Utilities
    Verify CAPSULE_ENABLE Feature using Generated Signing Keys

10. Implement Platform Components for UEFI Capsule
  Requirements for EDK II Projects to support SignedCapsulePkg

  Library
    An instance of PlatformFlashAccessLib must be implemented to provied API to update a portion of the non-volatile storage device.
      <Your Platform Package>/Feature / Capsule / Library / PlatformFlashAccessLib

    Descriptor
    PEIM System Firmware Descriptor
      <Your Platform Package> / Feature / Capsule / SystemFirmwareDescriptor
      -Requires.aslc (C Structure syntax)

    Config INI
    System Firmware Update Configuration INI File
      <Your Platform Package> / Feature / Capsule / SystemFirmwareUpdateConfig.ini

11. Add CAPSULE_ENABLE feature to Platform Files
  Add -D CAPSULE_ENABLE to the build command line to enable capsule update features.
  The build process generates a capsule update image ( .cap file ) along with the UEFI application CapsuleApp.efi
      Copy .cap file and CapsuleApp.efi to USB thumb drive.
      Boot to UEFI Shell and use CapsuleApp.efi with .cap signed capsule file.
  Once the system is rebooted, the signed capsule is authenticated and the firmware is update with the new system firmware version.










