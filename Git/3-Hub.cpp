1.github
  注册账号
  创建仓库
  本地代码推送

  给远程仓库url取别名：		  git remote add origin(别名) url
  本地分支推送到远程仓库：	  git push -u(默认) origin(别名) [branch-name]
  				  git push origin [branch-name]
  克隆云端代码：		  git clone [url]
  查看分支情况：		  git branch
  将版本库中代码更新至本地：      git pull

  以图示查看提交记录：            git log --graph

  以简洁图示查看提交记录(只显示哈希值和记录)： git log --graph --pretty=format:"%h %s"

2.本地忘记提交情况
  地点1：新增功能C1(0%-50%)，但是未提交
  地点2：新增功能C1(50%-100%)，提交成功

  地点1：拉取代码(可能会产生冲突)合并

  拉取远程代码： 		git pull origin/dev
		        	=
  把代码拉到版本库：            git fetch origin/dev
                                +
  把代码拉到工作区：            git merge origin/dev

3.rebase(变基)应用场景一
  使git提交记录变得简洁

  第一种：多个提交记录整合成一个提交记录
         开发进度：C1<-day1<-day2<-day3 ... <-dayn

         从当前开始，合并最近的n条记录： git rebase -i HEAD~n
         从当前开始，合并指定版本记录： git rebase -i [版本号]
  注意事项：合并记录时建议不要合并已push到远程仓库的提交记录

4.rebase应用场景二
  第二种：合并不同分支的提交记录
         master分支：C1 <- C2 <- C4 <- C5
         dev:               <- C3 <-----

         合并master和dev分支的提交记录：git rebase
  第三种：消除合并代码产生记录分叉
	 将远程仓库代码拉取到本地工作区： git pull
	 替换为：

	 将远程仓库代码拉取到本地缓冲区： git fetch
	 将远程仓库与本地合并(包括记录与代码)：git rebase

5.注意事项
  使用git rebase可能发生冲突：
  消除冲突
  继续合并：git rebase --continue

6.beyond compare快速解决冲突
  安装beyond compare

  在git中配置
    git config --local merge.tool bc3
    git config --local merge.path '/usr/local/bin/bcomp'
    git config --local mergetool.keepBackup false

  应用beyond compare解决冲突
    git mergetool

7.命令总结
  添加远程连接：git remote add origin url
  推送代码：git push url 分支
  下载代码：git clone url
  拉取代码：git pull url 分支
	    等价于
	    git fetch url 分支
	    git merge url 分支
  保持代码提交整洁(变基)：git rebase 分支
  图示法记录展示：git log --graph --pretty=format:"%h %s"
