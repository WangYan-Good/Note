使用Cg编写的着色程序默认的文件后缀是*.Cg

# 4.1 开始 Cg 之旅  

Cg 语言规范是公开和开放的，并且 NVIDIA 开放了 Cg 编译器技术的源代码，使用无限制的、免费的许可证  

到目前为止没有一个主流的专门为编写着色程序而开发地IDE，都是直接在文本中写好程序后，修改文件后缀

# 4.2 CG 特性  

Cg同时被OpenGL与Direct3D两种编程API所支持

# 4.3 CG 编译  

## 4.3.1 CG 编译原理  

Cg语言通常采用动态编译的方式，在宿主程序运行时利用Cg运行库（Cg Runtime library）动态编译Cg代码

Cg语言同样支持静态编译方式，即Cg源码编译成汇编代码后，这部分目标代码被链接到宿主程序最后的可执行程序中

Cg编译器首先将Cg程序翻译成可被图形API（OpenGL 和 Direct3D）所接受的形式，然后应用程序使用适当的OpenGL和Direct3D命令将翻译后的Cg程序传递到图形处理器，OpenGL和Direct3D驱动程序最后把它翻译成图形处理器所需要的硬件可执行格式

NVIDIA提供的Cg编译器为cgc.exe

Cg Profiles是Cg语言的重要组成部分，编写Cg语言程序时要考虑到当前的图形硬件是否支持该Cg Profile

## 4.3.2 CGC 编译命令

cgc -h

Cg 程序编译的命令形式是 cgc [options] file

例如 cgc –profile glslv –entry main_v test.cg  

需要强调以下几点：

1.profile 也分为顶点 profile 和片段 profile ， 编译片段着色程序时必须选用当前图形硬件支持的片段profile  

2.选择 profile 如果不被当前图形硬件所支持，编译时会出现错误  

3.如果没有确切的把握，不要在低级的profiles中使用循环控制语句  

4.被编译的着色程序文件名必须加上.cg 后缀  

5.另外 cgc 还提供一种比较特殊的功能：就是将 Cg 语言所写的着色程序转换为使用 GLSL 或 HLSL 所编写的程序  

6.还有一个非常隐蔽的编译情况是：如果着色程序中的某些变量并没有为最终的输出做出贡献，则编译时会将该部分代码忽略  

基于 GPU 编程，最令人崩溃的一点是：无法跟踪调试着色程序！  

# 4.4 CG Profiles  

一个 Cg profile 定义了一个“被特定图形硬件或 API 所支持的 Cg 语言子集”  

不同的图形硬件对应着不同的功能子集，当前 Cg compiler所支持的 profiles有：

OpenGL ARB vertex programs
Runtime profile: CG_PROFILE_ARBVP1
Compiler option: _profile arbvp1  

OpenGL ARB fragment programs
Runtime profile: CG_PROFILE_ARBFP1
Compiler option: _profile arbfp1  

OpenGL NV40 vertex programs
Runtime profile: CG_PROFILE_VP40
Compiler option: _profile vp40  

OpenGL NV40 fragment programs
Runtime profile: CG_PROFILE_FP40
Compiler option: _profile fp40  

OpenGL NV30 vertex programs
Runtime profile: CG_PROFILE_VP30
Compiler option: _profile vp30  

OpenGL NV30 fragment programs
Runtime profile: CG_PROFILE_FP30
Compiler option: _profile fp30  

OpenGL NV2X vertex programs
Runtime profile: CG_PROFILE_VP20
Compiler option: _profile vp20  

OpenGL NV2X fragment programs
Runtime profile: CG_PROFILE_FP20
Compiler option: _profile fp20  

DirectX 9 vertex shaders
Runtime profiles: CG_PROFILE_VS_2_X
CG_PROFILE_VS_2_0
Compiler options:-profile vs_2_x
-profile vs_2_0  

DirectX 9 pixel shaders
Runtime profiles: CG_PROFILE_PS_2_X
CG_PROFILE_PS_2_0
Compiler options: -profile ps_2_x
-profile ps_2_0  

DirectX 8 vertex shaders
Runtime profiles: CG_PROFILE_VS_1_1
Compiler options:-profile vs_1_1  

DirectX 8 pixel shaders
Runtime profiles: CG_PROFILE_PS_1_3
CG_PROFILE_PS_1_2
CG_PROFILE_PS_1_1
Compiler options: -profile ps_1_3
-profile ps_1_2
-profile ps_1_2
-profile ps_1_1  

截止到 2009 年 10 月，出现的 profile 已经不止上面这些种类  