leetcode
========
Count_and_Say                    //循环n次依次计算即可，注意0次等边界情况<br>
Longest_Consecutive_Sequence     //双向确认是否连续，避免重复的n^2复杂度 <br>
Palindrome_Partitioning          //DP，避免递归调用，利用数组储存已算出来的数值，由后向前逐渐增加字符串处理 <br>
Palindrome_Partitioning_2        //同上 <br>
Sum_Root_to_Leaf_Numbers         //DFS <br>
Surrounded_Regions               //由四周‘O’开始向内检索，利用第三个字符对可以变换的‘O’进行暂存 <br>
Word_Lader_2                     //BFS，避免DFS记录以遍历的节点错误，且保证优先找到最短的路径 <br>
Word_Lader                       //同上 <br>
Valid_Palindrome                 //从两头开始遍历字符串，注意长度为0的输入
Binary_Tree_Maximum_Path_Sum     //注意：不一定经过根节点，DP-DFS，对于每个节点计算从该节点开始向下子节点和最大值，便于后续计算，注意子节点最大值为负时仅算该节点本身，同时记录该节点，该节点+左子，该节点+右子，该节点+左子+右子的最大值同当前最大结果比较，更新结果。 <br>
Best_Time_to_Buy_and_Sell_Stock  //遍历每次求当前节点与前面节点差更新差的最大值，然后更新节点的最小值 <br>
Best_Time_to_Buy_and_Sell_Stock_2   //遍历当前价格减去前一个价格，所有整数求和 <br>
Best_Time_to_Buy_and_Sell_Stock_3   //动态规划，某个节点前方一次交易最大值+后方一次交易最大值，所有结果去最大，可以遍历缓存结果的对应一次交易最大值，O(n)。 <br>
Triangle                         //自底向上动态规划计算，更新输入的vector即可，不需要额外空间 <br>
Distinct_Subsequences            //矩阵二维的动态规划，类似于计算编辑距离的方法，仅仅是状态方程不一样而已 <br>
Flatten_Binary_Tree_to_Linked_List            //令人崩溃的一道题，用C++会runtime error，但是vc++和g++都是没有问题的。经测试貌似是自己新建的TreeNode不能访问，或者干脆在定义一个TreeNode是否构造函数会编译错误，却没有输出任何信息，但是前几道涉及TreeNode的题目并没有出现类似问题，目测leetcode在处理C++的struct甚至是class时候会存在bug！！最后改用java实现非常简单。整个问题不难，前序遍历二叉树，记录转化成的新的List的最后一个节点，便于续接，或者每哥节点将其右子树全部转移到左子树的最右叶子节点，然后左子树全部移到右子树位置，左子树清空。 <br>