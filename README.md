# LispCAD
A scriptable 2D CAD software written in C++ using FLTK with Embeddable Common Lisp

Ensure you have installed the FLTK and ECL libraries.
Also you will need to download FLUID for GUI editing.

To build this software you must download Embeddable Common Lisp ( https://common-lisp.net/project/ecl/ )
Ensure that you configure the library locally with C++ support.
./configure --prefix=/usr/local --with-x --with-cxx --withdffi

It may be necessary to run ldconfig as root
Finally compile with g++ -std=c++11 main.cpp -I/usr/local/include -L/usr/local/lib -lecl -stdlib=libstdc++

Note: This project currently contains files that are generated and configured in the FLTK GUI builder FLUID.
This means that you'll need FLTK and FLUID also installed.

Currently I feel that FLUID is a bit simple for this complex of a GUI system and I may abandon it.
