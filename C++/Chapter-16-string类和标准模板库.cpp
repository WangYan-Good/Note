�������ݰ�����
  ��׼C++ string ��
  ģ��auto_ptr��unique_ptr �� shared_ptr
  ��׼ģ��� ��STL��
  ������
  ������
  ��������functor��
  STL�㷨
  ģ�� initializer_list

16.1 string ��
  string ������ͷ�ļ� string ֧�ֵģ�����ͷ�ļ� string.h �� cstring ֧�� C-����ַ������в��ݵ�C���ַ�������������֧��string�ࡣ

  �����ַ���
  string ʵ������ģ����廯 basic_string<char> ��һ�� typedef, ͬʱʡ�������ڴ������صĲ���
  size_type ��һ��������ʵ�ֵ����ͣ�����ͷ�ļ� string �ж����
  string �ཫ string::npos ����Ϊ�ַ�������󳤶ȣ�ͨ��Ϊ unsigned int �����ֵ

  string ( const char * s )
  string ( size_type n, char c )
  string ( const string & str )
  string (  )
  string ( const char * s, size_type n )

  template<class Iter>
  string ( Iter begin, Iter end )    //[begin, end ) ����[begin] ��������[end]Ԫ��

  string ( const string & str, string size_type pos = 0, size_type n = npos )

  string ( string && str ) noexcept

  string ( initializer_list<char> il )

  ���ʹ�� string �����ʼ����һ�� string ������Ҫ���õ�ַ���ţ����������ᱻ�����Ƕ���ĵ�ַ����˲���ָ�롣

  string ������
  ���� C-����ַ�������3�ַ�ʽ��
  char info[100];
  cin >> info;
  cin.getline( info, 100 );
  cin.get( info, 100 );

  ���� string ���������ַ�ʽ��
  string stuff;
  cin >> stuff;
  getline( cin, stuff );

  string �汾�� getline() ���Զ�����Ŀ�� string ����Ĵ�С��ʹ֮�պ��ܴ洢������ַ���

  string �汾�� getline() �����������ж�ȡ�ַ���������洢��Ŀ�� string �У�ֱ�������������֮һ������
    �����ļ�β�������� eofbit �������ã�fail() �� eof() �������� true
    �����ֽ��ַ�( \n ), һ��Ὣ�ֽ��ַ�����������ɾ���������洢��
    ��ȡ���ַ����ﵽ�������ֵ string::npos ��ɹ��ڴ�����ֽ����н�С��һ����������½������������� failbit, fail() ������ true

  ʹ���ַ���
  �����Զ��ֲ�ͬ�ķ�ʽ���ַ������������������ַ������ַ��������� find() �����ļ����汾��
  size_type find( const string & str, size_type pos = 0 ) const

  size_type find( const char * s, size_type pos = 0 ) const

  size_type find( const char * s, size_type pos = 0, size_type n )

  size_type find( char ch, size_type pos = 0 )const

  ���Ƶķ�������
  rfind()
  find_first_of()
  find_last_of()
  find_first_not_of()

  �����ļ�������Ҫʹ��C-����ַ�����Ϊ����������ʹ�� c_str() ��������һ��ָ�� C-����ַ�����ָ�룬���磺
  fout.open( filename.c_str() );

  �ַ�������
  ���ڽ� string ����Ϊ���� char ���͵ģ� string  ��ʵ������һ������һ��ģ����ģ�
  template< class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> >
  basic_string { ... };

  ģ�� basic_string ��4�����廯��ÿ�����廯����һ�� typedef ���ƣ�
  typedef basic_string<char> string;
  typedef basic_string<wchat_t> wstring;
  typedef basic_string<char16_t> u16string;
  typedef basic_string<char32_t> u32string;

16.2 ����ָ��ģ����
  ����ָ������Ϊ������ָ�������󣬵����ֶ������������ܡ�

  ʹ������ָ��
  auto_ptr
  unique_ptr
  shared_ptr
  ����������ָ��ģ�嶼����������ָ��Ķ��󣬿��Խ� new ��õĵ�ֱַ�Ӹ������ֶ���
  ������ָ�����ʱ����Щ�ڴ潫���Զ��ͷš�

  Ҫ��������ָ����󣬱������ͷ�ļ� memory , ���ļ�ģ�嶨�塣
  ģ�� auto_ptr �������¹��캯����
  template < class X > class auto_ptr {
    public:
      explicit auto_ptr ( X * p = 0 ) throw();
      ...
  };
  ���У�throw() ��ζ�Ź��캯�����������쳣

  ����ָ��Ӧ�ñ����һ�֣�
  string vacation( "I wandered longly as a cloud." );
  shared_ptr<string> pvac( &vacation );
  �� pvac ����ʱ�������� delete ��������ڷǶ��ڴ棬���Ǵ����

  �й�����ָ���ע������
  ʵ������4��
  auto_ptr<string> ps ( new string( "I reigned lonely as a cloud." ) );
  auto_ptr<string> vocation;
  vocation = ps;

  ���ϳ�����Ӧ������ͬһ���ڴ����������Ρ�Ҫ�����������⣬�����ж��֣�
  ���帳ֵ�������ʹ֮������ơ�
  ��������Ȩ��ownership����������ض��Ķ���ֻ����һ������ָ���ӵ������  // auto_ptr
  �������ܸ��ߵ�ָ�룬���������ض����������ָ���������Ϊ���ü���( reference counting ).  // share_ptr

  unique_ptr Ϊ������ auto_ptr
  unique_ptr �� auto_ptr ����ȫ������׶δ����Ǳ�ڵĳ����������ȫ��

  unique_ptr <string> p3 ( new string("quto") );
  unique_ptr <string> p4 ;
  p4 = p3; //#6
  ʹ�� unique_ptr ���Խ�����Ϊ #6 �Ƿ������� p3 ����ָ����Ч���ݵ����⣬��ʹ�� auto_ptr ����� p4 �ڴ��Զ�����֮��p3 ָ����Ч�ڴ棬�ڴ����ʱ���ִ�������⡣

  ��Ҫ�� unique_ptr ��ֵ����һ��������ʹ�� C++ ��׼�⺯�� std::move();

  ����� auto_ptr, unique_ptr ������һ���ŵ㡣����һ������������ı��塣
  ģ�� auto_ptr �Զ������ڴ�ʱʹ�õ��� delete , ������ delete[], �޷�������ʹ�á� unique_ptr ��ʹ�� new[] �� delete[] �İ汾��
  std::unique_ptr<double []> pda( new double(5) );

  ѡ����������ָ��
  �������Ҫʹ�ö��ָ��ָ��ͬһ������ģ�Ӧѡ�� shared_ptr, ���������û���ṩ shared_ptr, ����ʹ�� boost ���ṩ�� shared_ptr
  ���������Ҫ���ָ��ͬһ�������ָ�룬�����ʹ�� unique_ptr

  �� unique_ptr ת��Ϊ shared_ptr, shared_ptr ���ӹ�ԭ���� unique_ptr ���еĶ���
  ������ unique_ptr Ҫ�������ʱ��Ҳ����ʹ�� auto_ptr, �� unique_ptr �Ǹ��õ�ѡ�����������û���ṩ unique_ptr ,���Կ���ʹ�� boost ���е� scoped_ptr, ���� unique_ptr ���ơ�

16.3 ��׼ģ���
  STL �ṩ��һ���ʾ������������������������㷨��ģ�塣
  ������һ�����������Ƶĵ�Ԫ�����Դ洢���ɸ�ֵ��STl��������ͬ�ʵģ��洢��ֵ������ͬ��
  �㷨������ض�����Ĵ�����
  ���������������������Ķ������ܹ����������ָ�����ƣ��ǹ���ָ��
  ���������������ں����Ķ��󣬿�������������ָ��
  STL ʹ���ܹ��������������ִ�и��ֲ���

  STL �����������ı�̣�����һ�ֲ�ͬ�ı��ģʽ--���ͱ��( generic programming )

  ģ���� vector
  vector ���ṩ�� valarray �� array ���ƵĲ����������Դ��� vector ���󣬽�һ�� vector ���󸳸���һ������ʹ�� []����������� vector Ԫ�ء�
  #include vector
  using namespace std;
  vector<int> rating(5);
  ���������[]�����أ���˴��� vector ����󣬿���ʹ��ͨ���������ʾ�������ʸ���Ԫ��

  �ɶ�ʸ��ִ�еĲ���
  STL �ṩ��һЩ��������
  size() -- ����������Ԫ����Ŀ
  swap() -- ������������������
  begin() -- ����һ�������еĵ�һ��Ԫ�صĵ�����
  end() -- ����һ����ʾ��������β�ĵ�����

  ͨ������ָ�뻯Ϊ���������� STL �ܹ�Ϊ���ֲ�ͬ���������ṩͳһ�Ľӿڡ�
  ÿ�������඼������һ�����ʵĵ��������õ�������������һ����Ϊ iterator �� typedef , ��������Ϊ������
  Ϊ vector �� double ���͹淶����һ����������������������
  vector<double>::iterator pd;
  vector<double> scores;
  pd = scores.begin();
  ������ʾ������������Ϊ��ָ������ơ����⣬C++11 �Զ������жϿ�����������
  auto pd = scores.begin();
  �������������ȼۣ�
  vector<double>::iterator pd = scores.begin();

  vector ģ����Ҳ����һЩֻ��ĳЩ STL �������еķ�����
  push_back() ��һ������ķ���������Ԫ����ӵ�ʸ��ĩβ�����������ڴ��������ʸ���ĳ��ȣ�ʹ֮�������µĳ�Ա��

  erase() ����ɾ��ʸ���и��������Ԫ�ء�������ʾ��
  scores.erase( scores.begin(), scores.begin()+2 );

  insert() �����Ĺ����� erase() �����෴�������� 3 ����������������һ������ָ������Ԫ�صĲ���λ�ã��ڶ����͵��������������˱��������䣬������ͨ������һ�������Ķ����һ���֡���������Ĵ�����ʾ��
  vector<int> old_v;
  vector<int> new_v;
  ...
  old_v.insert( old_v.begin(), new_v.begin()+1, new_v.end() );

  ��ʸ����ִ�е���������
  3 �����д����Ե� STL ������ for_each(), random_shuffle() �� sort()

  for_each() �������� 3 ��������ǰ�����Ƕ�������������ĵ����������һ����ָ������ָ�롣
  for_each() ��������ָ��ĺ���Ӧ�������������еĸ���Ԫ�ء���ָ��ĺ��������޸�����Ԫ�ص�ֵ�������� for_each() ���������� for ѭ�������磺
  vector<Review>::iterator pr;
  for( pr = books.begin(); pr != books.end(); pr++ )
    ShowReview( *pr );
  �滻Ϊ��
  for_each( books.begin(), books.end(), ShowRevicew );

  random_shuffle() ������������ָ������ĵ�������������������и������е�Ԫ�ء����磺
  random_shuffle( books.begin(), books.end() );
  �ú���Ҫ�������������漴���ʣ� vector �����������һ�㡣

  sort() ����ҲҪ������֧��������ʡ��ú����������汾
  ��һ���汾����������������ĵ�������������ʹ��Ϊ�洢�������е�����Ԫ�ض���� < ��������������е�Ԫ�ؽ��в�����
  �������Ԫ�����û�����Ķ�����Ҫʹ�� sort(), ���붨���ܹ����������Ͷ���� operator<() ������

  �����÷�Ϊ sort() �������������У������ʹ�ý��������ʹ����һ�ָ�ʽ�� sort()
  �ø�ʽ�� sort() �������� 3 ��������ǰ��������Ҳ��ָ������ĵ����������һ��������ָ��Ҫʹ�õĺ�����ָ�루�������󣩣����������ڱȽϵ� operator<(), ����ֵ��ת��Ϊ bool, false ��ʾ����������˳����ȷ��
  bool WorseThan( const Revicew & r1, const Review & r2 )
  {
    if( r1.rating < r2.rating )
      return true;
    else
      return false;
  }

  sort( books.begin(), books.end(), WorseThan );

  ���ڷ�Χ�� for ѭ����C++11��
  ���ڷ�Χ�� for ѭ����Ϊ���� STL ����Ƶ�
  double prices[5] = {};
  for( double x : prices )
    cout << x << std::endl;
  ���´�������໥�滻
  for_each( books.begin(), books.end(), ShowReview );
  =
  for( auto x : books ) ShowReview(x);

  ��ͬ�� for_each(), ���ڷ�Χ�� for ѭ�����޸����������ݣ�������ָ��һ�����ò��������£�
  void InflatReview( Review & r ) { r.rating++; }
  =
  for( auto & x : books ) InflateReview( x );

16.4 ���ͱ��
  STL ��һ�ַ��ͱ�̣�generic programming��
  ��������̹�ע���Ǳ�̵����ݷ��棬�����ͱ�̹�ע�����㷨������֮��Ĺ�ͬ���ǳ���ʹ��������ô��롣
  ���ͱ��ּ�ڱ�д�������������͵Ĵ��룬C++��ͨ�ó���Ĺ�����ģ�塣

  Ϊ��ʹ�õ�����
  ������������� STL �Ĺؼ����ڣ�ģ��ʹ���㷨�����ڴ洢���������ݣ���������ʹ�㷨������ʹ�õ��������͡�

  ���ͱ��ּ��ʹ��ͬһ����������������������κ������������͡����������������������д洢���������ͣ����һ�������������������ݽṹ��
  ģ���ṩ�˴洢�������е��������͵�ͨ�ñ�ʾ����˻���Ҫ���������е�ֵ��ͨ�ñ�ʾ������������������ͨ�ñ�ʾ��

  ������Ӧ�߱�������
  �ܹ��Ե�����ִ�н����õĲ������Ա��ܹ����������õ�ֵ
  �ܹ���һ��������������һ��
  �ܹ���һ������������һ�����������бȽϣ��������Ƿ����
  �ܹ�ʹ�õ��������������е�����Ԫ�أ�����ͨ��Ϊ������p���� ++p �� p++ ʵ�֡�

  Ϊ����++�������ǰ׺�汾�ͺ�׺�汾��C++�� operator++��Ϊǰ׺�汾���� operator++(int) ��Ϊ��׺�汾

  ����������
  STL ������ 5 �ӵ����������������������������������������˫���������������ʵ�����

  �����������������ȡ�����е���Ϣ������һ���ܹ��޸�ֵ�����⣬����������ǵ�������������Ե����������ܵ��ˡ�
  ���������������Ϣ�ӳ�����������ĵ���������������������ƣ�ֻ�ǽ�������ó������޸�����ֵ�������ܶ�ȡ��
  ��������������������ֻʹ��++�����������������������ÿ����������ǰ�ƶ�һ��Ԫ�أ������ǰ�����ͬ��Ԫ�ر���һϵ��ֵ��
  ˫���������˫�����������������������������ԣ�ͬʱ֧�����ֵݼ��������
  ������ʵ�������������ʵ���������˫����������������ԣ�ͬʱ�����֧��������ʵĲ��������ڶ�Ԫ�ؽ�������Ĺ�ϵ�����

  ��������νṹ
  Ϊ����Ҫ��ô���������Ŀ����Ϊ�˱�д�㷨ʱ������ʹ��Ҫ����͵ĵ�������������������������������䡣

  ����Ľ���ģ��
  ��ָ������������

  �������õĵ�����
