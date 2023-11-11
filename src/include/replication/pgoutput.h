/*-------------------------------------------------------------------------
 *
 * pgoutput.h
 *		Logical Replication output plugin
 *
 * Copyright (c) 2015-2022, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *		src/include/replication/pgoutput.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef PGOUTPUT_H
#define PGOUTPUT_H

#include "nodes/pg_list.h"
/*
pgoutput 插件的内部数据结构 PGOutputData 的定义。这个结构用于存储 pgoutput 插件的状态和配置信息。以下是每个字段的含义：

context: 这是一个内存上下文，用于分配临时内存。在 PostgreSQL 中，内存上下文是一种内存分配和管理的机制，它允许你在一个上下文中分配内存，然后一次性释放所有的内存，而不需要单独释放每个内存块。

cachectx: 这也是一个内存上下文，但它用于存储缓存数据。这可以提高性能，因为一些经常使用的数据可以被缓存起来，而不需要每次都重新计算或获取。

protocol_version: 这是客户端指定的协议版本。pgoutput 插件可以支持多个版本的协议，这个字段用于确定应该使用哪个版本的协议。

publication_names: 这是一个列表，包含了客户端想要订阅的所有发布的名称。

publications: 这是一个列表，包含了客户端想要订阅的所有发布的详细信息。每个发布都是一个 Publication 结构，包含了发布的名称、所有者、表等信息。

binary: 这是一个布尔值，表示是否应该使用二进制格式进行复制。二进制格式通常比文本格式更快，但也更难以调试。

streaming: 这是一个布尔值，表示是否应该使用流模式进行复制。在流模式下，数据更改会立即发送给客户端，而不是等到事务提交时才发送。

messages: 这是一个布尔值，表示是否应该发送额外的消息，如事务开始和结束消息。

two_phase: 这是一个布尔值，表示是否应该使用两阶段提交进行复制。两阶段提交可以确保在多个数据库之间的复制是原子的，但它也会增加复制的复杂性和开销。

*/
typedef struct PGOutputData
{
	MemoryContext context;		/* private memory context for transient allocations */
	MemoryContext cachectx;		/* private memory context for cache data */

	/* client-supplied info: */
	uint32		protocol_version;
	List	   *publication_names;
	List	   *publications;
	bool		binary;
	bool		streaming;
	bool		messages;
	bool		two_phase;
} PGOutputData;

#endif							/* PGOUTPUT_H */
