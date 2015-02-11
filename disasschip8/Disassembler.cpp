#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <iomanip>
#
#include <stdio.h>
#include "Disassembler.h"

using namespace std;

Disassembler::Disassembler()
{
}

void Disassembler::insClearScreen()
{
  theDisassembly[theAddress] = "clear_screen";
}

void Disassembler::insReturnFromSub()
{
   theDisassembly[theAddress] = "ret";
}

void Disassembler::insJump(unsigned addr)
{
   ostringstream ss;
   ss << "jmp 0x" << setfill('0') << setw(4) << hex << addr;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insCall(unsigned addr)
{
   ostringstream ss;
   ss << "call 0x" << setfill('0') << setw(4) << hex << addr;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetIndexReg(unsigned addr)
{
   ostringstream ss;
   ss << "mov I, 0x" << setfill('0') << setw(4) << hex << addr;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insJumpWithOffset(unsigned addr)
{
   ostringstream ss;
   ss << "jmp 0x" << setfill('0') << setw(4) << hex << addr << " + v0";

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfRegEqConst(unsigned reg, unsigned val)
{
   ostringstream ss;
   ss << "skipnext_eq v" << hex << reg << ", 0x" << setfill('0') << setw(2) << hex << val;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfRegNotEqConst(unsigned reg, unsigned val)
{
   ostringstream ss;
   ss << "skipnext_ne v" << hex << reg << ", 0x" << setfill('0') << setw(2) << hex << val;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetReg(unsigned reg, unsigned val)
{
   ostringstream ss;
   ss << "mov v" << hex << reg << ", 0x" << setfill('0') << setw(2) << hex << val;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insAddReg(unsigned reg, unsigned val)
{
   ostringstream ss;
   ss << "add v" << hex << reg << ", 0x" << setfill('0') << setw(2) << hex << val;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insRandomNum(unsigned reg, unsigned mask)
{
   ostringstream ss;
   ss << "rand v" << hex << reg << ", 0x" << setfill('0') << setw(2) << hex << mask;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfRegEq(unsigned reg1, unsigned reg2)
{
   ostringstream ss;
   ss << "skipnext_eq v" << hex << reg1 << ", v" << reg2;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfRegNotEq(unsigned reg1, unsigned reg2)
{
   ostringstream ss;
   ss << "skipnext_ne v" << hex << reg1 << ", v" << reg2;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetRegToRegVal(unsigned regToSet, unsigned regVal)
{
   ostringstream ss;
   ss << "mov v" << hex << regToSet << ", v" << regVal;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insOrReg(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "or v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insAndReg(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "and v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insXorReg(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "xor v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insAddRegs(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "add v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSubRegs(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "sub v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSubRegsOtherOrder(unsigned reg, unsigned otherReg)
{
   ostringstream ss;
   ss << "subrev v" << hex << reg << ", v" << otherReg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insRightShift(unsigned reg)
{
   ostringstream ss;
   ss << "right_shift v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insLeftShift(unsigned reg)
{
   ostringstream ss;
   ss << "left_shift v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfKeyPressed(unsigned reg)
{
   ostringstream ss;
   ss << "skipnext_on_keypress v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSkipNextIfKeyNotPressed(unsigned reg)
{
   ostringstream ss;
   ss << "skipnext_on_not_keypress v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}

void Disassembler::insWaitForKeyPress(unsigned reg)
{
   ostringstream ss;
   ss << "store_keypress v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetRegToDelayTimer(unsigned reg)
{
   ostringstream ss;
   ss << "mov v" << hex << reg << ", delay_timer";

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetDelayTimer(unsigned reg)
{
   ostringstream ss;
   ss << "mov delay_timer, v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetSoundTimer(unsigned reg)
{
   ostringstream ss;
   ss << "mov sound_timer, v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insAddRegToIndexReg(unsigned reg)
{
   ostringstream ss;
   ss << "add I, v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetIndexToCharInReg(unsigned reg)
{
   ostringstream ss;
   ss << "mov I, (font_base + v" << hex << reg << ")";

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insSetIndexMemoryToRegBcd(unsigned reg)
{
   ostringstream ss;
   ss << "mov [I:I+2], bcd(" << hex << reg << ")";

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insStoreRegsToIndexMemory(unsigned reg)
{
   ostringstream ss;
   ss << "mov [I:I+" << reg << "], v0:v" << hex << reg;

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insLoadRegsFromIndexMemory(unsigned reg)
{
   ostringstream ss;
   ss << "mov v0:v" << reg << ", [I:I+" << reg << "]";

   theDisassembly[theAddress] = ss.str();
}


void Disassembler::insDrawSprite(unsigned xReg, unsigned yReg, unsigned height)
{
   ostringstream ss;
   ss << "draw_spirte xreg=v" << xReg << ", yreg=v" << yReg << ", h=" << height;

   theDisassembly[theAddress] = ss.str();
}

void Disassembler::printDisassembly()
{
   unsigned int curAddress = 0x200;

   while (curAddress < theAddress)
   {
      printf("0x%04x\t%s\n", curAddress, theDisassembly[curAddress].c_str());
      curAddress += 2;
   }
}

void Disassembler::insBad(unsigned opCode)
{
   ostringstream ss;
   ss << "BAD OPCODE 0x" << setfill('0') << setw(4) << hex << opCode;

   theDisassembly[theAddress] = ss.str();
}

