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

(define_attr "rfwriteports" "none,even,odd,both" (symbol_ref "riscv_amethyst_regfile_halves (insn)"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Additional Instructions.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_insn "*loadconstsi"
  [(set (match_operand:SI 0 "register_operand"             "=r")
        (plus:SI (match_operand:SI 1 "lui_operand"         " L")
                 (match_operand:SI 2 "const_arith_operand" " I")))]
  "TARGET_AMETHYST"
  "lui\t%0,%1;\taddi\t%0,%0,%2"
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




(define_automaton "amethyst")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functional units.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;(define_cpu_unit "amethyst_pipea, amethyst_pipeb" "amethyst")

;;(define_reservation "amethyst_both" "amethyst_pipea+amethyst_pipeb")

;; Amethyst is in order and can dual-issue under limited circumstances.
;; pipeb can be reserved only after pipea is reserved.

;;(final_presence_set "amethyst_pipeb" "amethyst_pipea")


;;"unknown,branch,jump,call,load,fpload,store,fpstore,
;;   mtc,mfc,const,arith,logical,shift,slt,imul,idiv,move,fmove,fadd,fmul,
;;   fmadd,fdiv,fcmp,fcvt,fsqrt,multi,auipc,sfb_alu,nop,ghost,bitmanip"



(define_cpu_unit "am_alua" "amethyst")
(define_cpu_unit "am_idiv" "amethyst")

(define_insn_reservation "amethyst_alu" 1
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "unknown,const,arith,shift,slt,multi,auipc,nop,logical,move"))
  "am_alua")

(define_insn_reservation "amethyst_load" 3
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "load,fpload"))
  "am_alua")

(define_insn_reservation "amethyst_store" 1
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "store,fpstore"))
  "am_alua")

(define_insn_reservation "amethyst_branch" 1
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "branch,jump,call"))
  "am_alua")

(define_insn_reservation "amethyst_imul" 1
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "imul"))
  "am_alua")

(define_insn_reservation "amethyst_idivsi" 34
  (and (eq_attr "tune" "amethyst")
       (eq_attr "type" "idiv"))
  "am_idiv*10")
