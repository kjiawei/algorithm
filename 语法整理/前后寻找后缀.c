#include"myhead.h"
//文件操作:判断文件的后缀，分别从前判断和从后判断

int main(int argc,char** argv){
	int i;
	char dot[20];//用于存放文件名的字符数组
	bzero(dot,0);
	
	struct stat buf;//文件信息结构体
	stat("/mnt/hgfs/share",&buf);
	
	DIR *dirptr = NULL;
	struct dirent *entry;//目录信息结构体
	dirptr=opendir("/mnt/hgfs/share");
	
	while((entry = readdir(dirptr) )!= NULL){
		printf("%s\n",entry->d_name);//显示当前目录下的文件
	//readdir();
	
	/*while(buf->st_errno!=0){
	for(i=0;i<strlen(buf);i++){IS_RDWU(argv[i])!=0}//对每个文件进行循环检查
	//printf("%d\n",p->st_size);//测试输出长度
	
	for(i=0;i<sizeof(buf->st_name);i++){
		if(dot[i]=='.'){
			//dot[i]得到当前文件的后缀
			//printf("");
		}
		//检测.计数，取最后一个.用switch选择后缀输出
		switch(){
			case .txt:printf("这是一个txt文件");break;
			case .wmv:printf("这是一个wmv文件");break;
			case .avi:printf("这是一个avi文件");break;
			case .mp3:printf("这是一个mp3文件");break;
			case .jpg:printf("这是一个jpg文件");break;
			default:case .txt:printf("已经不用找了");
		}
	}
	}*/
	
	}
	
	
	
	closedir(dirptr);
	
	return 0;
}
