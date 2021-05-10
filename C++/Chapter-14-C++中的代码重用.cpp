has-a 关系
包含对象成员的类
模板类valarray
私有和保护机继承
多重继承
虚基类
创建类模板
使用类模板
模板的具体化

14.1 包含对象成员的类
  包含(containment)
  组合(composition)
  层次化(layering)

  多重继承能够使用两个或更多的基类派生出新的类，将基类的功能组合在一起。

  valarray类
  valarray类由头文件valarray。
  使用valarray类声明对象时，需要在标识符valarray后面加上一对尖括号，并在其中包含所需的数据类型
  valarray<int> q_values;
  valarray<double> weights;

  valarray可以创建：
  长度为0的空数组
  指定长度的空数组
  所有元素都被初始化为指定值的数组
  用常规数组中的值进行初始化的数组

  valarray类的一些方法：
  operator[]():能够访问各个元素
  size():返回包含的元素数
  sum():返回所有元素的总和
  max():返回最大的元素
  min():返回最小的元素

  通常用于建立has-a关系的C++技术是组合(包含)，即创建一个包含其他对象的类，例如：
  class Student
  {
  private:
    string name;
    valarray<double> scores;
    ...
  };

  explicit防止构造函数的隐式转换

14.2 私有继承
  私有继承是另一种实现has-a关系的途径

  使用包含时将使用对象名来调用方法，而使用私有继承时将使用类名和作用域解析运算符来调用方法，例如：
  Student类私有继承ArrayDb,调用基类方法
  double Student::Average() const
  {
    if (ArrayDb::size() > 0)
      return ArrayDb::sum()/ArrayDb::size();
    else
      return 0;
  }

  访问基类对象
  可以通过强制类型转换完成，将子类对象转换为父类对象，其结果为继承而来的父类对象。
  例如子类Student获取基类对象的name成员:
  const string & Student::Name() const
  {
    return (const string &) *this;
  }

  在私有继承中，在不进行显示类型转换的情况下，不能将指向派生类的引用或指针赋给基类引用或者指针


  使用包含还是私有继承
  包含易于理解，针对同类的多个对象便于处理

  继承提供的特性比包含多，针对保护成员，继承是可以使用的，但是组合无法使用
  当需要重新定义虚函数时，继承可以进行重载，但是组合无法做到。

  保护继承
  保护继承是私有继承的变体，使用关键字protected
  class Student:protected std::string,
                 protected std::valarry<double>
  { ... };

  使用保护继承时，基类的私有成员无法继承，公有成员和受保护成员都将继承为受保护类型成员。

  使用using重新定义访问权限
  将函数调用包装在另一个函数调用中，如下所示：
  class Student : private std::string, private std::valarray<double>
  {
  public:
    using std::valarray<double>::min;
    using std::valarray<double>::max;
  };

  以上通过 using 声明，可以令私有继承或保护继承的子类直接调用基类方法。
  using 声明只使用成员名--没有圆括号、函数特征标和返回类型

  还有一种老式方式可用于在私有派生类中重新声明基类方法，将方法名放在派生类的公有部分，如下：
  class Student:private std::string,
                 private std::valarray<double>
  {
  public:
    std::valarray<double>::operator[];
    ...
  };
  该方法目前可能被摒弃

14.3 多重继承
  进行多重继承时，必须使用 public 关键字，否则编译器会默认为是私有派生

  公有的多重继承表示的是 is-a 关系
  私有和受保护的多重继承MI可以表示 has-a 关系

  MI会带来两个主要问题：
  1.从两个不同基类继承同名方法
  这种赋值将把基类指针设置为派生对象中的基类对象的地址，但派生类包含两个相同基类方法，有两个地址可供选择
  应当使用类型转换来指定对象

  2.从两个或更多相关基类那里继承同一个类的多个实例

  虚基类的引用
  虚基类使得从多个类（它们基类相同）派生出来的类只继承一个基类对象
  通过使用关键字 virtual ，可以使得派生类 Worker 被用作基类 Singer 和 Waiter 的虚基类（virtual 和 public的次序无关紧要）：
  class Singer: virtual public Worker {...};
  class Waiter: public virtual Worker {...};

  然后可以将SingerWaiter类定义为：
  class SingingWaiter: public Singer, public Waiter {...};
  这样，SingerWaiter将只包含 Worker 对象的一个副本

  C++在基类是虚的时，禁止信息通过中间类自动传递给基类，因此需要调用基类的默认构造函数或者显示调用基类构造函数

  多重继承可能导致函数调用的二义性
  可以使用作用域解析运算符来澄清编程者的意图

  也可以在派生类中重新定义对应方法

  当类通过多条虚途径和非虚途径继承某个特定的基类时，该类将包含一个表示所有的虚途径的基类子对象和分别表示各条非虚途径的多个基类子对象

  虚二义性规则与访问规则无关

14.4 类模板
  容器类设计用来存储其他对象或数据类型，例如 Stack 类和 Queue 类

  泛型，即独立于类型，可以通过将具体类型作为参数传递来生成对应类型对象。

  定义类模板，模板类以下面这样的代码开头：
  template <class Type>
  关键字 template 告诉编译器， 将要定义一个模板，尖括号中的内容相当于函数的参数列表。
  可以把关键字 class 看作是变量的类型名，该变量接收类型作为其值，把 Type 看作是该变量的名称。

  上面使用的 class 并不意味着 Type 必须是一个类，仅表示 Type 是一个通用的类型说明符，新版本的 C++ 使用不易混淆的关键字 typename 代替 class
  template <typename Type>

  使用泛型模板定义方法时，应当注意类限定符，例如：
  bool Stack::push( const Item & item ) { ... }
  应该为：
  template <class Type>
  bool Stack<Type>::push( const Type & item ) { ... }

  如果在类中定义了方法(内联定义)，则可以省略模板前缀和类限定符

  模板不是类和成员函数定义，它们是C++编译器指定，说明了如何生成类和成员函数。
  模板的具体实现被成为实例化或具体化，模板必须与特定的模板实例化请求一起使用

  使用模板类，下面代码用于创建两个栈，一个用于存储 int,另一个用于存储 string 对象
  Stack<int> kernels;
  Stack<string> colonels;

  模板中必须显示地提供所需的类型

  正确使用指针栈
  提供一个指针数组，每个指针指向不同的内容，栈的职责使管理指针，并非创建指针

  模板代码不能修改参数的值，也不能使用参数的地址，例如:
    template <typename T, int size>
    其中，&size 以及 size++ 是非法的

  模板的多功能性
  模板可用作基类，也可用作组件类，还可以作其他模板的类型参数

  模板可以有多个参数，不同参数实例化的模板类是不同的
  类模板的另一项新特性是可以为类型参数提供默认值，但是不能为函数模板参数提供默认值。例如:
    template < typename T1, typename T2 = int > class topo {...};
  可以为非类型参数提供默认值。

  模板的具体化
  模板以泛型的方式描述类，而具体化是使用具体的类型生成类声明。

  模板的显示实例化
  template  class XXX< type1, type2 >;

  模板的显示具体化
  显示具体化是特定类型（用于替换模板中的泛型）的定义
  具体化类模板定义的格式如下：
  template <> class Classname<specialized-type-name> { ... };

  部分具体化
  template <class T1， class T2 > class Pair { ... };
  template <class T1> class Pair<T1, int > { ... };

  当有多个可选模板时，编译器将选择具体化最高的现有模板

  将模板用作参数
  模板可以包含类型参数和非类型参数，模板还可以包含本身就是模板的参数。如下:
    template < template <typename T> class  Thing > class Crab
    模板参数是 template <typename T> class Thing , 其中 template < typenam  T > class 是类型， Thing 是参数。





