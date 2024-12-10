@echo off
title ECBM一键部署器
color a
set /p address=请输入工程名（请不要输入中文，keil对中文的支持不好，最好路径也是全英文的）:
md "new_project\ecbm_%address%"
cd  "new_project\ecbm_%address%"
md "device"
xcopy "..\..\device"       "%cd%\device" /s/e
md "ECBM_LIB"
xcopy "..\..\ECBM_LIB"  "%cd%\ECBM_LIB" /s/e
md ".vscode"
xcopy "..\..\.vscode"      "%cd%\.vscode" /s/e

copy "..\..\main.c"                 "%cd%\main.c"
copy "..\..\ecbm.uvproj"        "%cd%\ecbm.uvproj"
copy "..\..\STARTUP.A51"      "%cd%\STARTUP.A51"
copy "..\..\删除多余文件.bat" "%cd%\删除多余文件.bat"