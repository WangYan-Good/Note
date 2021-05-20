PCD

1. PCD Introduction
    PCD Format
    PCD Section

2.  PCD Introduction
      Platform Configuration Database (PCD)

      A mechanism that provides modules writers a uniform interface to extract external input information determined in build time or run time of firmware.

      This mechanism standardizes the exposure of platform and module settings that can in-turn facilitate platform porting.

      The PCD mechanism provides FeatureFlag, FlxedAtBuild, PatchableInModule, and Dynamic / DynamicEx types for a PCD token.

      These configuration settings can be classified as two trypes:
        1) Build - time generated platform settings
        2) Run - time generation platform settings

3. PCD  Format
  PCD declared in DEC file

  - PcdName gammar is
  < TokenSpaceGuidCName > "." < PcdName >
  where both are defined as a C Variable name

  -Other PCD parameters are
  InitialValue | DataType | TokenNum

4. PCD Section
  [PcdsFeatureFlag]
  [PcdsFixedAtBuild]
  [PcdsPatchableInModule]
  [PcdsDynamic]
  [PcdsDynamicEx]

  [PcdsFeatureFlag]
    This PCD type replaces a switch MACRO to enable or diasble a feature.
    This is a Boolean values, and is either TURE, FALSE, 1 or 0

  [PcdsFixedAtBuild]
    This PCD type replaces a macro that produces a customizable value.

    The value of this PCD type is determined at build time

  [PcdsPatchableInModule]
    used to patch for a specific module

  [PcdsDynamic]
    It is produced by PEI/DXE driver and consumed by other driver in execution time

  [PcdsDynamicEx]
    The DynamicEx type of PCD is recommended for modules that are distributed in binary form.

5. Access PCD
  1) Define GUID and PCD in application DEC file

  2) Set default value in DSC file

  3) Declare PCD in INF file

  4) Include PCD lib header in C or H file

  5) Access PCD in C file
