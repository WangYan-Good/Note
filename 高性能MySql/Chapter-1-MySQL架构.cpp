MySQL最重要、最不寻常的特征是它的存储引擎架构，这种架构可以将查询处理( Query Processing )和各类服务器任务 ( Server Tasks ) 与数据的存储 ( Storage ) / 提取( Retrieval ) 相分离

1.1 MySQL的逻辑架构

  1.1.1 连接管理与安全性

  1.1.2 优化与执行

1.2 并发控制

  1.2.1 读锁( Read Lock ) / 写锁( Write Lock )

  1.2.2 锁粒度 ( Lock Granularity )
    一种提高共享资源并发性的方法就是让锁定对象更具有选择性
    加锁也会消耗系统资源
    锁策略，在锁开销和数据安全之间寻求一种平衡，这种平衡也能影响系统性能，大多数商业数据服务器通常在表上施加行级锁 ( Row-Level Locking )
    MySQL 提供了多种选择，每种 MySQL 存储引擎都可以实现独有的锁策略 ( Locking Policy ) 或 锁粒度 ( Lock Granularitey )

    表锁 ( Table Lock )
    MySQL 支持大多数基本的锁策略，其中开销最小的锁策略是表锁，它将整个表加锁
    写锁比读锁有更高级的优先权
    一个被申请的写锁仍可以排列在锁队列的前列 ( 写锁会被安排在读锁之前，而读锁不能排在写锁之前 )

    行级锁 ( Row locks )
    行级锁可以支持最大的并发处理 ( 同时也带来最大的锁开销 )，行级锁由存储引擎实现，而不是 MySQL 服务器实现。

1.3 事务
  事务是一组原子性的SQL查询语句，也可以被看作一个工作单元
  如果事务的任何一条语句因为奔溃或其他原因而无法执行，那么所有的语句就都不会执行
  ACID代表了原子性( Atomicity ), 一致性( Consistency ), 隔离性(Isolation) 和持久性 ( Durability )

  1.3.1 隔离级
    SQL 标准定义了 4 类隔离级
    READ UNCOMMITTED ( 读取未提交内容 )
    READ COMMITTED ( 读取提交内容 )
    REPEATABLE READ ( 可重读 )
    SERIALIZABLE ( 可串行化 )

    MySQL 的默认事务隔离级是 REPEATABLE READ ( 可重读 )

  1.3.2 死锁
    死锁是指两个或多个事务在同一资源上相互占用，并请求加锁时，而导致的恶性循环现象
    任何时间，多个事务同时加锁一个资源，一定产生死锁

  1.3.3 事务日志
    预写式日志( Write-Ahead Logging ), 利用两次磁盘写入操作把数据改变写入磁盘，第一次存储引擎将数据记录写入事务日志，它位于磁盘上，具有持久性，随后相关进程会在某个时间追加日志事件导致的写操作，把表数据更新到磁盘上。

  1.3.4 MySQL 中的事务
    MySQL AB提供 3 个事务型存储引擎： InnDB， NDB Cluster 和 Falcon

    AUTOCOMMIT ( 自动提交 )
    MySQL默认操作模式是AUTOCOMMIT模式，可以在当前连接中通过变量设置，启用( Enable ) 和禁用(Disable) AUTOCOMMIT模式
    mysql > SHOW VARIABLES LIKE 'AUTOCOMMIT';
    mysql > SET AUTOCOMMIT = 1;

    在事务中混合使用存储引擎

    隐式和显式锁定
    一个事务在执行过程中的任何时候，都可以获得锁，但只有在执行 COMMIT 或 ROLLBACK 语句后，才可以释放这些锁

1.4 多版本并发控制
  多版本并发控制 ( MVCC, Multiversion Concurrency Control )

1.5 MySQL的存储引擎、
  可以使用 SHOW TABLE STATUS 获知具体每张表使用何种存储引擎
