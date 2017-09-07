#include <stdio.h>
#include <string.h>

struct Student
{
      int id;
      char name[16];
      Student* next;
};

 Student* find(Student* head,int id)
 {
      Student* p = head;
      while(p)
      {
            if(p.id == id)//符合条件
                 return p;
            p = p->next;
      }
   return NULL；//没有找到符合条件的对象
 }
 /*链表的构造与遍历
 int main()
 {
          Student ss[4];
          ss[0].next = &ss[1];
          ss[1].next = &ss[2];
          ss[2].next = &ss[3];
          ss[3].next = 0;
       Student* p = &ss[0]; 
       while(p)
       {
           printf("ID:%d,name:%s\n",p.id,p.name);
           p = p.next;
       }
     Student* result = find(&ss[0],201711);
     return 0;
 }
 */
 
 //定义一个头节点
 Student m_head ={0};
 //插入一个对象到链表
 void add(Student* obj)
 {
      Student* p = &m_head;
      while(p->next)
            p = p->next;//找到最后一个对象
      p->next = obj;//把obj挂到最后一个对象后面
      obj.next = NULL;
 }
 
 //用户输入数据，返回值0，成功；返回值-1，用户输入有误
 int user_input(Student* obj)
 {
      printf("学号：");
      scanf("%d",*obj.id);
      printf("名字：");
      scanf("%s",*obj.name);
      return 0;
 }
 
 /*
 int main()
 {
    while(1)
    {
         Student* obj1 = (Student*) malloc(sizeof(Student));
         if(user_input(obj1) == 0)
         {
              add(obj1);
         }
         else
         {
             free(obj1);
         }
    }
    return 0;
 }
 */
 
 //按顺序插入节点
 int insert(Student* obj)
 {
       Student* cur = m_head.next;//当前节点
       Student* pre = &m_head;//上一个节点
       while(cur)
       {
            if(obj.id <= cur.id)//找到位置
              break;
          pre = cur;    
          cur = cur.next;
       }
      //插到pre节点的后面
      obj.next = pre.next;
      pre.next = obj;
      return 0;
 }
 //按ID查找并删除节点
 void remove(int id)
 {
      Student* cur = m_head.next;
      Student* pre = &m_head;
      while(cur)
      {
          if(id == cur.id)
            {
                pre.next = cur.next;
                free(cur);
                break;
            }
            pre = cur;
            cur = cur.next;
      }
 }
//遍历
void show_all()
{
     Student* p = m_head.next;
     while(p)
     {
          printf("ID:%d,name:%s\n",p.id,p.name);
          p = p.next;
     }
}

int main()
{
       Student* obj = NULL;
       
        Student* obj = (Student*)malloc(sizeof(Student));
        obj.id = 8;
        strcpy(obj.name,"abc");
        insert(obj);
        
        Student* obj1 = (Student*)malloc(sizeof(Student));
        obj1.id = 555;
        strcpy(obj1.name,"ddd");
        insert(obj1);
        
        Student* obj2 = (Student*)malloc(sizeof(Student));
        obj2.id = 2;
        strcpy(obj2.name,"www");
        insert(obj2);
        
        remove(555);
        remove(2);
        show_all();
        return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
