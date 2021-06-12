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

  可对矢量执行的操作
  STL 提供了一些基本方法
  size() -- 返回容器中元素数目
  swap() -- 交换两个容器的内容
  begin() -- 返回一个容器中的第一个元素的迭代器
  end() -- 返回一个表示超过容器尾的迭代器

  通过广义指针化为迭代器，让 STL 能够为各种不同的容器类提供统一的接口。
  每个容器类都定义了一个合适的迭代器，该迭代器的类型是一个名为 iterator 的 typedef , 其作用域为整个类
  为 vector 的 double 类型规范声明一个迭代器，可以这样做：
  vector<double>::iterator pd;
  vector<double> scores;
  pd = scores.begin();
  如上所示，迭代器的行为与指针很类似。另外，C++11 自动类型判断可以这样做：
  auto pd = scores.begin();
  它与下面声明等价：
  vector<double>::iterator pd = scores.begin();

  vector 模板类也包含一些只有某些 STL 容器才有的方法。
  push_back() 是一个方便的方法，它将元素添加到矢量末尾。它将负责内存管理，增长矢量的长度，使之能容纳新的成员。

  erase() 方法删除矢量中给定区间的元素。如下所示：
  scores.erase( scores.begin(), scores.begin()+2 );

  insert() 方法的功能与 erase() 方法相反。它接收 3 个迭代器参数，第一个参数指定了新元素的插入位置，第二个和第三个参数定义了被插入区间，该区间通常是另一个容器的对象的一部分。例如下面的代码所示：
  vector<int> old_v;
  vector<int> new_v;
  ...
  old_v.insert( old_v.begin(), new_v.begin()+1, new_v.end() );

  对矢量可执行的其他操作
  3 个具有代表性的 STL 函数： for_each(), random_shuffle() 和 sort()

  for_each() 函数接收 3 个参数，前两个是定义容器中区间的迭代器，最后一个是指向函数的指针。
  for_each() 函数将被指向的函数应用于容器区间中的各个元素。被指向的函数不能修改容器元素的值。可以用 for_each() 函数来代替 for 循环，例如：
  vector<Review>::iterator pr;
  for( pr = books.begin(); pr != books.end(); pr++ )
    ShowReview( *pr );
  替换为：
  for_each( books.begin(), books.end(), ShowRevicew );

  random_shuffle() 函数接受两个指定区间的迭代器参数，并随机排列该区间中的元素。例如：
  random_shuffle( books.begin(), books.end() );
  该函数要求容器类允许随即访问， vector 类可以做到这一点。

  sort() 函数也要求容器支持随机访问。该函数有两个版本
  第一个版本接收两个定义区间的迭代器参数，并使用为存储在容器中的类型元素定义的 < 运算符，对区间中的元素进行操作。
  如果容器元素是用户定义的对象，则要使用 sort(), 必须定义能够出来该类型对象的 operator<() 函数。

  以上用法为 sort() 函数的升序排列，如果是使用降序，则可以使用另一种格式的 sort()
  该格式的 sort() 函数接受 3 个参数，前两个函数也是指定区间的迭代器，最后一个参数是指向要使用的函数的指针（函数对象），而不是用于比较的 operator<(), 返回值可转换为 bool, false 表示两个参数的顺序不正确。
  bool WorseThan( const Revicew & r1, const Review & r2 )
  {
    if( r1.rating < r2.rating )
      return true;
    else
      return false;
  }

  sort( books.begin(), books.end(), WorseThan );

  基于范围的 for 循环（C++11）
  基于范围的 for 循环是为用于 STL 而设计的
  double prices[5] = {};
  for( double x : prices )
    cout << x << std::endl;
  以下代码可以相互替换
  for_each( books.begin(), books.end(), ShowReview );
  =
  for( auto x : books ) ShowReview(x);

  不同于 for_each(), 基于范围的 for 循环可修改容器的内容，诀窍是指定一个引用参数。如下：
  void InflatReview( Review & r ) { r.rating++; }
  =
  for( auto & x : books ) InflateReview( x );

16.4 泛型编程
  STL 是一种泛型编程（generic programming）
  面向对象编程关注的是编程的数据方面，而泛型编程关注的是算法。它们之间的共同点是抽象和创建可重用代码。
  泛型编程旨在编写独立于数据类型的代码，C++中通用程序的工具是模板。

  为何使用迭代器
  理解迭代器是理解 STL 的关键所在，模板使得算法独立于存储的类型数据，而迭代器使算法独立于使用的容器类型。

  泛型编程旨在使用同一个函数来处理数组链表或任何其他容器类型。即函数不仅独立于容器中存储的数据类型，而且还独立于容器本身的数据结构。
  模板提供了存储在容器中的数据类型的通用表示，因此还需要遍历容器中的值的通用表示，迭代器正是这样的通用表示。

  迭代器应具备的特征
  能够对迭代器执行解引用的操作，以便能够访问它引用的值
  能够将一个迭代器赋给另一个
  能够将一个迭代器与另一个迭代器进行比较，看它们是否相等
  能够使用迭代器遍历容器中的所有元素，可以通过为迭代器p定义 ++p 和 p++ 实现。

  为区分++运算符的前缀版本和后缀版本，C++将 operator++作为前缀版本，将 operator++(int) 作为后缀版本

  迭代器类型
  STL 定义了 5 钟迭代器：输入迭代器，输出迭代器，正向迭代器，双向迭代器和随机访问迭代器

  输入迭代器：用来读取容器中的信息，但不一定能够修改值，另外，输入迭代器是单向迭代器，可以递增，但不能倒退。
  输出迭代器：将信息从程序传输给容器的迭代器，与输入迭代器类似，只是解除引用让程序能修改容器值，而不能读取。
  正向迭代器：正向迭代器只使用++运算符来遍历容器，所以它每次沿容器向前移动一个元素，他总是按照相同的元素编译一系列值。
  双向迭代器：双向迭代器具有正向迭代器的所有特性，同时支持两种递减运算符。
  随机访问迭代器：随机访问迭代器具有双向迭代器的所有特性，同时添加了支持随机访问的操作和用于对元素进行排序的关系运算符

  迭代器层次结构
  为何需要那么多迭代器？目的是为了编写算法时尽可能使用要求最低的迭代器，并让它适用于容器的最大区间。

  概念，改进和模型
  将指针用作迭代器
  STL 为输出迭代器提供了 ostream_iterator 模板， 该模板是输出迭代器概念的一个模型，它也是一个适配器( adapter ) -- 一个类或函数，可以将一些其他接口转换为STL使用的接口。
  可以通过包含头文件 iterator ( iterator.h ) 来声明和创建该迭代器。
  #include <iterator>
  ...
  ostreambuf_iterator<int ,char> out_iter( cout, " " );

  iterator 头文件还定义了一个 istream_iterator 模板，使 istream 输入可作为迭代器接口。
  与 ostreambuf_iterator 相似， istream_iterator 也使用两个模板参数。第一个参数指出要读取的数据类型，第二个参数指出输入流使用的字符类型。
  使用构造函数参数 cin 意味着由 cin 管的的输入流，省略构造函数参数表示输入失败。

  其他有用的迭代器
  除了 ostreambuf_iterator 和 istreambuf_iterator 之外，头文件 istream 还提供了一些专门的预定义迭代器类型。
  reverse_iterator
  back_insert_iterator
  front_insert_iterator
  insert_iterator

  vector 类中有一个名为 rbegin() 的成员函数和一个名为 rend() 的成员函数，前者指向一个只想超尾的反向迭代器，后者返回一个指向第一个元素的反向迭代器。

  注意: rbegin() 和 end() 返回相同的值( 超尾 ), 但类型不同( reverse_iterator 和 iterator ), 同样， rend() 和 end() 也是如此

  rbegin() 返回超尾，因此不能对地址进行解引用
  如果 rend() 是第一个元素的位置，则 copy() 必须提早一个位置停止，因为区间的结尾不包括在区间中。

  copy() 不仅可以将信息从一个容器复制到另一个容器中，还可以将信息从容器复制到输出流，从输入流复制到容器中，还可以使用 copy() 将信息插入到另一个容器中。

  容器种类
  STL 具有容器概念和容器类别
  概念是具有名称的通用类型
  容器类型是可用于创建具体容器对象的模板

  以前 11 个容器类型分别是
  deque list queue priority_queue stack vector map multimap set multiset bitset
  C++ 11 新增了
  forward_list unordered_map unordered_multimap unordered_set unordered_multiset, 且不将 bitset 视为容器，而将其视为一种独立的类别

  容器概念
  容器是存储其他对象的对象，被存储的对象必须是同一类型的
  存储在容器中的数据为容器所有，这意味着当容器过期时，存储在容器中的数据也将过期

  复杂度要求是 STL 特征，虽然实现细节可以隐藏，但性能规格应公开，以便程序员能够知道完成特定操作的计算成本。

  C++11 新增的容器要求
  复制构造和复制赋值以及移动构造和移动赋值之间的差别在于，复制操作保留源对象，而移动操作可以修改源对象，还可能转让所有权，而不做任何复制
  如果源对象是临时的，移动操作的效率将高于常规复制

  序列
  序列要求元素按严格的线性顺序排列

  7 种序列容器类型
  vector: 数组的一种类表示，提供了内存自动管理功能，可以动态改变 vector 对象的长度，提供了对元素的随机访问。 vector 还是可反转容器( reversible container )概念的模型。
  deque: 在头文件 deque 头文件中声明，表示双端队列，在 STL 中，实现类似 vector 容器，支持随机访问。
  list: 在 list 头文件中声明，表示双向链表，与 vector 相似, list 也是可反转容器， list 不支持数组表示法和随机访问。
  forward_list: 只需要单项迭代器，不可反转，类似于单项链表
  queue: 适配器类，让输出流能够使用迭代器接口，它不仅不允许随机访问队列元素，甚至不允许遍历队列
  priority_queue: 另一个适配器类，操作与 queue 相同，但在 priority_queue 中，最大的元素被移动到队首，默认的底层类是 vector
  stack: 适配器类，不允许随机访问栈元素，不允许遍历栈
  array: 并非 STL 容器，长度是固定的

  关联容器
  关联容器( associative container ) 是对容器概念的另一个改进。
  关联容器将值与键关联在一起，并使用键来查找值，它提供了对元素的快速访问，允许插入新元素，但不能指定元素的插入位置。

  关联容器通常是使用某种树实现的

  STL 提供了 4 种关联容器: set multiset map multimap

  set 也使用模板参数来指定要存储的值类型：
  set<string> A;
  显示集合A与B的并集：
  set_union( A.begin(), A.end(), B,begin(), B.end(), ostream_iterator<string, char> out( cout, "  " ) );

  函数 set_intersection() 和 set_difference() 分别查找交集和获得两个集合的差

  无序关联容器( C++11 )
  关联容器基于树结构
  无序关联容器基于数据结构哈希表，有 4 种无序关联容器
  unordered_set unordered_multiset unordered_map unordered_multimap

16.5 函数对象
  函数对象，也叫函数符
  函数符是可以以函数方式与()结合使用的任意对象

  函数符概念
  生成器是不用参数就可以调用的函数符
  一元函数是用一个参数就可以调用的函数符
  二元函数是用两个参数就可以调用的函数符
  返回 bool 值的一元函数是谓词
  返回 bool 值的二元函数是二元谓词

  预定义的函数符
  函数 transform()
  第一个版本，接收 4 个参数，前两个参数是指定容器区间的迭代器，第 3 个参数是指定将结果复制到哪里的迭代器，最后一个参数是一个函数符，它被应用于区间里的每个元素，生成结果中的新元素。

  第二个版本，使用一个接受两个参数的函数，并将该函数用于两个区间中的元素
  transform( gr8.begin(), gr8.end(), m8.begin(), out, mean );
  假如要将两个数组相加，可以按如下操作：
  transform( gr8.begin(), gr8.end(), m8.begin(), out, add )

  使用 STL 模板来完成运算
  #include <functional>
  ...
  plus<double> add;
  double y = add( a, b );

  plus 使得将函数对象作为参数很方便
  transform（ gr8.begin(), gr8.end(), out, plus<double>() ）;

  对于所有的内置的算术运算符、关系运算符和逻辑运算符， STL 都提供了等价的函数符

  自适应函数符和函数适配器
  STL 有 5 个与自定义函数符相关的该概念
  自适应生成器、自适应一元函数、自适应二元函数、自适应谓词、自适应二元谓词

  multiplies() 函数符可以执行乘法运行，但它是一个二元函数，需要一个适配器，将接受两个参数的函数符转换为接受一个参数的函数符。

  STL 提供了函数 bind1st(), 可以问其提供用于构建 binder1st 对象的函数名称和值，它将返回一个这种类型的对象。
  将二元函数 multiplies() 转换为将参数乘以 2.5 的一元函数，则可以这样做：
  bind1st( multiplies<double>() , 2.5 );

  bind2nd() 类与此类似，只是将常数赋值给第二个参数

  C++11 提供了函数指针和函数符的替代品 -- lambad 表达式

16.6 算法
  STL 包含了很多处理容器的非成员函数
  sort(), copy(), find(), random_shuffle(), set_union(), set_intersection(), set_difference(), transform()

  对于算法函数设计，有两个主要的通用部分
  1. 使用模板来提供泛型
  2. 都使用迭代器来提供访问容器中数据的通用表示

  统一的容器设计使得不同类型之间的容器具有明显关系
  copy() 可以将常规数组中的值复制到 vector 对象中，将 vector 对象中的值复制到 list 对象中， 将 list 对象中的值复制到 set 对象中。
  可以用 == 来比较不同类型的容器，因为容器重载的 == 运算符使用迭代器来比较内容

  算法组
  STL 将算法库分为 4 组
  非修改式序列操作
  修改式序列操作
  排序和相关操作
  通用数字运算
  前 3 组在头文件 algorithm 中描述，第 4 组是专用于数值数据的，有自己的头文件，称为 numeric

  算法的通用特征

  STL 和 string 类
  string 类虽然不是 STL 组成部分，但是设计它时考虑到了 STL，它仍可使用 STL 接口
  next_permutation() 算法将区间内容转换为下一种排列方式，对于字符串，排列按照字母递增的顺序进行
  next_permutation() 自动提供唯一的排列组合

  函数和容器方法
  删除链表 list<int> 中某个特定的值的所有实例，可以使用链表的 remove() 方法，例如：
  la.remove(4); // remove all 4 s from the list
  调用该方法后，所有该值的实例都将被删除，同事链表的长度将会自动调整

  还有一个 remove() 的STL算法，它不是由对象调用，而是接受区间参数，例如：
  remove( lb.begin(), lb.end(), 4 );
  由于该函数不是成员，因此不能调整链表长度。它将未被删除的元素至于链表开始位置，返回新的超尾迭代器

  可以使用链表的 erase() 方法来删除一个区间

  使用 STL
  STL 是一个库，其组成部分被设计成协同工作。STL 组件是工具，但是也是创建其他工具的基本部件
  要获得容器中元素的出现次数，可以使用 count() 函数。它将区间和一个值作为参数，返回该值在区间中出现的次数。

  map可以使用数组表示法来访问存储的值。 例如 wordmap[ "the" ], 表示与键 "the" 相关联的值
  map 一般与 set 组合来遍历整个容器
  使用 STL 时应尽可能减少要编写的代码，STL 通用灵活的设计将节省大量的工作。

16.7 其他库
  C++ 还提供了其他类库
  头文件 complex 为复数提供了类模板 complex, 包含用于 float, long 和 long double 的具体化
  头文件 random 提供了更多的随机数功能
  头文件 valarray 提供了模板类 valarray, 用于表示数值数组，支持各种数值数组操作。

  vector, valarray 和 array
  vector 模板类是一个容器类和算法系统的一部分，它支持面向容器的操作，如排序、插入、重新排列、搜索、将数据转移到其他容器中等。
  valarray 类模板是面向数值计算的，不是 STL 的一部分，它没有 push_back() 和 insert() 方法，但为很多数学运算提供了一个简单、直观的接口。
  array 是为替代内置数组而设计的，它通过提供更好、更安全的接口、让数组更紧凑、效率更高。它表示程度固定的数组，不支持动态扩展。

  就数学运算而言，valarray 类提供了比 vector 更清晰的表示方式，但通用性更低。
  针对 valarray 对象使用 sort() 函数，可以使用
  sort( begin( val ), end( val ) );

  slice 类对象可用作数组索引，slice 对象被初始化为 3 个整数值：起始索引、索引数、跨距
  另外，使用 gslice 类可以表示多维下标

  模板 initializer_list ( C++ )
  可以使用初始化列表语法将 STL 容器初始化为一系列值
  std::vector<double> payments { 45.99, 39.23, 19.95, 89.01 };
  之所以可行，是因为容器类现在包含将 initializer_list<T> 作为参数的构造函数。上述代码与下面的代码等价
  std::vector<double> payments ({ 45.99, 39.23, 19.95, 89.01 });

  使用 initializer_list
  可按值传递 initializer_list 对象，也可按引用传递

