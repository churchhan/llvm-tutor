//========================================================================
// FILE:
//    RIV.h
//
// DESCRIPTION:
//    Declares the RIV pass
//
// License: MIT
//========================================================================
#ifndef LLVM_TUTOR_RIV_H
#define LLVM_TUTOR_RIV_H

#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/IR/ValueMap.h"
#include "llvm/ADT/MapVector.h"
#include "llvm/Pass.h"

//------------------------------------------------------------------------------
// New PM interface
//------------------------------------------------------------------------------
// TODO

//------------------------------------------------------------------------------
// Legacy PM interface
//------------------------------------------------------------------------------
struct RIV : public llvm::FunctionPass {
  static char ID;
  RIV() : FunctionPass(ID) {}
  bool runOnFunction(llvm::Function &) override;
  void print(llvm::raw_ostream &O, llvm::Module const *) const override;

  using RIVMapTy = llvm::MapVector<llvm::BasicBlock const *,
                                  llvm::SmallPtrSet<llvm::Value *, 8>>;

  void getAnalysisUsage(llvm::AnalysisUsage &Info) const override;
  RIVMapTy const &getRIVMap() const;

private:
  RIVMapTy RIVMap;
};
#endif
