#ifndef	#define	#endif

https://blog.csdn.net/ljinddlj/article/details/2193788



#pragma once

 **#ifndef**的方式受C/C++语言标准支持。它不光可以保证同一个文件不会被包含多次，也能保证内容完全相同的两个文件（或者代码片段）不会被不小心同时包含。当然，缺点就是如果不同头文件中的宏名不小心“撞车”，可能就会导致你看到头文件明明存在，编译器却硬说找不到声明的状况——这种情况有时非常让人抓狂。

**#pragma once**一般由编译器提供保证：同一个文件不会被包含多次。注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。你无法对一个头文件中的一段代码作pragma once声明，而只能针对文件。

> 参考博客：https://blog.csdn.net/jfkidear/article/details/7868662







