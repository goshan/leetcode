leetcode
========
Count_and_Say <br>
循环n次依次计算即可，注意0次等边界情况 <br>
<br>
Longest_Consecutive_Sequence <br>
双向确认是否连续，避免重复的n^2复杂度 <br>
<br>
Palindrome_Partitioning <br>
DP，避免递归调用，利用数组储存已算出来的数值，由后向前逐渐增加字符串处理 <br>
<br>
Palindrome_Partitioning_2<br>
同上 <br>
<br>
Sum_Root_to_Leaf_Numbers <br>
DFS <br>
<br>
Surrounded_Regions <br>
由四周‘O’开始向内检索，利用第三个字符对可以变换的‘O’进行暂存 <br>
<br>
Word_Lader <br>
BFS，避免DFS记录以遍历的节点错误，且保证优先找到最短的路径,  按照图的方法判断任意两个节点是否差一个字母，复杂度为O(n^2)，会超时，因此修改方法：对当前节点对每个位置遍历26个字母修改，判断修改后的单词是否在已有的dict中。这样对大数据较快 <br>
<br>
Word_Lader_2 <br>
基本思想同上，细节变动较多，因为上到题只要找到一条最短路径就可以了，但是本题需要全部找出，因此需要建立每个节点到首节点的距离信息，避免重复路径的搜索，利用二维数组记录每个节点的上一个节点，最后通过递归返回整个路径。(事实证明，leetcode最好tmd还是用java刷！！！) <br>
<br>
Valid_Palindrome <br>
从两头开始遍历字符串，注意长度为0的输入 <br>
<br>
Binary_Tree_Maximum_Path_Sum <br>
注意：不一定经过根节点，DP-DFS，对于每个节点计算从该节点开始向下子节点和最大值，便于后续计算，注意子节点最大值为负时仅算该节点本身，同时记录该节点，该节点+左子，该节点+右子，该节点+左子+右子的最大值同当前最大结果比较，更新结果。 <br>
<br>
Best_Time_to_Buy_and_Sell_Stock <br>
遍历每次求当前节点与前面节点差更新差的最大值，然后更新节点的最小值 <br>
<br>
Best_Time_to_Buy_and_Sell_Stock_2 <br>
遍历当前价格减去前一个价格，所有整数求和 <br>
<br>
Best_Time_to_Buy_and_Sell_Stock_3 <br>
动态规划，某个节点前方一次交易最大值+后方一次交易最大值，所有结果去最大，可以遍历缓存结果的对应一次交易最大值，O(n)。 <br>
<br>
Triangle <br>
自底向上动态规划计算，更新输入的vector即可，不需要额外空间 <br>
<br>
Distinct_Subsequences <br>
矩阵二维的动态规划，类似于计算编辑距离的方法，仅仅是状态方程不一样而已 <br>
<br>
Flatten_Binary_Tree_to_Linked_List <br>
令人崩溃的一道题，用C++会runtime error，但是vc++和g++都是没有问题的。经测试貌似是自己新建的TreeNode不能访问，或者干脆在定义一个TreeNode是否构造函数会编译错误，却没有输出任何信息，但是前几道涉及TreeNode的题目并没有出现类似问题，目测leetcode在处理C++的struct甚至是class时候会存在bug！！最后改用java实现非常简单。整个问题不难，前序遍历二叉树，记录转化成的新的List的最后一个节点，便于续接，或者每哥节点将其右子树全部转移到左子树的最右叶子节点，然后左子树全部移到右子树位置，左子树清空。 <br>
<br>
Path_Sum <br>
DFS， 递归，每个节点值更新为父节点同当前节点之和，叶子节点值同期望值比较 <br>
<br>
Path_Sum_2 <br>
DFS， 递归调用子节点时将父节点值+当前节点值的和传进子节点中，然后在子节点中进行比较。调用完子节点之后如果子节点存在结果，将子节点返回的向量中依次添加完当前节点值后返回。 <br>
<br>
Pascal's_Triangle <br>
按顺序生成新的vector，push到二维vector中就可以了，注意边界处理 <br>
<br>
Pascal's_Triangle_2 <br>
每次缓存vector，然后计算更新当前vector即可，注意边界处理 <br>
<br>
Minimun_Depth_of_Binary_Tree <br>
简单，递归，DP <br>
<br>
Balanced_Binary_Tree <br>
简单，先递归DP求解所有节点深度，然后再递归一次判断所有节点的左右子树深度差，不符合直接返回 <br>
<br>
Populating_Next_Right_Pointers_in_Each_Node <br>
为了统一，也按照不完全二叉树进行算法设计和没实现，方法见下 <br>
<br>
Populating_Next_Right_Pointers_in_Each_Node_2 <br>
不完全二叉树，BFS，每个节点计算其各个子节点的next指针，对于右子结点的next指针查找父节点的next，直到next存在子节点停止，将该next节点的最左边子节点作为当前右子节点的next指针 <br>
<br>
Convert_Sorted_List_to_Binary_Search_Tree <br>
递归，找到链表的中间节点，然后递归实现前半部分和后半部分 <br>
<br>
Convert_Sorted_Array_to_Binary_Search_Tree <br>
递归，中间节点做根节点，然后递归实现前半部分和后半部分 <br>
<br>
Binary_Tree_Level_Order_Traversal_2 <br>
BFS，最后按层次逆序输出 <br>
<br>
Construct_Binary_Tree_from_Inorder_and_Postored_Traversal <br>
根据后序遍历最后一个节点确定根节点，然后找到中序遍历中根节点，将中序遍历分为左右子树两部分，删去后序遍历中最后一个节点也就是当前根节点，然后先递归右节点，然后递归左节点 <br>
<br>
Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal <br>
根据前序遍历第一个节点确定根节点，然后找到中序遍历中根节点，将中序遍历分为左右子树两部分，删去前序遍历中第一个节点也就是当前根节点，然后先递归左节点，然后递归右节点 <br>
(根据上两题总结，前中后序遍历中的任意一种都不能确定一个二叉树，至少两种遍历才能确定，同时其中必须含有中序遍历以区别左右子树，也就是说前序遍历和后序遍历不能确定一颗二叉树)  <br>
<br>
Maximun_Depth_of_Binary_Tree <br>
同Minimun_Depth_of_Binary_Tree， 简单，递归，DP <br>
<br>
Binary_Tree_Zigzag_Level_Order_Traversal <br>
BFS 遍历所有节点，然后按照要求每行变序输出 <br>
<br>
Binary_Tree_Level_Order_Traversal <br>
BFS 遍历所有节点，然后直接输出 <br>
<br>
Symmetric Tree <br>
BFS, 子节点为空也压入队列，以#或者-100000代替，只不过不再遍历空节点的子节点，每层遍历结束后判断该行是否对称 <br>
<br>
Same_Tree <br>
简单，DFS，同步遍历两棵树比较 <br>
<br>
Recover_Binary_Search_Tree <br>
O(n)空间方法：树转换为数组，然后从头开始遍历找到出现逆序的两个数值，（逆序大树值为首次出现逆序的，逆序小数值为最后出现逆序的，例如1 4 3 2 5， 逆序大数值为4，逆序小数值为2），然后交换两个逆序数，转换成为新的二叉搜索树即可，<br>
O(1)空间方法：近似于上述方法，不同的是不需要数组进行存储，而是通过递归模拟从最小的数值开始查找逆序的数，即先递归左子树，然后记录下当前根节点的前一个节点(前一个节点就是上次递归的根节点)，检查前一节点同根节点是否存在逆序，然后递归右子树 <br>
<br>
Validate_Binary_Search_Tree <br>
上一题简化版，不需记录逆序数位置，发现存在逆序数直接返回false <br>
<br>