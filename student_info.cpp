#include <stdio.h>
#include <string.h>
///////定义数据///////
struct Student
{
       int id;
       char name[16];
       int scores[3];
};
Student data[100];//数据源：存储所有数据
int count = 0;//总个数
//定义一个用于信息输入的函数
//将输入的信息保存到输入参数s
//返回0，表示成功录入；返回-1，表示录入失败
int input(Student* s)
{
           printf("ID:");
           scanf("%d",s->id);
           
           printf("Name:");
           scanf("%s",s->name);
           
           printf("Score:");
           int a,b,c;
           scanf("%d,%d,%d",&a,&b,&c);
           s->scores[0] = a;
           s->scores[1] = b;
           s->scores[2] = c;
           return 0;
}
//函数：将新录入的学生信息保存到数据源
//返回值0，成功；返回值-1，失败
int add(const Student* s)
{
        data[count] = * s;
        count++;
        return 0;//总是成功
}
//函数：将数据源里所有记录全部打印显示
void list_all()
{
     printf("ID \tName \tScore \n");
     printf("--------------------------\n");
     for(i = 0;i < count;i++)
     {
           Student* s = data[i];
           printf("%d\t%s\t%d,%d,%d\n",s.id,s.name,s.scores[0],s.scores[1],s.scores[2]);
 
     }
     printf("------------------------\n");
}
//按照名称查找
Student* find(const char* name)
{
        for(i = 0; i < count; i++)
        {
              Student* s = data[i];
              if(strcmp(name,s->name) == 0)
              {
                 return s;
              }
        }
       return NULL;
}

int main()
{
         char cmdline[128];
         while(1)
         {
              printf(">");
              scanf("cmd:%s\n",cmdline);
              //退出
              if(strcmp(cmdline,"exit") == 0)
              {
                   printf("now exit......\n");
                   break;
              }
              //菜单处理
              if(strcmp(cmdline,"list") == 0)
              {
                  list_all();
                  continue;
              }
              if(strcmp(cmdline,"add") == 0)
              {
                  Student s;
                  input(&s);
                  add(&s);
                  continue;
              }
              if(strcmp(cmdline,"count") == 0)
              {
                 printf("total:%d\n",count);
                 continue;
              }
              if(strcmp(cmdline,"find") == 0)
              {
                 printf("please enter Name:");
                 char name[16];
                 scanf("%s",name);
                 Student* s = find(name);
                 if(s)
                 {
                      printf("Find:ID:%d, Name:%s, Scores:%d,%d,%d\n",s->id,s->name,s->scores[0],s->scores[1],s->scores[2]);
                 }
                 else
                 {
                      printf("not found.....\n");
                 }
                 continue;
              }
              
            printf("bad input...\n");  
         }
         return 0;
}

int test()
{
   Student s;
   s.id = 1024;
   strcpy(s.name,"xiaoming");
   s.scores[0] = 70;
   s.scores[1] = 80;
   s.scores[2] = 90;
   add(&s);
   list_all();
   return 0;
}








