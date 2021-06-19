图形绘制管线描述GPU渲染流程，即“给定视点、三维物体、光源、照明模式和纹理等元素，如何绘制一幅二维图像”

图形绘制管线主要阶段

应用程序阶段：使用高级编程语言进行开发，主要和CPU、内存打交道

几何阶段：主要负责顶点坐标变换、光照、裁剪、投影以及屏幕映射，该阶段基于GPU进行运算

光栅阶段：基于几何阶段的输出数据，为像素（Pixel）正确配色，以便绘制完整图像。

光照计算属于几何阶段

雾化以及涉及物体透明度的计算属于光栅化阶段

# 2.1 几何阶段

根据顶点坐标变换的先后顺序，主要有以下几个坐标空间：

Object space，模型坐标空间

World space，世界坐标空间

Eye space，观察坐标空间

Clip and Project space，屏幕坐标空间

## 2.1.1 从object space 到 world space

object space coordinate
就是模型文件中的顶点值，这些值是在模型建模时得到的  

object space coordinate 与其他物体没有任何参照关系  

从 object space coordinate 到 world space coordinate 的变换过程由一个四阶矩阵控制，通常称之为 world matrix。  

光照计算通常是在 world coordinate space（世界坐标空间）中进行的  

顶点法向量在模型文件中属于 object space，在 GPU 的顶点程序中必须将法向量转换到 world space 中才能使用  

## 2.1.2 从 world space 到 eye space

eye space，即以 camera（视点或相机）为原点，由视线方向、视角和远近平面，共同组成一个梯形体的三维空间，称之为 viewing frustum（视锥）  

超出这个远平面之外的场景数据，会被视点去除（ Frustum Culling，也称之为视锥裁剪）  

## 2.1.3 从 eye space 到 project and clip space  

裁剪算法：识别指定区域内或区域外的图形部分的过程  

在不规则的体（ viewing frustum）中进行裁剪并非易事，所以经过图形学前辈们的精心分析，裁剪被安排到一个单位立方体中进行，该立方体的对角顶点分别是(-1,-1,-1)和(1,1,1)，通常称这个单位立方体为规范立方体（ Canonical view volume,CVV）  

多边形裁剪就是 CVV 中完成的。  

从视点坐标空间到屏幕坐标空间（ screen coordinate space）事实上是由三步组成：  

用透视变换矩阵把顶点从视锥体中变换到裁剪空间的 CVV 中；  

在 CVV 进行图元裁剪；  

屏幕映射：将经过前述过程得到的坐标映射到屏幕坐标系上。  

主要的投影方法有两种：正投影（也称平行投影）和透视投影。  

视点去除，不但可以在 GPU 中进行，也可以使用高级语言（ C\C++）在 CPU 上实现。  

# 2.2 Primitive Assembly && Triangle setup  

Primitive Assembly，图元装配  

将顶点根据 primitive（原始的连接关系） ,还原出网格结构。  

裁减算法主要包括：视域剔除（ View Frustum Culling）、背面剔除（ Back-Face Culling）、遮挡剔除（ Occlusing Culling）和视口裁减等。  

处理三角形的过程被称为 Triangle Setup。  

# 2.3 光栅化阶段  

## 2.3.1 Rasterization  

光栅化：决定哪些像素被集合图元覆盖的过程（ Rasterization is the process of determining the set of pixels covered by a geometric primitive）。  

问题一：点的屏幕坐标值是浮点数，但像素都是由整数点来表示的，如何确定屏幕坐标值所对应的像素？  

绘制的位置只能接近两指定端点间的实际线段位置，例如，一条线段的位置是（ 10.48， 20.51），转换为像素位置则是（ 10， 21）  

问题二：  在屏幕上需要绘制的有点、线、面，如何根据两个已经确定位置的2 个像素点绘制一条线段，如果根据已经确定了位置的 3 个像素点绘制一个三角
形面片？  

问题二涉及到具体的画线算法，以及区域图元填充算法。通常的画线算法有 DDA 算法、 Bresenham 画线算法；区域图元填充算法有，扫描线多边形填充算法、边界填充算法等  

这个过程结束之后，顶点(vertex)以及绘制图元（线、面）已经对应到像素(pixel)。  

2.3.2 Pixel Operation  

Pixel operation 又称为 Raster Operation  其目的是：计算出每个像素的颜色值。  

消除遮挡面  

Texture operation，纹理操作，也就是根据像素的纹理坐标，查询对应的纹理值；  

Blending 

Filtering，将正在算的颜色经过某种 Filtering（滤波或者滤镜）后输出。  

# 2.4 图形硬件  

主要包括 GPU 中数据的存放硬件，以及各类缓冲区的具体含义和用途  

z buffer（深度缓冲区）、 stencil buffer（模板缓冲区）、 frame buffer（帧缓冲区）和 color buffer（颜色缓冲区）。  

## 2.4.1 GPU 内存架构  

从物理结构而言

寄存器是 cpu 或 gpu 内部的存储单元  ，内存则可以独立存在  

从功能上而言  

寄存器是有限存储容量的高速存储部件，用来暂存指令、数据和位址  

## 2.4.2 Z Buffer 与 Z 值

Z Buffer 又称为 depth buffer，即深度缓冲区，可见物体的Z值为[0,1]区间

使用Z Buffer 来判断空间点的遮挡关系

Z值并非真正的笛卡尔空间坐标系中的欧几里德距离( Euclidean distance )，而是一种顶点到视点距离的相对度量。

Z Buffer中存放的z值不一定是线性变化的。在正投影中的同一图元相邻像素的Z值是线性关系的，但在透视投影中却不是的。透视投影中这种关系是非线性的，而且非线性的程度随着空间点到视点的距离增加而越发明显。

Z精度值决定了物体之间的相互遮挡关系

两个相距很近的物体将会出现随机遮挡的现象，这种现象称为 flimmering 或 Z-fighting

## 2.4.3 Stencil Buffer

Stencil buffer:模板缓冲区

它是一个额外的buffer，通常附加到 z buffer 中。

2.4.4 Frame Buffer

帧缓冲器，用于存放显示输出的数据，这个buffer中的数据一般是像素颜色值。

## 2.5 本章小节

图形绘制管线是GPU编程的基础