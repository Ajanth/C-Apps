#include <windows.h>
#include<shlobj.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<iostream>
#include "resource.h" 
using namespace std;

char szFile[256];
char mas[256];
char path1[256],path2[256],path[256],path3[256],mpath[256];
HWND win1,win2,win3,win4,win5,win6,win7,win8;
OPENFILENAME opfile;
HANDLE han[50];
int sor=0,sor1=0;
int check_file(char *,int);
int remove_fol(char*,int,char*);
int file_updater(char*,char*);
int renamer();
int initiator();
char windir_op1()//function to get the windows directory
{   
     GetWindowsDirectory(path1,sizeof(path1));
     }
int count_read()//fun to read the number of lines stored
{
    windir_op1();
    char reed[256];
    strcpy(reed,path1);
    strcat(reed,"\\system32\\conto.aja");
    FILE *read;
    int coun=0;
    read=fopen(reed,"r+");
    if(!read)
    MessageBox(NULL,"error in file. did u delete that","hei",MB_OK);
    fscanf(read,"%d",&coun);
    fclose(read);
    return coun;
    }
int initiator()
{
    HWND running,extra;
    running=FindWindow(NULL,"secret");
    if(running)
    SendMessage(running,WM_DESTROY,0,0);
    Sleep(150);
    ShellExecute(NULL,"open","foldpro.exe",NULL,NULL,SW_HIDE);
    }
int count_inr_write(int c)//function to increment or decrement count
{
    windir_op1();
    char wri[256];
    strcpy(wri,path1);
    strcat(wri,"\\system32\\conto.aja");
    int ncoun=count_read()+1;
    FILE *write;
    write=fopen(wri,"w+");
    if(c==1)
    fprintf(write,"%d",ncoun);
    else
    fprintf(write,"%d",ncoun+2);
    fclose(write);
    }
int renamer()//function to rename temporary file
{
   MessageBox(NULL,"inside renamer","HEY",MB_OK);
   Sleep(100);
    char ren[256],old[256],olddr[256],newdr[256];
    windir_op1();
    strcpy(ren,path1);
    strcpy(old,path1);
    strcat(old,"\\system32\\fltemp.aja");
    strcat(ren,"\\system32\\flpass.aja");
    CopyFile(old,ren,false);
    MessageBox(NULL,"please wait.....","HEY",MB_OK);
    Sleep(200);
    DeleteFile(old);
    strcpy(olddr,path1);
    strcpy(newdr,path1);
    strcat(olddr,"\\system32\\driv.nth");
    strcat(newdr,"\\system32\\drtemp.nth");
    Sleep(100);
    MessageBox(NULL,"complete.....","HEY",MB_OK);
    CopyFile(newdr,olddr,false);
    MessageBox(NULL,"operation success.","HEY",MB_OK);
    Sleep(100);
     DeleteFile(newdr);
    }
int create_files()//function to initially create files
{
windir_op1();
char adrs[256],adrs2[256];
strcpy(adrs,path1); 
strcat(adrs,"\\system32\\driv.nth");
FILE *create;
create=fopen(adrs,"a+");
if(create)
{
fclose(create);
          } 
strcpy(adrs2,path1); 
strcat(adrs2,"\\system32\\conto.aja");
create=fopen(adrs2,"a+");
if(create)
{
fclose(create);
          } 
             }
int store_path(char* pathh)//this will store the locked folder path
{
    windir_op1();
    char addh2[256];
    strcpy(addh2,path1);
    strcat(addh2,"\\system32\\driv.nth");
    FILE *stor;
    stor=fopen(addh2,"a+");
    fprintf(stor,"%s\n",pathh); 
    fclose(stor);
    count_inr_write(1);
    }
int check_pass(char *passwd)//check if the password is correct
{ 
 windir_op1();
 char exis[200];
 char paty[256];
 strcpy(paty,path1);
 strcat(paty,"\\system32\\flpass.aja");
 FILE *chpas; 
 int i;
 chpas=fopen(paty,"r+"); 
 int posi=check_file(mas,500);
 for(i=1;i<=posi;i++)
 {        
 fscanf(chpas,"%s",&exis);
}
         if(strcmp(exis,passwd)==0)         
         {
         remove_fol(mas,posi,exis);
         }
         else if(strcmp(exis,passwd))
         {MessageBox ( NULL ,"WRONG PASSWORD",passwd, MB_OK);
         return 10;
              }
 fclose(chpas);      
 return 0;
 }
int remove_fol(char* mass,int num,char* dpas)
{
 windir_op1();
 char oldp[256],oldf[256],newf[256],newd[256],mov[256];
 char jim[256],lilly[100],amma[100];
 strcpy(oldp,path1);
 strcpy(mov,path1);
 strcat(oldp,"\\system32\\flpass.aja");
 FILE *rem;
 rem=fopen(oldp,"a+");
 for(int ni=1;ni<=num;ni++)
 {
         fscanf(rem,"%s",&jim);
         } 
 fclose(rem);
 rem=fopen(oldp,"r+");        
strcpy(newf,path1);
strcat(newf,"\\system32\\fltemp.aja");
FILE *temp;
temp=fopen(newf,"a+");
for(int nik=1;nik<=count_read();nik++)
{
fscanf(rem,"%s",&amma);
if(strcmp(amma,jim)!=0)
{
fprintf(temp,"%s\n",amma);
}
  else if(strcmp(jim,amma)==0)
   fprintf(temp,"thisfolderpathunlocked\n");
}
fclose(rem);
fclose(temp);
strcpy(oldf,path1);
strcat(oldf,"\\system32\\driv.nth");
rem=fopen(oldf,"r+");
for(int in=0;in<num;in++)
{ 
fscanf(rem,"%s",&jim);
}
fclose(rem);
rem=fopen(oldf,"r+");
strcpy(newd,path1);
strcat(newd,"\\system32\\drtemp.nth");
FILE* temp2;
temp2=fopen(newd,"a+");
for(int nika=1;nika<=count_read();nika++)
{
fscanf(rem,"%s",&amma);
if(strcmp(amma,jim)!=0)
{
fprintf(temp2,"%s\n",amma);
}
  else if(strcmp(jim,amma)==0)
   fprintf(temp2,"thisfolderpathunlocked\n");
}
fclose(rem);
fclose(temp2);
    }
int check_file(char *isit,int a=0)//check if the file is already locked
{ 
 windir_op1();
 strcpy(path3,path1);
 strcat(path3,"\\system32\\driv.nth");
 char red[256],blue[256],wit[256];
 FILE *check; 
 check=fopen(path3,"r+");
  for(int l=1;l<=count_read();l++)
 {
         fscanf(check,"%s",&red);
         
         if(strcmp(red,isit)==0&&a==0)         
         {
         MessageBox ( NULL ,"file is already locked.\nunlock it first","compare success" , MB_OK);
         fclose(check);
         return 1;
         }
         if(strcmp(red,isit)==0&&a)
         {
              fclose(check);
              return l; 
              }
         }
         
 if(a)
 {
 MessageBox ( NULL ,"The Folder You Specified Is Not Locked","SIR" , MB_OK);
 return 5;
 fclose(check);      
 return 0;
}

 fclose(check);      
 return 0;
 }
int pass_write(char* pass)//write the new password to the file (**secret)
{
    MessageBox(NULL,"please make a note of ur password",pass,MB_OK);
    FILE *passw;
    char buf2[256];
    windir_op1();
    strcpy(buf2,path1);
    strcat(buf2,"\\system32\\flpass.aja");
    passw=fopen(buf2,"a+");
    fprintf(passw,"%s\n",pass);
    fclose(passw);
    
    }
BOOL CALLBACK DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_INITDIALOG:
            { win2=GetDlgItem(hwnd,IDC_CLEAR);
             win3=GetDlgItem(hwnd,IDC_LIST);
             ShowWindow(win2,SW_HIDE);
             ShowWindow(win3,SW_HIDE);
             win4=GetDlgItem(hwnd,IDC_SHOWCOUNT);
             ShowWindow(win4,SW_HIDE);
             win5=GetDlgItem(hwnd,IDC_TEXTP);
             ShowWindow(win5,SW_HIDE);
             win6=GetDlgItem(hwnd,IDC_LOCK);
             ShowWindow(win6,SW_HIDE);
             }
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDC_ADD://when browse button is clicked
				{    
BROWSEINFO broso;//a structure that holds info about path,folder name,etc for browse dlg box
broso.hwndOwner=hwnd;//owner of the window
broso.pidlRoot=NULL;//initial directory to be shown
broso.pszDisplayName=szFile;//string to get the folder name
broso.lpszTitle="SELECT FOLDER TO SET PASSWORD";//hint displayed in dlg box
broso.ulFlags=BIF_RETURNONLYFSDIRS;//show only directories in the dialog box
broso.lpfn=NULL;//dont care for now
broso.lParam=NULL;  //dont care for now                 
LPITEMIDLIST pidl=SHBrowseForFolder(&broso);
//pid1 will get the path from the shbrowse function
SHGetPathFromIDList(pidl,mas);
//this will get the path of the folder selected
SetDlgItemText(hwnd,IDC_TEXT,mas);
char *pch;
pch=strstr(mas," ");
if(pch)
{MessageBox(NULL,"Please enter a path name without spaces!.\neg:c:\programfiles and not c:\program files","HELP!",MB_OK); 
      PostQuitMessage(0);
       }
ShowWindow(win2,SW_SHOWDEFAULT);
ShowWindow(win3,SW_SHOWDEFAULT);
ShowWindow(win6,SW_HIDE);
ShowWindow(win4,SW_HIDE);
  }
				break;
case IDC_REMOVE://id for help
MessageBox(NULL,"Use Browse to select a folder and then click on operation.\ndo not use a folder path that contains spaces inbetween please!\nfor any errors or bugs contact rktserviceproviders@gmail.com","HELP!",MB_OK);
break;
case IDC_LIST://id for unlock folder
{         
ShowWindow(win3,SW_HIDE);   
ShowWindow(win4,SW_SHOW);
ShowWindow(win2,SW_HIDE); 
ShowWindow(win5,SW_SHOW);
ShowWindow(win6,SW_SHOW);   //unlock folder button handle
SetWindowText(win5,"ENTER PASSWD");
SetWindowText(win6,"UNLOCK");
 SetWindowText(win4,"");
 }
 break;
 case IDC_CLEAR://id for lock folder
{
create_files();
SetWindowText(win5,"SET PASSWORD");
SetWindowText(win6,"LOCK");
SetWindowText(win4,"");
ShowWindow(win3,SW_HIDE);   
ShowWindow(win4,SW_SHOW);
ShowWindow(win2,SW_HIDE); 
ShowWindow(win5,SW_SHOW);
ShowWindow(win6,SW_SHOW);        
}
break;
case IDC_HIDE:
{
ShowWindow(hwnd,SW_HIDE);
PostQuitMessage(0);
}
break;
case IDC_LOCK://when the lock button is clicked send passwd to be written to the file (**confidential)
{
char car[256],cmpr[15];
GetWindowText(win4,car,sizeof(car));
GetWindowText(win6,cmpr,sizeof(cmpr));
if(strcmp(cmpr,"LOCK")==0)
{
if(strlen(car)<5)
MessageBox(hwnd,"Password Strength too low sir","caution",MB_OK);
if(check_file(mas)==1)
MessageBox(hwnd,"unlock the folder first","MR",MB_OK);
else
{ pass_write(car);
 store_path(mas);
  initiator();
   MessageBox(NULL,"operation success","HEY",MB_OK);
     }
   }
else if(check_pass(car)>=5)
{
GetWindowText(win4,car,sizeof(car));
MessageBox(hwnd,"hey man wat irresponsible work ur doing.\n Enter correct passwd and dont try chit chat with my application","hey man",MB_OK);
}
else   
{    
HWND run;
run=FindWindow(NULL,"secret");
SendMessage(run,WM_CLOSE,0,0); 
SendMessage(run,WM_CLOSE,0,0); 
SendMessage(run,WM_CLOSE,0,0); 
renamer();
initiator();
}
ShowWindow(win4,SW_HIDE);
ShowWindow(win5,SW_HIDE);
ShowWindow(win6,SW_HIDE);
win8=GetDlgItem(hwnd,IDC_TEXT);
SetWindowText(win8,"");
}
break;
}
break;
case WM_CLOSE:
PostQuitMessage(0);
break;
default:
return FALSE;
	}
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
    win1=FindWindow(NULL,"FOLDER PASSWORD");
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc);
}
