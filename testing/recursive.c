#include <stdio.h>

/*Ӧ�ó���:��ɾ��ָ��·���µ��ļ����������Լ����ļ����Լ����ļ�������
��һ����״�ṹ�Ķ�����ʹ�õݹ��ѯ,�����ѯ����,��״�Ĳ˵��ȵȣ��ݹ����ͨ���㷨���ڴ�,����ʹ�á�
����һ�ֽ�����β�ݹ顱���ǰ���һ�������ķ���ֵ��������������һ������,������ݹ������Ϸ���.β�ݹ�:����ֵ������*/
int fun(int n)
{
	int num;
	if(n == 1) return num = 1;//�������㣬�����ݹ����
	num = fun(n-1)+n; //�Լ������Լ���Ҳ���ǽеݹ�
	return num;
}

int main(void)
{
	int sum = fun(100);
	printf("sum = %d\n",sum);
	return 0;
}

/*�ݹ�ɾ���ļ���
static void DeleteFolder(string dir)
        {
            foreach (string d in Directory.GetFileSystemEntries(dir))
            {
                //�ж�·���Ƿ����
                if (File.Exists(d))
                {
                    FileInfo fi = new FileInfo(d);
                    //ȥ���ļ��е�ֻ������
                    if (fi.Attributes.ToString().IndexOf("ReadOnly") != -1)
                        fi.Attributes = FileAttributes.Normal;
                    File.Delete(d);//ֱ��ɾ�����е��ļ�  
                }
                else
                {
                    DirectoryInfo d1 = new DirectoryInfo(d);
                    if (d1.GetFiles().Length != 0)
                    {
                        DeleteFolder(d1.FullName);////�ݹ�ɾ�����ļ���
                    }
                    Directory.Delete(d);
                }
            }
        }
*/