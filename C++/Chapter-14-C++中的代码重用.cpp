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

