leetcode
========
Count_and_Say                    //循环n次依次计算即可，注意0次等边界情况<br>
Longest_Consecutive_Sequence     //双向确认是否连续，避免重复的n^2复杂度 <br>
Palindrome_Partitioning          //DP，避免递归调用，利用数组储存已算出来的数值，由后向前逐渐增加字符串处理 <br>
Palindrome_Partitioning_2        //同上 <br>
Sum_Root_to_Leaf_Numbers         //DFS <br>
Surrounded_Regions               //由四周‘O’开始向内检索，利用第三个字符对可以变换的‘O’进行暂存 <br>
Word_Lader                       //BFS，避免DFS记录以遍历的节点错误，且保证优先找到最短的路径,  按照图的方法判断任意两个节点是否差一个字母，复杂度为O(n^2)，会超时，因此修改方法：对当前节点对每个位置遍历26个字母修改，判断修改后的单词是否在已有的dict中。这样对大数据较快 <br>
Word_Lader_2                     //基本方法同上，不同的是需要记录父节点便于输出整个路径，同时找到路径后要继续搜索以输出全部可能路径，同时需要逐层记录层数以及对dict删除该层的遍历过的节点，而不是遍历一个删一个，因为上到题只要找到一条最短路径就可以了，但是本题需要全部找出。(这题大数据没有过，Time Limited) <br>
Valid_Palindrome                 //从两头开始遍历字符串，注意长度为0的输入
Binary_Tree_Maximum_Path_Sum     //注意：不一定经过根节点，DP-DFS，对于每个节点计算从该节点开始向下子节点和最大值，便于后续计算，注意子节点最大值为负时仅算该节点本身，同时记录该节点，该节点+左子，该节点+右子，该节点+左子+右子的最大值同当前最大结果比较，更新结果。 <br>
Best_Time_to_Buy_and_Sell_Stock  //遍历每次求当前节点与前面节点差更新差的最大值，然后更新节点的最小值 <br>
Best_Time_to_Buy_and_Sell_Stock_2   //遍历当前价格减去前一个价格，所有整数求和 <br>
Best_Time_to_Buy_and_Sell_Stock_3   //动态规划，某个节点前方一次交易最大值+后方一次交易最大值，所有结果去最大，可以遍历缓存结果的对应一次交易最大值，O(n)。 <br>
Triangle                         //自底向上动态规划计算，更新输入的vector即可，不需要额外空间 <br>
Distinct_Subsequences            //矩阵二维的动态规划，类似于计算编辑距离的方法，仅仅是状态方程不一样而已 <br>
Flatten_Binary_Tree_to_Linked_List            //令人崩溃的一道题，用C++会runtime error，但是vc++和g++都是没有问题的。经测试貌似是自己新建的TreeNode不能访问，或者干脆在定义一个TreeNode是否构造函数会编译错误，却没有输出任何信息，但是前几道涉及TreeNode的题目并没有出现类似问题，目测leetcode在处理C++的struct甚至是class时候会存在bug！！最后改用java实现非常简单。整个问题不难，前序遍历二叉树，记录转化成的新的List的最后一个节点，便于续接，或者每哥节点将其右子树全部转移到左子树的最右叶子节点，然后左子树全部移到右子树位置，左子树清空。 <br>
Path_Sum                         //DFS， 递归，每个节点值更新为父节点同当前节点之和，叶子节点值同期望值比较 <br>
Path_Sum_2                       //DFS， 递归调用子节点时将父节点值+当前节点值的和传进子节点中，然后在子节点中进行比较。调用完子节点之后如果子节点存在结果，将子节点返回的向量中依次添加完当前节点值后返回。 <br>
Pascal's_Triangle                //按顺序生成新的vector，push到二维vector中就可以了，注意边界处理 <br>
Pascal's_Triangle_2              //每次缓存vector，然后计算更新当前vector即可，注意边界处理 <br>
Minimun_Binary_Tree              //简单，递归，DP <br>
Balanced_Binary_Tree             //简单，先递归DP求解所有节点深度，然后再递归一次判断所有节点的左右子树深度差，不符合直接返回 <br>
Populating_Next_Right_Pointers_in_Each_Node          //为了统一，也按照不完全二叉树进行算法设计和没实现，方法见下 <br>
Populating_Next_Right_Pointers_in_Each_Node_2        //不完全二叉树，BFS，每个节点计算其各个子节点的next指针，对于右子结点的next指针查找父节点的next，直到next存在子节点停止，将该next节点的最左边子节点作为当前右子节点的next指针 <br>