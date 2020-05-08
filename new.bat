@echo off
title ECBM一键部署器
color a
set /p address=请输入工程名（请不要输入中文）:
md "ecbm_%address%"
cd "ecbm_%address%"
md "device"
xcopy "..\device" "%cd%\device" /s/e
md "ECBM_LIB"
xcopy "..\ECBM_LIB" "%cd%\ECBM_LIB" /s/e

copy "..\main.c" "%cd%\main.c"
copy "..\stc.h"  "%cd%\stc.h"