;; DFA-based pipeline description for Amethyst.
;; Copyright (C) 2021 Free Software Foundation, Inc.
;; Contributed by Thomas Sailer (t.sailer@alumni.ethz.ch).
;; Based on MIPS target for GNU compiler.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published
;; by the Free Software Foundation; either version 3, or (at your
;; option) any later version.

;; GCC is distributed in the hope that it will be useful, but WITHOUT
;; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;; or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
;; License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Attributes.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_attr "amethyst_rfwriteports" "none,even,odd,both" (symbol_ref "riscv_amethyst_regfile_halves (insn)"))

(define_attr "amethyst_maypipeb" "no,yes" (symbol_ref "riscv_amethyst_maypipeb (insn)"))

(define_attr "amethyst_cycle" "" (const_int 2))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Additional Instructions.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_insn "*loadconstsi"
  [(set (match_operand:SI 0 "register_operand"             "=r")
        (plus:SI (match_operand:SI 1 "lui_operand"         " L")
                 (match_operand:SI 2 "const_arith_operand" " I")))]
  "TARGET_AMETHYST"
  "li\t%0,%1+%2"
  [(set_attr "type" "const")
   (set_attr "mode" "SI")
   (set_attr "insnpair" "yes")])

(define_peephole2
  [(set (match_operand:SI 0 "register_operand")
        (match_operand:SI 1 "lui_operand"))
   (set (match_dup 0)
        (plus:SI (match_dup 0)
                 (match_operand:SI 2 "const_arith_operand")))]
   "TARGET_AMETHYST"
   [(set (match_dup 0)
         (plus:SI (match_dup 1)
                  (match_dup 2)))]
   {})

(define_insn "*loadsymaddrsi"
  [(set (match_operand:SI 0 "register_operand"                     "=r")
        (lo_sum:SI (high:SI (match_operand:SI 1 "symbolic_operand" ""))
                   (match_dup 1)))]
  "TARGET_AMETHYST"
  "lui\t%0,%h1;\taddi\t%0,%0,%R1"
  [(set_attr "type" "const")
   (set_attr "mode" "SI")
   (set_attr "insnpair" "yes")])

(define_peephole2
  [(set (match_operand:SI 0          "register_operand")
        (high:SI (match_operand:SI 1 "symbolic_operand")))
   (set (match_dup 0)
        (lo_sum:SI (match_dup 0)
                   (match_dup 1)))]
   "TARGET_AMETHYST"
   [(set (match_dup 0)
         (lo_sum:SI (high:SI (match_dup 1))
                    (match_dup 1)))]
   {})

(define_expand "divmodsi4"
  [(parallel
    [(set (match_operand:SI 0 "register_operand" "")
          (div:SI (match_operand:SI 1 "register_operand" "")
                  (match_operand:SI 2 "register_operand" "")))
     (set (match_operand:SI 3 "register_operand" "")
          (mod:SI (match_dup 1) (match_dup 2)))])]
  "TARGET_AMETHYST"
  "")

(define_insn "*divmodsi4_insn"
  [(set (match_operand:SI 0 "register_operand"         "=Re,Ro")
        (div:SI (match_operand:SI 1 "register_operand" " r, r")
                (match_operand:SI 2 "register_operand" " r, r")))
   (set (match_operand:SI 3 "register_operand"         "=Ro,Re")
        (mod:SI (match_dup 1) (match_dup 2)))]
  "TARGET_AMETHYST"
{
  if (find_reg_note (insn, REG_UNUSED, operands[3]))
    return "div\t%0,%1,%2";
  else if (find_reg_note (insn, REG_UNUSED, operands[0]))
    return "rem\t%3,%1,%2";
  else
    return "div\t%0,%1,%2 ; rem\t%3,%1,%2";
}
  [(set_attr "type" "idiv")
   (set_attr "mode" "SI")
   (set_attr "insnpair" "yes")])

(define_expand "udivmodsi4"
  [(parallel
    [(set (match_operand:SI 0 "register_operand" "")
          (udiv:SI (match_operand:SI 1 "register_operand" "")
                   (match_operand:SI 2 "register_operand" "")))
     (set (match_operand:SI 3 "register_operand" "")
          (umod:SI (match_dup 1) (match_dup 2)))])]
  "TARGET_AMETHYST"
  "")

(define_insn "*udivmodsi4_insn"
  [(set (match_operand:SI 0 "register_operand"          "=Re,Ro")
        (udiv:SI (match_operand:SI 1 "register_operand" " r, r")
                 (match_operand:SI 2 "register_operand" " r, r")))
   (set (match_operand:SI 3 "register_operand"          "=Ro,Re")
        (umod:SI (match_dup 1) (match_dup 2)))]
  "TARGET_AMETHYST"
{
  if (find_reg_note (insn, REG_UNUSED, operands[3]))
    return "divu\t%0,%1,%2";
  else if (find_reg_note (insn, REG_UNUSED, operands[0]))
    return "remu\t%3,%1,%2";
  else
    return "divu\t%0,%1,%2 ; remu\t%3,%1,%2";
}
  [(set_attr "type" "idiv")
   (set_attr "mode" "SI")
   (set_attr "insnpair" "yes")])

(include "amethystsimd.md")



(define_automaton "amethyst")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functional units.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_cpu_unit "amethyst_pipea, amethyst_pipeb" "amethyst")

(define_reservation "amethyst_pipeboth" "amethyst_pipea+amethyst_pipeb")

;; Amethyst is in order and can dual-issue under limited circumstances.
;; pipeb can be reserved only after pipea is reserved.

(final_presence_set "amethyst_pipeb" "amethyst_pipea")

(define_cpu_unit "amethyst_rfeven, amethyst_rfodd" "amethyst")

(define_reservation "amethyst_rfboth" "amethyst_rfeven+amethyst_rfodd")

(define_cpu_unit "amethyst_imul, amethyst_idiv" "amethyst")

(define_insn_reservation "amethyst_controlflow" 0
  (eq_attr "type" "branch,jump,call")
  "amethyst_pipeboth")

(define_insn_reservation "amethyst_load_rfnone" 2
  (and (eq_attr "type" "load,fpload") (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea")

(define_insn_reservation "amethyst_load_rfeven" 2
  (and (eq_attr "type" "load,fpload") (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven")

(define_insn_reservation "amethyst_load_rfodd" 2
  (and (eq_attr "type" "load,fpload") (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd")

(define_insn_reservation "amethyst_load_rfboth" 2
  (and (eq_attr "type" "load,fpload") (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth")

(define_insn_reservation "amethyst_store" 0
  (eq_attr "type" "store,fpstore")
  "amethyst_pipea")

(define_insn_reservation "amethyst_arith_rfnone" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "no")) (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea")

(define_insn_reservation "amethyst_arith_rfeven" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "no")) (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven")

(define_insn_reservation "amethyst_arith_rfodd" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "no")) (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd")

(define_insn_reservation "amethyst_arith_rfboth" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "no")) (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth")

(define_insn_reservation "amethyst_arithb_rfnone" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "yes")) (eq_attr "amethyst_rfwriteports" "none"))
  "(amethyst_pipea|amethyst_pipeb)")

(define_insn_reservation "amethyst_arithb_rfeven" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "yes")) (eq_attr "amethyst_rfwriteports" "even"))
  "(amethyst_pipea|amethyst_pipeb)+amethyst_rfeven")

(define_insn_reservation "amethyst_arithb_rfodd" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "yes")) (eq_attr "amethyst_rfwriteports" "odd"))
  "(amethyst_pipea|amethyst_pipeb)+amethyst_rfodd")

(define_insn_reservation "amethyst_arithb_rfboth" 1
  (and (and (eq_attr "type" "unknown,mtc,mfc,const,arith,logical,shift,slt,move,fmove,fadd,fmul,fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,bitmanip") (eq_attr "amethyst_maypipeb" "yes")) (eq_attr "amethyst_rfwriteports" "both"))
  "(amethyst_pipea|amethyst_pipeb)+amethyst_rfboth")

(define_insn_reservation "amethyst_idiv_rfnone" 5
  (and (eq_attr "type" "idiv") (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea+amethyst_idiv, amethyst_idiv * 4")

(define_insn_reservation "amethyst_idiv_rfeven" 5
  (and (eq_attr "type" "idiv") (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven+amethyst_idiv, amethyst_idiv * 4")

(define_insn_reservation "amethyst_idiv_rfodd" 5
  (and (eq_attr "type" "idiv") (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd+amethyst_idiv, amethyst_idiv * 4")

(define_insn_reservation "amethyst_idiv_rfboth" 5
  (and (eq_attr "type" "idiv") (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth+amethyst_idiv, amethyst_idiv * 4")

(define_insn_reservation "amethyst_imul1_rfnone" 1
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "1")) (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea+amethyst_imul")

(define_insn_reservation "amethyst_imul1_rfeven" 1
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "1")) (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven+amethyst_imul")

(define_insn_reservation "amethyst_imul1_rfodd" 1
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "1")) (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd+amethyst_imul")

(define_insn_reservation "amethyst_imul1_rfboth" 1
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "1")) (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth+amethyst_imul")

(define_insn_reservation "amethyst_imul2_rfnone" 2
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "2")) (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea+amethyst_imul, amethyst_imul")

(define_insn_reservation "amethyst_imul2_rfeven" 2
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "2")) (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven+amethyst_imul, amethyst_imul")

(define_insn_reservation "amethyst_imul2_rfodd" 2
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "2")) (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd+amethyst_imul, amethyst_imul")

(define_insn_reservation "amethyst_imul2_rfboth" 2
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "2")) (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth+amethyst_imul, amethyst_imul")

(define_insn_reservation "amethyst_imul4_rfnone" 4
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "4")) (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea+amethyst_imul, amethyst_imul * 3")

(define_insn_reservation "amethyst_imul4_rfeven" 4
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "4")) (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven+amethyst_imul, amethyst_imul * 3")

(define_insn_reservation "amethyst_imul4_rfodd" 4
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "4")) (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd+amethyst_imul, amethyst_imul * 3")

(define_insn_reservation "amethyst_imul4_rfboth" 4
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "4")) (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth+amethyst_imul, amethyst_imul * 3")

(define_insn_reservation "amethyst_imul8_rfnone" 8
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "!1,2,4")) (eq_attr "amethyst_rfwriteports" "none"))
  "amethyst_pipea+amethyst_imul, amethyst_imul * 7")

(define_insn_reservation "amethyst_imul8_rfeven" 8
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "!1,2,4")) (eq_attr "amethyst_rfwriteports" "even"))
  "amethyst_pipea+amethyst_rfeven+amethyst_imul, amethyst_imul * 7")

(define_insn_reservation "amethyst_imul8_rfodd" 8
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "!1,2,4")) (eq_attr "amethyst_rfwriteports" "odd"))
  "amethyst_pipea+amethyst_rfodd+amethyst_imul, amethyst_imul * 7")

(define_insn_reservation "amethyst_imul8_rfboth" 8
  (and (and (eq_attr "type" "imul") (eq_attr "amethyst_cycle" "!1,2,4")) (eq_attr "amethyst_rfwriteports" "both"))
  "amethyst_pipea+amethyst_rfboth+amethyst_imul, amethyst_imul * 7")
