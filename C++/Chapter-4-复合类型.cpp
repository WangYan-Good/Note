<<<<<<< HEAD
4.2 字符串

在数组中使用字符串
标准头文件：cstring( 老式实现为 string.h )

  字符串输入
  cin:使用空白( 空格、制表符、换行符 )来确定字符串的结束位置，并自动在数组末尾添加空字符

  每次读取一行字符串输入:getline()、get()
  1.getline():读取整行，通过回车键输入的换行符来确定输入结尾。
  cin.getling( array_name , char_number )
  2.getline()通过换行符来确定行尾，但不保存换行符

  3.面向行的输入：get()
  get()函数的一种工作方式与getline()类似，它们的接受的参数相同，解释参数也相同，并且都读取到行尾。
  但是get()并不再丢弃换行符，而是将其留在输入队列中。

=======
4.2 字符串

在数组中使用字符串
标准头文件：cstring( 老式实现为 string.h )

  字符串输入
  cin:使用空白( 空格、制表符、换行符 )来确定字符串的结束位置，并自动在数组末尾添加空字符

  每次读取一行字符串输入:getline()、get()
  1.getline():读取整行，通过回车键输入的换行符来确定输入结尾。
  cin.getling( array_name , char_number )
  2.getline()通过换行符来确定行尾，但不保存换行符

  3.面向行的输入：get()
  get()函数的一种工作方式与getline()类似，它们的接受的参数相同，解释参数也相同，并且都读取到行尾。
  但是get()并不再丢弃换行符，而是将其留在输入队列中。

>>>>>>> 7939dbdb37bd7ad9fa69b798b98b1ff1678af17c
