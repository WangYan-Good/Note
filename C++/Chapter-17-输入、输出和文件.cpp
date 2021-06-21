本章内容包括：
  C++ 角度的输入和输出
  iostream 类系列
  重定向
  ostream 类方法
  格式化输出
  istream
  流状态
  文件 I/O
  使用 ifstream 类从文件输入
  使用 ofstream 类输出到文件
  使用 fstream 类进行文件输入和输出
  命令行处理
  二进制文件
  随机文件访问
  内核格式化

17.1 C++ 输入和输出概述
  标准输入输出包的头文件为 stdio.h , 在 C++ 中使用 cstdio.h 头文件来支持I / O 函数
  C++ 依赖与 C++ 的 I / O 解决方案，而不是C语言的I/O解决方案。
  C++ 的 I/O 解决方案是在头文件 iostream 和 fstream 中定义一组类。

  流和缓冲区
  C++把输入和输出看作字节流。
  输入时，程序从输入流中抽取字节
  输出时，程序将字节插入到输出流中
  流充当了程序和流源或流目标之间的桥梁

  管理输入包含两步：
  将流与输入去向的程序关联起来
  将流与文件连接起来
  输入流需要两个连接，每端各一个。文件端部提供了流的来源，程序端连接将流的流出部分转储到程序中。
  对输出的管理包括将输出流连接到程序以及将输出目标与流关联起来。

  C++ 程序通常在用户按下回车键时刷新缓冲区

  流、缓冲区和 iostream 文件
  streambuf 类为缓冲区提供了内存，并提供了用于填充缓冲区、访问缓冲区内容、刷新缓冲区和管理缓冲区内存的类方法
  ios_base 表示流的一般特征，如是否可读取、是二进制还是文本流等
  ios 类基于 ios_base, 其中包括了一个指向 streambuf 对象的指针成员
  ostream 类是从 ios 类派生来的，提供了输出方法
  istream 类也是从 ios 类派生而来的，提供了输入方法
  iostream 类是基于 istream 和 ostream 类的，因此继承了输入方法和输出方法

  wcout 对象用于输出宽字符流

  重定向
  输入重定向 <
  输出重定向 >

17.2 使用cout进行输出
  C++将输出看作字节流
  ostream 类将数据内部表示(二进制模式)转换为由字符字节组成的输出流

  重载的 << 运算符
  << 默认含义是按位左移运算符
  ostream 类重新定义了 << 运算符，方法是将其重载为输出。

  其它 ostream 方法
  除了各种 operator<<() 函数外， ostream 类还提供了 put() 方法和 write() 方法，前者显示字符，后者显示字符串
  put() 方法原型
  ostream & put( char );

  write() 方法显示整个字符串，模板原型如下：
  basic_ostream< charT, traits > & write( const char_type * s, streamsize n );
  第一个参数提供了要显示的字符串地址，第二个参数指出要显示多少个字符串
  write() 方法并不会在遇到空字符时自动停止打印字符，而只是打印指定数目的字符，即使超出了字符串的边界。

  刷新输出缓冲区
  由于 ostream 类对 cout 对象处理的输出进行缓冲，所以输出不会立即发送到目标地址，而是被存储在缓冲区，直到缓冲区满。
  可以通过控制符来强行刷新缓冲区，控制符 flush 刷新缓冲区，而控制符 endl 刷新缓冲区，还插入一个换行符

  事实上，控制符也是函数，可以直接调用 flush() 来刷新缓冲区： flush( out );

  用 cout 进行格式化
  进制控制符： dec、hex、oct，例如十六进制：hex(cout);
  控制符不是成员函数，因此不必通过对象来调用。以上例子与下面等价：
  cout << hex;
  控制符位于名称空间 std 中

  调整字段宽度
  可以使用 width 成员函数将长度不同的数字放到宽度相同的字段中，该方法的原型为：
  int width();
  int width( int i );
  第一种格式返回字段宽度的当前设置；
  第二种格式将字段宽度设置为 i 个空格，并返回以前的字段宽度值
  警告： width() 方法只影响接下来显示的一个项目，然后字段宽度将恢复默认值

  C++ 永远不会截短数据，如果试图在宽度为2的字段中打印一个7位数，C++ 将增宽字段。
  C/C++的原则是：显示所有的数据比保持列的整洁更重要。C++ 视内容重于形式

  填充字符
  cout 用空格填充字段中未被使用的部分，可以用 fill() 成员函数来改变填充字符
  cout.fill( '* ' );
  与地段宽度不同的是，新的填充字符将一直有效，知道更改它为止。

  设置浮点数的显示精度
  在定点模式和科学模式下，精度指的是小数点后面的位数
  C++ 的默认精度为 6 位， precision() 成员函数使得能够选择其他值，例如将 cout 的精度设置为 2
  cout.precision( 2 );
  与 fill() 类似，新的精度设置将一直有效

  打印末尾的 0 和小数点
  ios_base 类提供了一个 self() 函数（用于 set 标记），能够控制多种格式化特性。
  下面的函数调用使 cout 显示末尾小数点
  cout.setf( ios_base::showpoint );
  showpoint 是ios_base类声明中定义的类级静态常量。

  再谈 setf()
  setf() 方法控制了小数点被显示时其他几个格式选项
  setf() 函数有两个原型，第一个为：
  fmtflags setf( fmtflags );

  注意：bitmask 类型是一种用来存储各个位值的类型

  第二个 setf() 原型接受两个参数，并返回以前的设置：
  fmtflags setf( fmtflags, fmtflags );
  第一个参数包含了所需设置的 fmtflags 值
  第二参数指出要清楚第一个参数中的哪些位
  下面的函数调用与使用十六进制控制符的作用相同：
  cout.setf( ios_base::hex, ios_base::basefield );

  默认的 C++ 模式对应于 %g 说明符，定点表示法对应于 %f 说明符，而科学表示法对应于 %e 说明符

  C++ 标准中，定点表示法和科学表示法都有下面两个特征：
  精度指的是小数位数，而不是总位数
  显示末尾的 0

  调用 setf() 的效果可以通过 unseff() 清除， 后者原型如下：
  void unsetf( fmtflags mask );
  setf() 将位设置为 1, unsetf() 将位恢复为 0

  启用默认模式的方法之一如下：
  cout.setf( 0, ios_base::floatfield );

  标准控制符

  iomanip
  使用 iostream 工具来设置一些格式值不太方便，C++ 在头文件 iomanip 中提供了其他一些控制符
  3 个最常用的控制符分别是 setprecison() , setfill(), setw()
  分别用于设置精度、填充字符和字段宽度

17.3 使用cin进行输入

