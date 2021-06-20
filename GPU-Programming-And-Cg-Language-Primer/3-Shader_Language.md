shader langaue, 称为着色语言

shader language基于物体本身属性和光照条件，计算每个像素的颜色值。

目前shader language 早已经用于通用计算研究

shader language 被定位为高级语言，GLSL的全称是“High Level Shading Language”, Cg语言的全称为“C for Graphic”

shader language完全依赖于GPU架构，暂时还做不到“独立于硬件”

shader language的发展方向是“赋予程序员灵活而方便的编程方式”，并“尽可能的控制渲染过程“同时”利用图形硬件的并行性，提高算法的效率“。

shader language 目前主要有3种语言

基于OpenGL的GLSL

基于Direct3D的HLSL

还有NVIDIA公司的Cg语言

# 3.1 Shader Language原理

shader language 编写的程序称之为 shader program( 着色程序 )

着色程序可分为两大类：

vertex shader program（顶点着色程序）

fragment shader program（片段着色程序）



GPU的两大组件：

Programmable Vertex Processor（可编程顶点处理器，又称顶点着色器）

Programmable Fragment Processor（可编程片段处理器，又称片段着色器）

顶点和片段处理器都拥有非常强大的并行计算能力，并且非常擅长矩阵（不高于四阶）计算，片段处理器还可以告诉查询纹理信息。

以下展示了可编程图形渲染管线  

![image-20210620210302104](C:\Users\98763\AppData\Roaming\Typora\typora-user-images\image-20210620210302104.png)

顶点着色器控制顶点坐标转换过程

片段着色器控制像素颜色计算过程

前者的输出是后者的输入

# 3.2 Vexter Shader Program

顶点着色程序从GPU前端模块中提取图元信息，并完成顶点坐标空间转换、法向量空间转换、光照计算等操作，将数据传送到指定寄存器中

片段着色程序从中获取所需数据，通常为“纹理坐标、光照信息等“，并根据从应用程序传递的纹理信息进行每个片段的颜色计算，最后将处理后的数据送到光栅操作模块。

![image-20210620211710947](C:\Users\98763\AppData\Roaming\Typora\typora-user-images\image-20210620211710947.png)

# 3.3 Fragment Shader Program  

片段着色程序对每个片段进行独立的颜色计算，最后输出颜色值的就是该片段最终显示地颜色。

顶点着色程序的运算主要进行几何方面的运算，而片段着色程序主要针对最终的颜色值进行计算。

片段着色程序拥有检索纹理的能力



什么是片段？

片段就是所有的三维顶点在光栅之后的数据集合，这些数据还没有经过深度值的比较。屏幕显示地像素都是经过深度比较的。

# 3.4 CG VS GLSL VS HLSL  

Shader language 主要有3种主流语言

基于OpenGL的 GLSL（OpenGL Shading Language）

基于Direct3D的HLSL（High Level Shading Language）

NVIDIA公司的Cg（C for Graphic）语言



Cg是一个可以被 OpenGL 和 Direct3D广泛支持的图形处理器编程语言

Cg是OpenGL、DirectX的上层语言，是运行在OpenGL和DirectX标准顶点和像素着色的基础之上的

Cg语言是Microsoft和NVIDIA相互协作在标准硬件光照语言的语法和语义上达成了一致

Cg语言极力保留了C语言的大部分语义，力图让开发人员从硬件细节中解脱出来

# 3.5 本章小结  

着色程序的工作原理

三种主流着色语言