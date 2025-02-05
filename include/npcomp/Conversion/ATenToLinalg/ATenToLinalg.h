//===------------------------------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef NPCOMP_CONVERSION_ATENTOLINALG_ATENTOLINALG_H
#define NPCOMP_CONVERSION_ATENTOLINALG_ATENTOLINALG_H

#include "mlir/Pass/Pass.h"
#include <memory>

namespace mlir {
namespace NPCOMP {
std::unique_ptr<OperationPass<FuncOp>> createConvertATenToLinalgPass();
}
} // namespace mlir

#endif // NPCOMP_CONVERSION_ATENTOLINALG_ATENTOLINALG_H
