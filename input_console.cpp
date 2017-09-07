#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//去除头尾的空白字符，返回一个C风格字符串指针
char* Trim(char* src);
//输入一个字符串，存到output里，左右空白字符会被自动去掉
char* GetString(char* output);
//获取一个整数，如果输入为空则返回默认值defValue
int GetInt(int defValue);
//获取一个小数，如果输入为空则返回默认值defValue
double GetDouble(double defValue);
//获取单字符输入，如果输入为空则返回默认值defValue
char GetChar(char defValue);
//获取bool型输入，如果输入为空则返回默认值defValue
bool GetBool(bool defValue);

struct User
{
      int id;
      char name[128];
      char phone[32];
      bool vip;
};

int main()
{
      User u;
      u.id = GetInt(0);
      GetString(u.phone);
      GetString(u.name);
      u.vip = GetBool(true);
      
      system("pause");//加上这一行，则需要按回车后才能退出
      return 0;
}

char* Trim(char* src)
{
      char* pStart = NULL;
      char* pEnd = NULL;
      char* p;
      
      //从第一个字符开始扫描
      for(p = src;*p != '\0';p++)
      {
          if(*p ==''||*p =='\t'||*p == '\n')
          {
                continue;
          }
          else
          {
               pStart = p;//开头
               break;
          }
      }
      //全部为空白字符
      if(pStart == NULL)
      {
          *src ='\0';
          return 0;
      }
      //继续扫描
      bool nonBlank = true;
      for(;;p++)
      {
           if(*p ==''||*p =='\t'||*p == '\n'||*p == '\0')
           {
                if(nonBlank)
                 {
                      pEnd = p;
                      nonBlank = false;
                 }
                 if(*p == '\0') break;
           }
           else
           {
               nonBlank = true;
           }
      }
 //截断末尾的空白  
 *pEnd = '\0'; 
 //有效长度为0，返回空指针
 if(pEnd == pStart) return NULL;
 return pStart;
}
 
char* GetString(char* output)
{
         char buf[512];
         gets(buf);
         char* str = Trim(buf);
         if(str == NULL)
                 return NULL;
         else
         {
            strcpy(output,str);
            return output;
         }
}
 
int GetInt(int defValue)
{
      char buf[128];
      char* str = GetString(buf);
       if(str == NULL)
                 return defValue;
       else
                 return atoi(str);
}
 
double GetDouble(double defValue)
{
      char buf[128];
      char* str = GetString(buf);
       if(str == NULL)
                 return defValue;
       else
                 return atof(str);
}
 
char GetChar(char defValue)
{
       char buf[128];
      char* str = GetString(buf);
       if(str == NULL)
                 return defValue;
       else
                 return str[0];
}
 
bool GetBool(bool defValue)
{
       char buf[128];
      char* str = GetString(buf);
       if(str == NULL)
                 return defValue;
       else
       {
         if(strcmp(str,"YES") == 0 ||strcmp(str,"yes") == 0||strcmp(str,"1") == 0||strcmp(str,"true") == 0||strcmp(str,"TRUE") == 0)
             return true;
           
         else 
             return false;
       }
}







