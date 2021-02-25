1.1 Git 
  分布式
  版本控制，论文
  软件，电脑工具

  文件：
  文件(N种).
  本地版本控制:一个版本->保留
  集中式版本控制:SVN
  分布式版本控制工具:Git

1.2 为什么要用git？

1.3 安装Git:版本控制 -> git管理文件夹
  1.进入管理文件夹（进入）
  2.初始化（提名）:			git init
  3.管理:				git status(检测当前文件夹的文件状态，包括修改文件，增加文件)
  4.个人信息配置:	用户名，邮箱	git config --global user.email "166.9932941@163.com"
					git config --global user.name  "WangYan-Good"
  5.生成版本:				git add [file]
					git add .
					git commit "*****(Information)"
  6.版本记录:				git log

1.5 git三大区域
  1.工作区：已管理 => 已修改/新增
    => 提交 暂存区

  2.暂存区：提交 版本库(commit)
  3.版本库

1.6 回滚
  第一阶段：自己写
  第二阶段：增加功能，例如直播，短视频
  第三阶段：约饭（违法，该功能下线，需要进行版本回滚）：git reset --hard [hd5Code] (往之前版本回滚)

							git reflog (往之后版本回滚)
							git reset --hard [hd5Code]
  版本库回滚到暂存区：		  git reset --soft 版本号
  暂存区回滚到工作已修改区：	  git reset HEAD
  回滚已修改文件(工作区)：	  git checkout
  版本库回滚到已修改文件(工作区)：git reset --mix 版本号 
