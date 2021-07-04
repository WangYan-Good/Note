本章内容包括：

​	移动语义和右值引用

​	Lambda 表达式

​	包装器模板 function

​	可变参数模板

# 18.1 复习前面介绍过的C++11功能

​	新类型
  C++ 11 新增了 long long 和 unsigned long long 以支持64位
  新增了 char16_t 和 char32_t, 以支持 16 位和 32 位的字符表示

  统一的初始化
  C++ 11 扩大了大括号括起的列表的适用范围，可用于所有内置类型和用户定义的类型，使用初始化列表时可以添加等号（=），也可不添加
  int x = { 5 };
  double y { 2.75 };
  short quar[5] { 4,5,2,76,1 };

  列表初始化也可用于 new 表达式中：
  int * ar = new int [4] { 2,4,6,7 };

  也可使用大括号括起的列表来调用构造函数
  class Stump
  {
    ...
  };

  Stump s2 { 5, 43.4 };

  如果类有将模板 std::initializer_list 作为参数的构造函数，则只有该构造函数可以使用列表初始化形式

  缩窄
  初始化列表可防止缩窄，即禁止将数值赋给无法存储它的数值变量，如下：
  char c1 = 1.57e27;
  char c1 = { 1.57e27 };

  std::initializer_list

  声明
  auto 存储类型说明符，用于实现自动类型推断
  auto 还可以简化模板声明

  decltype: 将变量的类型声明为表达式指定的类型。
  下面语句让 y 的类型与 x 相同，其中 x 是一个表达式：
  decltype {x} y;
  这在定义模板时特别有用，因为只有等到模板被实例化时才能确定类型。

  返回类型后置
  C++ 11 新增了一种函数声明语法：在函数名和参数列表后面指定返回类型：
  double f1( double , int  );
  auto f2( double, int ) -> double;

  它可以使用 decltype 来指定模板函数的返回值
  template < typename T, typename U >
  auto eff( T t, U u ) -> decltype ( T * U )
  {
    ...
  }
  在编译器遇到 eff的参数列表前，T 和 U 还不在作用域内，因此必须在参数列表后使用 decltype

  模板别名： using
  以前 C++ 为了创建别名，提供了 typedef
  C++ 11 提供了另一种创建别名的语法：
  using itType = std::vector<std::std::string>::iterator
  新语法可用于模板部分具体化，但是 typedef 不能，例如：
  template<typename T>
    using arr12 = std::array<T, 12>;
  可将其替换为如下声明：
  arr12<double> a1;
  arr12<std::string> a2;

  nullptr
  空指针是不会指向有效数据的指针

  智能指针
  如果在程序中使用 new 从堆（自由存储区）分配内存，等到不再需要时，应使用 delete 将其释放
  基于程序员的编程体验和 BOOST 库提供的解决方案， C++ 11摒弃了 auto_ptr, 并新增了三种智能指针： unique_ptr, shared_ptr, weak_ptr

  异常规范方面的修改
  以前，C++提供了异常规范
  在C++ 11 中摒弃了异常规范，但是标准委员会认为，指出函数不会引发异常有一定的价值，为此添加了关键字 noexcept;
  void f875 ( short, short ) noexcept;

  作用域内枚举
  传统的 C++ 枚举提供了一种创建名称常量的方式，作用域为枚举定义所属的作用域
  C++ 11 新增了一种枚举，解决了不能完全移植的问题，这种枚举使用 class 和 struct 定义：
  enum class New1 { ... };;
  enum struct New2 { ... };;
  新枚举要求进行显示限定，以免发生名称冲突，例如： New1::never

  对类的修改
  显示转换运算符
  C++ 引入了关键字 explicit ,以禁止单参数构造函数导致的自动转换
  C++ 11 拓展了 explicit 的用法，使得可对转换函数做类似的处理

  类内成员初始化
  C++ 11 允许在类定义中初始化成员，需要使用等号 " = " 或大括号 "{ }" 初始化成员，不能使用圆括号

  模板和 STL 方面的修改
  基于范围的 for 循环

  新的 STL 容器
  forward_list,  单向链表实现

  哈希表实现
  unordered_map,
  unordered_multimap,
  unordered_multiset,
  unordered_set

  C++ 11 还增加了 array, 可指定元素类型和固定的元素数，例如：
  atd::array<int, 360> ar;

  新的 STL 方法
  C++ 11 新增了 STL 方法 cbegin() 和 end() , 其放回一个迭代器，指向容器的第一个元素和最后一个元素的后面，这些新方法将元素视为 const

  valarray 升级
  模板 valarray 独立于 STL 开发的，最初的设计导致无法将基于范围的 STL 算法用于 valarray 对象。
  C++ 11 添加了两个函数 begin() 和 end() 都接受 valarray 作为参数，并返回迭代器

  摒弃 export
  C++ 98 新增了关键字 export 让程序员能够将模板定义放在接口文件和实现文件中， C++ 11 终止了这种用法，但仍然保留了关键字 export

  尖括号
  为避免与运算符 >> 混淆，C++ 要求在声明嵌套模板时使用空格将尖括号分开
  C++ 11 中不再这样要求

  右值引用
  左值是一个表示数据的表达式，程序可获取其地址
  C++ 11 新增了右值引用，这是使用 && 表示的，可以出现在赋值表达式的右边但不能对其应用地址运算符的值
  引入右值引用的主要目的之一是实现移动语义

18.2 移动语义和右值引用
  为何需要移动语义
  移动语义实际上避免了移动原始数据，而只是修改了记录
  要实现移动语义，需要采取某种方式，让编译器知道什么时候需要复制，什么时候不需要。

  一个移动示例

  移动构造函数解析

  赋值

  强制移动
  右值引用带来的主要好处并非是能够编写使用右值引用的代码，而是能够使用利用右值引用实现移动语义的库代码

18.3 新的类功能
  特殊的成员函数
  在原有的 4 个特殊成员函数 默认构造函数，赋值构造函数，复制赋值运算符和析构函数
  C++ 11 新增了两个： 移动构造函数 和 移动赋值运算符

  默认的方法和禁用的方法
  当提供了移动构造函数时，编译器不会自动创建默认的构造函数、赋值构造函数和复制赋值构造函数，这时可以使用关键字 default 显式的声明这些方法的默认版本。
  另一方面，关键字 delete 可用于禁止编译器使用特定方法，例如，要禁止复制对象，可禁用复制构造函数和复制赋值运算符
  关键字 default 只能用于 6 个特殊成员函数， 但 delete 可用于任何成员函数

  委托构造函数

  继承构造函数

  管理虚方法： override 和 final
  在 C++ 11 中，可使用虚说明符 override 指出要覆盖一个虚函数：将其放在参数列表后面
  如果想要禁止派生类覆盖特定的虚方法，可在参数列表后面加上 final
  说明符 override 和 final 并非关键字，而是具有特殊含义的标识符

18.4 Lambda 函数
  1. 比较函数指针、函数符和 Lambda 函数
    假设: 生成一个随机数列表，判断多少数可以被 3 整除，多少个整数可被 13 整除
    (1) 使用 vector<int> 存储数字，并使用 STL 算法 generate() 在其中填充随机数
      #include <vector>
      #include <algorithm>
      #include <cmath>
      ...
      std::vector<int> numbers(1000);
      std::generate( vector.begin(), vector.end(), std::rand );

      也可以通过使用算法 count_if(), 例如:
      bool f3( int x ) { return x % 3 == 0; }
      int count3 = std::count_if ( numbers.begin(), numbers.end(), f3 );
    (2) 函数符
      class f_mod
      {
      private:
        int dv;
      public:
        f_mod( int d = 1 ):dv(d) {}
        bool operator() ( int x ) { return x % dv == 0; }
      };

      f_mod obj( 3 );
      count3 = std::count_if( numbers.begin(), numbers.end(), f_mod(3) );

    (3) 最后来看看 lambda 的情况
      名称 lambda 来自 lambda calculus, 一种定义和应用函数的数学系统，该系统能够使用匿名函数
      在 C++ 11 中，对于接受函数指针或函数符的函数，可使用匿名函数定义( lambda )作为其参数，与前面对应的 f3() 对应的 lambda 如下:
      [] ( int x ) { return x % 3 == 0; }
      与之前的差别有两个:
        (1) 使用 [] 替代了函数名
        (2) 没有声明返回类型，返回类型相当于使用 decltyp 根据返回值推断得到的， 如果 lambda 不包含返回语句，推断出的返回类型将为 void
      也就是说，使用2整个 lambda 表达式替换函数指针或函数符构造函数
      仅当 lambda 表达式完全由一条返回语句组成时，自动类型推断才管用；否则需要使用新增的返回类型后置语法:
      [] (double x) -> double { int y = x; return x = y;} // return type is double

  2. 为何使用 lambda
    lambda 可访问作用域内的任何动态变量：要捕获要使用的变量，可将其名称放在中括号内。
    如果只指定了变量名，如 [z] , 将按值访问变量；如果名称前加上 &， 如 [ &count ], 将按引用访问变量。
    [&] 能够按引用访问所有的动态变量，而 [=] 能够按值访问所有动态变量，还可以混合使用这两种形式

  在 C++ 中引入 lambda 的主要目的是，能够将类似于函数的表达式用作接受函数指针或函数符的函数参数。

18.5 包装器
  C++ 除了提供了 bind1st 和 bind2nd, 还提供了其他包装器
  包括模板 bind , mem_fn 和 reference_wrapper 以及包装器 function
  模板 bind 可替代 bind1st 和 bind2nd, 但更灵活
  模板 mem_fn 能够将成员函数作为常规函数进行传递
  模板 reference_wrapper 能够创建行为像引用但可被复制的对象
  包装器 function 能够以统一的方式处理多种类似于函数的形式

  1. 包装器 function 及模板的低效性

  2. 修复问题
    包装器 function 能够使程序员重写程序，使得调用特征标 ( call signature ) 相同的模板只生成一个函数实例
    模板 function 是在头文件 functional 中声明的，它从特征标的角度定义了一个对象；可用于包装调用特征标相同的函数指针、函数对象或 lambda 表达式。

  3. 其他方式

18.6 可变参数模板
  可变参数模板 ( variadic template ) 让您能够创建 可接受可变数量的的参数 的模板函数和模板类
  要创建可变参数模板，需要理解几个要点:
    模板参数包 ( parameter pack )
    函数参数包
    展开 ( unpack ) 参数包
    递归

  1. 模板和函数参数包
    C++ 提供了一个用省略号表示的元运算符 ( meta-operator ), 让您能够表示模板参数包的标识符，模板参数包基本上是一个类型列表
    同样，它还可以声明表示函数参数包的标识符，而函数参数包基本上是一个值列表
    template < typename... Args >
    void show_list1 ( Args... args )
    {
      ...
    }

  2. 展开函数包
    函数如何访问包的内容，索引功能在这里不适用，可将省略号放在函数包名的右边，将参数包展开

  3. 在可变参数模板函数中使用递归
    将函数参数包展开，对列表中的第一项进行处理，再将余下的内容传递给递归调用，以此类推，直到列表为空
    template < typename T, typename... Args >
    void show_list3 ( T value, Args... args );

18.7 C++ 11 新增的其他功能
  1. 并行编程
    为解决并行性问题，C++ 定义了一个支持线程化执行的内存模型，添加了关键字 thread_local, 提供了相关的库支持。
    thread_local 将变量声明为静态存储，其持续性与特定线程相关：即定义这种变量的线程过期时，变量也将过期
    库支持由原子操作 ( atomic operation )  库和线程支持库组成，其中原子操作库提供了头文件 atomic, 而线程支持库提供了头文件 thread, mutex, condition_variable 和 future

  2. 新增的库
    头文件 random 支持可扩展随机数库
    头文件 chrono 提供了处理时间间隔的途径
    头文件 tuple 支持模板 tuple. tuple 使广义的 pair 对象
    头文件 ratio 支持编译阶段有理数算术库
    头文件 regex 支持正则表达式库

  3. 低级编程


