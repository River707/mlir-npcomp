#  Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
#  See https://llvm.org/LICENSE.txt for license information.
#  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

import torch

from torch_mlir.torchscript.e2e_test.framework import TestUtils
from torch_mlir.torchscript.e2e_test.registry import register_test_case
from torch_mlir.torchscript.annotations import annotate_args, export

# ==============================================================================

class MmModule(torch.nn.Module):
    def __init__(self):
        super().__init__()
    @export
    @annotate_args([
        None,
        ([-1, -1], torch.float32),
        ([-1, -1], torch.float32),
    ])
    def forward(self, lhs, rhs):
        return torch.mm(lhs, rhs)

@register_test_case(module_factory=lambda: MmModule())
def MmModule_basic(module, tu: TestUtils):
    module.forward(tu.rand(4, 4), tu.rand(4, 4))

@register_test_case(module_factory=lambda: MmModule())
def MmModule_chained(module, tu: TestUtils):
    res = module.forward(tu.rand(4, 4), tu.rand(4, 4))
    module.forward(res, res)

# ==============================================================================

class TanhModule(torch.nn.Module):
    def __init__(self):
        super().__init__()
    @export
    @annotate_args([
        None,
        ([2, 3, -1], torch.float32),
    ])
    def forward(self, x):
        return torch.tanh(x)

@register_test_case(module_factory=lambda: TanhModule())
def TanhModule_basic(module, tu: TestUtils):
    module.forward(tu.rand(2, 3, 1))

# ==============================================================================

class MmTanhModule(torch.nn.Module):
    def __init__(self):
        super().__init__()
    @export
    @annotate_args([
        None,
        ([-1, -1], torch.float32),
        ([-1, -1], torch.float32),
    ])
    def forward(self, lhs, rhs):
        return torch.tanh(self.matmul(lhs, rhs))
    def matmul(self, lhs, rhs):
        return torch.mm(lhs, rhs)

@register_test_case(module_factory=lambda: MmTanhModule())
def MmTanhModule_basic(module, tu: TestUtils):
    module.forward(tu.rand(4, 2), tu.rand(2, 4))
