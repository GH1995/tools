@echo off
title ���WiFi���ó���1.2
color 3B
:WindowsZIA
set TempFile_Name=%SystemRoot%\System32\BatTestUACin_SysRt%Random%.batemp
( echo "BAT Test UAC in Temp" >%TempFile_Name% ) 1>nul 2>nul
if exist %TempFile_Name% (
del %TempFile_Name% 1>nul 2>nul
goto:startx
) else (
echo.
echo ���ޣ���Ҫ�Ҽ��Թ���Ա������в��ܽ�����������
echo.
pause
goto:ZEnd
)
:startx
del %systemroot%\System32\admintestf.txt
cls
echo.
echo                    ���WIFI���ó���v1.2
echo.
echo            * ˵��1������WIFI����������������֧��
echo.
echo            * ˵��2������ICS����ʱ�迪��Windows Firewall
echo.
echo ����������ѡ���ܣ�
echo.
echo 	  ��������������������������������������������������������
echo 	  ��    1.  ����WiFi            2.  �鿴�����豸        ��
echo 	  ��                                                    �� 
echo 	  ��    3.  �޸�WIFI����        4.  �޸�WIFI����        ��
echo 	  ��                                                    ��
echo 	  ��    5.  ����WiFi����        6.  ����WiFi����        ��
echo 	  ��                                                    ��
echo 	  ��    7.  �˳�����                                    ��
echo 	  ��������������������������������������������������������
echo.
choice /C 1234567 /N /M " ѡ���� [1-7]:" 
if ERRORLEVEL 7 goto ZEnd
if ERRORLEVEL 6 goto ZStp
if ERRORLEVEL 5 goto ZGot
if ERRORLEVEL 4 goto ZPsw
if ERRORLEVEL 3 goto ZChange 
if ERRORLEVEL 2 goto ZSet 
if ERRORLEVEL 1 goto ZTech

:ZTech
cls
  netsh wlan set hostednetwork mode=allow
:SetID
echo.
  set /p ssid=���������WIFI���ƣ�ȡ���밴C):
  if "%ssid%"=="" echo ����������&pause&goto:SetID
  if "%ssid%"=="c" goto WindowsZIA 
  netsh wlan set hostednetwork ssid=%ssid%
:SetKey
echo.
  set /p pw=���������WIFI����:
  if "%pw%"=="" echo ����������&pause&goto:SetKey
  netsh wlan set hostednetwork key=%pw%
  netsh wlan start hostednetwork
echo  WIFI���ó�ʼ���ɹ�����������������ڼ������ã�
echo.
echo  �������£��Ҽ�����������������½�����ͼ�ꡪ��������͹������ġ���
echo.
echo        �������������á����뽫�����ӵ������������������ѡ�񡰹���
echo.
echo        ��ѡ�е��ղ����õ��������磺%ssid%
echo.
echo  ����޷��������Ժ���߹ر�ɱ���������ǽ���ԣ�������ע�����ٳ���~
echo.
echo �����������
 pause>nul
 goto WindowsZIA

:ZSet
cls
netsh wlan show hostednetwork
echo.
echo �����������
 pause>nul
 goto WindowsZIA

:ZChange
cls
echo.  
 set /p ssid=���������WIFI���ƣ�ȡ���밴C):
 if "%ssid%"=="" echo ID����Ϊ��&goto:ZChange
 if "%ssid%"=="c" goto WindowsZIA
 netsh wlan set hostednetwork ssid=%ssid% 
 goto WindowsZIA

:ZPsw
cls
echo.
 set /p pw=�������µ�WIFI���루ȡ���밴C):
 if "%pw%"=="" echo ���벻��Ϊ��&goto:ZPsw
 if "%pw%"=="c" goto WindowsZIA
 netsh wlan set hostednetwork key=%pw% 
 goto WindowsZIA



:ZGot
cls
netsh wlan set hostednetwork mode=allow
echo ����WiFi�ѳɹ�����
echo �����������
 pause>nul
 goto WindowsZIA

:ZStp
cls
netsh wlan set hostednetwork mode=disallow
echo ����WiFi�ѳɹ�����
echo �����������
 pause>nul
 goto WindowsZIA
end

:ZEnd
exit