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
