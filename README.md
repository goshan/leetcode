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