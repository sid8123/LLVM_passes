#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Target/TargetRegisterInfo.h"

using namespace llvm;

#define RISCV_MACHINEINSTR_PRINTER_PASS_NAME "RISCV PHI Instruction printer pass"

namespace {

class RISCVMachineInstrPrinter : public MachineFunctionPass {
public:
    static char ID;

    X86MachineInstrPrinter() : MachineFunctionPass(ID) {
        initializeRISCVMachineInstrPrinterPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override;

    StringRef getPassName() const override { return RISCV_MACHINEINSTR_PRINTER_PASS_NAME; }
};

char RISCVMachineInstrPrinter::ID = 0;

bool X86MachineInstrPrinter::runOnMachineFunction(MachineFunction &MF) {

    for (auto &MBB : MF) {
         for (auto& MI : MBB) {
             if (isa<PHINode>(*MI)) 
                        outs() << *I << "\n"; 
        outs() << "Contents of MachineBasicBlock:\n";
        outs() << MBB << "\n";
        const BasicBlock *BB = MBB.getBasicBlock();
        outs() << "Contents of BasicBlock corresponding to MachineBasicBlock:\n";
        outs() << BB << "\n";
    }
}

    return false;
}

} // end of anonymous namespace

INITIALIZE_PASS(X86MachineInstrPrinter, "RISCV-machineinstr-printer",
    RISCV_MACHINEINSTR_PRINTER_PASS_NAME,
    true, // is CFG only?
    true  // is analysis?
)

namespace llvm {

FunctionPass *createRISCVMachineInstrPrinterPass() { return new RISCVMachineInstrPrinter(); }

}