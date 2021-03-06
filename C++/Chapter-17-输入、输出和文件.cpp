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
  cin 对象将标准输入表示为字节流
  cin 对象根据接收值的变量的类型，使用其方法将字符序列转换为所需的类型。
  cin >> value_holder;
  value_holder 为存储输入的内存单元，它可以是变量、引用、被解除引用的指针，也可以是类或结构的成员。

  典型的运算符函数的原型如下：
  istream & operator >> ( int & );

  每个抽取运算符都返回调用对象的引用，例如： cin >> name >> fee >> group;
  cin >> name 返回的 cin 对象成了处理 fee 的对象

  cin >> 如何检查输入
  不同版本的抽取运算符查看输入流的方法是相同的。它们跳过空白（空格、换行符和制表符），直到遇到非空白字符

  流状态
  eofbit | badbit | failbit | goodbit | good() | eof() | bad() | fail() | rdstate() | ...

  设置状态
  clear() 方法将状态设置为它的参数，例如：
  clear( eofbit );

  setstate() 方法只影响其参数中已设置的位，下面的调用将设置 eofbit, 例如：
  setstate( eofbit );

  I / O 和异常

  流状态的影响
  设置流状态有一个非常严重的后果；流将对后面的输入和输出关闭，直到位被清除
  如果希望程序在流状态被设置后能够读取后面的输入，就必须将流状态重置为良好。可以通过 clear() 方法实现

  其他 istream 类方法
  1. 单字符输入
  get( char & )

  get( void )  该成员函数还读取空白，但使用返回值来将输入传递给程序，返回类型位 int（或某种更大的整型，这取决于字符集和区域）

  2. 采用哪种单字符输入形式
  如果跳过空白更方便，则使用 >>
  如果希望程序检查每个字符，请使用 get() 方法
  在 get() 方法中， get( char & ) 的接口更佳
  可以通过包含 iostream (而不是 stdio.h)，并用 cin.get() 替换所有的 getchar(), 用 cout.put(ch)替换所有的 putchar(ch)

  3. 字符串输入： getline()、get()和 ignore()
  get() 和 getline() 之间主要的区别在于，get() 将换行符留在输入流中，这样接下来的输入操作首先看到是换行符，而 getline() 抽取并丢弃输入流中的换行符
  get() 将分界符留在输入队列中，而 getline() 不保留

  4. 意外字符串输入
  get( char * , int ) 和 getline在遇到文件尾时将设置 eofbit(), 遇到流被破坏时将设置 badbit

  其他 istream 方法
  read(): read() 最常与 ostream write() 函数结合使用，来完成文件的输入输出, 返回类型为 istream &
  peek():返回输入流中的下一个字符，但是不抽取输入流中的字符
  gcount(): 返回最后一个非格式化抽取方法读取的字符数
  putback(): 将一个字符插入到字符串中，被插入的字符将是下一条输入语句读取的第一个字符

17.4 文件的输入和输出
  文件本身是存储在某种设备上的一系列字节
  操作系统管理文件，跟踪它们的位置、大小、创建时间等
  一般需要的只是将程序与文件相连的途径、让程序读取文件的途径以及让程序创建和写入文件的途径
  重定向来自操作系统而非 C++ , 因此并非所有系统都有这样的功能

  C++ I / O 类软件包处理文件输入和输出的方式与处理标准输入和输出的方式非常相似
  要写入文件，需要创建 ofstream 对象，并使用 ofstream 方法，如 << 插入运算符或 write()
  要读取文件，需要创建 ifstream 对象，并使用 ifstream 方法，如 >> 抽取运算符或 get()
  C++ 还定义了一个 fstream 类， 用于同步文件 I / O

  简单的文件I / O
  让程旭写入文件：
  创建一个 ofstream 对象来管理输出流
  将该对象与特定文件关联起来
  以使用 cout 的方式使用该对象，唯一的区别是输出将进入文件，不是屏幕，例如：
  ofstream fout;
  fout.open("jar.txt");
  ofstream fout("jar.txt");
  fout << "Dull Data";

  ostream 是 ofstream 类的基类， 因此可以使用所有的 ostream 方法
  ofstream 类使用被缓冲的输出，程序在在创建 ofstream 对象时，将为缓冲区分配空间
  警告：以默认模式打开文件进行输出将自动把文件长度截短为 0 , 这相当于删除已有数据。

  读取文件
  创建一个 ifstream 对象来管理输入流
  将该对象与特定的文件关联起来
  以使用 cin 的方式使用该对象，例如：
  ifstream fin;
  fin.open("jellyjar.txt");

  ifstream fis("jamjar.txt");
  当输入和输出流对象过期时，到文件的连接将自动关闭。另外，也可以使用 close() 方法来显示地关闭到文件的连接
  fout.close();
  fin.close();
  关闭连接并不会删除流，只会断开到文件的连接，但是流管理装置仍被保留。
  可以将流重新连接到同一个文件或另一个文件。

  流状态检查和 is_open()
  C++ 文件流类从 ios_base 类那里继承了一个流状态成员，该成员存储了指出流状态地信息：一切顺利、已到达文件尾、I / O 操作记录等
  较新的 C++ 实现提供了一种更好的检查文件是否被打开的方法，is_open() 方法

  打开多个文件
  如果需要同时打开两个文件，则必须为每个文件创建一个流
  可以同时打开的文件数取决于操作系统
  对于要依次处理的一组文件，可以打开一个流，并将它依次关联到各个文件

  命令行处理技术
  命令行参数是用户在输入命令时，在命令行中输入的参数
  命令行参数与命令行操作系统紧密相关
  在程序末尾是否需要使用 fin.clear(), 取决于将文件与 ifstream 对象关联起来时，是否自动重置流状态。

  文件模式
  文件模式描述的是文件将被如何使用：读、写、追加等
  ios_base 类定义了一个 openmode 类型，用于表示模式
  ios_base::in
  ios_base::out
  ios_base::ate
  ios_base::app
  ios_base::trunc
  ios_base::binary
  fstream 类不提供默认的模式值，因此在创建这种类的对象时，必须显示地提供模式
  要以二进制格式存储数据，可以使用 write() 成员函数，该函数只会逐字节地复制数据，而不进行任何转换。
  要使用文件恢复信息，可以通过一个 ifstream 对象使用相应的 read() 方法
  可以利用二进制将结构体保存到文件中，同样的方法也适用于不适用虚函数的类

  随机存储
  随即存储指的是直接移动到文件的任何位置
  fstream 类继承了两个方法：seekg() 和 seekp()
  前者将输入指针移动指定的文件位置
  后者将输出指针移动到指定的文件位置
  事实上指针指向的是缓冲区位置

  使用临时文件
  cstdio 中声明的 tmpnam() 标准函数船舰一个临时文件名
  char* tmpnam( char * pszName );

17.5 内核格式化
  iostream 族支持程序与终端之间的I / O
  fstream 族使用相同的接口程序和文件之间的I / O
  C++ 库还提供了 sstream 族，他们使用相同的接口提供程序和 string 对象之间的 I / O

  读物 string 对象中的格式化信息或将格式化信息写入 string 对象中被称为内核格式化
  头文件 sstream  定义了一个从 ostream 类派生而来的 ostringstream 类
  ostringstream 类有一个名为 str() 的成员函数，该函数返回一个被初始化为缓冲区内容的字符串对象，例如：
  string mesg = outstr.str();

  istringstream 类允许使用 istream 方法族读取 isstringstream 对象中的数据， istringstream 对象可以使用 string 对象进行初始化
  istringstream 和 ostringstream 类使得能够使用 istream 和 ostream 类的方法来管理存储字符串中的字符数据
