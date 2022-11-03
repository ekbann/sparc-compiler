# SPARC Architecture and Compiler Design

### Abstract
Present the architecture of a modern RISC digital computer circa 1996, its relationship to the Unix operating system and the C programming language. Understand the representation of high level languages in a form executable by such a computer and the underlying machine programming language and structure. The project will consider the C programming language, SPARC architecture, boolean logic, number systems, and computer arithmetic; macro assembly language programming and subroutine linkages; the operating system interface and input/output; understanding the output of the C compiler; the use of the C programming language to generate specific assembly language instructions.

### Objective
Understand the architecture of a RISC machine, specifically a Sun SPARCstation 5 workstation; Understand the microSPARC-II (code-named Swift) microprocessor implementing the SPARC V8 instruction set architecture (ISA) developed by Sun Microsystems; Learn the C language grammar and assembly language programming; the form of assembly language generated by a compiler; the interface to an operating system; and design a complete SPARC C compiler using flex and bison.

### Text Used
* Richard Paul, “SPARC Architecture, Assembly Language Programming, and C.” Prentice Hall.
* Brian Kernighan and Dennis Ritchie, “The C Programming Language.” Second Edition, Prentice Hall.
* Samuel P. Harbison and Guy L. Steel Jr., “C: A Reference Manual” Third Edition, Prentice Hall.
* Alfred V. Aho et. al., “Compilers: Principles, Techniques, and Tools” Addison-Wesley.
* John R. Levine et. al., “lex & yacc” Second Edition, O'Reilly & Associates.
* Richard M. Stallman, “GNU Emacs Manual.” Free Software Foundation.

### Usage
To **compile** the SPARC assembly compiler code only requires a *gcc* environment, but if you wish to **assemble** the resulting assembly code generated by the compiler would require a cross-platform environment as well (or a real/virtual SPARCstation 5/10/20 machine with the *gcc* tools installed).

You can run a Debian Linux *netinst* installation (version 11.5 / 32-bit) using Oracle's Virtualbox with minimum specs (2-vcores, 4GB RAM, 128MB VRAM, and 16GB dynamic HD). Install the base system with the *standard system utilities*. Then log into the text terminal as *root* and execute the following:

```
apt install git make gcc vim bison flex
git clone https://github.com/ekbann/sparc-compiler
cd sparc-compiler
make
./CC < test/test1.c
```

An alternative is to use **QEMU** and **Buildroot** to make tiny virtual machines. This tutorial describes how to compile or assemble simple user-level programs for a Sparc V8 target and step through their execution using Qemu and gdb. This tutorial assumes you're using linux.

###### Cross Compiler
A cross compiler is needed when the machine on which the compiler is running (called the host) is of a different architecture (say x86) than the machine for which the executable is to be produced (called target, which is Sparc V8 in our case). The simplest way of obtaining a working cross compiler is to use Buildroot.

Download the latest buildroot tarball and untar it. Navigate to the untared buildroot directory and run the following commands:

```
$ sudo apt install rsync
$ git clone https://github.com/buildroot/buildroot.git buildroot
$ make qemu_sparc_ss10_defconfig
$ make menuconfig
```

This will open a graphical interface. Go to `Toolchain–>` , scroll down and select the option `Build cross gdb for the host` . We have selected this option because the default buildroot configuration for sparc V8 (called qemu_sparc_ss10_defconfig) does not include cross-gdb by default. Save and exit the graphical interface. Now run make:

```
$ make
```

This will download and build required packages and can take a while. At the end of make, we get a working cross compiler toolchain. The binaries (sparc-linux-gcc, sparc-linux-as, sparc-linux-gdb etc) are present in folder: `<path-to-buildroot>/output/host/usr/bin`. Add this location to your system's PATH variable to use the cross compiler binaries outside buildroot.

###### Compiling and Assembling a Program
Consider a simple assembly program Foo.s:

Foo.s
```
.global _start
_start:
		  	  ! comments start with '!'
	mov 2, %g1        !
	mov 3, %g2        !
	add %g1, %g2, %g3 ! g3 should now contain 5
	nop
	nop
	nop
```
Assemble and link it to get an executable Foo. (The -g option is to include debugging symbols in the generated executable).
```
$ sparc-linux-as -g -o Foo.o Foo.s
$ sparc-linux-ld -g -o Foo   Foo.o
```
Instead of assembly, you can start with a simple C program Bar.c:

Bar.c
```
int a,b,c=0;
int main()
{
	a=2;
	b=3;
	c=a+b;
	return 0;
};
```
Compile, assemble and link it as follows.
```
$ sparc-linux-gcc -g -S      -o Bar.s Bar.c
$ sparc-linux-as  -g         -o Bar.o Bar.s
$ sparc-linux-ld  -g -e main -o Bar   Bar.o
```
The `-e` option points out location of the first executable instruction (the entry point) to the linker. We set the entry point to the function main() in our case. The disassembled instructions in Bar can be viewed using objdump utility
```
$ sparc-linux-objdump -d -S Bar
```
###### Running on Qemu with gdb
Install package qemu-user. This installs binaries for several targets, example qemu-alpha, qemu-mips, qemu-sparc.
```
$ sudo apt-get install qemu-user
```
In a terminal start qemu-sparc and set it up for remote debugging with gdb.
```
$ qemu-sparc -g 1234 Foo
```
In another terminal, open gdb.
```
$ sparc-linux-gdb  Foo
```
Inside gdb, attach to qemu :
```
(gdb) target remote :1234
In gdb, press s to step through assembly instructuctions. Use command `info reg <reg-name>` to examine register contents.

(gdb) target remote :1234
Remote debugging using :1234
_start () at Foo.s:4
4		mov 2, %g1        !
(gdb) s
5		mov 3, %g2        !
(gdb) s
6		add %g1, %g2, %g3 ! g3 should now contain 5
(gdb) info reg g3
g3             0x0	0
(gdb) s
7		nop
(gdb) info reg g3
g3             0x5	5
(gdb)
```
Here are some useful tutorials on gdb:

- http://www.dirac.org/linux/gdb/
- http://www.csee.umbc.edu/~cpatel2/links/310/nasm/gdb_help.shtml

### Design Notes
Summary of the important aspects of my compiler:

* All `external_decls` are assigned `modifier` type `EXTERN` unless specifically defined in the source code.
* I added a new debug directive, `debug(node_dump_on)` and its counterpart `debug(node_dump_off)`, which keeps track of the creation of new syntax tree nodes. The output format of a sample node is:

```   
    node_type: = [104576]
         left:   LEAF [106304]
        right:   NODE [104640]
```

The number in square brackets is a pointer to that specific node. At the end of parsing the source code, this directive outputs the pointer to the `ROOT` of the program syntax tree, e.g.

    `syntax tree root = [138368]`

This allows the user to manually reconstruct the syntax tree to verify if the syntax tree was constructed properly. Another simpler way is to use the directive `debug(statement_dump)`.

* The debug directive `debug(symtab_dump)` dumps the symbol table at the *current* context level. After the closing brace of a compound statement (see *CC.y* **statement** ) the compiler will delete the closing context level because those symbols are not required anymore.
*
