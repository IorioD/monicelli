#ifndef MONICELLI_ASMGEN_H
#define MONICELLI_ASMGEN_H

// Copyright 2017 the Monicelli project authors. All rights reserved.
// Use of this source code is governed by a GPLv3 license, see LICENSE.txt.

#include "llvm/IR/Module.h"
#include "llvm/Target/TargetMachine.h"

#include <string_view>
#include <vector>

namespace monicelli {

void registerTargets();

llvm::TargetMachine* getTargetMachine(std::string_view triple, std::string_view cpu,
                                      std::string_view features, bool emit_pic);

void writeAssembly(std::string_view to_filename, llvm::Module* module,
                   llvm::TargetMachine* target_machine);

#ifdef MONICELLI_ENABLE_LINKER
void linkAssembly(std::string_view output_name, const std::vector<std::string>& object_files,
                  bool keep_object_files = false);
#endif

} // namespace monicelli

#endif
