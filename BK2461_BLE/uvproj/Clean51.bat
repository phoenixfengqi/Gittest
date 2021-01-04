@echo off
echo 正在执行清理......

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

: 删除没有扩展名的文件
: del /f/s/q *. 

: del /f/s/q 11.cpp 
: del /f/s/q CMyPropertyPageTest.*

: 清理VC工程
: del /f/s/q *.aps
: del /f/s/q *.ncb
: del /f/s/q *.opt
: del /f/s/q *.plg
: del /f/s/q readme.txt

: rem 强删debug目录
: for /d /r .\ %%b in (*debug*) do rd /s /q "%%b"

rem 这句是注释
: 这句也是注释

echo 清理完毕！
echo. & pause