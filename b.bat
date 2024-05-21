
del diff2u.exe
del *.o
SET PATH=C:\msys64\usr\bin;C:\WM;C:\msys64\mingw64\bin
pkg-config --cflags --static  >cflags.txt
pkg-config --libs --static  >libs.txt
g++ -c *.cpp @cflags.txt
g++ *.o -o diff2u.exe @libs.txt @libs.txt @libs.txt @libs.txt -static

