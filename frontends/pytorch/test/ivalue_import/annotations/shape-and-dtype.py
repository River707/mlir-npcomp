# -*- Python -*-
# This file is licensed under a pytorch-style license
# See frontends/pytorch/LICENSE for license information.

import typing

import torch
import torch_mlir

# RUN: %PYTHON %s | npcomp-opt | FileCheck %s

mb = torch_mlir.ModuleBuilder()

class TestModule(torch.nn.Module):
    def __init__(self):
        super().__init__()
    def forward(self, tensor):
        return

test_module = TestModule()
recursivescriptmodule = torch.jit.script(test_module)

annotator = torch_mlir.ClassAnnotator()
class_type = recursivescriptmodule._c._type()
# CHECK: func private @__torch__.TestModule.forward(
# CHECK-SAME: %arg0: !torch.nn.Module<"__torch__.TestModule">,
# CHECK-SAME: %arg1: !numpy.ndarray<*:!numpy.any_dtype> {torch.type_bound = !numpy.ndarray<[?,1024]:i8>}
# CHECK-SAME: ) -> !basicpy.NoneType             
annotator.annotateShapesAndDtypes(class_type, ['forward'], [
    None,
    ((-1, 1024), torch.int8),
])

# # TODO: Automatically handle unpacking Python class RecursiveScriptModule into the underlying ScriptModule.
mb.import_module(recursivescriptmodule._c, annotator)
mb.module.operation.print()
