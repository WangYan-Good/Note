UEFI PLATDORM FW SECURITY OVERVIEW

1. Aecurity Architecture
  Spoof user identity - E.g. Fake password to steal credit card info
  Tampering - Modifying data or code
  Information disclosure - E.g Leave credit card data unencrypted
  Permanent Denial of  Service - hardware unusable without return to factory
  Elevation of privilege - e.g Can run in ring 0 or hidden form AV (SMM)
  Denial of service - Tempjorary inconvenience ( e.g. occasional crash )

2. Vulnerability Case:
    Unauthorized Firmware Update - Firmware can be updated without check or with weak check (Checksum == Nothing)
    Unauthorized 3rd Party Code - So it will hijack system API or escalate privilege
    Critical Register Unlocked - If unlock, then modified later
    Buffer Overflow - Not only OS, not only software
    Secret Used but bot Cleared - Later Malicious code can search secrete  in memory
    Default Passphrase to Access - BORE Attack ( Break once run everywhere ) ( Security != Obscurity )

3. Security Design

4. UEFI FW Protection Solutions
  BIOS Protection vis SPI Scenatios
    Permission for region access, configure on Softstrap
    PR registers to protect specific SPI region
    EISS and write pjrotection for BIOS region, only allow BIOS write under SMM once locked

  Authenticated BIOS Update
    Signed capsule update
    BIOS Guard

  Verified Boot
    Boot Guard
    UEFI Secure Boot

5. Quiz
  List the way of atteck
  List the aecurity assets
  List the way of protection
