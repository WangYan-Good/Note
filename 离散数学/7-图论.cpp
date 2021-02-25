第七章 图论
1.图的引入
  有向图
  无向图

  图的示例

  无序对和无序积
  设A、B为任意集合，称集合A&B = { (a,b)|a∈A, b∈B }为A与B的无序积,(a,b)称为无序对

  图的定义
  一个图(graph)是一个序偶<v,E>，记为G = <V,E>，其中：
  v = {v1,v2,...,vn}是有限非空集合，vi称为结点(node),V称为结点集
  E是有限集合，称为边集。E中的每个元素都有V中的结点对与之对应，称之为边(edge)。

2.图的表示
  集合表示和图形表示

  矩阵表示法
  设图G = < V , E >，其中v = {v1,v2,...vn},并假设结点已经有了从v1到vn的次序，则n阶方阵Ag = (aij)n*n 
称为G的邻接矩阵(adjacency matrix)，其中
  aij =| 1, <vi,vj>∈E或(vi,vj)∈E   ,( i,j = 1,2.3 )
       | 0, else

  邻接点与邻接边
  在图G = <V,E>中，若两个结点vi和vj是边e的端点，则称vi与vj互为邻接点，否则vi与vj称为不邻接的；
具有公共结点的两条边成为邻接边；两个端点相同的边称为环或自回路；图中不与任何相邻接的结点称为孤立点

  一些简单的特殊图
  仅有孤立结点组成的图称为零图；仅含一个结点的零图称为平凡图；含有n个结点，m条边的图，称为(n,m)图。

3.图的分类
  按边有无方向分类：
  每条边都是无向边的图称为无向图(undirected graph)；每条边都是有向边的图称为有向图(directed graph)；
有些边是无向边，而另一些是有向边的图称为混合图(mixed graph)。

  按平行边分类
  在有向图中，两结点若有同始点和同终点的几条边，则这几条边称为平行边；在无向图中，两结点间若有几条边，
则称几条边为平行边。两结点a，b间相互平行的边的条数称为边(a,b)或<a,b>的重数。含有平行边的图称为多重图(multigraph);
非多重图称为线图(line graph);无环的线图称为简单图(simple graph)

  按有无权值分类
  赋权图(weighted graph)G是一个三重图<V,E,g>或四重图<V,E,f,g>
其中V是结点集合，E是边的集合,f是从V到非负实数集合的函数(结点的权值函数),g是从E到非负实数集合的函数(边的权值函数)
边或结点均无权值的称为无权图

  综合分类方法

4.子图和补图
  子图
  设有图G=<v,E>和图G1=<V1,E1>
    若V1 ∈ V, E1 ∈ E，则称G1是G的子图(subgraph)
    若G1 ∈ V, 且G1 != G,则称G1是G的真子图(proper subgraph)
    若V1 ∈ V, E1 ∈ E,则称G1是G的生成子图(spanning subgraph)
    设V2 ∈ V且V2 != NULL,以V2为结点集，以两个端点均在V2中的边的全体为边集的G的子图，称为V2导出的G的子图，
简称V2的导出子图(induced subgraph)

  完全图
  设G = <V,E>为一个具有n个结点的无向简单图，如果G中的任意两个结点间都有边相连，则称G为无向完全图，简称G为完全图，记为Kn。
  设G = <V,E>为一个具有n个结点的有向简单图，如果G中任意两个结点间都有两条方向相反的有向边相连，则称G为有向完全图，在不发生误解的情况下，也记为Kn。

  补图
  设G = <V,E>为简单图，G' = <V1,E1>为完全图，则称G1 = <V,E1-E>为G的补图(complement of graph)
  
5.握手定理
  结点的度数
  图G = <V,E>中以结点v∈V为端点的次数之和称为结点v的度数或度，记为dega(v)。显然，有环时需要计算两次

  有向图G = <V,E>中以结点v为始点的次数称为v的出度，记为deg+(v)；以结点v为终点的次数称为v的入度，记为deg-(v)
  deg(v) = deg+(v)+deg-(v)。

  度数为1的结点称为悬挂结点，以悬挂结点为端点的边称为悬挂边

  图G = <V,E>中，最大度，最小度

  最大出度，最小出度，最大入度，最小入度

  握手定理
  图中结点度数的总和等于边数的2倍，即设图G = < V,E >，则有 dev(εv) = 2|E|

  度数序列
  设v = { v1, v2, ... , vn }为图G的结点集，称( deg(v1), deg(v2), ... , deg(vn) )为G的度数序列。
  若G为有向图，还可定义出度序列和入度序列

6.图的同构
  设两个图G = < V, E >和G' = <V',E'>,如果存在双射函数g: V->V',使得对于任意的e = (vi,vj)(或者<vi,vj>)∈E
  当且仅当e'= (g(vi),g(vj))(或者 < g(vi),g(vj)>)∈E',并且e与e'的重数相同，则称G与G'同构(isomorphism)

  同构的必要条件
  结点数相同
  边数相同
  度数相同的结点数相同

7.通路和回路
  通路
  给定图G = <V,E>中结点和边相继交错出现的序列 T = v0e1v1e2...ekvk
  T称为结点v0到vk的通路，v0和vk分别称为此通路的始点和终点，统称为通路的端点。边的数目称为通路的长度
  当v0和vk是同一个结点时，此通路称为回路。

  通路或者回路中所有边互不相同，则称为简单通路(回路)。

  通路数量
  设G = < V, E >为线图，V = {v1, v2, v3,...,vn}, A=(aij)n*n为G的邻接矩阵，
  a(m)ij 为从结点vi到结点vj长度为m的通路数目
  a(m)ii为结点vi到自身的长度为m的回路数目

8.可达性和最短通路
  vi到vj存在通路，则称vi到vj是可达的

  可达性矩阵
  pij = 1 当vi到vj可达
	0 当vi到vj不可达

  短程线及距离

9.无向图的连通性
  
  点割集与边割集

  连通度

10.有向图的连通性
  有向图的连通性
  有向图中的可达关系不是等价关系，仅仅具备自反性和传递性
  略去有向边的方向得到的是无向图是连通图，则称图G是连通图或弱连通图
  任一对结点之间至少有一个结点到另一个结点是可达的，则称G是单向连通图
  任一对结点之间是相互可达的，则称G是强连通图
  "强连通图必然是单向连通图；单向连通图必然是(弱)连通图。"

  强连通图的判定
  有向图G是强连通图的充分必要条件是G中存在一条经过所有结点至少一次的回路

  单向连通图的判定
  有向图G是单向连通图的充分必要条件是G中存在一条经过所有结点至少一次的通路

  邻接矩阵判定法
  邻接矩阵A，求出可达性矩阵P
  有向图G是强连通图当且仅当它的可达性矩阵P的所有元素均为1
  有向线图G是单向连通图当且仅当它的可达性矩阵P及其转置矩阵pT经过布尔加运算后所得的矩阵p' = P ∪ PT中除主对角元外其余元素均为1；
  有向线图G是若连通图当且仅当它的邻接矩阵A及其转置矩阵AT经布尔加运算所得的矩阵A' = A ∪ AT作为邻接矩阵而求得的可达性矩阵P'中所有元素均为1

  连通分支
  
  连通分支的判定
  在有向图G = < V, E >中，它的每一条边至多在一个强连通分支中；至少在一个单向连通分支中；在且仅在一个弱连通分支中


