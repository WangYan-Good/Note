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
