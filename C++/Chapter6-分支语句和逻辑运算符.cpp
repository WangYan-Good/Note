6.1 if语句
  if (test-condition)
    statement

  if (test-condition)
    statement 1
  else
    statement 2

  if (test-condition)
    statement 1
  esle if (test-conditon)
    statement 2

6.2 逻辑表达式
  或运算  ||
  与运算  &&
  非运算  !
  
  逻辑或运算符|| 逻辑与运算符&& 优先级低于关系运算符 例如：
  x > 5 && x < 10
  等价于
  (x > 5) && (x < 10)

  逻辑非运算符! 优先级高于关系运算符和算术运算符

  逻辑与运算符&& 优先级大于 逻辑或运算符||

6.3 字符函数库cctpye
  isalpha():  检验字符是否为字母字符
  isdigits(): 检验字符是否为数字字符
  isspace():  检验字符是否为空白，如换行符，空格，制表符
  ispunct():  检验字符是否为标点符号
  isalnum():  检测字符是否是字母数字
  iscntrl():  检测字符是否为控制字符
  isgraph():  检测字符是否为空格之外的打印字符
  islower():  检测字符是否为小写字母
  isprint():  检测字符是否为打印字符，包括空格
  isupper():  检测字符是否为大写字母
  isxdigit(): 检测字符是否为十六进制数字
  tolower():  将大写字母转化为小写字母
  toupper():  将小写字母转化为大写字母

6.4 ?:运算符
  expression1 ? expression2 : expression3
  如果expression1为true, 则条件表达式为expression2，否则条件表达式值为expression3

6.5 switch语句
  switch (integer expression)
  {
    case label1: statement(s);
    case label2: statement(s);
    ...
    default: statement(s);
  }

  switch 可以与枚举量enum 组合
  
  switch 无法处理浮点测试

6.6 break 和 continue 语句
  break：整个循环体结束
  continue: 当前本次循环结束，进入下一次循环

  跳转语句
  goto paris;
  paris:

6.8 简单文件输入/输出
  
