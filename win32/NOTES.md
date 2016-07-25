# Windows Programming

## Targets

1. To learn WIN32 programming with MinGW/MinGW-w64
1. To learn DirectShow programming
1. To learn encode/decode on Windows platform

## FAQs

### Can MinGW Link to MSVC DLL?
reference: [link](http://stackoverflow.com/questions/2472924/linking-to-msvc-dll-from-mingw)

A brief answer is no. Microsoft exported C++ classes from dlls, rather than C-functions. C++ functions are always exported with names in a mangled form that is specific to a particular version of the compiler.

Their dll is usable by MSVC only in that form, and will probably not even work between different versions of MSVC, as Microsoft have changed their mangling scheme before.

### How to use MSVC and Mingw DLL's and vice versa
reference: [link](http://www.mingw.org/wiki/MSVC_and_MinGW_DLLs)

### How to determine which version of Visual Studio was used to compile a static library
reference: [link](http://stackoverflow.com/questions/1411854/is-there-a-way-to-determine-which-version-of-visual-studio-was-used-to-compile-a)

## References
* Petzold, Windows Programming, 5e, Microsoft Press 1998

## History
* 2016/05/06 init
