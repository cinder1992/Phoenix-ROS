## What is Phoenix-ROS?
Phoenix Research Operating System is pretty much what it says on the tin, a "Research" operating system for learning about how Operating Systems work

## Compiling
### NOTE
Phoenix-ROS requires a GCC cross-compiler for the i686-elf platform, along with a working copy of GRUB 2, therefore it is HIGHLY reccomended to compile Phoenix-ROS on a Linux based platform.

you can see how to create a cross-compiler [here](http://wiki.osdev.org/GCC_Cross-Compiler)

After creating a GCC cross-compiler and adding it to your $path, the operating system can be compiled into a working LiveCD ISO like so:

    make all

If you have a copy of qemu with the i686 platform included, you can launch qemu convinently from the makefile like so:

    make run-qemu

## License

MIT License

Copyright (c) 2015,2016 Neil Ray

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
