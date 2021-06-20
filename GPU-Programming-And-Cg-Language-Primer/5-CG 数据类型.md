本章将着重介绍Cg语言中预定义的内置 （ built in）的、 或称为基本 （ primitive）的数据类型  

学习本章时，需要体会内置向量类型和数组类型的区别  

# 5.1 基本数据类型  

Cg支持7种数据类型：

float 32bit浮点数据，一个符号位

half 16bit浮点数据

int 32bit整型数据

fixed 12bit定点数

bool 布尔数据

sample* 纹理对象的句柄

string 字符类型 可以通过 Cg runtime API 声明该类型变量，并赋值  



Cg还内置了向量数据类型（built-in vector data types）内置的向量数据类型基于基础数据类型，如：float4 表示float类型的4元向量；bool4表示bool类型的4元向量

注意：向量最长不能超过4元

初始化向量一般为： float4 array = float4(1.0, 2.0, 3.0, 4.0);  

较长的向量还可以通过较短的向量进行构建：  

float2 a = float2(1.0, 1.0);
float4 b = float4(a, 0.0, 0.0);  

此外， Cg 还提供矩阵数据类型，不过最大的维数不能超过 4*4 阶  

float1x1 matrix1;//等价于 float matirx1; x 是字符，并不是乘号！
float2x3 matrix2;// 表示 2*3 阶矩阵，包含 6 个 float 类型数据
float4x2 matrix3;// 表示 4*2 阶矩阵，包含 8 个 float 类型数据
float4x4 matrix4;//表示 4*4 阶矩阵，这是最大的维数  

矩阵的初始化方式为：
float2x3 matrix5 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};  

注意： Cg 中向量、矩阵与数组是完全不同，向量和矩阵是内置的数据类型（矩阵基于向量），而数组则是一种数据结构，不是内置数据类型！  

# 5.2 数组类型  