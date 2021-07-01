11.1 运算符重载
  C++多态类型之一的形式便是运算符重载
  C++的另一种重载形式是能够定义多个名称相同但特征标不同的函数，这被称为函数重载或函数多态。

  C++允许将运算符重载扩展到用户定义的类型，例如允许使用+将两个对象相加。

  重载运算符需要使用运算符函数的特殊函数形式，格式如下：
  operatorop( argument-list )
  例如：
  operator+(), operator-(), operator*(), operator/();

11.2 计算时间：一个运算符重载示例
  Time operator+( const Time & t ) const;
  返回一个Time类对象，可以使用以下两种方法表示：
  1. total = coding.operator+(flxing);
  2. total = coding + fixing;

  重载限制
  多数C++运算符都可以用这样的形式重载，重载的运算符不必是成员函数，但必须至少有一个操作数是用户定义的类型。
  1.重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。
    例如，用户不能将（-）减法运算符重载为计算两个double值的和。

  2.使用运算符时不能违反运算符原来的句法规则。
    例如，不能将求模运算符( % )重载成使用一个操作数。
    同样，不能修改运算符的优先级。

  3.不能重载新运算符
    例如，不能定义operator**()函数来表示求幂

  4.不能重载下面的运算符：
    sizeof:sizeof运算符
    .:成员运算符
    .*:成员指针运算符
    ::：作用域解析运算符
    ?:：条件运算符
    typeid：一个RTTI运算符
    const_cast：强制类型转换运算符
    dynamic_cast：强制类型转换运算符
    reinterpret_cast：强制类型转换运算符
    static_cast：强制类型转换运算符

  5.具体可重载运算符可参见其他详细资料

11.3 友元
  友元是C++提供的另一种访问私有类型数据的访问权限，有3种：
  1.友元函数
  2.友元类
  3.友元成员函数

  在为类重载二元运算符时常常需要友元。通过一个重载的(*)运算符：
  A = B * 2.75
  等价于
  A = B.operator*( 2.57 );

  但是下列情况可能会出错：
  A = 2.75 * B 等价于 A = 2.75.operator*( B ) 显然这是不对的
  其中 2.75 不是一个对象

  解决方法：
  1. 服务器友好-客户警惕型( server-friendly, client-beware ),与OOP无关
  2. 非成员函数： Time operator*( double m， const Time & t );
     则 A = 2.75 * B 等价于 A = operator*( 2.75, B )

  可以通过友元函数来访问私有数据来解决以上问题

  创建友元函数，首选需要在类中声明友元函数，在原型声明前加上关键字 friend
  friend Time operator*( ... );
  注意：
  1. 在类中声明的友元函数，不是成员函数， 不能使用成员运算符调用
  2. 友元函数与成员函数访问权限相同

  重载<<运算符
  要使<<运算符重载输出一个特定的类，需要分两步来完成：
  1. 第一种重载版本：通过使用类的成员函数，符合的形式应该是： classname << cout;

     通过使用下面类的友元函数进行重载：
    void operator<<( ostream & os, const Time & t );
      其中，重载函数时类Time的友元函数，因为需要访问Time的私有成员，但不一定是ostream类的友元函数，它并不直接访问oetream对象的私有成员
      使用形式：
    cout << classname;

    ostream另一个对象是cerr，它将输出发送到标准输出流，一般默认为显示器，但是在UNIX、Linux和Windows命令行环境中，可将标准错误流重定向到文件。

  2. 第二种重载版本：返回ostream对象的引用，以便于类似下列中的多重输出形式：
    cout << x << y;

11.4 重载运算符：作为成员函数还是非成员函数

11.5 再谈重载：一个矢量类
  矢量(vector)是工程和物理中使用的一个术语，它是一个有大小和方向的量

  计算机在屏幕上移动对象时也涉及到距离和方向，可以使用矢量来描述这类问题。

  使用状态成员
  Vector类存储了矢量的直角坐标和极坐标，它使用名为mode的成员来控制使用构造函数、reset()方法和重载operator<<()函数使用哪种形式

11.6 类的自动转换和强制类型转换
  C++将会自动转换相互兼容的类型
  C++新增关键字 explicit 用于关闭自动类型转换的特性，但仍然允许显示转换

  只有接收一个参数的构造函数，可以隐式转换类型，例如：
  Stonewt(double lbs);
  可以写成下面的形式：
  Stonewt myCat;
  mycat = 19.6；

  对于接收多个参数的构造函数，如果除了第一个参数，其他参数均提供默认值，也可以用于隐式类型转换。

  通过关键字 explicit 关闭自动转换类型
  explicit Stonewt( double lbs );

  上述例子中，在不使用 explicit 关闭自动类型转换情况下，还可以用于下列情况的隐式转换：
  1. 将Stonewt对象初始化为double值时
  2. 将double值赋给Stonewt对象时
  3. 将double值传递给接收Stonewt参数的函数时
  4. 返回值被声明为Stonewt的函数试图返回double值时
  5. 在上述任意一种情况下，使用可转换为double类型的内置类型时。


  转换函数
  上述将数字转换为Stonewt对象，那么是否可以将Stonewt对象转换为 double 值，例如以下例子：
  Stronewt wolfe(285.7);
  double host = wolfe;

  通过使用C++运算符函数--转换函数，可以完成用户定义的强制类型转换。如下所示：
  Stonewt wolfe(wolfe);
  double host = double (wolfe);
  double thinker = (double) wolfe;

  创建转换函数
  operator typeName();
  示例如下：
  operator double();

  注意：
  转换函数必须是类函数
  转换函数不能指定返回类型
  转换函数不能有参数

  转换函数是类方法，需要通过类对象来调用，从而告知函数要转换的值，不需要参数
  operator int() 将转换的值四舍五入为最接近的值，而不是去除小数部分

  可以通过关键字 explicit 将转换运算符声明为显式的
  explicit operator int() const;




