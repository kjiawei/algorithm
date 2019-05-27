//哈夫曼树(最优二叉)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//树结点定义
typedef  struct 
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode,*HuffmanTree;

static char N[100];//用于保存正文

//哈弗曼编码，char型二级指针
typedef char **HuffmanCode;

//封装最小权结点和次小权结点
typedef  struct 
{
    int s1;
    int s2;
}MinCode;

//函数声明
void Error(char *message);
HuffmanCode HuffmanCoding(HuffmanTree &HT,HuffmanCode HC,int *w,int n);
MinCode   Select(HuffmanTree HT,int n);

//当输入1个结点时的错误提示
void Error(char *message)
{  
    fprintf(stderr,"Error:%s\n",message);  
    exit(1);
}

//构造哈夫曼树HT，编码存放在HC中,w为权值,n为结点个数
HuffmanCode HuffmanCoding(HuffmanTree &HT,HuffmanCode HC,int *w,int n)
{ 
    int i,s1=0,s2=0; 
    HuffmanTree p;
    char *cd;
    int f,c,start,m;
    MinCode min;

    if(n<=1) 
    {
        Error("Code too small!");//只有一个结点不进行编码，直接exit(1)退出。非return,如果return 会造成main函数HT[i]无值
    }

    m=2*n-1;//哈弗曼编码需要开辟的结点大小为2n-1
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//开辟哈夫曼树结点空间 m+1 。为了对应关系，我们第0个空间不用。

    //初始化n个叶子结点,w[0] = 0,main函数已赋值
    for(p=HT,i=0;i<=n;i++,p++,w++)
    { 
        p->weight=*w;  
        p->parent=0; 
        p->lchild=0; 
        p->rchild=0;
    }

    //将n-1个非叶子结点的初始化
    for(;i<=m;i++,p++)
    { 
        p->weight=0;  
        p->parent=0; 
        p->lchild=0;
        p->rchild=0;
    }

    //构造哈夫曼树
    for(i=n+1;i<=m;i++)
    {
        min=Select(HT,i-1);//找出最小和次小的两个结点
        s1=min.s1 ; //最小结点下标
        s2=min.s2;//次小结点下标
        HT[s1].parent=i; 
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;//赋权和
    }

    //打印哈弗曼树
    printf("HT  List:\n");
    printf("Number\t\tweight\t\tparent\t\tlchild\t\trchild\n");

    for(i=1;i<=m;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }

    //从叶子结点到根节点求每个字符的哈弗曼编码
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
    cd=(char *)malloc(n*sizeof(char *));//为哈弗曼编码动态分配空间
    cd[n-1]='\0';//如：3个结点编码最长为2。cd[3-1] = '\0';

    //求叶子结点的哈弗曼编码
    for(i=1;i<=n;i++)
    { 
        start=n-1;
        //定义左子树为0，右子树为1
        /*
        从最下面的1号节点开始往顶部编码(逆序存放)，然后编码2号节点，3号......
        */
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)  
                cd[--start]='0';
            else 
                cd[--start]='1';
        }

        //为第i个字符分配编码空间
        HC[i]=(char *)malloc((n-start)*sizeof(char *));
        //将当前求出结点的哈弗曼编码复制到HC
        strcpy(HC[i],&cd[start]);   
    }
    free(cd);
    return HC;
}

MinCode Select(HuffmanTree HT,int n)
{  
    int min,secmin;
    int temp = 0;
    int i,s1,s2,tempi = 0;
    MinCode  code ;
    s1=1;
    s2=1;

    min = 66666;//足够大

    //找出权值weight最小的结点，下标保存在s1中
    for(i=1;i<=n;i++)
    {
        if(HT[i].weight<min && HT[i].parent==0)
        {
            min=HT[i].weight;
            s1=i;
        }
    }

    secmin = 66666;//足够大

    //找出权值weight次小的结点，下标保存在s2中
    for(i=1;i<=n;i++)
    {
        if((HT[i].weight<secmin) && (i!=s1) && HT[i].parent==0)
        {
            secmin=HT[i].weight; 
            s2=i;
        }
    }

    //放进封装中
    code.s1=s1;
    code.s2=s2;
    return code;
}

void HuffmanTranslateCoding(HuffmanTree HT, int n,char* ch)
{//译码过程
    int m=2*n-1;
    int i,j=0;

    printf("After Translation:");
    while(ch[j]!='\0')//ch[]:你输入的要译码的0101010串
    {
        i=m;
        while(0 != HT[i].lchild && 0 != HT[i].rchild)//从顶部找到最下面
        {
            if('0' == ch[j])//0 往左子树走
            {
                i=HT[i].lchild;
            }
            else//1 往右子树走
            {
                i=HT[i].rchild;
            }
            ++j;//下一个路径
        }
        printf("%c",N[i-1]);//打印出来
    }
    printf("\n");
}

int main()
{
    HuffmanTree HT=NULL;
    HuffmanCode HC=NULL;
    int *w=NULL;
    int i,n;
    char tran[100];

    printf("Input  N(char):");
    gets(N);
    fflush(stdin);
    n = strlen(N);

    w=(int *)malloc((n+1)*sizeof(int *));//开辟n+1个长度的int指针空间
    w[0]=0;
    printf("Enter weight:\n");

    //输入结点权值
    for(i=1;i<=n;i++)
    {  
        printf("w[%d]=",i);  
        scanf("%d",&w[i]);
    }
    fflush(stdin);//清空文件缓冲区,加后多次输入需要回车
    //构造哈夫曼树HT，编码存放在HC中,w为权值,n为结点个数
    HC=HuffmanCoding(HT,HC,w,n);

    //输出哈弗曼编码
    printf("HuffmanCode:\n");
    printf("Number\t\tWeight\t\tCode\n");
    for(i=1;i<=n;i++)
    {
        printf("%c\t\t%d\t\t%s\n",N[i-1],w[i],HC[i]);
    }

    fflush(stdin);
    //译码过程
    printf("Input HuffmanTranslateCoding:");
    gets(tran);
    HuffmanTranslateCoding(HT, n, tran);
    return 0;
}

