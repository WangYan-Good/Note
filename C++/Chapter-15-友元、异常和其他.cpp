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
