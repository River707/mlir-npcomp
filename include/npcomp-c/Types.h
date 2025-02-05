/*===-- npcomp-c/Types.h - NPComp custom types --------------------*- C -*-===*\
|*                                                                            *|
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM          *|
|* Exceptions.                                                                *|
|* See https://llvm.org/LICENSE.txt for license information.                  *|
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception                    *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifndef NPCOMP_C_TYPES_H
#define NPCOMP_C_TYPES_H

#include "mlir-c/IR.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*/
/* Any dtype type.                                                            */
/*============================================================================*/

/** Checks whether the given type is the special "any dtype" type that is used
 * to signal an NDArray or tensor of unknown type. */
int npcompTypeIsAAnyDtype(MlirType t);

/** Gets the "any dtype" type. */
MlirType npcompAnyDtypeTypeGet(MlirContext context);

/*============================================================================*/
/* Bool type.                                                                 */
/*============================================================================*/

/** Checks whether the given type is the Python "bool" type. */
int npcompTypeIsABool(MlirType t);

/** Gets the Python "bool" type. */
MlirType npcompBoolTypeGet(MlirContext context);

/*============================================================================*/
/* Bytes type.                                                                */
/*============================================================================*/

/** Checks whether the given type is the Python "bytes" type. */
int npcompTypeIsABytes(MlirType t);

/** Gets the Python "bytes" type. */
MlirType npcompBytesTypeGet(MlirContext context);

/*============================================================================*/
/* Dict type.                                                                 */
/*============================================================================*/

/** Checks whether the given type is the Python "dict" type. */
int npcompTypeIsADict(MlirType t);

/** Gets the generic Python "dict" type. */
MlirType npcompDictTypeGet(MlirContext context);

/*============================================================================*/
/* List type.                                                                 */
/*============================================================================*/

/** Checks whether the given type is the Python "list" type. */
int npcompTypeIsAList(MlirType t);

/** Gets the generic Python "list" type. */
MlirType npcompListTypeGet(MlirContext context);

/*============================================================================*/
/* NDArray type.                                                              */
/*============================================================================*/

/** Checks whether the given type is an NdArray type. */
int npcompTypeIsANdArray(MlirType t);

/** Gets a numpy.NdArray type that is unranked. */
MlirType npcompNdArrayTypeGetUnranked(MlirType elementType);

/** Gets a numpy.NdArray type that is ranked. Any dimensions that are -1 are
 * unknown. */
MlirType npcompNdArrayTypeGetRanked(intptr_t rank, const int64_t *shape,
                                    MlirType elementType);

/// Helper that gets an equivalent NdArrayType from a ShapedType.
MlirType npcompNdArrayTypeGetFromShaped(MlirType shapedType);

/// Helper that converts an NdArrayType to a TensorType.
MlirType npcompNdArrayTypeToTensor(MlirType ndarrayType);

/*============================================================================*/
/* None type.                                                                 */
/*============================================================================*/

/** Checks whether the given type is the type of the singleton 'None' value. */
int npcompTypeIsANone(MlirType t);

/** Gets the type of the singleton 'None'. */
MlirType npcompNoneTypeGet(MlirContext context);

/*============================================================================*/
/* SlotObject type.                                                           */
/*============================================================================*/

MlirType npcompSlotObjectTypeGet(MlirContext context, MlirStringRef className,
                                 intptr_t slotTypeCount,
                                 const MlirType *slotTypes);

/*============================================================================*/
/* Tuple type.                                                                */
/*============================================================================*/

/** Checks whether the given type is the special "any dtype" type that is used
 * to signal an NDArray or tensor of unknown type. */
int npcompTypeIsATuple(MlirType t);

/** Gets the generic Python "tuple" type. */
MlirType npcompTupleTypeGet(MlirContext context);

/*============================================================================*/
/* torch.nn.Module type.                                                      */
/*============================================================================*/

/** Checks whether the given type is a torch.nn.Module type */
int npcompTypeIsANnModule(MlirType t);

/** Gets the !torch.nn.Module type of the specified class. */
MlirType npcompNnModuleTypeGet(MlirContext context, MlirStringRef className);

/*============================================================================*/
/* torch.optional type.                                                       */
/*============================================================================*/

/** Checks whether the given type is a !torch.optional<T> type */
int npcompTypeIsAOptional(MlirType t);

/** Gets the !torch.optional<T> type with subtype T. */
MlirType npcompOptionalTypeGet(MlirType containedType);

/*============================================================================*/
/* torch.Device type.                                                         */
/*============================================================================*/

/** Checks whether the given type is a !torch.Device type */
int npcompTypeIsADevice(MlirType t);

/** Gets the !torch.Device type. */
MlirType npcompDeviceTypeGet(MlirContext context);

#ifdef __cplusplus
}
#endif

#endif // NPCOMP_C_TYPES_H
