第53节 线程基本知识
  1.线程与进程
    
    进程:执行中的程序
    线程：轻量级的进程
	  线程本身不能单独运行，必须放在一个进程中才能执行
  2.Java的线程模型
    新建状态：线程被创建之后便处于新建状态
    就绪状态：新建状态的线程调用start()进入就绪状态
	      阻塞状态的线程解除阻塞之后进入就绪状态
    运行状态：处于就绪状态的线程获得了CPU的资源，该线程就进入了运行状态
    阻塞状态：是一个正在运行的线程因为某些原因让出CPU资源暂时中止而进入的状态
    终止状态：正常终止
	      强制终止 stop、destroy
	      异常终止 当线程执行过程中产生异常线程会终止
第54节 继承Thread类创建线程
  1.继承thread类创建线程
  //define
    class <Class name> extends Thread{
      public void run(){
	//code 
      }
    }
  //start
  Thread.start() 多线程执行方法

    /*
     Thread.sleep( time ) 睡眠 time 毫秒
    */
第55节 实现Runable接口
  1.实现Runable接口
    class <Class name> implements Runable{
      public void run(){
	
      }
    }  
    
    Thread t = new Thread(Class name);
    Thread t1 = new Thread(Class name, "线程1");

  2.两种方法的比较
    extends Thread
    implements Runable

    类属于单继承，接口可以多实现

第56节 多线程应用
  1.多个线程并发执行
    Java对于线程启动后唯一能保证的是每个线程都被启动并且结束。但是对于哪个线程先执行，哪个后执行，
    什么时候执行，是没有保证的。
  2.线程优先级
    Java中优先级高的线程有更大的可能性获得CPU，但不是优先级高的总是先执行，也不是优先级低的线程总是后执行
    Thread th1 = new Thread();
    t1.getPriority();//获取线程优先级
    t1.setPriority();//设置线程的优先级，一般10为最高优先级，1为最低优先级
