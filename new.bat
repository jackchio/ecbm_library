@echo off
title ECBMһ��������
color a
set /p address=�����빤�������벻Ҫ�������ģ�:
md "ecbm_%address%"
cd "ecbm_%address%"
md "device"
xcopy "..\device" "%cd%\device" /s/e
md "ECBM_LIB"
xcopy "..\ECBM_LIB" "%cd%\ECBM_LIB" /s/e

copy "..\main.c" "%cd%\main.c"
copy "..\stc.h"  "%cd%\stc.h"