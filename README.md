# SPARC Architecture and Compiler Design

##### Abstract
Present the architecture of a modern RISC digital computer circa 1996, its relationship to the Unix operating system and the C programming language. Understand the representation of high level languages in a form executable by such a computer and the underlying machine programming language and structure. The project will consider the C programming language, SPARC architecture, boolean logic, number systems, and computer arithmetic; macro assembly language programming and subroutine linkages; the operating system interface and input/output; understanding the output of the C compiler; the use of the C programming language to generate specific assembly language instructions.

##### Objective
Understand the architecture of a RISC machine, specifically a Sun SPARCstation 5 workstation; C and assembly language programming; the form of assembly language generated by a compiler; the interface to an operating system; and design a complete SPARC C compiler using flex and bison.

##### Text Used
* Richard Paul, “SPARC Architecture, Assembly Language Programming, and C.” Prentice Hall.
* Brian Kernighan and Dennis Ritchie, “The C Programming Language.” Second Edition, Prentice Hall.
* Samuel P. Harbison and Guy L. Steel Jr., “C: A Reference Manual” Third Edition, Prentice Hall.
* Alfred V. Aho et. al., “Compilers: Principles, Techniques, and Tools” Addison-Wesley.
* John R. Levine et. al., “lex & yacc” Second Edition, O'Reilly & Associates.
* Richard M. Stallman, “GNU Emacs Manual.” Free Software Foundation.

#### Design Notes
Summary of the important aspects of my compiler:

* All `external_decls` are assigned `modifier` type `EXTERN` unless specifically defined in the source code.
* I added a new debug directive, 'debug(node_dump_on)' and its counterpart 'debug(node_dump_off)', which keeps track of the creation of new syntax tree nodes. The output format of a sample node is:

```    node_type: = [104576]
         left:   LEAF [106304]
        right:   NODE [104640]```

The number in square brackets is a pointer to that specific node. At the end of parsing the source code, this directive outputs the pointer to the 'ROOT' of the program syntax tree, e.g.

    syntax tree root = [138368]

This allows the user to manually reconstruct the syntax tree to verify if the syntax tree was constructed properly. Another simpler way is to use the directive `debug(statement_dump)`.

