@echo off
title 简洁WiFi配置程序1.2
color 3B
:WindowsZIA
set TempFile_Name=%SystemRoot%\System32\BatTestUACin_SysRt%Random%.batemp
( echo "BAT Test UAC in Temp" >%TempFile_Name% ) 1>nul 2>nul
if exist %TempFile_Name% (
del %TempFile_Name% 1>nul 2>nul
goto:startx
) else (
echo.
echo 啊噢，需要右键以管理员身份运行才能进行设置诶。
echo.
pause
goto:ZEnd
)
:startx
del %systemroot%\System32\admintestf.txt
cls
echo.
echo                    简洁WIFI配置程序v1.2
echo.
echo            * 说明1：建立WIFI需无线网卡及驱动支持
echo.
echo            * 说明2：设置ICS共享时需开启Windows Firewall
echo.
echo 请输入数字选择功能：
echo.
echo 	  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓
echo 	  ┃    1.  配置WiFi            2.  查看联接设备        ┃
echo 	  ┃                                                    ┃ 
echo 	  ┃    3.  修改WIFI名称        4.  修改WIFI密码        ┃
echo 	  ┃                                                    ┃
echo 	  ┃    5.  启用WiFi服务        6.  禁用WiFi服务        ┃
echo 	  ┃                                                    ┃
echo 	  ┃    7.  退出程序                                    ┃
echo 	  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛
echo.
choice /C 1234567 /N /M " 选择功能 [1-7]:" 
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
  set /p ssid=请输入你的WIFI名称（取消请按C):
  if "%ssid%"=="" echo 请输入名称&pause&goto:SetID
  if "%ssid%"=="c" goto WindowsZIA 
  netsh wlan set hostednetwork ssid=%ssid%
:SetKey
echo.
  set /p pw=请输入你的WIFI密码:
  if "%pw%"=="" echo 请输入名称&pause&goto:SetKey
  netsh wlan set hostednetwork key=%pw%
  netsh wlan start hostednetwork
echo  WIFI配置初始化成功，请进入网络连接内继续设置：
echo.
echo  步骤如下：右键点击桌面任务栏右下角网络图标——打开网络和共享中心——
echo.
echo        更改适配器设置——请将正连接到网络的有线网络设置选择“共享”
echo.
echo        并选中到刚才设置的虚拟网络：%ssid%
echo.
echo  如果无法共享，请稍候或者关闭杀毒软件防火墙尝试，不行则注销后再尝试~
echo.
echo 按任意键返回
 pause>nul
 goto WindowsZIA

:ZSet
cls
netsh wlan show hostednetwork
echo.
echo 按任意键返回
 pause>nul
 goto WindowsZIA

:ZChange
cls
echo.  
 set /p ssid=请输入你的WIFI名称（取消请按C):
 if "%ssid%"=="" echo ID不能为空&goto:ZChange
 if "%ssid%"=="c" goto WindowsZIA
 netsh wlan set hostednetwork ssid=%ssid% 
 goto WindowsZIA

:ZPsw
cls
echo.
 set /p pw=请输入新的WIFI密码（取消请按C):
 if "%pw%"=="" echo 密码不能为空&goto:ZPsw
 if "%pw%"=="c" goto WindowsZIA
 netsh wlan set hostednetwork key=%pw% 
 goto WindowsZIA



:ZGot
cls
netsh wlan set hostednetwork mode=allow
echo 虚拟WiFi已成功启用
echo 按任意键返回
 pause>nul
 goto WindowsZIA

:ZStp
cls
netsh wlan set hostednetwork mode=disallow
echo 虚拟WiFi已成功禁用
echo 按任意键返回
 pause>nul
 goto WindowsZIA
end

:ZEnd
exit