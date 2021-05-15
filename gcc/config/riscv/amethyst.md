;; Generic DFA-based pipeline description for RISC-V targets.
;; Copyright (C) 2011-2020 Free Software Foundation, Inc.
;; Contributed by Andrew Waterman (andrew@sifive.com).
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


(define_automaton "amethyst")
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
