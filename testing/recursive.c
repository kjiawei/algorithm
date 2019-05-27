#include <stdio.h>

/*应用场景:①删除指定路径下的文件夹里内容以及子文件夹以及子文件夹内容
②一般树状结构的都可以使用递归查询,比如查询地区,树状的菜单等等，递归比普通的算法耗内存,谨慎使用。
还有一种叫作“尾递归”就是把上一个方法的返回值当作参数传给下一个方法,不用像递归再向上返回.尾递归:返回值做参数*/
int fun(int n)
{
	int num;
	if(n == 1) return num = 1;//条件满足，结束递归调用
	num = fun(n-1)+n; //自己调用自己，也就是叫递归
	return num;
}

int main(void)
{
	int sum = fun(100);
	printf("sum = %d\n",sum);
	return 0;
}

/*递归删除文件夹
static void DeleteFolder(string dir)
        {
            foreach (string d in Directory.GetFileSystemEntries(dir))
            {
                //判断路径是否存在
                if (File.Exists(d))
                {
                    FileInfo fi = new FileInfo(d);
                    //去除文件夹的只读属性
                    if (fi.Attributes.ToString().IndexOf("ReadOnly") != -1)
                        fi.Attributes = FileAttributes.Normal;
                    File.Delete(d);//直接删除其中的文件  
                }
                else
                {
                    DirectoryInfo d1 = new DirectoryInfo(d);
                    if (d1.GetFiles().Length != 0)
                    {
                        DeleteFolder(d1.FullName);////递归删除子文件夹
                    }
                    Directory.Delete(d);
                }
            }
        }
*/