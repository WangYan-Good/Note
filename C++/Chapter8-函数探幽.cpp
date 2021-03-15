8.1 C++内联函数
  内联函数与常规函数区别在于内联函数C++编译器将它们组合到程序中的方式不一样

  函数声明前加上关键字 inline
  函数定义前加上关键字 inline

  内联函数不能递归

8.2 引用变量
  引用变量的主要用途是改变是用作函数的形参

  创建和引用变量
  int rats;
  int & rodents = rats;

  引用在声明对象时需要被初始化，且之后不可改变所指向的对象。
  以下代码表达的效果相同
  int & rodents = rats;
  int * const pr = &rats;

  不能将表达式或常量按照变量的引用传递

  左值参数：可被引用的数据对象
  右值引用：C++11的新特性，可对赋值语句的右边进行引用（右值-不能通过地址访问的值）

  ofstream 类是从 ostream 类派生出来的

  适合使用引用参数的条件：
  1.程序员能够修改调用函数中的数据对象
  2.通过传递引用而不是整个数据对象，可以提高程序的运行速度

  一般传递对象时用引用传递

8.3 默认参数
  Example: char * left ( const char * str, int n = 1 );
  以上参数 n 为默认参数，在不指定参数 n 的时候，默认使用n = 1;

  通过使用默认参数，可以减少要定义的析构函数，方法以及方法重载的数量。

8.4 函数重载
  通过使用不同数目的参数调用通过一个函数
  函数特征标(function signature):函数的参数列表

  当调用参数无法与函数原型匹配时，C++将尝试类型转换，若有多个可转换类型匹配，则视为错误。
  Example：
    print( float, int );
    print( int, int );
    print( double, int );

    unsigned int year = 3210;
    print( year, 6 );
  以上情况会被视为错误， unsigned int 类型转换后有以上三个函数原型可以匹配，将会视为错误。

  在使用引用时，C++将类型引用和类型本身视为同一个特征标

  对于 const 与 非const 变量， C++编译器不将其区分

  仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应采用函数重载。

  在进行重载的过程中，C++编译器将会根据函数形参类型对每个函数名进行加密，称之为名称修饰或名称矫正。

8.5 函数模板
  模板定义
  template <typename AnyType>
  BaseType functionname( AnyType &a, AnyType &b )
    Segment

  template <class AnyType>
  BaseType functionname( AnyType &a, AnyType &b )
    Segment

  模板并不创建任何函数，只是告诉编译器如何定义函数，由编译器根据类型来创建函数

  相同模板函数中相同类型，需要注意数组，结构等类型的计算和赋值

  模板函数和具体化的原型
  template <> BbseType functionname<typename>(typename &, typename &)

  编译器使用模板位特定类型生成函数定义时，得到的是模板实例( instantiation )

  与显示实例化不同的是，显示具体化不使用模板来生成函数定义，而使用专门为具体类型的显示地定义的函数定义。
  显示具体化声明在关键字temppate后包含<>，而显示实例化没有。


