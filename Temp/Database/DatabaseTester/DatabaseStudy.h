#pragma once

/*****************************************************************************************************
* 常见的DB
*     Sybase IQ、Oracle、SQLite、PostgreSQL、Firebird、MySQL
*
* CDM(Conceptual Data Model)：概念数据模型，表现数据库的全部逻辑的结构,与任何的软件或数据储藏结构无关。实体-关系图？
* PDM(Physical Data Model)：物理数据模型，体现数据库的物理实现（基于某一特定数据库管理系统）
* OOM()：面向对象模型，包含一系列包，类，接口和他们的关系。形成软件系统的逻辑的设计视图的类结构。本质上是软件系统的一个静态的概念模型
* BPM()：业务程序模型，描述业务的各种不同内在任务和内在流程，而且客户如何以这些任务和流程互相影响
* ILM()：信息流模型，是一个高层的信息流模型，主要用于分布式数据库之间的数据复制
*
* 
* 索引性能 ? 种类和各种的性能
*   聚集索引 -- 利用索引树(多路平衡树, b+tree)，时间复杂度是 O(logx(n)) ?
*   不使用 -- 顺序查找?
*   树状 -- 对数复杂度?
*   位图 -- Bitmap ?
*   
* 使用BME(?)优化 -- 搜索明显的不佳SQL语句；查询耗时的业务逻辑；通过培植JBOSS AOP来找出普通方法的性能问题
*****************************************************************************************************/

/*****************************************************************************************************
* 并行数据库
* 内存数据库 -- 
* 分布式数据库 -- BigTable
*****************************************************************************************************/
