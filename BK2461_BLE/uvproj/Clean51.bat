@echo off
echo ����ִ������......

del /f/s/q *.
del /f/s/q *.lst
del /f/s/q *.obj
del /f/s/q *.lnp
del /f/s/q *.M51
del /f/s/q *.plg
del /f/s/q *.bak
del /f/s/q *.bin
del /f/s/q *.hex

: del /f/s/q *.bak
: del /f/s/q *.scc

: ɾ��û����չ�����ļ�
: del /f/s/q *. 

: del /f/s/q 11.cpp 
: del /f/s/q CMyPropertyPageTest.*

: ����VC����
: del /f/s/q *.aps
: del /f/s/q *.ncb
: del /f/s/q *.opt
: del /f/s/q *.plg
: del /f/s/q readme.txt

: rem ǿɾdebugĿ¼
: for /d /r .\ %%b in (*debug*) do rd /s /q "%%b"

rem �����ע��
: ���Ҳ��ע��

echo ������ϣ�
echo. & pause