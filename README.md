# beotiming-management
BEO-Timing Management Software


## Windows Deployment of the Binaries


* CD to your <path-to-app-binary><br>
D:<br>
cd D:\Dev\DidokFinder-Win-V1.0.0


* Use the Qt deploy tool
PATH=%PATH%;D:\Qt5\5.2.0\mingw48_32\bin <br>
windeployqt .

* Remove the debug libraries in subfoldery by hand

* Copy over the MinGW DLLs (only the lib*.dll)