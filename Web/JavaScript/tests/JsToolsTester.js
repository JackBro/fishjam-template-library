"use strict";

/*************************************************************************************************************************
JavaScript相关的工具

混淆工具 -- JS代码必须明文下载到客户端，其保护非常困难
  Javascript 是一种基于原型的语言，没有严格的类型定义。在自定义的类中，对于需要外部访问的属性和方法，不能进行混淆；
  对于内部访问的属性和方法，需要进行混淆
  Chrome中可以通过 Sources -> Pretty print 来格式化混淆后的代码
*************************************************************************************************************************/


module("ToolsTester", {
    setup: function() {
    //dump("in ToolsTester::setup\n");
    },
    teardown: function() {
    //dump("in ToolsTester::teardown\n");
    }
});

test("JavaScript相关的工具", function() {
    equal(1, 1, "TODO:工具");
});


test("JUnit测试", function() {
    var objNull;
    equal(objNull, null, "jUnit的 equal 采用 == 进行判断");
    ok(objNull !== null, "证明 objNull !== null");
});
