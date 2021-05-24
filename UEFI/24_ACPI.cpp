1. Agenda
  什么是ACPI
  ACPI可以实现什么功能？
  A axample-Set GPIO Pin ( SystemIO )
  ACPI Tree
  SystemMemory
  PCI_Config
  对I/O端口的访问
  如何表示一个Controller
  如何表示一个Device?
  _Qxx/_Lxx Event
  asl文件怎样与C文件通信？
  C文件怎样与asl文件通信？

2. 什么是ACPI？
  ACPI表示高级配置和电源管理接口（Advanced Configuration and Power Management Interface）
  对于Windows2000，ACPI定义了Windows2000、BIOS和系统硬件之间的新型工作接口。
  这些新接口包括允许Windows 2000控制电源管理和设备配置的机制

3. ACPI可以实现的功能
  系统电源管理（System power management）
  设备电源管理（Device power management）
  处理器电源管理（Processor power management）
  设备和处理器性能管理（Device and processor performance management）
  配置 / 即插即用（Configuration / Plug and Play）
  系统事件（System Event ）
  电池管理（Battery management）
  温度管理（Thermal management）
  嵌入式控制器（Embedded Controller）
  SMBus控制器（SMBus Controller）

4. Set GPIO Pin

5. ACPI Tree

6. SystemMemory

7. System power states
  S0: System / OS working
  S1: Idle
  S2: Global Standby
  S3: Suspend-to-RAM
  S4: Suspend-to-Disk
  S5: Soft-Off
