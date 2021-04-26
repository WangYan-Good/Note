1.Explain How the OS and UEFI together
  UEFI Operate systems
  Windows Server 2008
  Windows 7
  Windows Storage Server 2008 Enterprise

  Linux

2.Explain the UEFI Reauirements for UEFI aware OS.
  UEFI Drivers:           |     UEFI OS installer | UEFI OS Loader
  Boot devices/conssole   |                       |
                          |                       |
  Disk                    |      Fireware         | Set Boot Path to
  Partition/Formats       |      Requirements     | Boot to UEFI OS

  required UEFI Driver : OS install & Boot
  Boot device
  Console output
  Console input
  NVRAM Driver: variable

  UEFI Runtime Services
  capsule update
  variable

3.Explain How Secure Boot Fits with UEFI
  how does UEFI ensure the Operating System is trusted ?
  Hardware Root of Trust  Boot Guard, Intel(R)TXT

  Measured Boot   Using TPM1 to store hash values

  Verified Boot   Boot Guard +
                  UEFI Secure Boot

  Boot Guard: Verification
  CPU verifies signature
  verification occurs before BIOS starts
  Hash of public key is fused in CPU

  Intel(R)TXT: Measurements
  Use a trusted Platform Moudle(TPM)
  & cryptographic

  Provides Measurements

  UEFI SECURE BOOT
  Software ID checking during every step of the boot flow:
    1.UEFI System BIOS(update via secure process)
    2.Add-In Cards(signed UEFI Option ROMs)
    3.OS Boot Loader(checks for "secure mode" at boot)

4.What about coreboot?
 linux boot
 u boot

