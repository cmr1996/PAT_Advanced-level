#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>

//本例的优势在于用一重循环解决了《算法笔记》上两重循环解决的问题，降低了时间复杂度
int main()
{
	char num[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	char unit[5][5] = { "Shi","Bai","Qian","Wan","Yi" };
	
	int left = 0, right = 0;//左右标志位
	bool flag = false;//累积零标志位
	bool IsPrint = false;//在一个节中未输出过
	char src[11];
	scanf("%s", src);//按字符串读入数字
	int len = strlen(src);//字符串长度
	left = 0; right = len - 1;
	if (src[0] == '-') { printf("Fu"); left++; }//负数则输出负并将left右移1位
	while (left + 4 <= right)
	{
		right -= 4;//将right每次左移4位，直到left与right在同一节
	}
	while (left <= right)//循环处理数字的一节
	{
		//当前位为0，开始累计0的数量
		if (left>0&&src[left] == '0') { flag = true; }//left前累计有0的存在
		else//无累计零存在
		{
			if (flag == true) { printf(" ling"); flag = false; }
			if (left > 0) { printf(" "); }//left不指向首位就打印空格
			printf("%s", num[src[left] - '0']);
			IsPrint = true;
			if (left != right) { printf(" %s", unit[right - left - 1]); }//打印十、百、千，不打印个位	
		}

		
		//输出节间的单位亿、万
		if (left == right)
		{
			if (IsPrint = true && (right != len - 1)) { printf(" %s", unit[(len - 1 - right) / 4 + 2]); }
			if (right + 4 <= len - 1) { right += 4; }
			else { break; }
		}
		left++;
		
	}

	return 0;
}