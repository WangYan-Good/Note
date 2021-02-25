1.分支
		<- C4
  C1 <- C2 <- C3    (merge)<-C6
		<- C5

  查看目前所处分支：    git branch
  创建其他分支：	git branch	[branch-name]
  跳转到其他分支：	git checkout	[branch-name]
  合并其他分支到本分支：git merge	[branch-name]  //可能会产生冲突
  删除分支：		git branch  -d	[branch-name]

2.工作流

  ->master(稳定版)
  ->dev(开发，公测版)
