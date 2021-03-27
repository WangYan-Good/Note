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

