# AStar
## 提到的名词
开放列表：一个记录所有被考虑来寻找最短路径的网格集合
关闭列表：一个记录下不会被考虑的网格集合
G ：表示从起点方格移动到网格上指定方格的移动耗费 (可沿斜方向移动)
H ：表示从指定的方格移动到终点方格的预计耗费 (H启发函数)
权重值：F=G+H
## 步骤
1. 把起始格添加到开启列表
2. 重复如下的工作：
  a) 寻找开启列表中估量代价F值最低的格子。我们称它为当前格。
  b) 把它切换到关闭列表。
  c) 对相邻的8格中的每一个进行如下操作
      * 如果它不可通过或者已经在关闭列表中，略过它。反之如下。
      * 如果它不在开启列表中，把它添加进去。把当前格作为这一格的父节点。记录这一格的F,G,和H值。
      * 如果它已经在开启列表中，用G值为参考检查新的路径是否更好。更低的G值意味着更好的路径。如果是这样，就把这一格的父节点改成当前格，并且重新计算这一格的G和F值。如果你保持你的开启列表按F值排序，改变之后你可能需要重新对开启列表排序。
  d) 停止，当你
      * 把目标格添加进了关闭列表(注解)，这时候路径被找到，或者
      * 没有找到目标格，开启列表已经空了。这时候，路径不存在。
3. 保存路径。从目标格开始，沿着每一格的父节点移动直到回到起始格。这就是你的路径。
