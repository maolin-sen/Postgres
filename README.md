PostgreSQL Database Management System
=====================================

This directory contains the source code distribution of the PostgreSQL
database management system.

PostgreSQL is an advanced object-relational database management system
that supports an extended subset of the SQL standard, including
transactions, foreign keys, subqueries, triggers, user-defined types
and functions.  This distribution also contains C language bindings.

PostgreSQL has many language interfaces, many of which are listed here:

	https://www.postgresql.org/download/

See the file INSTALL for instructions on how to build and install
PostgreSQL.  That file also lists supported operating systems and
hardware platforms and contains information regarding any other
software packages that are required to build or run the PostgreSQL
system.  Copyright and license information can be found in the
file COPYRIGHT.  A comprehensive documentation set is included in this
distribution; it can be read as described in the installation
instructions.

The latest version of this software may be obtained at
https://www.postgresql.org/download/.  For more information look at our
web site located at https://www.postgresql.org/.


## 代码目录

src目录下的backend文件包含了所有后端源码：

```
./
├── access 各种存储访问方法、索引的实现(重要)
│   ├── brin BlockRange索引相关代码
│   ├── common 公共存取相关代码
│   ├── gin 倒排索引相关代码
│   ├── gist 可自定义的存取代码
│   ├── hash 哈希索引相关代码
│   ├── heap 堆相关代码，用于存取表
│   ├── index 索引访问相关代码
│   ├── nbtree B+树索引相关代码
│   ├── rmgrdesc WAL（redo日志）相关代码
│   ├── spgist SP-GiST索引相关代码
│   ├── table 访问"表(table)"相关的方法
│   ├── tablesample 抽样调查相关的方法
│   └── transam 事务管理器
├── backup
├── bootstrap 数据库初始化时调用方法
├── catalog 系统目录
├── commands SQL命令(重要)
├── executor 执行器相关代码(重要)
├── foreign FDW相关代码，使得用户可以通过SQL访问没有存储在数据库中的数据(扩展)
├── jit Just-In-Time Compilation，为即时编译的相关代码，用于提高查询语句性能（扩展）
│   └── llvm
├── lib 通用函数
├── libpq c/cpp的库函数，处理与客户端的通信
├── main 主程序
├── nodes 链表、节点等数据结构，以及相关的方法(重要)
├── optimizer 优化器相关代码(重要)
│   ├── geqo
│   ├── path
│   ├── plan
│   ├── prep
│   └── util
├── parser 编译器相关代码(重要)
├── partitioning 分片相关代码(重要)
├── po 语言文件配置
├── port 平台兼容性处理相关代码
│   ├── aix
│   ├── hpux
│   ├── tas
│   └── win32
├── postmaster postmaster进程，以及相关辅助进程的代码
├── regex 正则处理相关代码(重要)
├── replication 有关流复制的相关代码(重要)
│   ├── libpqwalreceiver
│   ├── logical
│   └── pgoutput
├── rewrite 规则与视图相关的重写处理
├── snowball 全文检索相关（语干处理）代码
│   ├── libstemmer
│   └── stopwords
├── statistics 收集统计信息相关代码，与估算相关
├── storage 管理各种类型存储系统相关代码(重要)
│   ├── buffer 共享磁盘缓冲区相关代码
│   ├── file 文件管理相关代码
│   ├── freespace 空闲空间映射（目的是能够快速定位到一个有足够空间存储元组的页）相关代码
│   ├── ipc 信号灯和共享内存相关代码
│   ├── large_object 大对象相关代码
│   ├── lmgr 锁管理器
│   ├── page 页管理器
│   ├── smgr 存储/磁盘管理器
│   └── sync 文件同步管理器
├── tcop postgres服务进程的主要处理部分，即查询流程调用的相关代码(重要)
├── tsearch 全文检索(扩展)
│   └── dicts
└── utils 各种支持函数，如错误报告、各种初始化操作、内存管理等
    ├── activity
    ├── adt 自定义数据类型相关代码
    ├── cache 高速缓存相关代码
    ├── error 错误报告相关代码
    ├── fmgr 函数管理器
    ├── hash 哈希相关代码，用于提升cache和mmgr的速度
    ├── init 初始化相关代码
    ├── mb 字符集编码相关代码
    │   ├── Unicode
    │   └── conversion_procs
    │       ├── cyrillic_and_mic
    │       ├── euc2004_sjis2004
    │       ├── euc_cn_and_mic
    │       ├── euc_jp_and_sjis
    │       ├── euc_kr_and_mic
    │       ├── euc_tw_and_big5
    │       ├── latin2_and_win1250
    │       ├── latin_and_mic
    │       ├── utf8_and_big5
    │       ├── utf8_and_cyrillic
    │       ├── utf8_and_euc2004
    │       ├── utf8_and_euc_cn
    │       ├── utf8_and_euc_jp
    │       ├── utf8_and_euc_kr
    │       ├── utf8_and_euc_tw
    │       ├── utf8_and_gb18030
    │       ├── utf8_and_gbk
    │       ├── utf8_and_iso8859
    │       ├── utf8_and_iso8859_1
    │       ├── utf8_and_johab
    │       ├── utf8_and_sjis
    │       ├── utf8_and_sjis2004
    │       ├── utf8_and_uhc
    │       └── utf8_and_win
    ├── misc 实现GUC相关代码
    ├── mmgr 内存管理器
    ├── resowner
    ├── sort 排序（内存或磁盘）相关代码
    └── time 事务时间相关代码
```


