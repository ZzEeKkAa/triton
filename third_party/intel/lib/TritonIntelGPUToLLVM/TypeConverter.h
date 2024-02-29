#ifndef TRITON_CONVERSION_TRITONINTELGPU_TO_LLVM_TYPECONVERTER_H
#define TRITON_CONVERSION_TRITONINTELGPU_TO_LLVM_TYPECONVERTER_H

#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "triton/Conversion/MLIRTypes.h"

using namespace mlir;
using namespace mlir::triton;

class TritonIntelGPUToLLVMTypeConverter : public LLVMTypeConverter {
public:
  using TypeConverter::convertType;

  TritonIntelGPUToLLVMTypeConverter(
      MLIRContext *ctx, LowerToLLVMOptions &option,
      const DataLayoutAnalysis *analysis = nullptr);

  Type getElementTypeForStruct(RankedTensorType type);
  Type convertTritonPointerType(triton::PointerType type);
  Type convertTritonTensorType(RankedTensorType type);
};

#endif