本章内容包括：
  友元类
  友元类方法
  嵌套类
  引发异常、try块和catch块
  异常类
  运行阶段类型识别（RTTI）
  dynamic_cast 和 typeid
  static_cast 、 const_cast 和 reinterpret_cast

  15.1 友元
  类除了拥有友元函数，也可以将类作为友元
  友元类的所有方法都可以访问原始类的私有成员和保护成员，也可以作更严格的限制，可以只将特定的成员函数指定为另一个类的友元

  友元类
  遥控器和电视机是一组典型的友元类实例，即Tv类和Remote类

  友元成员函数
  可以选择特定的类成员成为另一个类的友元
  例如：让 Remote::set_chan() 成为Tv类的友元

  class Tv
  {
    friend void Remote::set_chan( Tv & t, int c );
    ...
  };

  避免循环依赖，选择前向声明，在Remote 定义前使用如下语句：
  class Tv;

  排列顺序如下：
  class Tv;
  class Remote { ... };
  class Tv { ... };

  在Remote类中，调用了 Tv 类中的内联函数，一般在Remote声明中只包含方法声明，定义实现放在Tv类定义后面。

  其他友元关系
  让类成为彼此对方的友元

  共同的友元
  可以将一个函数，设置为多个类共同的友元

  15.2 嵌套类
  C++中可以将类声明放在另一个类中，这样的声明的类被称为嵌套类，包含类的成员函数可以创建和使用被嵌套的对象。

  对类的嵌套与包含并不同，包含指的是将类杜象作为另一个类的成员，而对类嵌套不创建类成员，而是定义了一种类型

  嵌套类和访问权限
  在哪些地方可以使用嵌套类以及如何使用嵌套类，取决于作用域和访问控制

  在类中声明的嵌套类的声明如果在类的公有部分，则可以通过类的限定符来访问嵌套类，但是对于声明在类的私有部分的嵌套类，则只有在类内部才能访问。
  对于声明在共有部分的嵌套类，如下：
  class Team
  {
  public:
    class Coach { ... };;
    ...
  };

  如果要访问以上的内部类，可以使用下面的案例：
  Team::Coach forhire;

  模板中的嵌套
  将Queue类定义为模板时，不会因为它包含模板类而带来问题

  15.3 异常

  调用abort(): 改函数原型位于头文件 cstdlib (或 stdliib.h )中，典型实现是向标准错误流( cerr 使用的错误流 )发送消息 abnormal program termination （程序异常中止），然后中止程序，返回一个随实现而异的值。

  异常机制
  引发异常: throw
  使用处理程序捕获异常: catch
  使用try块: try

  注: catch  接收由 throw 抛出的异常类型

  如果函数引发了异常，而没有 try 块或没有匹配的处理程序时，默认会调用 abort() 函数。

  将对象用作异常类型
  通常引发的函数将传递一个对象，可以使用不同的异常类型来区分不同的函数在不同情况下引发的异常

  异常规范和C++11
  C++98 中新增了异常规范（exception specification），但在 C++11 中被摈弃了。
  异常规范的作用之一: 告诉用户可能需要使用 try 块，然而这项工作也可使用注释轻松完成。
  异常规范的作用之二: 让编译器添加执行运行阶段检查的代码，检查是否违反了异常规范。
  C++11 建议忽略异常规范

  C++中的特殊的异常规范: noexcept
  该关键字指出函数不会引发异常，例如:
    double marm() noexcept;

  类构造函数修饰符:
    explicit: 用于修饰只有一个参数的类构造函数，它表示该类的构造函数是显示的。
    implicit: 与 explicit 相对应，表示类构造函数是隐藏的。

  栈解退
  假如 try 块没有直接调用引发异常的函数，而是调用了对引发异常的函数进行调用的函数，则程序流程将从引发异常的函数跳到包含 try 块和处理程序的函数。

  其他异常特性
  1) 与函数参数返回机制不同的是，普通函数调用结束后将控制权返回到调用该函数的函数，但 throw 语句将控制权向上返回到第一个这样的函数：包含能够捕获相应异常的 try-catch 组合。
  2) 引发异时编译器总是创建一个临时拷贝，即使异常规范和 catch 块中指定的是引用。

  引用的另一个重要特征：基类引用可以执行派生类对象。因此，异常规范中仅需列出一个基类引用，它将任何派生类引用。

  对于不知道类型的异常，可以使用省略号来捕获任何异常。
  catch ( ... ) { /*statements*/ } //catch any type exception

  在 catch 语句中使用基类对象时，将捕获所有的派生类对象，但派生特性将被剥去，因此将使用虚方法的基类版本。

  exception 类
  该类定义在 exception 头文件  （以前为 exception.h 或 except.h）

  C++ 库定义了很多基于 exception 的异常类型
  stdexcept 异常类: 该文件定义了 logical_error 和 runtime_error 类，且以公有方式从 exception 类派生而来。

  bad_alloc 异常和 new
  对于使用 new 导致的内存分配问题，C++ 处理的方式是让 new 引发 bad_alloc 异常。
  头文件 new 包含 bad_alloc 类的声明，它是从 exception 类公有派生而来的。

  在 bad_alloc 异常以前，很多代码都是在 new 失败时返回空指针，C++ 标准提供了一种在失败时返回空指针的 new, 用法如下:
    int * pi = new (std::nothrow) int;
    int * pa = new (std::nowthrow) int [500];

  异常、类和继承
  三种方式相互关联
  1) 可以从一个异常类派生出另一个
  2) 可以在类定义中嵌套异常类声明来组合异常
  3) 嵌套声明本身可以被继承，可以用作基类

  有关异常的注意事项
  1) 使用异常会增加程序代码，降低运行效率
  2) 异常规范不适用于模板，因为模板函数引发的异常可能随特定的具体化而异
  3) 异常和动态内存分配并非总能协同工作

15.4 RTTI
  RTTI 是运行阶段类型识别的简称 （Runtime Type Identification）的简称
  RTTI 针对那些派生对象可能包含不是继承而来的方法，可能出于调试目的或是想跟踪生成对象的类型，并为此提供解决方案。

  RTTI 的工作原理

  C++ 有3个支持RTTI的元素
  1) dynamic_cast 运算符将使用一个指向基类的指针来生成一个指向派生类的指针，否则该运算符返回0--空指针
  2) typeid 运算符返回一个指向对象的类型的值
  3) type_info 结构存储了有关特定类型的信息
  只能将 RTTI 用于包含虚函数的类层次，只有对于这种类层次结构，才应该将派生类对象的地址赋给基类地址

  dynamic_cast 运算符: 它不能回答“指针指向的是哪类对象”，但能回答“是否可以安全地将对象的地址赋给特定类型的指针”
  要调用方法，类型不一定要完全匹配，而可以定义了方法的虚拟版本的基本类型。
  如果指向的对象(*pt)的类型为 type 或者是从 type 直接或间接派生出来的类型，下面的表达式将指针pt转换为type类型的指针：
  dynamic_cast<Type *> (pt)
  否则，结果为0，即空指针

  typeid 运算符和 type_info 类
  typeid 运算符能够确定两个对象是否为同种类型，它接受两个参数：
  1) 类名
  2) 结果为对象的表达式
  typeid 运算符返回一个对 type_info 对象的引用， type_info  在头文件 typeinfo 中声明

  如果发现在扩展的 if else 语句系列中使用了 typeid  ，则应考虑是否应该使用虚函数和 dynamic_cast

  const_cast 运算符用于执行只有一种用途的的类型转换，改变值为 const 或 volatile ,  其用法与 dynamic_cast 运算符相同:
    const_cast <type-name > (expression)
  const_cast 运算符可以删除 const int* pt 中的 const

  static_cast 运算符的语法与其他类型转换运算符相同
  static_cast <type-name> (expression)
  仅当 type_name 可被隐式转换为 expression 所属的的类型或者 expression 可被隐式转化为 type_name 所属的类型时，类型转换才是合法的，否则将会出错。

  reinterpret_cast 运算符用于天生危险的类型转换。它不允许删除 const ，但会执行其他令人生厌的操作。有时程序员必须做一些依赖于实现的、令人生厌的操作。
  该运算符的语法与另外三个相同：
  reinterpret_cast <type-name> (expression)

  由于 char 类型太小，不能存储指针，在C语言中是允许的，但C++中是通常不允许。
  char ch = char (&d);
