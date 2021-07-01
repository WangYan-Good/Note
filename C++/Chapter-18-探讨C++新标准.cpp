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
  C++ 11 新增了一种枚举，这种枚举使用 class 和 struct 定义：
  enum class New1 { ... };;
  enum struct New2 { ... };;


