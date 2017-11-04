#include <cstring>
#include <windows.h>
bool UTF8ToUnicode(const char* UTF8, wchar_t* strUnicode)
{
    DWORD dwUnicodeLen;        //ת����Unicode�ĳ���
    TCHAR *pwText;            //����Unicode��ָ��
    //  wchar_t* strUnicode;        //����ֵ
    //���ת����ĳ��ȣ��������ڴ�
    dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,UTF8,-1,NULL,0);
    pwText = new TCHAR[dwUnicodeLen];
    if (!pwText)
    {
        return false;
    }
    //תΪUnicode
    MultiByteToWideChar(CP_UTF8,0,UTF8,-1,pwText,dwUnicodeLen);
    //תΪCString
    wcscpy(strUnicode, pwText);
    //����ڴ�
    delete []pwText;
    return true;
}
