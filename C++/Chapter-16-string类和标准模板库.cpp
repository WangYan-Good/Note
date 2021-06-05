本章内容包括：
  标准C++ string 类
  模板auto_ptr、unique_ptr 和 shared_ptr
  标准模板库 （STL）
  容器类
  迭代器
  函数对象（functor）
  STL算法
  模板 initializer_list

16.1 string 类
  string 类是由头文件 string 支持的，其中头文件 string.h 和 cstring 支持 C-风格字符串进行操纵的C库字符串函数，但不支持string类。

  构造字符串
  string 实际上是模板具体化 basic_string<char> 的一个 typedef, 同时省略了与内存管理相关的参数
  size_type 是一个依赖于实现的整型，是在头文件 string 中定义的
  string 类将 string::npos 定义为字符串的最大长度，通常为 unsigned int 的最大值

  string ( const char * s )
  string ( size_type n, char c )
  string ( const string & str )
  string (  )
  string ( const char * s, size_type n )

  template<class Iter>
  string ( Iter begin, Iter end )    //[begin, end ) 包含[begin] 但不包含[end]元素

  string ( const string & str, string size_type pos = 0, size_type n = npos )

  string ( string && str ) noexcept

  string ( initializer_list<char> il )

  如果使用 string 对象初始化另一个 string 对象，需要利用地址符号，对象名不会被看做是对象的地址，因此不是指针。

  string 类输入
  对于 C-风格字符串，由3种方式：
  char info[100];
  cin >> info;
  cin.getline( info, 100 );
  cin.get( info, 100 );

  对于 string 对象，有两种方式：
  string stuff;
  cin >> stuff;
  getline( cin, stuff );

  string 版本的 getline() 将自动调整目标 string 对象的大小，使之刚好能存储输入的字符。

  string 版本的 getline() 函数从输入中读取字符，并将其存储到目标 string 中，直到以下三种情况之一发生：
    到达文件尾，输入流 eofbit 将被设置，fail() 和 eof() 都将返回 true
    遇到分界字符( \n ), 一般会将分界字符从输入流中删除，但不存储它
    读取的字符数达到最大允许值 string::npos 或可供内存分配字节数中较小的一个，该情况下将设置输入流的 failbit, fail() 将返回 true

  使用字符串
  可以以多种不同的方式在字符串中搜索给定的子字符串或字符。以下是 find() 方法的几个版本：
  size_type find( const string & str, size_type pos = 0 ) const

  size_type find( const char * s, size_type pos = 0 ) const

  size_type find( const char * s, size_type pos = 0, size_type n )

  size_type find( char ch, size_type pos = 0 )const

  类似的方法还有
  rfind()
  find_first_of()
  find_last_of()
  find_first_not_of()

  对于文件操作需要使用C-风格字符串作为参数，可以使用 c_str() 方法返回一个指向 C-风格字符串的指针，例如：
  fout.open( filename.c_str() );

  字符串种类
  本节将 string 类视为基于 char 类型的， string  库实际上是一个基于一个模板类的：
  template< class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> >
  basic_string { ... };

  模板 basic_string 有4个具体化，每个具体化都有一个 typedef 名称：
  typedef basic_string<char> string;
  typedef basic_string<wchat_t> wstring;
  typedef basic_string<char16_t> u16string;
  typedef basic_string<char32_t> u32string;

16.2 智能指针模板类
  智能指针是行为类似于指针的类对象，但这种对象还有其他功能。

  使用智能指针
  auto_ptr
  unique_ptr
  shared_ptr
  这三个智能指针模板都定义了类似指针的对象，可以将 new 获得的地址直接赋给这种对象。
  在智能指针过期时，这些内存将会自动释放。

  要创建智能指针对象，必须包含头文件 memory , 该文件模板定义。
  模板 auto_ptr 包含如下构造函数：
  template < class X > class auto_ptr {
    public:
      explicit auto_ptr ( X * p = 0 ) throw();
      ...
  };
  其中，throw() 意味着构造函数不会引发异常

  智能指针应该避免的一种：
  string vacation( "I wandered longly as a cloud." );
  shared_ptr<string> pvac( &vacation );
  当 pvac 过期时，程序会把 delete 运算符用于非堆内存，这是错误的

  有关智能指针的注意事项
  实际上有4种
  auto_ptr<string> ps ( new string( "I reigned lonely as a cloud." ) );
  auto_ptr<string> vocation;
  vocation = ps;

  以上程序中应当避免同一块内存避免回收两次。要避免这种问题，方法有多种：
  定义赋值运算符，使之进行深复制。
  建立所有权（ownership）概念，对于特定的对象，只能有一个智能指针可拥有它。  // auto_ptr
  创建智能更高的指针，跟踪引用特定对象的智能指针数。这称为引用计数( reference counting ).  // share_ptr

  unique_ptr 为何优于 auto_ptr
  unique_ptr 比 auto_ptr 更安全（编译阶段错误比潜在的程序崩溃更安全）

  unique_ptr <string> p3 ( new string("quto") );
  unique_ptr <string> p4 ;
  p4 = p3; //#6
  使用 unique_ptr 可以将会认为 #6 非法，避免 p3 不再指向有效数据的问题，而使用 auto_ptr 会出现 p4 内存自动回收之后，p3 指向无效内存，内存回收时出现错误的问题。

  欲要将 unique_ptr 赋值给另一个，可以使用 C++ 标准库函数 std::move();

  相比于 auto_ptr, unique_ptr 还有另一个优点。它有一个可用于数组的变体。
  模板 auto_ptr 自动回收内存时使用的是 delete , 而不是 delete[], 无法对数组使用。 unique_ptr 有使用 new[] 和 delete[] 的版本。
  std::unique_ptr<double []> pda( new double(5) );

  选择哪种智能指针
  如果程序要使用多个指针指向同一个对象的，应选择 shared_ptr, 如果编译器没有提供 shared_ptr, 可以使用 boost 库提供的 shared_ptr
  如果程序不需要多个指向同一个对象的指针，则可以使用 unique_ptr

  将 unique_ptr 转换为 shared_ptr, shared_ptr 将接管原来归 unique_ptr 所有的对象。
  在满足 unique_ptr 要求的条件时，也可以使用 auto_ptr, 但 unique_ptr 是更好的选择。如果编译器没有提供 unique_ptr ,可以考虑使用 boost 库中的 scoped_ptr, 它与 unique_ptr 类似。

16.3 标准模板库
  STL 提供了一组表示容器、迭代器、函数对象和算法的模板。
  容器是一个与数组类似的单元，可以存储若干个值。STl的容器是同质的，存储的值类型相同。
  算法是完成特定任务的处方。
  迭代器是用来遍历容器的对象，与能够遍历链表的指针类似，是广义指针
  函数对象是类似于函数的对象，可以是类对象或函数指针
  STL 使得能够构造各种容器和执行各种操作

  STL 不是面向对象的编程，而是一种不同的编程模式--泛型编程( generic programming )

  模板类 vector
  vector 类提供了 valarray 和 array 类似的操作，即可以创建 vector 对象，将一个 vector 对象赋给另一个对象，使用 []运算符来访问 vector 元素。
  #include vector
  using namespace std;
  vector<int> rating(5);
  由于运算符[]被重载，因此创建 vector 对象后，可以使用通常的数组表示法来访问各个元素

