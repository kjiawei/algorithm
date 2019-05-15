#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

#define peopleNum 200

typedef struct detailInfo
{
	string birthDay;
	string deathDay;
	string tombPlace;
	string lifeEvent; //生平大事记
} * dI;

typedef struct KFamily
{
	string name;
	struct KFamily *father; //root = NULL
	struct KFamily *mother;
	int grade;	//等级 第几世
	int belongTo; //属于父的第几个孩子
	//char fatherName[nameSize];
	//char motherName[nameSize];
	string statement;		 //备注 说明
	struct detailInfo dInfo; //更详细的个人信息

	//KFamily() {}
	/*KFamily(string n, struct KFamily *f, struct KFamily *m, int g, int b,
			string s, struct detailInfo d) : name(n), father(f), mother(m), grade(g),
											 belongTo(b), statement(s), dInfo(d){};*/
} * kFam;

/*目标:查询快,通过看图输入文字生成族谱图(在新建结点处增加关系、信息)以及保存到数据库和文件
0.以某个人为中心(可实现操作,添加父母,妻儿子女,兄弟,朋友)
1.使用树结构(多叉)实现族谱
2.网页应用(点击相应的图像介绍生平信息,相关上下族系)
3.音像资料上传下载
信息
定位,相片*/

kFam createFamilyTree(); //创建家族树 实际就是创建一个含有自己的结点
kFam insertTree(kFam kf, int grade, int belongTo);
kFam createNode(int type, kFam kf);
kFam updateNode(kFam kf);
void showNodeInfo();
bool addInfo(kFam kf, dI di); //添加额外信息 文字 图片 语音
void printFamily(kFam kf,int type);	//打印整个族谱 前中后序
int preNode(kFam kf);
int inNode(kFam kf);
int postNode(kFam kf);
int fatherChild(kFam kf, int type);
bool findPeople(kFam kf, int grade, int belongTo); //找人 根据名字 世 相关事件/说明
bool saveToFile(string fileName);
bool saveToDatabase(string dbName);
int menu();

int main(int argc, char **argv)
{
	int pos = 0, n;
	kFam kf = createFamilyTree();
	//string commond;cout<<"please input info:";cin>>commond;
	string tName = "k";
			kFam tFather = NULL;
			kFam tMother = NULL;
			int tGrade = -1;
			int tBelongTo = 1;
			string tStatement = "work hard";
			string tBirthDay = "1900:00:01";
			string tDeathDay = "1990:12:31";
			string tTombPlace = "GuangZhou";
			string tLifeEvent = "help many people";
			dI newDI = (dI)malloc(sizeof(struct detailInfo));
			kFam newNode = (kFam)malloc(sizeof(struct KFamily));
	while (1)
	{
		n = menu();
		switch (n)
		{
		case 7:
			break;
		case 0:
			n = menu();
			break;
		case 5:
			printf("please input name:\n");
			cin >> tName;
			//strcpy(newNode->name,tName);
			newNode->name = tName;
			printf("please input grade:\n");
			printf("please input name:\n");
			printf("please input name:\n");
			printf("please input name:\n");
			insertTree(newNode,pos++,1);
			free(newDI);
			free(newNode);
			break;
		default:break;
		}
	}
	printFamily(kf,3);
	return 0;
}

//菜单
int menu()
{
	cout << "        菜单：输入0返回菜单." << endl
		 << endl;
	cout << "一 遍历：" << endl;
	cout << "1.先序遍历 请输入1.";
	cout << endl
		 << "2.中序遍历 请输入2.";
	cout << endl
		 << "3.后序遍历 请输入3.";
	cout << endl
		 << endl
		 << "二 查找：" << endl;
	cout << "4.查找 请输入4." << endl;
	cout << endl
		 << "三 插入：" << endl;
	cout << "5.插入 请输入5." << endl;
	cout << endl
		 << "四 删除：" << endl;
	cout << "6.删除 请输入6." << endl;
	cout << endl
		 << "五 更新：" << endl;
	cout << "7.更新 请输入7." << endl;
	cout<< "请输入：";
	int n;
	cin >> n;
	return n;
}

//创建家族树
kFam createFamilyTree()
{
	kFam kf, f, m;
	dI di;
	di->birthDay="111";
	di->lifeEvent="222";
	/*for(int i=0;i<peopleNum;++i){
	kf[i]->belongTo=0;
	//kf->dInfo=NULL;
	kf[i]->father=NULL;
	kf[i]->mother=NULL;
	kf[i]->grade=-1;
	kf[i]->name="k";
	kf[i]->statement="666";}
	return true;*/
	//f = new KFamily("cm", f, f, 0, 1, "test", di);
	//m = new KFamily("jx", NULL, NULL, 0, 4, "test", NULL);
	//kf = new KFamily("jw", NULL, NULL, 1, 1, "test", NULL);
	kf->belongTo=1;
	kf->name="jw";
	//kf->dInfo=di;
	kf->grade=1;
	kf->statement="haha";

	return kf;
}

bool findPeople(kFam kf, int grade, int belongTo)
{
	if (kf)
	{
		if (kf->grade == grade && kf->belongTo == belongTo)
		{
			cout << kf->grade << "==" << grade << "&&" << kf->belongTo << "==" << belongTo << endl;
			return true;
		}
		else
		{
			findPeople(kf->father, grade, belongTo);
			findPeople(kf->mother, grade, belongTo);
		}
	}
	else
	{
		return false;
	}
}

//插入人员
kFam insertTree(kFam kf, int grade, int belongTo)
{
	if (findPeople(kf, grade, belongTo))
	{
		cout << "此人已在,请继续输入" << endl;
		return NULL;
	}
	else
	{
		if (kf == NULL)
		{
			kf = new KFamily();
		}
		else
		{
			//if(kf->grade&&kf->belongTo);
		}
	}
	return kf;
}

void showNodeInfo(kFam kf)
{
	//for (int i = 0; i < kf.length(); ++i)
	{
		cout << "kf->belongTo:"<< kf->belongTo << "\t";
		//kf->dInfo=NULL;
		//cout << "kf->father:"<< kf->father << "\t";
		//cout << "kf->mother:"<< kf->mother << "\t";
		cout << "kf->grade:"<< kf->grade << "\t";
		cout << "kf->name:"<< kf->name << "\t";
		cout << "kf->statement:"<< kf->statement << "\t\n"<<endl;
	}
}

//父子打印 1为先父后子 2为先子后父
int fatherChild(kFam kf, int type)
{
	if (kf)
	{
		if (type == 1)
		{
			preNode(kf);
			showNodeInfo(kf);
		}
		else
		{
			showNodeInfo(kf);
			preNode(kf);
		}
		return type;
	}else return 0;
}

int preNode(kFam kf)
{
	if(kf){
		showNodeInfo(kf);
		preNode(kf->father);
		preNode(kf->mother);
	}else return 0;
}

int inNode(kFam kf)
{
	if(kf){
		inNode(kf->father);
		showNodeInfo(kf);
		inNode(kf->mother);
	}else return 0;
}

int postNode(kFam kf)
{
	if(kf){
		postNode(kf->father);
		postNode(kf->mother);
		showNodeInfo(kf);
	}else return 0;
}

//输出家族信息
void printFamily(kFam kf, int type)
{
	switch (type)
	{
	case 0:
		preNode(kf);
		break;
	case 1:
		inNode(kf);
		break;
	case 2:
		postNode(kf);
		break;
	case 3:
		fatherChild(kf, 1);
		break;
	default:
		break;
	}
}

bool createNode(int type, struct KFamily kf)
{
	switch (type)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}