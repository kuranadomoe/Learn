#define _AFXDLL
#include <iostream>   
#include <afxinet.h>

int main()
{
	CInternetSession session("HttpClient");
	char * url = "https://forums.kleientertainment.com/game-updates/dst/?d=7&";
	CHttpFile *pfile = (CHttpFile *)session.OpenURL(url);

	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data + "\r\n";
		}
		content.TrimRight();
		printf(" %s\n ", content);
	}
	pfile->Close();
	delete pfile;
	session.Close();
	system("pause");
	return 0;
}