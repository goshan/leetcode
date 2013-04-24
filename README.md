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
Interleave_String <br>
二维DP,s3如果为s1, s2的交替，那么当s3的最后字符等于s1的最后字符时，必须s3[1..n3-1]是s1[1..n1-1], s2的交替，当s3的最后字符等于s2的最后字符时，必须s3[1..n3-1]是s1, s2[1..n2-1]的交替，除此之外的情况均为false，据此列出递推式。需要注意递归矩阵的宽高为s1, s2的长度+1，存在s1或s2为空时情况, 矩阵第0行和第0列分别为s1或s2为空的情况 <br>
<br>
Gray_Code <br>
格雷码生成，起始码为0，下一个为最有边的一位转换，再下一个是最右边的第一个1的左边一位转换，以此类推循环直至产生所有的格雷码。所谓转换就是0变1或者1变0 <br>
<br>
Pow_x_n <br>
比较简单，主要注意边界等特殊情况，如n为0或者n为负，然后二分法递归计算即可 <br>
<br>
Generate_Parentheses <br>
递归，通过一个变量stack记录当前含有多少个左括号为匹配，同时每当产生了一个完整匹配括号对输入的n减1，这样每次递归通过n和stack的值进行决策是新加一个左括号还是右括号 <br>
<br>
Unique_Binary_Search_Trees <br>
DP, 本题与节点内容无关，因此不需要真正实现树结构，而是对于某个n，其根节点使用一个数值，剩下n-1个数值依次分配给左右两个子树，最后两个子树的数量乘积为该种分配的总数，遍历左子树有0个节点到n-1个节点，所有情况总和为当前节点的所有数量，这样n从0一直DP至n就得到了最终结果 <br>
<br>
Unique_Binary_Search_Trees_2 <br>
与上题不同，需要实现树结构，同时递归左右子树的情况，递归思路同上题基本相同，有蛋疼的一点需要注意节点数值必须为中序遍历才能通过测试，因此需要一个int记录当前根节点该显示哪个数值，同时应当先左子树然后根节点，最后右子树 <br>
<br>
Binary_Tree_Inorder_Traversal <br>
简单的二叉树中序遍历，如果使用递归则非常简单，如果使用非递归则需要借助栈，初始存入根节点，然后循环取出栈顶节点，如果为叶子节点则输出值，否则先将右子结点压入栈便于后续处理，然后将该节点压入栈，然后压入左子节点便于后续处理，这时注意将该节点左右子节点分别置为空，表示再从栈中弹出时无需处理直接输出，注意不向栈中压入空节点 <br>
<br>
Restore_IP_Addresses <br>
题目不难，遍历三个点的位置，但是需要通过很多约束条件进行剪枝，约束条件考虑起来比较恶心 <br>
<br>
Reverse_Linked_List_2 <br>
比较简单，要求只遍历一次并且原地变换，注意细节边界和返回值，每次遍历记录上一节点，下一个节点，以及当前节点便于修改指针后能够继续向后遍历 <br>
<br>
Subsets_2 <br>
递归，每层递归确定选取剩余元素中的哪一个，同时判断是否重复以排除，递归之前注意对输入vector排序以保证升序 <br>
<br>
Decode_Ways <br>
DP，较为简单，各种边界组合情况（‘0’的处理）需要注意 <br>
<br>
Subsets <br>
Subsets_2的简化版，不需要判断是否有重复元素 <br>
<br>
Plus_One <br>
末尾加1之后从后向前遍历进位，如果首位仍需要进位则向量添加元素，平移所有元素后首位变为1 <br>
<br>
Merge_Sorted_Array <br>
思路很多，从中找到了一个最优的，思路一：将B通过O(n)时间全部添加到A结尾，然后以O((m+n)ln(m+n))时间快排A；思路二：两个指针分别从前遍历A和B，遇到B的当前值大于A则将A后续元素平移，然后将B的当前元素插入，这样时间是O(n*m)；思路三：将思路当的从前往后改为从后往前，需要三个指针，a指针，b指针，整体指针，均从后往前，每次比较a，b的对应值，大的赋值给整体指针所指位置，这样一次遍历O(m+n)的时间就可以完成，注意当a，b指针中一个到达开始后停止遍历，判断是a，b指针谁先到头，如果a到头，那么将b剩余元素放置a的开始。这样看来思路三最优 <br>
<br>
Scramble_String <br>
一次通过！！！递归，每次递归循环遍历判断s1的开头部分是否同s2的开头或结尾对应长度部分是否含有相同字母，且s1结尾部分是否同s2的结尾或开头部分含有相同字母，如果是则递归判断两个字串是否满足条件，否则遍历增加s1开头长度再进行判断 <br>
<br>
Partition_List <br>
较为简单，思想是遍历列表将其拆分为两个，将其中小于目标数节点的移至一个链表中，大于等于目标数的移至另外一个链表中，最后对接两个链表即可 <br>
<br>
Maximal_Rectangle <br>
O(n^4)复杂度，对于每个节点计算其到矩阵右下角中包含的最大矩阵，这个过程为对于每一行遍历是记录改行最短长度以便下一行遍历时对照 <br>
<br>
Largest_Rectangle_in_Histogram <br>
比较巧妙，利用一个栈，便利每个节点如果栈中最后一个元素小于他，则将其压入栈中，否则从栈中逐次弹出比他大的数，然后每次弹出数值时计算以此为高度的面积，不太好解释，参照代码思考！！ <br>
<br>
Remove_Duplicates_from_Sorted_List <br>
简单，遍历一遍，如果当前数值同前一个节点数值相同则修改指针删除该节点 <br>
<br>
<br>
Remove_Duplicates_from_Sorted_List_2 <br>
简单，遍历一遍，利用一个指针sub记录连续重复数值的开始位置的前一个节点，每次判断当前节点同下一节点数值是否相同，相同则继续遍历下一个节点，否则判断sub节点同当前节点是否相邻，如果相邻则sub后移，当前指针后移，否则删除从sub后的一个节点开始到当前节点结束的所有节点 <br>
<br>
Word_Search <br>
一次通过，较为简单，DFS，注意递归时不需要复制多个board，仅修改一个就可以，但是注意回朔 <br>
<br>
Search_in_Rotated_Sorted_Array <br>
二分查找，只不过在修改左右边界的时候注意判断条件 <br>
<br>
Search_in_Rotated_Sorted_Array_2 <br>
二分查找，同上题类似，不同的是判断区间是不能仅比较l和m的值，而是遍历该段判断是否满足非逆序 <br>
其实我想吐槽的是这两道题尼玛遍历比较也他么能过！！！ <br>
<br>
Remove_Duplicates_from_Sorted_Array <br>
一遍过，仅允许常数空间，因此发现重复数后将后续数依次前移，同时长度减小1 <br>
<br>
Remove_Duplicates_from_Sorted_Array_2 <br>
一遍过，同上题近似，不用的是需要一个计数器记录，重复一次时不进行删除，第二次重复时才进行删除 <br>
<br>
Combinations <br>
递归，分别计算(n-1, k)和(n-1, k-1)的结果，(n-1, k-1)的结果中每个向量后均加入n，然后再和(n-1, k)的结果合并起来就可以了，当k=1时，1..n每个数字形成一个向量加入到结果中返回，当n==k时，1..n形成一个向量加入结果中返回 <br>
<br>
Minimum_Window_Substring <br>
要求线性时间，并不简单，利用数组记录head到tail之间各个字母出现的次数。每次遍历tail判断符合条件字母总数是否满足，当前的字母个数是否满足，然后检查head能够后移，以使得窗口长度最小，然后同最小长度比较 <br>
<br>