### Windows 


##### 1. shell 后台执行
```
设置WshShell = CreateObject（“ WScript.Shell”）
WshShell.Run chr（34）＆“ C：\ ping.bat ”＆Chr（34），0
设置WshShell = Nothing
```
